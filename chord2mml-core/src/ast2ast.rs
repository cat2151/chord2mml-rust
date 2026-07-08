//! AST-to-AST pass (port of chord2mml_ast2ast.ts).
//!
//! Resolves stateful events (slash-chord mode, bass-play mode) and stamps
//! each chord's note length from bar positions. Bass-play mode and bar
//! handling arrive in later waves.

use crate::ast::{Event, SlashChordEvent, SlashChordMode};

pub(crate) fn ast_to_ast(events: Vec<Event>) -> Vec<Event> {
    let mut slash_mode = SlashChordMode::ChordOverBassNote;
    let mut bass_play_mode = "no bass".to_string();

    let mut result: Vec<Event> = Vec::with_capacity(events.len());
    for event in events {
        match event {
            Event::ChangeSlashChordMode(mode) => slash_mode = mode,
            Event::SlashChord(slash) => result.push(match slash_mode {
                SlashChordMode::ChordOverBassNote => Event::ChordOverBassNote(slash),
                SlashChordMode::Inversion => Event::Inversion(slash),
                SlashChordMode::Polychord => Event::Polychord(slash),
            }),
            // Bass-play mode is state here AND in ast2notes (JS keeps the
            // event in the list for both passes), so pass it through
            Event::ChangeBassPlayMode(mode) => {
                bass_play_mode = mode.clone();
                result.push(Event::ChangeBassPlayMode(mode));
            }
            // JS astToAst: in bass-play-mode "root", a plain chord becomes
            // chord-over-bass-note with upper = lower = the chord itself
            Event::Chord(chord) if bass_play_mode == "root" => {
                result.push(Event::ChordOverBassNote(SlashChordEvent {
                    upper_root: chord.root,
                    upper_quality: chord.quality.clone(),
                    upper_inversion: chord.inversion.clone(),
                    lower_root: chord.root,
                    lower_quality: chord.quality,
                    lower_inversion: chord.inversion,
                    upper_octave_offset: chord.octave_offset,
                    lower_octave_offset: chord.octave_offset,
                    note_length: None,
                }));
            }
            other => result.push(other),
        }
    }

    bar_to_note_length(&mut result);
    result
}

/// Port of bar2noteLength: chords start as whole notes (1). Each bar (`|`)
/// divides the whole note among its chords (4 chords → quarter notes);
/// a bar slash (`/ `) halves the bar, so each side's chords divide a half
/// note. Without any bar events, every chord keeps note length 1.
fn bar_to_note_length(events: &mut [Event]) {
    let mut bar_count = 0;
    let mut total_note_length: u32 = 1;
    let mut chord_indexes: Vec<usize> = Vec::new();

    for i in 0..events.len() {
        match &events[i] {
            Event::Chord(_)
            | Event::ChordOverBassNote(_)
            | Event::Inversion(_)
            | Event::Polychord(_)
            | Event::SlashChord(_) => {
                set_note_length(&mut events[i], 1);
                chord_indexes.push(i);
            }
            Event::Bar => {
                bar_count += 1;
                update_note_lengths(events, &chord_indexes, total_note_length);
                chord_indexes.clear();
                total_note_length = 1; // whole note
            }
            Event::BarSlash => {
                bar_count += 1; // also counts when there is no plain bar
                total_note_length = 2; // each half of the bar is a half note
                update_note_lengths(events, &chord_indexes, total_note_length);
                chord_indexes.clear();
            }
            _ => {}
        }
    }

    // Trailing chords (no bar line after them)
    if bar_count > 0 {
        update_note_lengths(events, &chord_indexes, total_note_length);
    }
}

/// Port of updateAstNoteLength: e.g. 4 chords in a bar → note length 4
/// (quarter notes); 2 chords in a half bar (total 2) also → 4.
fn update_note_lengths(events: &mut [Event], chord_indexes: &[usize], total_note_length: u32) {
    let note_length = chord_indexes.len() as u32 * total_note_length;
    for &i in chord_indexes {
        set_note_length(&mut events[i], note_length);
    }
}

fn set_note_length(event: &mut Event, note_length: u32) {
    match event {
        Event::Chord(chord) => chord.note_length = Some(note_length),
        Event::ChordOverBassNote(slash)
        | Event::Inversion(slash)
        | Event::Polychord(slash)
        | Event::SlashChord(slash) => slash.note_length = Some(note_length),
        _ => {}
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::{ChordEvent, SlashChordEvent};

    fn slash() -> SlashChordEvent {
        SlashChordEvent {
            upper_root: 5,
            upper_quality: "maj".to_string(),
            upper_inversion: None,
            lower_root: 0,
            lower_quality: "maj".to_string(),
            lower_inversion: None,
            upper_octave_offset: 0,
            lower_octave_offset: 0,
            note_length: None,
        }
    }

    #[test]
    fn test_chord_gets_whole_note_length() {
        let events = vec![Event::Chord(ChordEvent {
            root: 0,
            quality: "maj".to_string(),
            inversion: None,
            octave_offset: 0,
            note_length: None,
        })];
        let result = ast_to_ast(events);
        match &result[0] {
            Event::Chord(c) => assert_eq!(c.note_length, Some(1)),
            _ => panic!("Expected Chord"),
        }
    }

    #[test]
    fn test_slash_chord_default_mode() {
        let result = ast_to_ast(vec![Event::SlashChord(slash())]);
        match &result[0] {
            Event::ChordOverBassNote(s) => assert_eq!(s.note_length, Some(1)),
            _ => panic!("Expected ChordOverBassNote"),
        }
    }

    #[test]
    fn test_slash_chord_mode_switching() {
        let result = ast_to_ast(vec![
            Event::ChangeSlashChordMode(SlashChordMode::Polychord),
            Event::SlashChord(slash()),
            Event::ChangeSlashChordMode(SlashChordMode::Inversion),
            Event::SlashChord(slash()),
            Event::ChangeSlashChordMode(SlashChordMode::ChordOverBassNote),
            Event::SlashChord(slash()),
        ]);
        assert!(matches!(result[0], Event::Polychord(_)));
        assert!(matches!(result[1], Event::Inversion(_)));
        assert!(matches!(result[2], Event::ChordOverBassNote(_)));
        // mode-change events are consumed
        assert_eq!(result.len(), 3);
    }
}
