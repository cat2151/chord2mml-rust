//! Parser module for converting chord notation to AST
//!
//! This module handles Tree-sitter parsing and conversion from CST to AST.

use anyhow::{anyhow, Result};
use tree_sitter::Parser;
use crate::ast::{ASTChord, ASTRoot, Accidental, ChordQuality};

/// Parse chord notation using TreeSitter, convert CST to AST
pub fn parse_to_ast(input: &str) -> Result<ASTRoot> {
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
    let quality = if let Some(quality_node) = chord_node.child_by_field_name("quality") {
        let quality_text = quality_node.utf8_text(source.as_bytes())
            .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;
        
        parse_quality_text(quality_text)?
    } else {
        // Check if there's a second child that's a quality
        let mut found_quality = ChordQuality::Major;
        let mut cursor = chord_node.walk();
        for child in chord_node.children(&mut cursor) {
            if child.kind() == "quality" {
                let quality_text = child.utf8_text(source.as_bytes())
                    .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;
                
                found_quality = parse_quality_text(quality_text)?;
                break;
            }
        }
        found_quality
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
