//! Note operations for MML conversion
//!
//! This module handles note conversions and transposition operations.

use crate::ast::Accidental;

/// Convert note name to MML format (lowercase with accidentals)
pub fn note_to_mml(note: &str, accidental: &Option<Accidental>) -> String {
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
pub fn transpose_note(note: &str, semitones: i32) -> String {
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
    use crate::ast::Accidental;

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
