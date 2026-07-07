//! CST (JSON) to AST conversion — the shared semantic layer.
//!
//! Both parsing paths converge here, following the architecture proven in
//! `tonejs-mml-to-json`:
//! - Native: the `tree-sitter` Rust crate parses the input, and `parser.rs`
//!   serializes the CST into [`CSTNode`] (feature `tree-sitter`).
//! - WASM/browser: web-tree-sitter (JavaScript) parses the input and passes
//!   the CST as JSON, avoiding tree-sitter's C dependency entirely on
//!   `wasm32-unknown-unknown`.
//!
//! The output is the JS-compatible event array: roots resolved to semitone
//! numbers and qualities normalized to the strings used by the original
//! chord2mml (the resolution the JS version does inside its PEG grammar
//! happens here instead, because tree-sitter grammars cannot compute).

use anyhow::{anyhow, Result};
use serde::Deserialize;
use std::collections::HashMap;

use crate::ast::{ChordEvent, Event, SlashChordEvent};

/// A Tree-sitter CST node in the JSON shape emitted by web-tree-sitter
/// serialization (same shape as tonejs-mml-to-json's `nodeToCSTJson`):
/// named children without a field name go to `children`, field-bound
/// children go to `fields`.
#[derive(Debug, Clone, Deserialize)]
pub struct CSTNode {
    #[serde(rename = "type")]
    pub node_type: String,
    #[serde(default)]
    pub text: Option<String>,
    #[serde(default)]
    pub children: Vec<CSTNode>,
    #[serde(default)]
    pub fields: HashMap<String, Vec<CSTNode>>,
}

/// Convert a CST serialized as JSON into the event-array AST.
pub fn cst_json_to_ast(cst_json: &str) -> Result<Vec<Event>> {
    let root: CSTNode = serde_json::from_str(cst_json)
        .map_err(|e| anyhow!("Failed to parse CST JSON: {}", e))?;
    cst_to_ast(&root)
}

/// Convert a CST node tree into the event-array AST.
pub fn cst_to_ast(root: &CSTNode) -> Result<Vec<Event>> {
    if root.node_type != "source_file" {
        return Err(anyhow!(
            "Expected source_file root node, got: {}",
            root.node_type
        ));
    }

    let mut events = Vec::new();
    for child in &root.children {
        match child.node_type.as_str() {
            "chord" => events.push(parse_chord_node(child)?),
            "separator" => {} // progression separators carry no meaning
            other => return Err(anyhow!("Unexpected node type: {}", other)),
        }
    }

    if events.is_empty() {
        return Err(anyhow!("No chords found in input"));
    }

    Ok(events)
}

fn field_first<'a>(node: &'a CSTNode, name: &str) -> Option<&'a CSTNode> {
    node.fields.get(name).and_then(|nodes| nodes.first())
}

fn parse_chord_node(chord_node: &CSTNode) -> Result<Event> {
    let root_node =
        field_first(chord_node, "root").ok_or_else(|| anyhow!("No root node found"))?;
    let root = parse_root_node(root_node)?;

    let quality = match field_first(chord_node, "quality") {
        Some(quality_node) => {
            normalize_quality(quality_node.text.as_deref().unwrap_or(""))?
        }
        // Default to major when no explicit quality is present
        None => "maj".to_string(),
    };

    // Slash chord (bass): resolved to a mode by ast2ast, like the JS version
    if let Some(bass_node) = field_first(chord_node, "bass") {
        let bass_root_node = field_first(bass_node, "root")
            .or_else(|| bass_node.children.first())
            .ok_or_else(|| anyhow!("No root found in bass"))?;
        let lower_root = parse_root_node(bass_root_node)?;

        return Ok(Event::SlashChord(SlashChordEvent {
            upper_root: root,
            upper_quality: quality,
            lower_root,
            // Lower quality defaults to the upper quality in the JS grammar
            // when not written; a bare bass note only uses its root anyway.
            lower_quality: "maj".to_string(),
            upper_octave_offset: 0,
            lower_octave_offset: 0,
            note_length: None,
        }));
    }

    Ok(Event::Chord(ChordEvent {
        root,
        quality,
        octave_offset: 0,
        note_length: None,
    }))
}

/// Resolve a root node (note letter + accidentals) to a semitone offset.
/// C=0, D=2, E=4, F=5, G=7, A=9, B=11, +1 per sharp, -1 per flat
/// (not normalized mod 12, matching the JS grammar).
fn parse_root_node(root_node: &CSTNode) -> Result<i32> {
    let note = field_first(root_node, "note")
        .and_then(|n| n.text.as_deref())
        .ok_or_else(|| anyhow!("No note found in root"))?;

    let base = match note {
        "C" => 0,
        "D" => 2,
        "E" => 4,
        "F" => 5,
        "G" => 7,
        "A" => 9,
        "B" => 11,
        other => return Err(anyhow!("Unknown note: {}", other)),
    };

    let mut offset = 0;
    if let Some(accidentals) = root_node.fields.get("accidental") {
        for acc in accidentals {
            match acc.text.as_deref() {
                Some("#") | Some("＃") | Some("♯") => offset += 1,
                Some("b") | Some("♭") => offset -= 1,
                other => return Err(anyhow!("Unknown accidental: {:?}", other)),
            }
        }
    }

    Ok(base + offset)
}

/// Normalize a quality token to the JS chord2mml quality string.
fn normalize_quality(quality_str: &str) -> Result<String> {
    // Quartal harmony is kept as literal text (JS QUARTAL_HARMONY)
    if quality_str.starts_with("4.") {
        return Ok(quality_str.to_string());
    }

    let normalized = match quality_str {
        "" | "M" | "maj" | "Maj" | "MAJ" => "maj",
        "m" | "min" | "Min" | "MIN" => "min",
        "m7" | "min7" | "Min7" | "MIN7" => "min7",
        "maj7" | "Maj7" | "MAJ7" | "M7" | "△" => "maj7",
        // JS MAJ9: maj9 family resolves to maj7 plus an added ninth
        "maj9" | "Maj9" | "MAJ9" | "M9" | "△9" | "maj(9)" | "Maj(9)" | "MAJ(9)" | "M(9)"
        | "△(9)" => "maj7,add9",
        "6" => "6",
        "7" => "7",
        "9" => "9",
        "11" => "11",
        "13" => "13",
        "7sus2" => "7sus2",
        "7sus4" => "7sus4",
        "dim" => "dim triad",
        "aug" | "+" => "aug",
        "sus4" => "sus4",
        "sus2" => "sus2",
        other => return Err(anyhow!("Unknown chord quality: {}", other)),
    };
    Ok(normalized.to_string())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn leaf(node_type: &str, text: &str) -> CSTNode {
        CSTNode {
            node_type: node_type.to_string(),
            text: Some(text.to_string()),
            children: Vec::new(),
            fields: HashMap::new(),
        }
    }

    fn root_node(note: &str, accidentals: &[&str]) -> CSTNode {
        let mut fields = HashMap::new();
        fields.insert("note".to_string(), vec![leaf("note", note)]);
        if !accidentals.is_empty() {
            fields.insert(
                "accidental".to_string(),
                accidentals.iter().map(|a| leaf("accidental", a)).collect(),
            );
        }
        CSTNode {
            node_type: "root".to_string(),
            text: Some(format!("{}{}", note, accidentals.concat())),
            children: Vec::new(),
            fields,
        }
    }

    fn chord_node(note: &str, accidentals: &[&str], quality: Option<&str>) -> CSTNode {
        let mut fields = HashMap::new();
        fields.insert("root".to_string(), vec![root_node(note, accidentals)]);
        if let Some(q) = quality {
            fields.insert("quality".to_string(), vec![leaf("quality", q)]);
        }
        CSTNode {
            node_type: "chord".to_string(),
            text: None,
            children: Vec::new(),
            fields,
        }
    }

    fn source(children: Vec<CSTNode>) -> CSTNode {
        CSTNode {
            node_type: "source_file".to_string(),
            text: None,
            children,
            fields: HashMap::new(),
        }
    }

    #[test]
    fn test_c_major() {
        let events = cst_to_ast(&source(vec![chord_node("C", &[], None)])).unwrap();
        assert_eq!(
            events,
            vec![Event::Chord(ChordEvent {
                root: 0,
                quality: "maj".to_string(),
                octave_offset: 0,
                note_length: None,
            })]
        );
    }

    #[test]
    fn test_sharp_and_fullwidth_accidentals() {
        for acc in ["#", "＃", "♯"] {
            let events = cst_to_ast(&source(vec![chord_node("C", &[acc], None)])).unwrap();
            match &events[0] {
                Event::Chord(c) => assert_eq!(c.root, 1, "accidental {}", acc),
                _ => panic!("Expected Chord"),
            }
        }
        for acc in ["b", "♭"] {
            let events = cst_to_ast(&source(vec![chord_node("B", &[acc], None)])).unwrap();
            match &events[0] {
                Event::Chord(c) => assert_eq!(c.root, 10, "accidental {}", acc),
                _ => panic!("Expected Chord"),
            }
        }
    }

    #[test]
    fn test_quality_normalization() {
        for (token, expected) in [
            ("m", "min"),
            ("min", "min"),
            ("m7", "min7"),
            ("min7", "min7"),
            ("maj7", "maj7"),
            ("M7", "maj7"),
            ("△", "maj7"),
            ("M", "maj"),
            ("dim", "dim triad"),
            ("aug", "aug"),
            ("7", "7"),
        ] {
            let events =
                cst_to_ast(&source(vec![chord_node("C", &[], Some(token))])).unwrap();
            match &events[0] {
                Event::Chord(c) => assert_eq!(c.quality, expected, "token {}", token),
                _ => panic!("Expected Chord"),
            }
        }
    }

    #[test]
    fn test_slash_chord() {
        let mut chord = chord_node("F", &[], None);
        let mut bass_fields = HashMap::new();
        bass_fields.insert("root".to_string(), vec![root_node("C", &[])]);
        chord.fields.insert(
            "bass".to_string(),
            vec![CSTNode {
                node_type: "bass".to_string(),
                text: Some("/C".to_string()),
                children: Vec::new(),
                fields: bass_fields,
            }],
        );
        let events = cst_to_ast(&source(vec![chord])).unwrap();
        assert_eq!(
            events,
            vec![Event::SlashChord(SlashChordEvent {
                upper_root: 5,
                upper_quality: "maj".to_string(),
                lower_root: 0,
                lower_quality: "maj".to_string(),
                upper_octave_offset: 0,
                lower_octave_offset: 0,
                note_length: None,
            })]
        );
    }

    #[test]
    fn test_separator_nodes_are_skipped() {
        let events = cst_to_ast(&source(vec![
            chord_node("C", &[], None),
            leaf("separator", "-"),
            chord_node("G", &[], None),
        ]))
        .unwrap();
        assert_eq!(events.len(), 2);
    }

    #[test]
    fn test_empty_input_fails() {
        assert!(cst_to_ast(&source(vec![])).is_err());
    }

    #[test]
    fn test_invalid_json() {
        assert!(cst_json_to_ast("not json").is_err());
    }
}
