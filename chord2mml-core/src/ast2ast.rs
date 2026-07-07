//! AST-to-AST pass (port of chord2mml_ast2ast.ts).
//!
//! Resolves stateful events (slash-chord mode, bass-play mode) and stamps
//! each chord's note length from bar positions. Phase 1 implements the
//! default slash mode ("chord over bass note") and the no-bar case
//! (every chord gets note length 1, a whole note); bar handling arrives
//! with the bar events in a later wave.

use crate::ast::Event;

pub(crate) fn ast_to_ast(events: Vec<Event>) -> Vec<Event> {
    let mut result: Vec<Event> = events
        .into_iter()
        .map(|event| match event {
            // Default slash-chord mode is "chord over bass note";
            // mode-change events will switch this in a later wave.
            Event::SlashChord(slash) => Event::ChordOverBassNote(slash),
            other => other,
        })
        .collect();

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
            Event::ChordOverBassNote(slash) => slash.note_length = Some(1),
            Event::SlashChord(slash) => slash.note_length = Some(1),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::{ChordEvent, SlashChordEvent};

    #[test]
    fn test_chord_gets_whole_note_length() {
        let events = vec![Event::Chord(ChordEvent {
            root: 0,
            quality: "maj".to_string(),
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
    fn test_slash_chord_resolves_to_chord_over_bass_note() {
        let events = vec![Event::SlashChord(SlashChordEvent {
            upper_root: 5,
            upper_quality: "maj".to_string(),
            lower_root: 0,
            lower_quality: "maj".to_string(),
            upper_octave_offset: 0,
            lower_octave_offset: 0,
            note_length: None,
        })];
        let result = ast_to_ast(events);
        match &result[0] {
            Event::ChordOverBassNote(s) => {
                assert_eq!(s.upper_root, 5);
                assert_eq!(s.note_length, Some(1));
            }
            _ => panic!("Expected ChordOverBassNote"),
        }
    }
}
