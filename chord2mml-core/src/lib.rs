use anyhow::{anyhow, Result};

#[cfg(not(target_arch = "wasm32"))]
use tree_sitter::Parser;

/// Convert a chord notation to MML (Music Macro Language) format
/// 
/// # Example
/// ```
/// use chord2mml_core::convert;
/// 
/// let mml = convert("C").unwrap();
/// assert_eq!(mml, "c;e;g");
/// ```
pub fn convert(chord: &str) -> Result<String> {
    let chord = chord.trim();
    
    if chord.is_empty() {
        return Err(anyhow!(
            "Empty chord input. Please provide a chord notation (e.g., 'C', 'Dm', 'G7')."
        ));
    }
    
    // Validate input length to prevent potential issues
    if chord.len() > 100 {
        return Err(anyhow!(
            "Chord notation too long (max 100 characters)."
        ));
    }
    
    // Use TreeSitter for native builds, simple parser for WASM
    #[cfg(not(target_arch = "wasm32"))]
    {
        parse_and_convert_treesitter(chord)
    }
    
    #[cfg(target_arch = "wasm32")]
    {
        parse_and_convert_simple(chord)
    }
}

/// AST structure representing a chord (abstracted from CST)
#[derive(Debug, Clone, PartialEq)]
struct ASTChord {
    root: String,
    accidental: Option<Accidental>,
    quality: ChordQuality,
    bass: Option<String>,
}

#[derive(Debug, Clone, PartialEq)]
#[cfg_attr(target_arch = "wasm32", allow(dead_code))]
enum Accidental {
    Sharp,
    Flat,
}

#[derive(Debug, Clone, PartialEq)]
#[cfg_attr(target_arch = "wasm32", allow(dead_code))]
enum ChordQuality {
    Major,
    Minor,
    Diminished,
    Augmented,
    Dominant7,
    Major7,
    Sus4,
    Sus2,
}

/// Parse chord notation using TreeSitter, convert to AST, and then to MML
#[cfg(not(target_arch = "wasm32"))]
fn parse_and_convert_treesitter(chord: &str) -> Result<String> {
    let mut parser = Parser::new();
    parser
        .set_language(tree_sitter_chord::language())
        .map_err(|e| anyhow!("Failed to set TreeSitter language: {}", e))?;
    
    let tree = parser
        .parse(chord, None)
        .ok_or_else(|| anyhow!("Failed to parse chord notation"))?;
    
    let root_node = tree.root_node();
    
    // Check for parsing errors
    if root_node.has_error() {
        return Err(anyhow!("Syntax error in chord notation: {}", chord));
    }
    
    // Navigate to the chord node
    let chord_node = if root_node.kind() == "source_file" {
        root_node.child(0).ok_or_else(|| anyhow!("No chord found in parse tree"))?
    } else {
        root_node
    };
    
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
    
    let note = note_node.utf8_text(chord.as_bytes())
        .map_err(|e| anyhow!("Failed to extract note text: {}", e))?
        .to_string();
    
    let accidental = if let Some(acc_node) = root_node.child_by_field_name("accidental")
        .or_else(|| root_node.child(1))
    {
        let acc_text = acc_node.utf8_text(chord.as_bytes())
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
        let quality_text = quality_node.utf8_text(chord.as_bytes())
            .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;
        
        match quality_text {
            "m" => ChordQuality::Minor,
            "maj7" | "M7" => ChordQuality::Major7,
            "7" => ChordQuality::Dominant7,
            "dim" => ChordQuality::Diminished,
            "aug" | "+" => ChordQuality::Augmented,
            "sus4" => ChordQuality::Sus4,
            "sus2" => ChordQuality::Sus2,
            _ => return Err(anyhow!("Unknown chord quality: {}", quality_text)),
        }
    } else {
        // Check if there's a second child that's a quality
        if chord_node.child_count() > 1 {
            if let Some(second_child) = chord_node.child(1) {
                if second_child.kind() == "quality" {
                    let quality_text = second_child.utf8_text(chord.as_bytes())
                        .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;
                    
                    match quality_text {
                        "m" => ChordQuality::Minor,
                        "maj7" | "M7" => ChordQuality::Major7,
                        "7" => ChordQuality::Dominant7,
                        "dim" => ChordQuality::Diminished,
                        "aug" | "+" => ChordQuality::Augmented,
                        "sus4" => ChordQuality::Sus4,
                        "sus2" => ChordQuality::Sus2,
                        _ => return Err(anyhow!("Unknown chord quality: {}", quality_text)),
                    }
                } else {
                    ChordQuality::Major
                }
            } else {
                ChordQuality::Major
            }
        } else {
            ChordQuality::Major
        }
    };
    
    // Extract bass (optional) 
    let bass = if let Some(bass_node) = chord_node.child_by_field_name("bass") {
        let bass_text = bass_node.utf8_text(chord.as_bytes())
            .map_err(|e| anyhow!("Failed to extract bass text: {}", e))?;
        Some(bass_text.trim_start_matches('/').to_string())
    } else {
        None
    };
    
    // Create AST
    let ast = ASTChord {
        root: note,
        accidental,
        quality,
        bass,
    };
    
    // Convert AST to MML
    ast_to_mml(&ast)
}

/// Convert AST to MML notes
fn ast_to_mml(ast: &ASTChord) -> Result<String> {
    // Get the root note in MML format (lowercase)
    let root = note_to_mml(&ast.root, &ast.accidental);
    
    match ast.quality {
        ChordQuality::Major => {
            // Major chord: root, major third, perfect fifth
            let third = transpose_note(&root, 4); // Major third = 4 semitones
            let fifth = transpose_note(&root, 7); // Perfect fifth = 7 semitones
            Ok(format!("{};{};{}", root, third, fifth))
        }
        ChordQuality::Minor => {
            // Minor chord: root, minor third, perfect fifth
            let third = transpose_note(&root, 3); // Minor third = 3 semitones
            let fifth = transpose_note(&root, 7); // Perfect fifth = 7 semitones
            Ok(format!("{};{};{}", root, third, fifth))
        }
        _ => Err(anyhow!("Chord quality not yet implemented: {:?}", ast.quality)),
    }
}

/// Convert note name to MML format (lowercase with accidentals)
fn note_to_mml(note: &str, accidental: &Option<Accidental>) -> String {
    let mut mml = note.to_lowercase();
    if let Some(acc) = accidental {
        match acc {
            Accidental::Sharp => mml.push('+'),
            Accidental::Flat => mml.push('-'),
        }
    }
    mml
}

/// Transpose a note by semitones
fn transpose_note(note: &str, semitones: i32) -> String {
    // Simple note names in chromatic order (C, C#, D, D#, E, F, F#, G, G#, A, A#, B)
    let notes = ["c", "c+", "d", "d+", "e", "f", "f+", "g", "g+", "a", "a+", "b"];
    
    // Find the current note index - if not found, this is a programming error
    // as notes should only come from our own note_to_mml function
    let current_index = notes.iter().position(|&n| n == note)
        .unwrap_or_else(|| panic!("Internal error: invalid note '{}' passed to transpose_note", note));
    
    // Calculate new index with wrapping
    let new_index = ((current_index as i32 + semitones) % 12 + 12) % 12;
    
    notes[new_index as usize].to_string()
}

/// Simple parser for WASM builds (no TreeSitter dependency)
#[cfg(target_arch = "wasm32")]
fn parse_and_convert_simple(chord: &str) -> Result<String> {
    // Simple parser that only handles C major for now
    // This is sufficient for the minimal implementation requirement
    if chord == "C" {
        // Create AST directly
        let ast = ASTChord {
            root: "C".to_string(),
            accidental: None,
            quality: ChordQuality::Major,
            bass: None,
        };
        ast_to_mml(&ast)
    } else {
        Err(anyhow!("Unsupported chord: {}. Only 'C' is supported in WASM build.", chord))
    }
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
    fn test_convert_empty_input() {
        let result = convert("");
        assert!(result.is_err());
    }

    #[test]
    fn test_convert_whitespace_trimmed() {
        let result = convert("  C  ").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[test]
    fn test_ast_to_mml_c_major() {
        let ast = ASTChord {
            root: "C".to_string(),
            accidental: None,
            quality: ChordQuality::Major,
            bass: None,
        };
        let mml = ast_to_mml(&ast).unwrap();
        assert_eq!(mml, "c;e;g");
    }

    #[test]
    fn test_note_to_mml() {
        assert_eq!(note_to_mml("C", &None), "c");
        assert_eq!(note_to_mml("D", &Some(Accidental::Sharp)), "d+");
        assert_eq!(note_to_mml("E", &Some(Accidental::Flat)), "e-");
    }

    #[test]
    fn test_transpose_note() {
        assert_eq!(transpose_note("c", 0), "c");
        assert_eq!(transpose_note("c", 4), "e"); // Major third
        assert_eq!(transpose_note("c", 7), "g"); // Perfect fifth
    }
}
