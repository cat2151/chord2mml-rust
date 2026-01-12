//! MML (Music Macro Language) conversion
//!
//! This module handles the conversion from AST to MML format.

use anyhow::{anyhow, Result};
use crate::ast::{ASTChord, ASTRoot, ChordQuality};
use crate::note::{note_to_mml, transpose_note};

/// Convert AST to MML notes
pub fn ast_to_mml(ast: &ASTRoot) -> Result<String> {
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
pub fn chord_to_mml(chord: &ASTChord) -> Result<String> {
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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::{ASTChord, ChordQuality};

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
}
