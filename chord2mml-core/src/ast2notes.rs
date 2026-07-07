//! AST to concrete notes (port of chord2mml_ast2notes.ts).
//!
//! Converts each chord event into an array of semitone note offsets.
//! The quality→interval table and the note-stacking rules are ported
//! verbatim from the JS version; inversion / open-harmony / bass-play
//! modes arrive in later waves (their hook points are kept).

use anyhow::{anyhow, Result};

use crate::ast::{Event, NotesEvent};

pub(crate) fn ast_to_notes(events: Vec<Event>) -> Result<Vec<NotesEvent>> {
    let mut result = Vec::new();

    for event in events {
        match event {
            Event::Chord(chord) => {
                let notes = get_notes_by_chord(chord.root, &chord.quality, chord.octave_offset)?;
                result.push(NotesEvent {
                    notes,
                    note_length: chord.note_length,
                });
            }
            Event::ChordOverBassNote(slash) => {
                let notes = get_notes_by_chord_over_bass_note(
                    slash.upper_root,
                    &slash.upper_quality,
                    slash.lower_root,
                    slash.upper_octave_offset,
                    slash.lower_octave_offset,
                )?;
                result.push(NotesEvent {
                    notes,
                    note_length: slash.note_length,
                });
            }
            Event::SlashChord(_) => {
                return Err(anyhow!(
                    "SlashChord must be resolved by ast2ast before ast2notes"
                ));
            }
        }
    }

    Ok(result)
}

/// Port of getNotesByChord (inversion/open-harmony are no-ops until their wave).
fn get_notes_by_chord(root: i32, quality: &str, octave_offset: i32) -> Result<Vec<i32>> {
    let mut notes = get_notes_without_omit(root, quality)?;
    key_shift_notes(&mut notes, octave_offset * 12);
    apply_omit(&mut notes, quality, root);
    Ok(notes)
}

/// Port of getNotesByChordOverBassNote: the bass a note below, the upper
/// chord stacked strictly above it, and the whole voicing shifted down an
/// octave.
fn get_notes_by_chord_over_bass_note(
    upper_root: i32,
    upper_quality: &str,
    lower_root: i32,
    octave_offset_upper: i32,
    octave_offset_lower: i32,
) -> Result<Vec<i32>> {
    let lower_notes = vec![lower_root];

    let mut upper_notes = get_notes_without_omit(upper_root, upper_quality)?;
    key_shift_upper_notes(&mut upper_notes, &lower_notes);
    apply_omit(&mut upper_notes, upper_quality, upper_root);

    let mut notes = concat_lower_and_upper(
        upper_notes,
        octave_offset_upper,
        lower_notes,
        octave_offset_lower,
    )?;

    // Shift the register down to make room for the bass note
    key_shift_notes(&mut notes, -12);

    Ok(notes)
}

/// Port of getNotesWithoutOmit: base quality → intervals, then add /
/// altered-fifth modifiers, then shift to the root.
fn get_notes_without_omit(root: i32, quality: &str) -> Result<Vec<i32>> {
    let parts: Vec<&str> = quality.split(',').collect();

    let mut notes: Vec<i32> = match parts[0] {
        "maj" => vec![0, 4, 7],
        "maj7" => vec![0, 4, 7, 11],
        "min" => vec![0, 3, 7],
        "min7" => vec![0, 3, 7, 10],
        "sus2" => vec![0, 2, 7],
        "sus4" => vec![0, 5, 7],
        "7sus2" => vec![0, 2, 7, 10],
        "7sus4" => vec![0, 5, 7, 10],
        "dim triad" => vec![0, 3, 6],
        "aug" => vec![0, 4, 8],
        "6" => vec![0, 4, 7, 9],
        "7" => vec![0, 4, 7, 10],
        "9" => vec![0, 4, 7, 10, 14],
        "11" => vec![0, 4, 7, 10, 14, 17],
        "13" => vec![0, 4, 7, 10, 14, 17, 21],
        other => {
            // Quartal harmony: "4.N" stacks N notes in fourths.
            // Only the first digit counts (JS: parseInt(q[0][2])).
            if let Some(count) = other
                .strip_prefix("4.")
                .and_then(|n| n.chars().next())
                .and_then(|c| c.to_digit(10))
            {
                (0..count as i32).map(|i| i * 5).collect()
            } else {
                return Err(anyhow!("Unknown chord quality: {}", other));
            }
        }
    };

    for part in &parts {
        match *part {
            "add2" => add_note(&mut notes, 2),
            "add9" => add_note(&mut notes, 2 + 12),
            "add4" => add_note(&mut notes, 5),
            "add11" => add_note(&mut notes, 5 + 12),
            "add6" => add_note(&mut notes, 9),
            "add13" => add_note(&mut notes, 9 + 12),
            "flatted fifth" => notes.iter_mut().for_each(|n| {
                if *n == 7 {
                    *n = 6
                }
            }),
            "augmented fifth" => notes.iter_mut().for_each(|n| {
                if *n == 7 {
                    *n = 8
                }
            }),
            _ => {}
        }
    }

    key_shift_notes(&mut notes, root);
    Ok(notes)
}

/// Port of applyOmit: removes intervals named by omit modifiers.
fn apply_omit(notes: &mut Vec<i32>, quality: &str, root: i32) {
    for part in quality.split(',') {
        match part {
            "omit1" => omit_intervals(notes, root, &[0]),
            // Both the minor and major third
            "omit3" => omit_intervals(notes, root, &[3, 4]),
            "omit5" => omit_intervals(notes, root, &[7]),
            _ => {}
        }
    }
}

fn omit_intervals(notes: &mut Vec<i32>, root: i32, intervals: &[i32]) {
    notes.retain(|note| !intervals.contains(&(note - root).rem_euclid(12)));
}

fn add_note(notes: &mut Vec<i32>, n: i32) {
    if !notes.contains(&n) {
        notes.push(n);
        notes.sort_unstable();
    }
}

fn key_shift_notes(notes: &mut [i32], v: i32) {
    for note in notes.iter_mut() {
        *note += v;
    }
}

/// Port of keyShiftUpperNotes: raise the upper chord by octaves until it
/// sits strictly above the lower notes.
fn key_shift_upper_notes(upper_notes: &mut [i32], lower_notes: &[i32]) {
    if upper_notes.is_empty() || lower_notes.is_empty() {
        return;
    }
    let lower_top = *lower_notes.last().unwrap();
    while upper_notes[0] <= lower_top {
        key_shift_notes(upper_notes, 12);
    }
}

/// Port of concatLowerAndUpper: applies octave offsets, checks for
/// collision, and joins lower + upper.
fn concat_lower_and_upper(
    mut upper_notes: Vec<i32>,
    octave_offset_upper: i32,
    mut lower_notes: Vec<i32>,
    octave_offset_lower: i32,
) -> Result<Vec<i32>> {
    key_shift_notes(&mut lower_notes, octave_offset_lower * 12);
    key_shift_notes(&mut upper_notes, octave_offset_upper * 12);

    if !upper_notes.is_empty()
        && !lower_notes.is_empty()
        && upper_notes[0] <= *lower_notes.last().unwrap()
    {
        return Err(anyhow!(
            "Lower and upper collided: lower={:?} upper={:?}",
            lower_notes,
            upper_notes
        ));
    }

    let mut notes = lower_notes;
    notes.extend(upper_notes);
    Ok(notes)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::ChordEvent;

    fn chord(root: i32, quality: &str) -> Event {
        Event::Chord(ChordEvent {
            root,
            quality: quality.to_string(),
            octave_offset: 0,
            note_length: Some(1),
        })
    }

    // Expected values from the JS test suite (ast2notes block)
    #[test]
    fn test_c_major_notes() {
        let result = ast_to_notes(vec![chord(0, "maj")]).unwrap();
        assert_eq!(result[0].notes, vec![0, 4, 7]);
    }

    #[test]
    fn test_d_major_notes() {
        let result = ast_to_notes(vec![chord(2, "maj")]).unwrap();
        assert_eq!(result[0].notes, vec![2, 6, 9]);
    }

    #[test]
    fn test_c_major7_notes() {
        let result = ast_to_notes(vec![chord(0, "maj7")]).unwrap();
        assert_eq!(result[0].notes, vec![0, 4, 7, 11]);
    }

    #[test]
    fn test_g_major_notes() {
        let result = ast_to_notes(vec![chord(7, "maj")]).unwrap();
        assert_eq!(result[0].notes, vec![7, 11, 14]);
    }

    #[test]
    fn test_chord_over_bass_note() {
        // JS: F/C → [-12+0, -12+5, -12+9, -12+12]
        use crate::ast::SlashChordEvent;
        let result = ast_to_notes(vec![Event::ChordOverBassNote(SlashChordEvent {
            upper_root: 5,
            upper_quality: "maj".to_string(),
            lower_root: 0,
            lower_quality: "maj".to_string(),
            upper_octave_offset: 0,
            lower_octave_offset: 0,
            note_length: Some(1),
        })])
        .unwrap();
        assert_eq!(result[0].notes, vec![-12, -7, -3, 0]);
    }

    #[test]
    fn test_unknown_quality_fails() {
        assert!(ast_to_notes(vec![chord(0, "xyz")]).is_err());
    }
}
