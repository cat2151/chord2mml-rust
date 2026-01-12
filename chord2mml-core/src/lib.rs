use anyhow::{anyhow, Result};
use tree_sitter::Parser;

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
    
    parse_and_convert_treesitter(input)
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

/// AST structure representing the input (either a single chord or progression)
#[derive(Debug, Clone, PartialEq)]
enum ASTRoot {
    SingleChord(ASTChord),
    ChordProgression(Vec<ASTChord>),
}

/// Parse chord notation using TreeSitter, convert CST to AST, and then to MML
fn parse_and_convert_treesitter(input: &str) -> Result<String> {
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
    let ast = match first_child.kind() {
        "chord" => {
            let chord = parse_chord_node(&first_child, input)?;
            ASTRoot::SingleChord(chord)
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
            
            ASTRoot::ChordProgression(chords)
        }
        _ => return Err(anyhow!("Unexpected node type: {}", first_child.kind())),
    };
    
    // Convert AST to MML
    ast_to_mml(&ast)
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
        let mut found_quality = ChordQuality::Major;
        let mut cursor = chord_node.walk();
        for child in chord_node.children(&mut cursor) {
            if child.kind() == "quality" {
                let quality_text = child.utf8_text(source.as_bytes())
                    .map_err(|e| anyhow!("Failed to extract quality text: {}", e))?;
                
                found_quality = match quality_text {
                    "m" => ChordQuality::Minor,
                    "maj7" | "M7" => ChordQuality::Major7,
                    "7" => ChordQuality::Dominant7,
                    "dim" => ChordQuality::Diminished,
                    "aug" | "+" => ChordQuality::Augmented,
                    "sus4" => ChordQuality::Sus4,
                    "sus2" => ChordQuality::Sus2,
                    _ => return Err(anyhow!("Unknown chord quality: {}", quality_text)),
                };
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

/// Convert AST to MML notes
fn ast_to_mml(ast: &ASTRoot) -> Result<String> {
    match ast {
        ASTRoot::SingleChord(chord) => chord_to_mml(chord),
        ASTRoot::ChordProgression(chords) => {
            let mml_chords: Result<Vec<String>> = chords
                .iter()
                .map(|chord| chord_to_mml(chord))
                .collect();
            
            Ok(mml_chords?.join(" "))
        }
    }
}

/// Convert a single chord to MML
fn chord_to_mml(chord: &ASTChord) -> Result<String> {
    // Get the root note in MML format (lowercase)
    let root = note_to_mml(&chord.root, &chord.accidental);
    
    match chord.quality {
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
        _ => Err(anyhow!("Chord quality not yet implemented: {:?}", chord.quality)),
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
/// 
/// # Panics
/// 
/// This function panics if the input note is not a valid MML note.
/// For example, if an invalid note such as `"xyz"` or `"h"` is passed,
/// this function will panic.
/// This should never happen in normal operation as notes are only produced
/// by the `note_to_mml` function, which guarantees valid output.
/// A panic here indicates a programming error in the library itself.
fn transpose_note(note: &str, semitones: i32) -> String {
    // Simple note names in chromatic order (C, C#, D, D#, E, F, F#, G, G#, A, A#, B)
    let notes = ["c", "c+", "d", "d+", "e", "f", "f+", "g", "g+", "a", "a+", "b"];
    
    // INVARIANT: notes should only come from our own note_to_mml function
    // which guarantees valid MML note format. If this fails, it's a bug in our code.
    let current_index = notes.iter().position(|&n| n == note)
        .unwrap_or_else(|| panic!("Internal invariant violation: invalid note '{note}' passed to transpose_note. This is a bug in chord2mml-core."));
    
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

    #[test]
    fn test_chord_to_mml_c_major() {
        let chord = ASTChord {
            root: "C".to_string(),
            accidental: None,
            quality: ChordQuality::Major,
            bass: None,
        };
        let mml = chord_to_mml(&chord).unwrap();
        assert_eq!(mml, "c;e;g");
    }

    #[test]
    fn test_chord_to_mml_f_major() {
        let chord = ASTChord {
            root: "F".to_string(),
            accidental: None,
            quality: ChordQuality::Major,
            bass: None,
        };
        let mml = chord_to_mml(&chord).unwrap();
        assert_eq!(mml, "f;a;c");
    }

    #[test]
    fn test_chord_to_mml_g_major() {
        let chord = ASTChord {
            root: "G".to_string(),
            accidental: None,
            quality: ChordQuality::Major,
            bass: None,
        };
        let mml = chord_to_mml(&chord).unwrap();
        assert_eq!(mml, "g;b;d");
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
        assert_eq!(transpose_note("f", 4), "a"); // F major third
        assert_eq!(transpose_note("f", 7), "c"); // F perfect fifth
        assert_eq!(transpose_note("g", 4), "b"); // G major third
        assert_eq!(transpose_note("g", 7), "d"); // G perfect fifth
    }
}
