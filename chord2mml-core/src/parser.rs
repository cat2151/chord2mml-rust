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
                Some(bass_str.to_string())
            } else {
                None
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

/// Parse chord quality from string
#[cfg(not(feature = "tree-sitter"))]
fn parse_quality_manual(quality_str: &str) -> Result<ChordQuality> {
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
    match quality_text {
        "m" => Ok(ChordQuality::Minor),
        "maj7" | "M7" => Ok(ChordQuality::Major7),
        "7" => Ok(ChordQuality::Dominant7),
        "dim" => Ok(ChordQuality::Diminished),
        "aug" | "+" => Ok(ChordQuality::Augmented),
        "sus4" => Ok(ChordQuality::Sus4),
        "sus2" => Ok(ChordQuality::Sus2),
        _ => Err(anyhow!("Unknown chord quality: {}", quality_text)),
    }
}
