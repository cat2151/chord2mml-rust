//! AST to concrete notes (port of chord2mml_ast2notes.ts).
//!
//! Converts each chord event into an array of semitone note offsets.
//! The quality→interval table and the note-stacking / inversion rules are
//! ported verbatim from the JS version; open-harmony (drop2 etc.) and
//! bass-play modes arrive in later waves (their hook points are kept).

use anyhow::{anyhow, Result};

use crate::ast::{Event, NotesEvent, OutEvent};

pub(crate) fn ast_to_notes(events: Vec<Event>) -> Result<Vec<OutEvent>> {
    let mut result = Vec::new();
    // JS state: inversionMode / openHarmonyMode / bassPlayMode /
    // octaveOffsetUpper / octaveOffsetLower
    let mut inversion_mode = "root inv".to_string();
    let mut open_harmony_mode = "close".to_string();
    let mut bass_play_mode = "no bass".to_string();
    let mut octave_offset_upper = 0;
    let mut octave_offset_lower = 0;

    for event in events {
        match event {
            Event::Chord(chord) => {
                let inversion = chord.inversion.as_deref().unwrap_or(&inversion_mode);
                let notes = get_notes_by_chord(
                    chord.root,
                    &chord.quality,
                    inversion,
                    &open_harmony_mode,
                    octave_offset_upper + chord.octave_offset,
                )?;
                result.push(OutEvent::Notes(NotesEvent {
                    notes,
                    note_length: chord.note_length,
                }));
            }
            Event::ChordOverBassNote(slash) => {
                let inversion = slash.upper_inversion.as_deref().unwrap_or(&inversion_mode);
                let notes = get_notes_by_chord_over_bass_note(
                    slash.upper_root,
                    &slash.upper_quality,
                    slash.lower_root,
                    inversion,
                    &open_harmony_mode,
                    octave_offset_upper + slash.upper_octave_offset,
                    octave_offset_lower + slash.lower_octave_offset,
                )?;
                result.push(OutEvent::Notes(NotesEvent {
                    notes,
                    note_length: slash.note_length,
                }));
            }
            Event::Inversion(slash) => {
                let notes = get_notes_by_inversion_chord(
                    slash.upper_root,
                    &slash.upper_quality,
                    slash.lower_root,
                    &bass_play_mode,
                    octave_offset_upper + slash.upper_octave_offset,
                )?;
                result.push(OutEvent::Notes(NotesEvent {
                    notes,
                    note_length: slash.note_length,
                }));
            }
            Event::Polychord(slash) => {
                let upper_inversion = slash.upper_inversion.as_deref().unwrap_or(&inversion_mode);
                let lower_inversion = slash.lower_inversion.as_deref().unwrap_or(&inversion_mode);
                let notes = get_notes_by_polychord(
                    slash.upper_root,
                    &slash.upper_quality,
                    upper_inversion,
                    slash.lower_root,
                    &slash.lower_quality,
                    lower_inversion,
                    octave_offset_upper + slash.upper_octave_offset,
                    octave_offset_lower + slash.lower_octave_offset,
                )?;
                result.push(OutEvent::Notes(NotesEvent {
                    notes,
                    note_length: slash.note_length,
                }));
            }
            Event::Bar => result.push(OutEvent::Bar),
            // Bar slashes were consumed by ast2ast's note-length pass
            Event::BarSlash => {}
            Event::Key { offset } => result.push(OutEvent::Key { offset }),
            Event::Scale { offsets } => result.push(OutEvent::Scale { offsets }),
            Event::InlineMml(mml) => result.push(OutEvent::InlineMml(mml)),
            Event::ChangeInversionMode(mode) => inversion_mode = mode,
            Event::ChangeOpenHarmonyMode(mode) => open_harmony_mode = mode,
            Event::ChangeBassPlayMode(mode) => bass_play_mode = mode,
            Event::OctaveShift {
                upper_delta,
                lower_delta,
            } => {
                octave_offset_upper += upper_delta;
                octave_offset_lower += lower_delta;
            }
            Event::ChangeSlashChordMode(_) => {
                return Err(anyhow!(
                    "ChangeSlashChordMode must be consumed by ast2ast before ast2notes"
                ));
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

/// Port of getNotesByChord.
fn get_notes_by_chord(
    root: i32,
    quality: &str,
    inversion_mode: &str,
    open_harmony_mode: &str,
    octave_offset: i32,
) -> Result<Vec<i32>> {
    let mut notes = get_notes_without_omit(root, quality)?;
    notes = inversion_and_open_harmony(notes, inversion_mode, open_harmony_mode);
    key_shift_notes(&mut notes, octave_offset * 12);
    apply_omit(&mut notes, quality, root);
    Ok(notes)
}

/// Port of getNotesByChordOverBassNote: the bass a note below, the upper
/// chord (inverted per the mode) stacked strictly above it, and the whole
/// voicing shifted down an octave.
fn get_notes_by_chord_over_bass_note(
    upper_root: i32,
    upper_quality: &str,
    lower_root: i32,
    inversion_mode: &str,
    open_harmony_mode: &str,
    octave_offset_upper: i32,
    octave_offset_lower: i32,
) -> Result<Vec<i32>> {
    let lower_notes = vec![lower_root];

    let mut upper_notes = get_notes_without_omit(upper_root, upper_quality)?;
    upper_notes = inversion_and_open_harmony(upper_notes, inversion_mode, open_harmony_mode);
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

/// Port of getNotesByInversionChord (slash-chord-inversion mode): invert
/// the chord so the lower note becomes the bass. In bass-play-mode "root",
/// the chord root is also played as a bass note below the inversion.
fn get_notes_by_inversion_chord(
    upper_root: i32,
    upper_quality: &str,
    lower_root: i32,
    bass_play_mode: &str,
    octave_offset: i32,
) -> Result<Vec<i32>> {
    if bass_play_mode == "root" {
        // The upper root serves as the bass note
        let lower_notes = vec![upper_root];

        let upper_notes = get_notes_without_omit(upper_root, upper_quality)?;
        let mut upper_notes = inversion_by_target_note(upper_notes, lower_root)?;
        apply_omit(&mut upper_notes, upper_quality, upper_root);

        // Non-slash chord in bass-is-root: the octave offset applies to
        // upper and lower alike (JS comment in getNotesByInversionChord)
        let mut notes =
            concat_lower_and_upper(upper_notes, octave_offset, lower_notes, octave_offset)?;

        // Shift the register down to make room for the bass note
        key_shift_notes(&mut notes, -12);

        Ok(notes)
    } else {
        let mut notes = get_notes_without_omit(upper_root, upper_quality)?;
        key_shift_notes(&mut notes, octave_offset * 12);
        let mut notes = inversion_by_target_note(notes, lower_root)?;
        apply_omit(&mut notes, upper_quality, upper_root);
        Ok(notes)
    }
}

/// Port of getNotesByPolychord: two full chords stacked, the lower
/// structure shifted down an octave.
#[allow(clippy::too_many_arguments)]
fn get_notes_by_polychord(
    upper_root: i32,
    upper_quality: &str,
    upper_inversion: &str,
    lower_root: i32,
    lower_quality: &str,
    lower_inversion: &str,
    octave_offset_upper: i32,
    octave_offset_lower: i32,
) -> Result<Vec<i32>> {
    let mut upper_notes = get_notes_without_omit(upper_root, upper_quality)?;
    let mut lower_notes = get_notes_without_omit(lower_root, lower_quality)?;

    upper_notes = inversion_and_open_harmony(upper_notes, upper_inversion, "");
    lower_notes = inversion_and_open_harmony(lower_notes, lower_inversion, "");

    key_shift_upper_notes(&mut upper_notes, &lower_notes);
    apply_omit(&mut upper_notes, upper_quality, upper_root);
    apply_omit(&mut lower_notes, lower_quality, lower_root);

    let mut notes = concat_lower_and_upper(
        upper_notes,
        octave_offset_upper,
        lower_notes,
        octave_offset_lower,
    )?;

    // Shift the register down to make room for the lower structure
    key_shift_notes(&mut notes, -12);

    Ok(notes)
}

/// Port of inversionAndOpenHarmony.
fn inversion_and_open_harmony(
    notes: Vec<i32>,
    inversion_mode: &str,
    open_harmony_mode: &str,
) -> Vec<i32> {
    let notes = match inversion_mode {
        "1st inv" => inversion_by_count(notes, 1),
        "2nd inv" => inversion_by_count(notes, 2),
        "3rd inv" => inversion_by_count(notes, 3),
        _ => notes,
    };

    match open_harmony_mode {
        "drop2" => drop2(notes),
        "drop4" => drop4(notes),
        "drop2and4" => drop2and4(notes),
        _ => notes,
    }
}

/// Port of drop2: move the second-highest voice down an octave to the front.
fn drop2(mut notes: Vec<i32>) -> Vec<i32> {
    if notes.len() < 2 {
        return notes;
    }
    let idx = notes.len() - 2;
    let second_last = notes[idx] - 12;
    notes.remove(idx);
    notes.insert(0, second_last);
    notes
}

/// Port of drop4: move the fourth-highest voice down an octave to the front.
fn drop4(mut notes: Vec<i32>) -> Vec<i32> {
    if notes.len() < 4 {
        return notes;
    }
    let idx = notes.len() - 4;
    let fourth_last = notes[idx] - 12;
    notes.remove(idx);
    notes.insert(0, fourth_last);
    notes
}

/// Port of drop2and4 (index arithmetic follows the JS splices exactly:
/// the second removal index is computed after the first removal).
fn drop2and4(mut notes: Vec<i32>) -> Vec<i32> {
    if notes.len() < 4 {
        return notes;
    }
    let second_last = notes[notes.len() - 2] - 12;
    let fourth_last = notes[notes.len() - 4] - 12;
    let idx2 = notes.len() - 2;
    notes.remove(idx2);
    let idx4 = notes.len() + 1 - 4; // after the drop2 removal, so +1
    notes.remove(idx4);
    notes.insert(0, second_last);
    notes.insert(0, fourth_last);
    notes
}

/// Port of inversionByCount: rotate the chord and lift wrapped notes.
fn inversion_by_count(mut notes: Vec<i32>, count: usize) -> Vec<i32> {
    for _ in 0..count {
        if !notes.is_empty() {
            let first = notes.remove(0);
            notes.push(first);
        }
    }
    adjust_notes_octave(&mut notes);
    notes
}

/// Port of inversionByTargetNote: rotate until the target pitch class is
/// the lowest note; errors if the chord does not contain it.
fn inversion_by_target_note(mut notes: Vec<i32>, target_note: i32) -> Result<Vec<i32>> {
    let target_class = target_note.rem_euclid(12);
    for _ in 0..notes.len() {
        if notes[0].rem_euclid(12) == target_class {
            adjust_notes_octave(&mut notes);
            return Ok(notes);
        }
        let first = notes.remove(0);
        notes.push(first);
    }
    Err(anyhow!(
        "Cannot invert {:?}: the chord does not contain {:?}. Specify a note contained in the chord.",
        notes,
        target_note
    ))
}

/// Port of adjustNotesOctave: raise any note that is not higher than the
/// previous one by octaves (bounded like the JS loop).
fn adjust_notes_octave(notes: &mut [i32]) {
    let mut old_note = -128;
    for note in notes.iter_mut() {
        let mut guard = -128;
        while *note <= old_note && guard < 128 {
            *note += 12;
            guard += 12;
        }
        old_note = *note;
    }
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
    use crate::ast::{ChordEvent, SlashChordEvent};

    fn notes_of(out: &OutEvent) -> Vec<i32> {
        match out {
            OutEvent::Notes(n) => n.notes.clone(),
            other => panic!("Expected Notes, got {:?}", other),
        }
    }

    fn chord(root: i32, quality: &str) -> Event {
        Event::Chord(ChordEvent {
            root,
            quality: quality.to_string(),
            inversion: None,
            octave_offset: 0,
            note_length: Some(1),
        })
    }

    fn slash(
        upper_root: i32,
        upper_quality: &str,
        lower_root: i32,
        lower_quality: &str,
    ) -> SlashChordEvent {
        SlashChordEvent {
            upper_root,
            upper_quality: upper_quality.to_string(),
            upper_inversion: None,
            lower_root,
            lower_quality: lower_quality.to_string(),
            lower_inversion: None,
            upper_octave_offset: 0,
            lower_octave_offset: 0,
            note_length: Some(1),
        }
    }

    // Expected values from the JS test suite (ast2notes block)
    #[test]
    fn test_c_major_notes() {
        let result = ast_to_notes(vec![chord(0, "maj")]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![0, 4, 7]);
    }

    #[test]
    fn test_d_major_notes() {
        let result = ast_to_notes(vec![chord(2, "maj")]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![2, 6, 9]);
    }

    #[test]
    fn test_c_major7_notes() {
        let result = ast_to_notes(vec![chord(0, "maj7")]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![0, 4, 7, 11]);
    }

    #[test]
    fn test_g_major_notes() {
        let result = ast_to_notes(vec![chord(7, "maj")]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![7, 11, 14]);
    }

    #[test]
    fn test_chord_over_bass_note() {
        // JS: F/C → [-12+0, -12+5, -12+9, -12+12]
        let result =
            ast_to_notes(vec![Event::ChordOverBassNote(slash(5, "maj", 0, "maj"))]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![-12, -7, -3, 0]);
    }

    #[test]
    fn test_inversion_chord() {
        // JS: inversion C/G → [7, 12, 16]
        let result = ast_to_notes(vec![Event::Inversion(slash(0, "maj", 7, "maj"))]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![7, 12, 16]);
    }

    #[test]
    fn test_inversion_chord_target_missing_fails() {
        // JS: slash chord inversion C/D throws (D not in the C major triad)
        let result = ast_to_notes(vec![Event::Inversion(slash(0, "maj", 2, "maj"))]);
        assert!(result.is_err());
    }

    #[test]
    fn test_polychord() {
        // JS: polychord D/C → [0-12, 4-12, 7-12, 14-12, 18-12, 21-12]
        let result = ast_to_notes(vec![Event::Polychord(slash(2, "maj", 0, "maj"))]).unwrap();
        assert_eq!(*notes_of(&result[0]), vec![-12, -8, -5, 2, 6, 9]);
    }

    #[test]
    fn test_inversion_mode() {
        // JS: 1st inv C → [4, 7, 12]
        let result = ast_to_notes(vec![
            Event::ChangeInversionMode("1st inv".to_string()),
            chord(0, "maj"),
        ])
        .unwrap();
        assert_eq!(result.len(), 1);
        assert_eq!(*notes_of(&result[0]), vec![4, 7, 12]);
    }

    #[test]
    fn test_caret_inversion_overrides_mode() {
        // ^0 cancels the current inversion mode
        let result = ast_to_notes(vec![
            Event::ChangeInversionMode("1st inv".to_string()),
            Event::Chord(ChordEvent {
                root: 0,
                quality: "maj".to_string(),
                inversion: Some("root inv".to_string()),
                octave_offset: 0,
                note_length: Some(1),
            }),
        ])
        .unwrap();
        assert_eq!(*notes_of(&result[0]), vec![0, 4, 7]);
    }

    #[test]
    fn test_unknown_quality_fails() {
        assert!(ast_to_notes(vec![chord(0, "xyz")]).is_err());
    }
}
