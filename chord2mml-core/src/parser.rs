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

use crate::ast::Event;
use crate::cst_to_ast::{cst_to_ast, CSTNode};

/// Parse chord notation using Tree-sitter and convert to the event-array AST
pub(crate) fn parse_to_ast(input: &str) -> Result<Vec<Event>> {
    let mut parser = Parser::new();
    parser
        .set_language(&tree_sitter_chord::language())
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
    use crate::ast::{ChordEvent, SlashChordEvent};

    fn single_chord(input: &str) -> ChordEvent {
        let events = parse_to_ast(input).unwrap();
        assert_eq!(events.len(), 1, "input {}", input);
        match &events[0] {
            Event::Chord(chord) => chord.clone(),
            other => panic!("Expected Chord, got {:?}", other),
        }
    }

    fn single_slash_chord(input: &str) -> SlashChordEvent {
        let events = parse_to_ast(input).unwrap();
        assert_eq!(events.len(), 1, "input {}", input);
        match &events[0] {
            Event::SlashChord(slash) => slash.clone(),
            other => panic!("Expected SlashChord, got {:?}", other),
        }
    }

    #[test]
    fn test_parse_basic_major_chord() {
        let chord = single_chord("C");
        assert_eq!(chord.root, 0);
        assert_eq!(chord.quality, "maj");
    }

    #[test]
    fn test_parse_chord_with_sharp() {
        for input in ["C#", "C＃", "C♯"] {
            let chord = single_chord(input);
            assert_eq!(chord.root, 1, "input {}", input);
            assert_eq!(chord.quality, "maj");
        }
    }

    #[test]
    fn test_parse_chord_with_flat() {
        for input in ["Db", "D♭"] {
            let chord = single_chord(input);
            assert_eq!(chord.root, 1, "input {}", input);
        }
    }

    #[test]
    fn test_parse_minor_chord() {
        for input in ["Dm", "Dmin"] {
            let chord = single_chord(input);
            assert_eq!(chord.root, 2, "input {}", input);
            assert_eq!(chord.quality, "min");
        }
    }

    #[test]
    fn test_parse_minor7_chord() {
        for input in ["Cm7", "Cmin7"] {
            let chord = single_chord(input);
            assert_eq!(chord.quality, "min7", "input {}", input);
        }
    }

    #[test]
    fn test_parse_seventh_chord() {
        let chord = single_chord("G7");
        assert_eq!(chord.root, 7);
        assert_eq!(chord.quality, "7");
    }

    #[test]
    fn test_parse_major7_chord() {
        for input in ["CM7", "Cmaj7", "C△"] {
            let chord = single_chord(input);
            assert_eq!(chord.quality, "maj7", "input {}", input);
        }
    }

    #[test]
    fn test_parse_slash_chord() {
        let slash = single_slash_chord("F/C");
        assert_eq!(slash.upper_root, 5);
        assert_eq!(slash.upper_quality, "maj");
        assert_eq!(slash.lower_root, 0);
    }

    #[test]
    fn test_parse_slash_chord_with_accidental() {
        let slash = single_slash_chord("C/F#");
        assert_eq!(slash.upper_root, 0);
        assert_eq!(slash.lower_root, 6);
    }

    #[test]
    fn test_parse_progression_separators() {
        // Whitespace / spaced hyphen / → / ・ per the JS spec, plus the
        // legacy unspaced hyphen (until `-` becomes minor in a later wave)
        for input in [
            "C F G C",
            "C - F - G - C",
            "C→F→G→C",
            "C・F・G・C",
            "C-F-G-C",
        ] {
            let events = parse_to_ast(input).unwrap();
            assert_eq!(events.len(), 4, "input {}", input);
            let roots: Vec<i32> = events
                .iter()
                .map(|e| match e {
                    Event::Chord(c) => c.root,
                    other => panic!("Expected Chord, got {:?}", other),
                })
                .collect();
            assert_eq!(roots, vec![0, 5, 7, 0], "input {}", input);
        }
    }

    #[test]
    fn test_parse_invalid_root_note() {
        let result = parse_to_ast("H");
        assert!(result.is_err());
    }

    #[test]
    fn test_parse_unknown_quality_fails() {
        let result = parse_to_ast("Cxyz");
        assert!(result.is_err());
    }

    #[test]
    fn test_parse_sus_dim_aug() {
        assert_eq!(single_chord("Csus4").quality, "sus4");
        assert_eq!(single_chord("Csus2").quality, "sus2");
        assert_eq!(single_chord("Cdim").quality, "dim triad");
        assert_eq!(single_chord("Caug").quality, "aug");
        assert_eq!(single_chord("C+").quality, "aug");
    }
}
