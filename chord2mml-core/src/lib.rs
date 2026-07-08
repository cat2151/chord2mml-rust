//! Chord2MML Core Library
//!
//! Converts chord progression notation to MML (Music Macro Language) in the
//! format of the original JS chord2mml (e.g. `C` → `v11'c1eg'`), consumable
//! by obsidian-plugin-mmlabc.
//!
//! The pipeline mirrors the JS version's four stages:
//! ```text
//! parse → cst_to_ast (events) → ast2ast → ast2notes → notes2mml
//! ```
//!
//! Two parsing paths converge on the shared `cst_to_ast` semantic layer
//! (the architecture proven in tonejs-mml-to-json):
//! - Native (feature `tree-sitter`, enabled by the CLI): `convert` parses
//!   with the tree-sitter Rust crate.
//! - WASM/browser (default features, no C dependency): web-tree-sitter (JS)
//!   parses the input and `convert_cst` receives the CST as JSON.

use anyhow::{anyhow, Result};

// Module declarations
mod ast;
mod ast2ast;
mod ast2notes;
pub mod cst_to_ast;
mod notes2mml;
#[cfg(feature = "tree-sitter")]
mod parser;

// Re-export public types for external use
pub use ast::{ChordEvent, Event, NotesEvent, OutEvent, SlashChordEvent};

/// Run the shared pipeline stages after parsing.
fn events_to_mml(events: Vec<Event>) -> Result<String> {
    let events = ast2ast::ast_to_ast(events);
    let note_events = ast2notes::ast_to_notes(events)?;
    notes2mml::notes_to_mml(&note_events)
}

/// Convert a chord notation or chord progression to MML (Music Macro
/// Language) in the JS-chord2mml-compatible format.
///
/// Chords are separated by whitespace, ` - `, `→`, or `・`.
///
/// # Example
/// ```
/// use chord2mml_core::convert;
///
/// // Single chord
/// let mml = convert("C").unwrap();
/// assert_eq!(mml, "v11'c1eg'");
///
/// // Chord progression
/// let mml = convert("Dm G7 C").unwrap();
/// assert_eq!(mml, "v11'd1fa''g1b<df''c1eg'");
/// ```
#[cfg(feature = "tree-sitter")]
pub fn convert(input: &str) -> Result<String> {
    let input = input.trim();

    if input.is_empty() {
        return Err(anyhow!(
            "Empty input. Please provide a chord notation (e.g., 'C', 'Dm G7 C')."
        ));
    }

    // Validate input length to prevent potential issues
    if input.len() > 1000 {
        return Err(anyhow!("Input too long (max 1000 characters)."));
    }

    let events = parser::parse_to_ast(input)?;
    events_to_mml(events)
}

/// Convert a CST serialized as JSON (produced by web-tree-sitter in the
/// browser) to MML. This is the entry point for WASM builds, where the
/// parsing happens in JavaScript.
pub fn convert_cst(cst_json: &str) -> Result<String> {
    if cst_json.trim().is_empty() {
        return Err(anyhow!("Empty CST JSON input."));
    }

    let events = cst_to_ast::cst_json_to_ast(cst_json)?;
    events_to_mml(events)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[cfg(feature = "tree-sitter")]
    mod native {
        use super::super::*;

        #[test]
        fn test_convert_c_major() {
            let result = convert("C").unwrap();
            assert_eq!(result, "v11'c1eg'");
        }

        #[test]
        fn test_convert_chord_progression_whitespace() {
            let result = convert("C F G C").unwrap();
            assert_eq!(result, "v11'c1eg''f1a<c''g1b<d''c1eg'");
        }

        #[test]
        fn test_convert_chord_progression_hyphen() {
            // Unspaced-hyphen separators are legacy Rust-version syntax,
            // kept until `-` becomes the minor quality (JS spec) in a
            // later wave.
            let result = convert("C-F-G-C").unwrap();
            assert_eq!(result, "v11'c1eg''f1a<c''g1b<d''c1eg'");
        }

        #[test]
        fn test_convert_empty_input() {
            let result = convert("");
            assert!(result.is_err());
        }

        #[test]
        fn test_lower_upper_collision_fails() {
            // JS also errors on these (lower と upper が衝突)
            assert!(convert("F,/C").is_err());
            assert!(convert("/octave-up C/C").is_err());
        }

        #[test]
        fn test_convert_whitespace_trimmed() {
            let result = convert("  C  ").unwrap();
            assert_eq!(result, "v11'c1eg'");
        }
    }

    #[test]
    fn test_convert_cst_c_major() {
        let cst_json = r#"{
            "type": "source_file",
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
                }
            ]
        }"#;
        let result = convert_cst(cst_json).unwrap();
        assert_eq!(result, "v11'c1eg'");
    }

    #[test]
    fn test_convert_cst_empty_input() {
        assert!(convert_cst("").is_err());
    }
}
