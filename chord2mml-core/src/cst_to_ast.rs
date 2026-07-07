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

use crate::ast::{ChordEvent, Event, SlashChordEvent, SlashChordMode};

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
            "mode_chord_over_bass_note" => events.push(Event::ChangeSlashChordMode(
                SlashChordMode::ChordOverBassNote,
            )),
            "mode_slash_chord_inversion" => {
                events.push(Event::ChangeSlashChordMode(SlashChordMode::Inversion))
            }
            "mode_polychord" => {
                events.push(Event::ChangeSlashChordMode(SlashChordMode::Polychord))
            }
            "mode_root_inv" => {
                events.push(Event::ChangeInversionMode("root inv".to_string()))
            }
            "mode_1st_inv" => {
                events.push(Event::ChangeInversionMode("1st inv".to_string()))
            }
            "mode_2nd_inv" => {
                events.push(Event::ChangeInversionMode("2nd inv".to_string()))
            }
            "mode_3rd_inv" => {
                events.push(Event::ChangeInversionMode("3rd inv".to_string()))
            }
            "mode_close" => {
                events.push(Event::ChangeOpenHarmonyMode("close".to_string()))
            }
            "mode_drop2" => {
                events.push(Event::ChangeOpenHarmonyMode("drop2".to_string()))
            }
            "mode_drop4" => {
                events.push(Event::ChangeOpenHarmonyMode("drop4".to_string()))
            }
            "mode_drop2and4" => {
                events.push(Event::ChangeOpenHarmonyMode("drop2and4".to_string()))
            }
            "mode_no_bass" => {
                events.push(Event::ChangeBassPlayMode("no bass".to_string()))
            }
            "mode_bass_is_root" => {
                events.push(Event::ChangeBassPlayMode("root".to_string()))
            }
            "octave_up" => events.push(Event::OctaveShift {
                upper_delta: 1,
                lower_delta: 1,
            }),
            "octave_up_upper" => events.push(Event::OctaveShift {
                upper_delta: 1,
                lower_delta: 0,
            }),
            "octave_up_lower" => events.push(Event::OctaveShift {
                upper_delta: 0,
                lower_delta: 1,
            }),
            "octave_down" => events.push(Event::OctaveShift {
                upper_delta: -1,
                lower_delta: -1,
            }),
            "octave_down_upper" => events.push(Event::OctaveShift {
                upper_delta: -1,
                lower_delta: 0,
            }),
            "octave_down_lower" => events.push(Event::OctaveShift {
                upper_delta: 0,
                lower_delta: -1,
            }),
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
        Some(quality_node) => parse_quality_node(quality_node)?,
        // Default to major when no explicit quality is present
        None => "maj".to_string(),
    };

    let inversion = match field_first(chord_node, "inversion") {
        Some(node) => Some(parse_inversion(node.text.as_deref().unwrap_or(""))?),
        None => None,
    };

    let octave_offset = field_first(chord_node, "octave")
        .and_then(|n| n.text.as_deref())
        .map(parse_octave_offset)
        .unwrap_or(0);

    // Slash chord (`/`, resolved to a mode by ast2ast) or on-chord
    // (`on`/`over`, always chord-over-bass-note), like the JS version.
    // An absent lower root inherits the upper root (JS: lowerRoot ??=
    // upperRoot). An absent lower quality is "maj", NOT the upper quality:
    // in the PEG grammar CHORD_QUALITY matches the empty string as "maj",
    // so JS's `lowerQuality ??= upperQuality` never fires for quality.
    if let Some(bass_node) = field_first(chord_node, "bass") {
        let lower_root = match field_first(bass_node, "root") {
            Some(node) => parse_root_node(node)?,
            None => root,
        };
        let lower_quality = match field_first(bass_node, "quality") {
            Some(node) => parse_quality_node(node)?,
            None => "maj".to_string(),
        };
        let lower_inversion = match field_first(bass_node, "inversion") {
            Some(node) => Some(parse_inversion(node.text.as_deref().unwrap_or(""))?),
            None => None,
        };
        let lower_octave_offset = field_first(bass_node, "octave")
            .and_then(|n| n.text.as_deref())
            .map(parse_octave_offset)
            .unwrap_or(0);

        let slash = SlashChordEvent {
            upper_root: root,
            upper_quality: quality,
            upper_inversion: inversion,
            lower_root,
            lower_quality,
            lower_inversion,
            upper_octave_offset: octave_offset,
            lower_octave_offset,
            note_length: None,
        };

        return Ok(match bass_node.node_type.as_str() {
            "on_bass" => Event::ChordOverBassNote(slash),
            _ => Event::SlashChord(slash),
        });
    }

    Ok(Event::Chord(ChordEvent {
        root,
        quality,
        inversion,
        octave_offset,
        note_length: None,
    }))
}

/// Parse a per-chord octave offset token: net of `'` (up) minus `,` (down)
/// (JS OCTAVE_OFFSET).
fn parse_octave_offset(text: &str) -> i32 {
    let ups = text.chars().filter(|c| *c == '\'').count() as i32;
    let downs = text.chars().filter(|c| *c == ',').count() as i32;
    ups - downs
}

/// Map a `^N` token to the JS inversion name (`^0` cancels the current
/// inversion mode back to root position).
fn parse_inversion(text: &str) -> Result<String> {
    Ok(match text {
        "^0" => "root inv",
        "^1" => "1st inv",
        "^2" => "2nd inv",
        "^3" => "3rd inv",
        other => return Err(anyhow!("Unknown inversion: {}", other)),
    }
    .to_string())
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

/// Compose a quality node (base + modifiers) into the JS chord2mml
/// comma-joined quality string, e.g. "min7,flatted fifth" or
/// "maj,add9,omit5" (modifiers-only qualities get the implicit "maj"
/// base, matching JS MAJ_SHORT = "").
fn parse_quality_node(quality_node: &CSTNode) -> Result<String> {
    let base = field_first(quality_node, "base")
        .and_then(|n| n.text.as_deref())
        .unwrap_or("");
    let mut quality = normalize_quality(base)?;

    if let Some(modifiers) = quality_node.fields.get("modifier") {
        for modifier in modifiers {
            quality.push_str(&normalize_modifier(modifier.text.as_deref().unwrap_or(""))?);
        }
    }

    Ok(quality)
}

/// Normalize a modifier token to its comma-prefixed JS quality-string form.
fn normalize_modifier(modifier_str: &str) -> Result<String> {
    let inner = modifier_str
        .trim_start_matches('(')
        .trim_end_matches(')');

    match inner {
        "b5" | "-5" => return Ok(",flatted fifth".to_string()),
        "+5" | "#5" => return Ok(",augmented fifth".to_string()),
        _ => {}
    }
    if let Some(n) = inner.strip_prefix("add") {
        return Ok(format!(",add{}", n));
    }
    // "omit" before the short form "o" ("omit5" also starts with 'o')
    if let Some(n) = inner.strip_prefix("omit") {
        return Ok(format!(",omit{}", n));
    }
    if let Some(n) = inner.strip_prefix('o') {
        return Ok(format!(",omit{}", n));
    }

    Err(anyhow!("Unknown quality modifier: {}", modifier_str))
}

/// Normalize a quality token to the JS chord2mml quality string.
fn normalize_quality(quality_str: &str) -> Result<String> {
    // Quartal harmony is kept as literal text (JS QUARTAL_HARMONY)
    if quality_str.starts_with("4.") {
        return Ok(quality_str.to_string());
    }

    let normalized = match quality_str {
        "" | "M" | "maj" | "Maj" | "MAJ" => "maj",
        "m" | "-" | "min" | "Min" | "MIN" => "min",
        "m7" | "-7" | "min7" | "Min7" | "MIN7" => "min7",
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

    fn quality_node(base: Option<&str>, modifiers: &[&str]) -> CSTNode {
        let mut fields = HashMap::new();
        if let Some(b) = base {
            fields.insert("base".to_string(), vec![leaf("quality_base", b)]);
        }
        if !modifiers.is_empty() {
            fields.insert(
                "modifier".to_string(),
                modifiers
                    .iter()
                    .map(|m| leaf("quality_modifier", m))
                    .collect(),
            );
        }
        CSTNode {
            node_type: "quality".to_string(),
            text: None,
            children: Vec::new(),
            fields,
        }
    }

    fn chord_node(note: &str, accidentals: &[&str], quality: Option<&str>) -> CSTNode {
        let mut fields = HashMap::new();
        fields.insert("root".to_string(), vec![root_node(note, accidentals)]);
        if let Some(q) = quality {
            fields.insert("quality".to_string(), vec![quality_node(Some(q), &[])]);
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
                inversion: None,
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
            ("-", "min"),
            ("min", "min"),
            ("m7", "min7"),
            ("-7", "min7"),
            ("min7", "min7"),
            ("maj7", "maj7"),
            ("M7", "maj7"),
            ("△", "maj7"),
            ("M", "maj"),
            ("maj9", "maj7,add9"),
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
    fn test_quality_modifiers() {
        let cases: [(&str, Option<&str>, &[&str]); 5] = [
            ("maj,add9", None, &["add9"]),
            ("maj,flatted fifth", None, &["(b5)"]),
            ("7,augmented fifth", Some("7"), &["(#5)"]),
            ("min7,flatted fifth", Some("m7"), &["(b5)"]),
            ("maj,add9,omit5", None, &["(add9)", "(omit5)"]),
        ];
        for (expected, base, modifiers) in cases {
            let mut chord = chord_node("C", &[], None);
            chord.fields.insert(
                "quality".to_string(),
                vec![quality_node(base, modifiers)],
            );
            let events = cst_to_ast(&source(vec![chord])).unwrap();
            match &events[0] {
                Event::Chord(c) => assert_eq!(c.quality, expected),
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
                upper_inversion: None,
                lower_root: 0,
                lower_quality: "maj".to_string(),
                lower_inversion: None,
                upper_octave_offset: 0,
                lower_octave_offset: 0,
                note_length: None,
            })]
        );
    }

    #[test]
    fn test_mode_nodes() {
        let events = cst_to_ast(&source(vec![
            leaf("mode_polychord", "US"),
            chord_node("C", &[], None),
            leaf("mode_1st_inv", "1st inv"),
        ]))
        .unwrap();
        assert_eq!(
            events[0],
            Event::ChangeSlashChordMode(SlashChordMode::Polychord)
        );
        assert_eq!(
            events[2],
            Event::ChangeInversionMode("1st inv".to_string())
        );
    }

    #[test]
    fn test_caret_inversion() {
        let mut chord = chord_node("C", &[], None);
        chord.fields.insert(
            "inversion".to_string(),
            vec![leaf("chord_inversion", "^2")],
        );
        let events = cst_to_ast(&source(vec![chord])).unwrap();
        match &events[0] {
            Event::Chord(c) => assert_eq!(c.inversion, Some("2nd inv".to_string())),
            _ => panic!("Expected Chord"),
        }
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
