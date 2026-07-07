//! Chord2MML Core Library
//!
//! This library converts chord notation to MML (Music Macro Language) format.
//!
//! Two parsing paths converge on the shared `cst_to_ast` semantic layer
//! (the architecture proven in tonejs-mml-to-json):
//! - Native (feature `tree-sitter`, enabled by the CLI): `convert` parses with
//!   the tree-sitter Rust crate.
//! - WASM/browser (default features, no C dependency): web-tree-sitter (JS)
//!   parses the input and `convert_cst` receives the CST as JSON.
//!
//! Modules:
//! - `ast`: Abstract Syntax Tree data structures
//! - `cst_to_ast`: CST (JSON) to AST conversion — shared semantics
//! - `parser`: native tree-sitter parsing (feature `tree-sitter`)
//! - `mml`: AST to MML conversion
//! - `note`: Note operations (conversion and transposition)

use anyhow::{anyhow, Result};

// Module declarations
mod ast;
pub mod cst_to_ast;
mod mml;
mod note;
#[cfg(feature = "tree-sitter")]
mod parser;

// Re-export public types for external use
pub use ast::{ASTChord, ASTRoot, Accidental, ChordQuality};

/// Convert a chord notation or chord progression to MML (Music Macro Language) format
///
/// Supports:
/// - Single chords: "C" -> "'c;e;g'"
/// - Chord progressions: "C-F-G-C" -> "'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'"
///
/// # Example
/// ```
/// use chord2mml_core::convert;
///
/// // Single chord
/// let mml = convert("C").unwrap();
/// assert_eq!(mml, "'c;e;g'");
///
/// // Chord progression
/// let mml = convert("C-F-G-C").unwrap();
/// assert_eq!(mml, "'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'");
/// ```
#[cfg(feature = "tree-sitter")]
pub fn convert(input: &str) -> Result<String> {
    let input = input.trim();

    if input.is_empty() {
        return Err(anyhow!(
            "Empty input. Please provide a chord notation (e.g., 'C', 'C-F-G-C')."
        ));
    }

    // Validate input length to prevent potential issues
    if input.len() > 1000 {
        return Err(anyhow!("Input too long (max 1000 characters)."));
    }

    // Parse input to AST
    let ast = parser::parse_to_ast(input)?;

    // Convert AST to MML
    mml::ast_to_mml(&ast)
}

/// Convert a CST serialized as JSON (produced by web-tree-sitter in the
/// browser) to MML. This is the entry point for WASM builds, where the
/// parsing happens in JavaScript.
pub fn convert_cst(cst_json: &str) -> Result<String> {
    if cst_json.trim().is_empty() {
        return Err(anyhow!("Empty CST JSON input."));
    }

    let ast = cst_to_ast::cst_json_to_ast(cst_json)?;
    mml::ast_to_mml(&ast)
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
            assert_eq!(result, "'c;e;g'");
        }

        #[test]
        fn test_convert_chord_progression() {
            let result = convert("C-F-G-C").unwrap();
            assert_eq!(result, "'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'");
        }

        #[test]
        fn test_convert_empty_input() {
            let result = convert("");
            assert!(result.is_err());
        }

        #[test]
        fn test_convert_whitespace_trimmed() {
            let result = convert("  C  ").unwrap();
            assert_eq!(result, "'c;e;g'");
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
        assert_eq!(result, "'c;e;g'");
    }

    #[test]
    fn test_convert_cst_empty_input() {
        assert!(convert_cst("").is_err());
    }
}
