//! Chord2MML Core Library
//!
//! This library converts chord notation to MML (Music Macro Language) format.
//! 
//! The implementation follows the Single Responsibility Principle with separate modules:
//! - `ast`: Abstract Syntax Tree data structures
//! - `parser`: Tree-sitter parsing and CST to AST conversion
//! - `mml`: AST to MML conversion
//! - `note`: Note operations (conversion and transposition)

use anyhow::{anyhow, Result};

// Module declarations
mod ast;
mod parser;
mod mml;
mod note;

// Re-export public types for external use
pub use ast::{ASTChord, ASTRoot, Accidental, ChordQuality};

/// Convert a chord notation or chord progression to MML (Music Macro Language) format
/// 
/// Supports:
/// - Single chords: "C" -> "c;e;g"
/// - Chord progressions: "C-F-G-C" -> "c;e;g f;a;c g;b;d c;e;g"
/// 
/// # Example
/// ```
/// use chord2mml_core::convert;
/// 
/// // Single chord
/// let mml = convert("C").unwrap();
/// assert_eq!(mml, "c;e;g");
/// 
/// // Chord progression
/// let mml = convert("C-F-G-C").unwrap();
/// assert_eq!(mml, "c;e;g f;a;c g;b;d c;e;g");
/// ```
pub fn convert(input: &str) -> Result<String> {
    let input = input.trim();
    
    if input.is_empty() {
        return Err(anyhow!(
            "Empty input. Please provide a chord notation (e.g., 'C', 'C-F-G-C')."
        ));
    }
    
    // Validate input length to prevent potential issues
    if input.len() > 1000 {
        return Err(anyhow!(
            "Input too long (max 1000 characters)."
        ));
    }
    
    // Parse input to AST
    let ast = parser::parse_to_ast(input)?;
    
    // Convert AST to MML
    mml::ast_to_mml(&ast)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert_c_major() {
        let result = convert("C").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[test]
    fn test_convert_chord_progression() {
        let result = convert("C-F-G-C").unwrap();
        assert_eq!(result, "c;e;g f;a;c g;b;d c;e;g");
    }

    #[test]
    fn test_convert_empty_input() {
        let result = convert("");
        assert!(result.is_err());
    }

    #[test]
    fn test_convert_whitespace_trimmed() {
        let result = convert("  C  ").unwrap();
        assert_eq!(result, "c;e;g");
    }
}
