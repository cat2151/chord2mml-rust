//! Abstract Syntax Tree (AST) data structures.
//!
//! Mirrors the event-array model of the original JS chord2mml
//! (`chord2mml_chord2ast.pegjs` output): the AST is a sequence of events,
//! roots are semitone offsets (C=0 .. B=11), and qualities are normalized
//! comma-joinable strings ("maj", "min", "maj7,add9", ...).

/// One event in the input sequence.
#[derive(Debug, Clone, PartialEq)]
pub enum Event {
    /// A plain chord (JS: `{event: "chord", ...}`)
    Chord(ChordEvent),
    /// A slash chord as parsed (JS: `{event: "slash chord", ...}`);
    /// resolved by `ast2ast` into the current slash-chord mode.
    SlashChord(SlashChordEvent),
    /// A slash chord resolved to chord-over-bass-note mode
    /// (JS: `{event: "chord over bass note", ...}`)
    ChordOverBassNote(SlashChordEvent),
}

/// A plain chord event.
#[derive(Debug, Clone, PartialEq)]
pub struct ChordEvent {
    /// Root as semitone offset. C=0, D=2, ... B=11, plus accidentals
    /// (not normalized mod 12, matching the JS grammar).
    pub root: i32,
    /// Normalized quality string, e.g. "maj", "min", "min7", "dim triad".
    pub quality: String,
    /// Per-chord octave offset (`'` up / `,` down in the JS grammar).
    pub octave_offset: i32,
    /// Note length digit (1=whole, 2=half, 4=quarter, ...); assigned by
    /// `ast2ast` from bar positions.
    pub note_length: Option<u32>,
}

/// A slash chord (upper chord over lower chord/bass).
#[derive(Debug, Clone, PartialEq)]
pub struct SlashChordEvent {
    pub upper_root: i32,
    pub upper_quality: String,
    pub lower_root: i32,
    pub lower_quality: String,
    pub upper_octave_offset: i32,
    pub lower_octave_offset: i32,
    pub note_length: Option<u32>,
}

/// A resolved chord as concrete notes (output of `ast2notes`).
/// Notes are absolute semitone offsets relative to the base octave;
/// values may exceed 0..11 (octave up) or go negative (octave down).
#[derive(Debug, Clone, PartialEq)]
pub struct NotesEvent {
    pub notes: Vec<i32>,
    pub note_length: Option<u32>,
}
