//! AST-to-AST pass (port of chord2mml_ast2ast.ts).
//!
//! Resolves stateful events (slash-chord mode, bass-play mode) and stamps
//! each chord's note length from bar positions. Bass-play mode and bar
//! handling arrive in later waves.

use crate::ast::{Event, SlashChordMode};

pub(crate) fn ast_to_ast(events: Vec<Event>) -> Vec<Event> {
    let mut slash_mode = SlashChordMode::ChordOverBassNote;

    let mut result: Vec<Event> = Vec::with_capacity(events.len());
    for event in events {
        match event {
            Event::ChangeSlashChordMode(mode) => slash_mode = mode,
            Event::SlashChord(slash) => result.push(match slash_mode {
                SlashChordMode::ChordOverBassNote => Event::ChordOverBassNote(slash),
                SlashChordMode::Inversion => Event::Inversion(slash),
                SlashChordMode::Polychord => Event::Polychord(slash),
            }),
            other => result.push(other),
        }
    }

    bar_to_note_length(&mut result);
    result
}

/// Port of bar2noteLength: chords start as whole notes (1); bar events
/// (later wave) divide each bar's length among its chords. Without bars,
/// every chord keeps note length 1, matching the JS behavior.
fn bar_to_note_length(events: &mut [Event]) {
    for event in events.iter_mut() {
        match event {
            Event::Chord(chord) => chord.note_length = Some(1),
            Event::ChordOverBassNote(slash)
            | Event::Inversion(slash)
            | Event::Polychord(slash)
            | Event::SlashChord(slash) => slash.note_length = Some(1),
            Event::ChangeSlashChordMode(_) | Event::ChangeInversionMode(_) => {}
        }
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
