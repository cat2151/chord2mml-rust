//! Notes to MML text (port of chord2mml_notes2mml.ts).
//!
//! Output format is compatible with the original JS chord2mml, consumed by
//! obsidian-plugin-mmlabc: leading `v11` volume, each chord wrapped in
//! `'...'`, lowercase note names, sharp `+` / flat `-`, `<` / `>` for
//! relative octave movement, the note-length digit after the first note of
//! each chord, and `/*|*/` for bar lines. Sharp-vs-flat spelling is chosen
//! by the current key + scale (JS isSharpByKeyAndScale); the default is
//! C major, which spells sharps.

use anyhow::{anyhow, Result};

use crate::ast::OutEvent;

const SHARP_NAMES: [&str; 12] = [
    "c", "c+", "d", "d+", "e", "f", "f+", "g", "g+", "a", "a+", "b",
];
const FLAT_NAMES: [&str; 12] = [
    "c", "d-", "d", "e-", "e", "f", "g-", "g", "a-", "a", "b-", "b",
];

const IONIAN: [i32; 7] = [0, 2, 4, 5, 7, 9, 11];

pub(crate) fn notes_to_mml(events: &[OutEvent]) -> Result<String> {
    let twelve_ionians = create_12_ionians();
    // 和音なのでv16では大きすぎることがある想定（JS版のコメントを踏襲）
    let mut mml = String::from("v11");

    let mut key_offset = 0;
    let mut scale_offsets: Vec<i32> = IONIAN.to_vec();
    let mut is_sharp = is_sharp_by_key_and_scale(key_offset, &scale_offsets, &twelve_ionians)?;

    for event in events {
        let notes_event = match event {
            OutEvent::Bar => {
                mml.push_str("/*|*/");
                continue;
            }
            OutEvent::InlineMml(inline) => {
                mml.push_str(inline);
                continue;
            }
            OutEvent::Key { offset } => {
                key_offset = *offset;
                is_sharp =
                    is_sharp_by_key_and_scale(key_offset, &scale_offsets, &twelve_ionians)?;
                continue;
            }
            OutEvent::Scale { offsets } => {
                scale_offsets = offsets.clone();
                is_sharp =
                    is_sharp_by_key_and_scale(key_offset, &scale_offsets, &twelve_ionians)?;
                continue;
            }
            OutEvent::Notes(notes_event) => notes_event,
        };

        let notes = &notes_event.notes;
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
                if let Some(note_length) = notes_event.note_length {
                    mml.push_str(&note_length.to_string());
                }
            }
        }

        mml.push('\'');
    }

    Ok(mml)
}

/// Port of create12ionians: the twelve major scales as sorted pitch-class
/// sets.
fn create_12_ionians() -> Vec<Vec<i32>> {
    (0..12)
        .map(|i| {
            let mut ionian: Vec<i32> = IONIAN.iter().map(|x| (x + i) % 12).collect();
            ionian.sort_unstable();
            ionian
        })
        .collect()
}

/// Port of isSharpByKeyAndScale: find which major scale the key+scale
/// pitch-class set spells, then choose sharp or flat per that key
/// (C/D/E/G/A/B → sharps; Db/Eb/Gb/Ab/Bb/F → flats).
fn is_sharp_by_key_and_scale(
    key: i32,
    offsets: &[i32],
    twelve_ionians: &[Vec<i32>],
) -> Result<bool> {
    // JS uses plain % (a negative key would never match and throw, same here)
    let mut key_offsets: Vec<i32> = offsets.iter().map(|o| (o + key) % 12).collect();
    key_offsets.sort_unstable();

    let index = twelve_ionians
        .iter()
        .position(|ionian| ionian[..] == key_offsets[..])
        .ok_or_else(|| anyhow!("isSharpByKeyAndScale: no matching major scale"))?;

    Ok(matches!(index, 0 | 2 | 4 | 7 | 9 | 11))
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::NotesEvent;

    fn notes(notes: Vec<i32>) -> OutEvent {
        OutEvent::Notes(NotesEvent {
            notes,
            note_length: None,
        })
    }

    // Expected values from the JS test suite (notes2mml block)
    #[test]
    fn test_c_major() {
        assert_eq!(notes_to_mml(&[notes(vec![0, 4, 7])]).unwrap(), "v11'ceg'");
    }

    #[test]
    fn test_d_major() {
        assert_eq!(notes_to_mml(&[notes(vec![2, 6, 9])]).unwrap(), "v11'df+a'");
    }

    #[test]
    fn test_g_major_crosses_octave() {
        assert_eq!(
            notes_to_mml(&[notes(vec![7, 11, 14])]).unwrap(),
            "v11'gb<d'"
        );
    }

    #[test]
    fn test_b_major7() {
        assert_eq!(
            notes_to_mml(&[notes(vec![11, 15, 18, 22])]).unwrap(),
            "v11'b<d+f+a+'"
        );
    }

    #[test]
    fn test_note_length_after_first_note() {
        assert_eq!(
            notes_to_mml(&[OutEvent::Notes(NotesEvent {
                notes: vec![0, 4, 7],
                note_length: Some(1),
            })])
            .unwrap(),
            "v11'c1eg'"
        );
    }

    #[test]
    fn test_negative_bottom_note() {
        assert_eq!(
            notes_to_mml(&[notes(vec![-12, -7, -3, 0])]).unwrap(),
            "v11'>cfa<c'"
        );
    }

    #[test]
    fn test_chords_are_adjacent_without_spaces() {
        assert_eq!(
            notes_to_mml(&[notes(vec![0, 4, 7]), notes(vec![7, 11, 14])]).unwrap(),
            "v11'ceg''gb<d'"
        );
    }

    #[test]
    fn test_bar_marker() {
        assert_eq!(
            notes_to_mml(&[notes(vec![0, 4, 7]), OutEvent::Bar, notes(vec![0, 4, 7])])
                .unwrap(),
            "v11'ceg'/*|*/'ceg'"
        );
    }

    #[test]
    fn test_flat_key_spelling() {
        // key=F spells flats: Bb major triad → b- <d f
        assert_eq!(
            notes_to_mml(&[OutEvent::Key { offset: 5 }, notes(vec![10, 14, 17])]).unwrap(),
            "v11'b-<df'"
        );
    }

    #[test]
    fn test_phrygian_scale_spelling() {
        // C phrygian = the Ab major set → flats
        assert_eq!(
            notes_to_mml(&[
                OutEvent::Scale {
                    offsets: vec![0, 1, 3, 5, 7, 8, 10]
                },
                notes(vec![1, 5, 8])
            ])
            .unwrap(),
            "v11'd-fa-'"
        );
    }
}
