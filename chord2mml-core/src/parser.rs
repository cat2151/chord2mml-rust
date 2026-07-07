//! Native parser (feature `tree-sitter` only).
//!
//! Parses chord notation with the [tree-sitter](https://tree-sitter.github.io/tree-sitter/)
//! Rust crate and the `tree_sitter_chord` grammar, then serializes the CST into
//! the same [`CSTNode`] shape that web-tree-sitter produces in the browser, so
//! that all semantics live in the shared `cst_to_ast` module.
//!
//! Build notes:
//! - Requires a C toolchain (the grammar crate compiles C in its `build.rs`),
//!   which is why this module is gated behind the `tree-sitter` feature and
//!   excluded from `wasm32-unknown-unknown` builds. WASM builds parse with
//!   web-tree-sitter (JavaScript) instead and call `convert_cst`.

use anyhow::{anyhow, Result};
use std::collections::HashMap;
use tree_sitter::{Node, Parser};

use crate::ast::ASTRoot;
use crate::cst_to_ast::{cst_to_ast, CSTNode};

/// Parse chord notation using Tree-sitter and convert to AST
pub(crate) fn parse_to_ast(input: &str) -> Result<ASTRoot> {
    let mut parser = Parser::new();
    parser
        .set_language(tree_sitter_chord::language())
        .map_err(|e| anyhow!("Failed to set TreeSitter language: {}", e))?;

    let tree = parser
        .parse(input, None)
        .ok_or_else(|| anyhow!("Failed to parse chord notation"))?;

    let root_node = tree.root_node();

    if root_node.has_error() {
        return Err(anyhow!("Syntax error in chord notation: {}", input));
    }

    let cst = node_to_cst(root_node, input.as_bytes())?;
    cst_to_ast(&cst)
}

/// Serialize a tree-sitter node into the CSTNode JSON shape shared with
/// web-tree-sitter: named children with a field name go to `fields`, other
/// named children go to `children`.
fn node_to_cst(node: Node, source: &[u8]) -> Result<CSTNode> {
    let mut children = Vec::new();
    let mut fields: HashMap<String, Vec<CSTNode>> = HashMap::new();

    let mut cursor = node.walk();
    if cursor.goto_first_child() {
        loop {
            let child = cursor.node();
            if child.is_named() {
                let field_name = cursor.field_name().map(str::to_string);
                let child_cst = node_to_cst(child, source)?;
                match field_name {
                    Some(name) => fields.entry(name).or_default().push(child_cst),
                    None => children.push(child_cst),
                }
            }
            if !cursor.goto_next_sibling() {
                break;
            }
        }
    }

    let text = node
        .utf8_text(source)
        .map_err(|e| anyhow!("Failed to extract node text: {}", e))?
        .to_string();

    Ok(CSTNode {
        node_type: node.kind().to_string(),
        text: Some(text),
        children,
        fields,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::{Accidental, ChordQuality};

    #[test]
    fn test_parse_basic_major_chord() {
        let result = parse_to_ast("C").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.accidental, None);
                assert_eq!(chord.quality, ChordQuality::Major);
                assert_eq!(chord.bass, None);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_chord_with_sharp() {
        let result = parse_to_ast("C#").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.accidental, Some(Accidental::Sharp));
                assert_eq!(chord.quality, ChordQuality::Major);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_chord_with_flat() {
        let result = parse_to_ast("Db").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "D");
                assert_eq!(chord.accidental, Some(Accidental::Flat));
                assert_eq!(chord.quality, ChordQuality::Major);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_minor_chord() {
        let result = parse_to_ast("Dm").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "D");
                assert_eq!(chord.quality, ChordQuality::Minor);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_seventh_chord() {
        let result = parse_to_ast("G7").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "G");
                assert_eq!(chord.quality, ChordQuality::Dominant7);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_major7_chord() {
        let result = parse_to_ast("CM7").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.quality, ChordQuality::Major7);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_slash_chord() {
        let result = parse_to_ast("C/E").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.quality, ChordQuality::Major);
                assert_eq!(chord.bass, Some("E".to_string()));
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_slash_chord_with_accidental() {
        let result = parse_to_ast("C/F#").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.root, "C");
                assert_eq!(chord.bass, Some("F#".to_string()));
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_chord_progression() {
        let result = parse_to_ast("C-F-G-C").unwrap();
        match result {
            ASTRoot::ChordProgression(chords) => {
                assert_eq!(chords.len(), 4);
                assert_eq!(chords[0].root, "C");
                assert_eq!(chords[1].root, "F");
                assert_eq!(chords[2].root, "G");
                assert_eq!(chords[3].root, "C");
            }
            _ => panic!("Expected ChordProgression"),
        }
    }

    #[test]
    fn test_parse_invalid_root_note() {
        let result = parse_to_ast("H");
        assert!(result.is_err());
        let err_msg = result.unwrap_err().to_string();
        // Tree-sitter reports syntax errors for invalid input
        assert!(err_msg.contains("Syntax error") || err_msg.contains("error"));
    }

    #[test]
    fn test_parse_unknown_quality_fails() {
        let result = parse_to_ast("Cxyz");
        assert!(result.is_err());
        let err_msg = result.unwrap_err().to_string();
        // Tree-sitter reports syntax errors for unrecognized chord qualities
        assert!(err_msg.contains("Syntax error") || err_msg.contains("Unknown chord quality"));
    }

    #[test]
    fn test_parse_sus4_chord() {
        let result = parse_to_ast("Csus4").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.quality, ChordQuality::Sus4);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_dim_chord() {
        let result = parse_to_ast("Cdim").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.quality, ChordQuality::Diminished);
            }
            _ => panic!("Expected SingleChord"),
        }
    }

    #[test]
    fn test_parse_aug_chord() {
        let result = parse_to_ast("Caug").unwrap();
        match result {
            ASTRoot::SingleChord(chord) => {
                assert_eq!(chord.quality, ChordQuality::Augmented);
            }
            _ => panic!("Expected SingleChord"),
        }
    }
}
