use anyhow::{anyhow, Result};

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
    
    // Use pure Rust parser for all builds (native and WASM)
    parse_and_convert(chord)
}

/// AST structure representing a chord
#[derive(Debug, Clone, PartialEq)]
struct ASTChord {
    root: String,
    accidental: Option<Accidental>,
    quality: ChordQuality,
    bass: Option<String>,
}

#[derive(Debug, Clone, PartialEq)]
enum Accidental {
    Sharp,
    Flat,
}

#[derive(Debug, Clone, PartialEq)]
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

/// Parse chord notation using pure Rust parser, convert to AST, and then to MML
fn parse_and_convert(chord: &str) -> Result<String> {
    // Parse the chord string into an AST
    let ast = parse_chord(chord)?;
    
    // Convert AST to MML
    ast_to_mml(&ast)
}

/// Pure Rust parser for chord notation
fn parse_chord(chord: &str) -> Result<ASTChord> {
    let chars: Vec<char> = chord.chars().collect();
    let mut index = 0;
    
    if chars.is_empty() {
        return Err(anyhow!("Empty chord"));
    }
    
    // Parse root note (C, D, E, F, G, A, B)
    let root = chars[index];
    if !matches!(root, 'C' | 'D' | 'E' | 'F' | 'G' | 'A' | 'B') {
        return Err(anyhow!("Invalid root note: {}. Expected C, D, E, F, G, A, or B", root));
    }
    index += 1;
    
    // Parse accidental (# or b)
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
    
    // Parse quality (m, maj7, 7, dim, aug, sus4, sus2, etc.)
    let quality = if index < chars.len() {
        let remaining: String = chars[index..].iter().collect();
        
        // Check for multi-character qualities first
        if remaining.starts_with("maj7") || remaining.starts_with("M7") {
            index += if remaining.starts_with("maj7") { 4 } else { 2 };
            ChordQuality::Major7
        } else if remaining.starts_with("dim") {
            index += 3;
            ChordQuality::Diminished
        } else if remaining.starts_with("aug") || remaining.starts_with("+") {
            index += if remaining.starts_with("aug") { 3 } else { 1 };
            ChordQuality::Augmented
        } else if remaining.starts_with("sus4") {
            index += 4;
            ChordQuality::Sus4
        } else if remaining.starts_with("sus2") {
            index += 4;
            ChordQuality::Sus2
        } else if remaining.starts_with("7") {
            index += 1;
            ChordQuality::Dominant7
        } else if remaining.starts_with("m") {
            index += 1;
            ChordQuality::Minor
        } else {
            ChordQuality::Major
        }
    } else {
        ChordQuality::Major
    };
    
    // Parse bass note (optional, after /)
    let bass = if index < chars.len() && chars[index] == '/' {
        index += 1;
        if index < chars.len() {
            Some(chars[index..].iter().collect())
        } else {
            None
        }
    } else {
        None
    };
    
    Ok(ASTChord {
        root: root.to_string(),
        accidental,
        quality,
        bass,
    })
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert_c_major() {
        let result = convert("C").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[test]
    fn test_convert_d_minor() {
        let result = convert("Dm").unwrap();
        assert_eq!(result, "d;f;a");
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
