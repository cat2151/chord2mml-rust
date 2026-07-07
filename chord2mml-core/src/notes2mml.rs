//! Notes to MML text (port of chord2mml_notes2mml.ts).
//!
//! Output format is compatible with the original JS chord2mml, consumed by
//! obsidian-plugin-mmlabc: leading `v11` volume, each chord wrapped in
//! `'...'`, lowercase note names, sharp `+` / flat `-`, `<` / `>` for
//! relative octave movement, and the note-length digit after the first
//! note of each chord. Sharp-vs-flat spelling is chosen by key+scale;
//! until key/scale events arrive (later wave) the default is C major,
//! which spells sharps.

use crate::ast::NotesEvent;

const SHARP_NAMES: [&str; 12] = [
    "c", "c+", "d", "d+", "e", "f", "f+", "g", "g+", "a", "a+", "b",
];
const FLAT_NAMES: [&str; 12] = [
    "c", "d-", "d", "e-", "e", "f", "g-", "g", "a-", "a", "b-", "b",
];

pub(crate) fn notes_to_mml(note_events: &[NotesEvent]) -> String {
    // 和音なのでv16では大きすぎることがある想定（JS版のコメントを踏襲）
    let mut mml = String::from("v11");
    // Key/scale events (later wave) will switch this per the JS
    // isSharpByKeyAndScale table; default key C major spells sharps.
    let is_sharp = true;

    for event in note_events {
        let notes = &event.notes;
        if notes.is_empty() {
            continue;
        }

        let mut last_octave_offset = 0;
        mml.push('\'');

        // A bottom note below offset 0 starts in a lower octave (drop4 etc.)
        let mut bottom_note = notes[0];
        while bottom_note < 0 {
            bottom_note += 12;
            mml.push('>');
            last_octave_offset -= 1;
        }

        for (i, &note) in notes.iter().enumerate() {
            let octave_offset = note.div_euclid(12);
            while octave_offset > last_octave_offset {
                mml.push('<');
                last_octave_offset += 1;
            }

            let name_index = note.rem_euclid(12) as usize;
            mml.push_str(if is_sharp {
                SHARP_NAMES[name_index]
            } else {
                FLAT_NAMES[name_index]
            });

            if i == 0 {
                if let Some(note_length) = event.note_length {
                    mml.push_str(&note_length.to_string());
                }
            }
        }

        mml.push('\'');
    }

    mml
}

#[cfg(test)]
mod tests {
    use super::*;

    fn notes(notes: Vec<i32>) -> NotesEvent {
        NotesEvent {
            notes,
            note_length: None,
        }
    }

    // Expected values from the JS test suite (notes2mml block)
    #[test]
    fn test_c_major() {
        assert_eq!(notes_to_mml(&[notes(vec![0, 4, 7])]), "v11'ceg'");
    }

    #[test]
    fn test_d_major() {
        assert_eq!(notes_to_mml(&[notes(vec![2, 6, 9])]), "v11'df+a'");
    }

    #[test]
    fn test_g_major_crosses_octave() {
        assert_eq!(notes_to_mml(&[notes(vec![7, 11, 14])]), "v11'gb<d'");
    }

    #[test]
    fn test_b_major7() {
        assert_eq!(
            notes_to_mml(&[notes(vec![11, 15, 18, 22])]),
            "v11'b<d+f+a+'"
        );
    }

    #[test]
    fn test_note_length_after_first_note() {
        assert_eq!(
            notes_to_mml(&[NotesEvent {
                notes: vec![0, 4, 7],
                note_length: Some(1),
            }]),
            "v11'c1eg'"
        );
    }

    #[test]
    fn test_negative_bottom_note() {
        // F/C voicing: [-12, -7, -3, 0] → '>c1fa<c' without the length digit
        assert_eq!(
            notes_to_mml(&[notes(vec![-12, -7, -3, 0])]),
            "v11'>cfa<c'"
        );
    }

    #[test]
    fn test_chords_are_adjacent_without_spaces() {
        assert_eq!(
            notes_to_mml(&[notes(vec![0, 4, 7]), notes(vec![7, 11, 14])]),
            "v11'ceg''gb<d'"
        );
    }
}
