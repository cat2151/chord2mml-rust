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
//! Keeping the semantics in one place guarantees both paths behave
//! identically and can share the same golden tests.

use anyhow::{anyhow, Result};
use serde::Deserialize;
use std::collections::HashMap;

use crate::ast::{ASTChord, ASTRoot, Accidental, ChordQuality};

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

/// Convert a CST serialized as JSON into the AST.
pub fn cst_json_to_ast(cst_json: &str) -> Result<ASTRoot> {
    let root: CSTNode = serde_json::from_str(cst_json)
        .map_err(|e| anyhow!("Failed to parse CST JSON: {}", e))?;
    cst_to_ast(&root)
}

/// Convert a CST node tree into the AST.
pub fn cst_to_ast(root: &CSTNode) -> Result<ASTRoot> {
    let node = if root.node_type == "source_file" {
        root.children
            .first()
            .ok_or_else(|| anyhow!("No content found in parse tree"))?
    } else {
        root
    };

    match node.node_type.as_str() {
        "chord" => Ok(ASTRoot::SingleChord(parse_chord_node(node)?)),
        "chord_progression" => {
            let chords: Vec<ASTChord> = node
                .children
                .iter()
                .filter(|c| c.node_type == "chord")
                .map(parse_chord_node)
                .collect::<Result<_>>()?;

            if chords.is_empty() {
                return Err(anyhow!("No chords found in chord progression"));
            }

            Ok(ASTRoot::ChordProgression(chords))
        }
        other => Err(anyhow!("Unexpected node type: {}", other)),
    }
}

fn field_first<'a>(node: &'a CSTNode, name: &str) -> Option<&'a CSTNode> {
    node.fields.get(name).and_then(|nodes| nodes.first())
}

fn parse_chord_node(chord_node: &CSTNode) -> Result<ASTChord> {
    if chord_node.node_type != "chord" {
        return Err(anyhow!("Expected chord node, got: {}", chord_node.node_type));
    }

    let root_node =
        field_first(chord_node, "root").ok_or_else(|| anyhow!("No root node found"))?;

    let note = field_first(root_node, "note")
        .and_then(|n| n.text.clone())
        .ok_or_else(|| anyhow!("No note found in root"))?;

    let accidental = field_first(root_node, "accidental")
        .and_then(|n| n.text.as_deref())
        .and_then(|text| match text {
            "#" => Some(Accidental::Sharp),
            "b" => Some(Accidental::Flat),
            _ => None,
        });

    let quality = match field_first(chord_node, "quality") {
        Some(quality_node) => {
            parse_chord_quality(quality_node.text.as_deref().unwrap_or(""))?
        }
        // Default to major when no explicit quality is present
        None => ChordQuality::Major,
    };

    let bass = field_first(chord_node, "bass")
        .and_then(|n| n.text.as_deref())
        .map(|text| text.trim_start_matches('/').to_string());

    Ok(ASTChord {
        root: note,
        accidental,
        quality,
        bass,
    })
}

fn parse_chord_quality(quality_str: &str) -> Result<ChordQuality> {
    match quality_str {
        "" => Ok(ChordQuality::Major),
        "m" => Ok(ChordQuality::Minor),
        "maj7" | "M7" => Ok(ChordQuality::Major7),
        "7" => Ok(ChordQuality::Dominant7),
        "dim" => Ok(ChordQuality::Diminished),
        "aug" | "+" => Ok(ChordQuality::Augmented),
        "sus4" => Ok(ChordQuality::Sus4),
        "sus2" => Ok(ChordQuality::Sus2),
        _ => Err(anyhow!("Unknown chord quality: {}", quality_str)),
    }
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

    fn chord_node(note: &str, quality: Option<&str>) -> CSTNode {
        let mut root_fields = HashMap::new();
        root_fields.insert("note".to_string(), vec![leaf("note", note)]);

        let mut chord_fields = HashMap::new();
        chord_fields.insert(
            "root".to_string(),
            vec![CSTNode {
                node_type: "root".to_string(),
                text: Some(note.to_string()),
                children: Vec::new(),
                fields: root_fields,
            }],
        );
        if let Some(q) = quality {
            chord_fields.insert("quality".to_string(), vec![leaf("quality", q)]);
        }

        CSTNode {
            node_type: "chord".to_string(),
            text: Some(format!("{}{}", note, quality.unwrap_or(""))),
            children: Vec::new(),
            fields: chord_fields,
        }
    }

    #[test]
    fn test_cst_to_ast_single_chord() {
        let root = CSTNode {
            node_type: "source_file".to_string(),
            text: Some("C".to_string()),
            children: vec![chord_node("C", None)],
            fields: HashMap::new(),
        };
        let ast = cst_to_ast(&root).unwrap();
        match ast {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.quality, ChordQuality::Major);
                assert_eq!(chord.accidental, None);
                assert_eq!(chord.bass, None);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_cst_to_ast_minor_quality() {
        let root = CSTNode {
            node_type: "source_file".to_string(),
            text: Some("Dm".to_string()),
            children: vec![chord_node("D", Some("m"))],
            fields: HashMap::new(),
        };
        let ast = cst_to_ast(&root).unwrap();
        match ast {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "D");
                assert_eq!(chord.quality, ChordQuality::Minor);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_cst_json_to_ast_progression() {
        let cst_json = r#"{
            "type": "source_file",
            "children": [
                {
                    "type": "chord_progression",
                    "children": [
                        {
                            "type": "chord",
                            "text": "C",
                            "fields": {
                                "root": [{
                                    "type": "root",
                                    "text": "C",
                                    "fields": { "note": [{ "type": "note", "text": "C" }] }
                                }]
                            }
                        },
                        {
                            "type": "chord",
                            "text": "G",
                            "fields": {
                                "root": [{
                                    "type": "root",
                                    "text": "G",
                                    "fields": { "note": [{ "type": "note", "text": "G" }] }
                                }]
                            }
                        }
                    ]
                }
            ]
        }"#;
        let ast = cst_json_to_ast(cst_json).unwrap();
        match ast {
            ASTRoot::ChordProgression(chords) => {
                assert_eq!(chords.len(), 2);
                assert_eq!(chords[0].root, "C");
                assert_eq!(chords[1].root, "G");
            }
            _ => panic!("Expected ChordProgression"),
        }
    }

    #[test]
    fn test_cst_json_to_ast_invalid_json() {
        assert!(cst_json_to_ast("not json").is_err());
    }
}
