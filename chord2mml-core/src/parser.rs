//! Parser module for converting chord notation to AST
//!
//! This module handles parsing and conversion to AST.
//! - With tree-sitter feature: uses Tree-sitter for robust parsing
//! - Without tree-sitter feature: uses manual parsing for WASM compatibility

use anyhow::{anyhow, Result};
use crate::ast::{ASTChord, ASTRoot, Accidental, ChordQuality};

#[cfg(feature = "tree-sitter")]
use tree_sitter::Parser;

/// Parse chord notation using TreeSitter or manual parser, convert to AST
pub(crate) fn parse_to_ast(input: &str) -> Result<ASTRoot> {
    #[cfg(feature = "tree-sitter")]
    {
        parse_to_ast_tree_sitter(input)
    }
    
    #[cfg(not(feature = "tree-sitter"))]
    {
        parse_to_ast_manual(input)
    }
}

/// Manual parser for chord notation (used when tree-sitter feature is disabled)
#[cfg(not(feature = "tree-sitter"))]
fn parse_to_ast_manual(input: &str) -> Result<ASTRoot> {
    let input = input.trim();
    
    // Check for chord progression (contains hyphens)
    if input.contains('-') {
        let chord_strs: Vec<&str> = input.split('-').collect();
        let mut chords = Vec::new();
        
        for chord_str in chord_strs {
            let chord_str = chord_str.trim();
            if !chord_str.is_empty() {
                chords.push(parse_chord_manual(chord_str)?);
            }
        }
        
        if chords.is_empty() {
            return Err(anyhow!("No valid chords found in progression"));
        }
        
        Ok(ASTRoot::ChordProgression(chords))
    } else {
        // Single chord
        let chord = parse_chord_manual(input)?;
        Ok(ASTRoot::SingleChord(chord))
    }
}

/// Parse a single chord string manually
#[cfg(not(feature = "tree-sitter"))]
fn parse_chord_manual(input: &str) -> Result<ASTChord> {
    let chars: Vec<char> = input.chars().collect();
    if chars.is_empty() {
        return Err(anyhow!("Empty chord notation"));
    }
    
    let mut index = 0;
    
    // Parse root note (A-G)
    let root = chars[index];
    if !matches!(root, 'A'..='G') {
        if matches!(root, 'a'..='g') {
            return Err(anyhow!(
                "Invalid root note '{}': root note must be uppercase A-G",
                root
            ));
        }
        return Err(anyhow!("Invalid root note: {}", root));
    }
    index += 1;
    
    // Parse accidental (#, b) if present
    let accidental = if index < chars.len() {
        match chars[index] {
            '#' => {
                index += 1;
                Some(Accidental::Sharp)
            }
            'b' => {
                index += 1;
                Some(Accidental::Flat)
            }
            _ => None,
        }
    } else {
        None
    };
    
    // Parse quality (m, maj7, M7, 7, dim, aug, +, sus4, sus2, etc.)
    let quality = if index < chars.len() {
        let remaining: String = chars[index..].iter().collect();
        
        // Check for slash chord (bass note) first
        if let Some(slash_pos) = remaining.find('/') {
            let quality_str = &remaining[..slash_pos];
            let quality = parse_quality_manual(quality_str)?;
            
            // Parse bass note (everything after /)
            let bass_str = &remaining[slash_pos + 1..];
            let bass = if !bass_str.is_empty() {
                // Validate bass note format (should be A-G with optional accidental)
                validate_bass_note(bass_str)?;
                Some(bass_str.to_string())
            } else {
                return Err(anyhow!("Empty bass note after '/' in slash chord"));
            };
            
            return Ok(ASTChord {
                root: root.to_string(),
                accidental,
                quality,
                bass,
            });
        } else {
            parse_quality_manual(&remaining)?
        }
    } else {
        ChordQuality::Major
    };
    
    Ok(ASTChord {
        root: root.to_string(),
        accidental,
        quality,
        bass: None,
    })
}

/// Validate bass note format (A-G with optional accidental #, b)
#[cfg(not(feature = "tree-sitter"))]
fn validate_bass_note(bass_str: &str) -> Result<()> {
    let chars: Vec<char> = bass_str.chars().collect();
    
    // First character must be A-G
    if !matches!(chars[0], 'A'..='G') {
        return Err(anyhow!("Invalid bass note '{}': must start with A-G", bass_str));
    }
    
    // Optional second character must be # or b
    if chars.len() > 1 && !matches!(chars[1], '#' | 'b') {
        return Err(anyhow!("Invalid bass note '{}': accidental must be # or b", bass_str));
    }
    
    // No more than 2 characters allowed
    if chars.len() > 2 {
        return Err(anyhow!("Invalid bass note '{}': too many characters", bass_str));
    }
    
    Ok(())
}

/// Parse chord quality from string (shared by both parsers)
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

/// Parse chord quality from string
#[cfg(not(feature = "tree-sitter"))]
fn parse_quality_manual(quality_str: &str) -> Result<ChordQuality> {
    parse_chord_quality(quality_str)
}

/// Parse chord notation using TreeSitter, convert CST to AST
#[cfg(feature = "tree-sitter")]
fn parse_to_ast_tree_sitter(input: &str) -> Result<ASTRoot> {
    let mut parser = Parser::new();
    parser
        .set_language(tree_sitter_chord::language())
        .map_err(|e| anyhow!("Failed to set TreeSitter language: {}", e))?;
    
    let tree = parser
        .parse(input, None)
        .ok_or_else(|| anyhow!("Failed to parse chord notation"))?;
    
    let root_node = tree.root_node();
    
    // Check for parsing errors
    if root_node.has_error() {
        return Err(anyhow!("Syntax error in chord notation: {}", input));
    }
    
    // Navigate to the first child (chord or chord_progression)
    let first_child = if root_node.kind() == "source_file" {
        root_node.child(0).ok_or_else(|| anyhow!("No content found in parse tree"))?
    } else {
        root_node
    };
    
    // Convert CST to AST
    match first_child.kind() {
        "chord" => {
            let chord = parse_chord_node(&first_child, input)?;
            Ok(ASTRoot::SingleChord(chord))
        }
        "chord_progression" => {
            let mut chords = Vec::new();
            let mut cursor = first_child.walk();
            
            for child in first_child.children(&mut cursor) {
                if child.kind() == "chord" {
                    chords.push(parse_chord_node(&child, input)?);
                }
            }
            
            if chords.is_empty() {
                return Err(anyhow!("No chords found in chord progression"));
            }
            
            Ok(ASTRoot::ChordProgression(chords))
        }
        _ => Err(anyhow!("Unexpected node type: {}", first_child.kind())),
    }
}

/// Parse a single chord node from the CST
#[cfg(feature = "tree-sitter")]
fn parse_chord_node(chord_node: &tree_sitter::Node, source: &str) -> Result<ASTChord> {
    if chord_node.kind() != "chord" {
        return Err(anyhow!("Expected chord node, got: {}", chord_node.kind()));
    }
    
    // Extract root note
    let root_node = chord_node
        .child_by_field_name("root")
        .or_else(|| chord_node.child(0))
        .ok_or_else(|| anyhow!("No root node found"))?;
    
    let note_node = root_node.child_by_field_name("note")
        .or_else(|| root_node.child(0))
        .ok_or_else(|| anyhow!("No note found in root"))?;
    
    let note = note_node.utf8_text(source.as_bytes())
        .map_err(|e| anyhow!("Failed to extract note text: {}", e))?
        .to_string();
    
    let accidental = if let Some(acc_node) = root_node.child_by_field_name("accidental")
        .or_else(|| root_node.child(1))
    {
        let acc_text = acc_node.utf8_text(source.as_bytes())
            .map_err(|e| anyhow!("Failed to extract accidental text: {}", e))?;
        match acc_text {
            "#" => Some(Accidental::Sharp),
            "b" => Some(Accidental::Flat),
            _ => None,
        }
    } else {
        None
    };
    
    // Extract quality (optional)
    let mut quality_node_opt = chord_node.child_by_field_name("quality");
    if quality_node_opt.is_none() {
        // Fallback: search all children for a quality node
        let mut cursor = chord_node.walk();
        for child in chord_node.children(&mut cursor) {
            if child.kind() == "quality" {
                quality_node_opt = Some(child);
                break;
            }
        }
    }

    let quality = if let Some(quality_node) = quality_node_opt {
        let quality_text = quality_node.utf8_text(source.as_bytes())
            .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;

        parse_quality_text(quality_text)?
    } else {
        // Default to major when no explicit quality is present
        ChordQuality::Major
    };
    
    // Extract bass (optional) 
    let bass = if let Some(bass_node) = chord_node.child_by_field_name("bass") {
        let bass_text = bass_node.utf8_text(source.as_bytes())
            .map_err(|e| anyhow!("Failed to extract bass text: {}", e))?;
        Some(bass_text.trim_start_matches('/').to_string())
    } else {
        None
    };
    
    Ok(ASTChord {
        root: note,
        accidental,
        quality,
        bass,
    })
}

/// Parse chord quality text into ChordQuality enum
#[cfg(feature = "tree-sitter")]
fn parse_quality_text(quality_text: &str) -> Result<ChordQuality> {
    parse_chord_quality(quality_text)
}

#[cfg(test)]
mod tests {
    use super::*;

    // Tests for manual parser (without tree-sitter feature)
    #[cfg(not(feature = "tree-sitter"))]
    mod manual_parser_tests {
        use super::*;

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
        fn test_parse_lowercase_root_fails() {
            let result = parse_to_ast("c");
            assert!(result.is_err());
            assert!(result.unwrap_err().to_string().contains("uppercase"));
        }

        #[test]
        fn test_parse_invalid_root_note() {
            let result = parse_to_ast("H");
            assert!(result.is_err());
        }

        #[test]
        fn test_parse_empty_bass_note_fails() {
            let result = parse_to_ast("C/");
            assert!(result.is_err());
            assert!(result.unwrap_err().to_string().contains("Empty bass note"));
        }

        #[test]
        fn test_parse_invalid_bass_note_fails() {
            let result = parse_to_ast("C/xyz");
            assert!(result.is_err());
        }

        #[test]
        fn test_parse_unknown_quality_fails() {
            let result = parse_to_ast("Cxyz");
            assert!(result.is_err());
            assert!(result.unwrap_err().to_string().contains("Unknown chord quality"));
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
}
