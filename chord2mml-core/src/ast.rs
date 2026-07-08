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
    /// A slash chord resolved to chord-over-bass-note mode, or an on-chord
    /// like `EonC` which is this directly (JS: `{event: "chord over bass note"}`)
    ChordOverBassNote(SlashChordEvent),
    /// A slash chord resolved to inversion mode (JS: `{event: "inversion"}`)
    Inversion(SlashChordEvent),
    /// A slash chord resolved to polychord mode (JS: `{event: "polychord"}`)
    Polychord(SlashChordEvent),
    /// JS: `{event: "change slash chord mode to ..."}`; consumed by ast2ast
    ChangeSlashChordMode(SlashChordMode),
    /// JS: `{event: "change inversion mode to ..."}`; the String is the
    /// inversion name ("root inv" | "1st inv" | "2nd inv" | "3rd inv");
    /// consumed by ast2notes
    ChangeInversionMode(String),
    /// JS: `{event: "change open harmony mode to ..."}`; the String is
    /// "close" | "drop2" | "drop4" | "drop2and4"; consumed by ast2notes
    ChangeOpenHarmonyMode(String),
    /// JS: `{event: "change bass play mode to ..."}`; the String is
    /// "no bass" | "root"; read by ast2ast (chord rewriting) AND
    /// ast2notes (inversion chords), like the JS state in both passes
    ChangeBassPlayMode(String),
    /// JS octave up/down events (upper/lower variants shift only one
    /// register); consumed by ast2notes
    OctaveShift { upper_delta: i32, lower_delta: i32 },
    /// JS: `{event: "bar"}` (`|`); read by ast2ast for note lengths and
    /// rendered as `/*|*/` by notes2mml
    Bar,
    /// JS: `{event: "bar slash"}` (`/ `), a half-bar divider; read by
    /// ast2ast for note lengths, then dropped
    BarSlash,
    /// JS: `{event: "key", ...}`; the offset is the key root as semitones
    /// (degrees are resolved against it in cst_to_ast; notes2mml uses it
    /// for sharp/flat spelling)
    Key { offset: i32 },
    /// JS: `{event: "scale", offsets}`; used by notes2mml for sharp/flat
    /// spelling only
    Scale { offsets: Vec<i32> },
}

/// Output of `ast2notes`, consumed by `notes2mml` (mirrors what the JS
/// notesToMml switch handles).
#[derive(Debug, Clone, PartialEq)]
pub enum OutEvent {
    Notes(NotesEvent),
    Bar,
    Key { offset: i32 },
    Scale { offsets: Vec<i32> },
}

/// Slash-chord interpretation modes (JS slashMode state in ast2ast).
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum SlashChordMode {
    ChordOverBassNote,
    Inversion,
    Polychord,
}

/// A plain chord event.
#[derive(Debug, Clone, PartialEq)]
pub struct ChordEvent {
    /// Root as semitone offset. C=0, D=2, ... B=11, plus accidentals
    /// (not normalized mod 12, matching the JS grammar).
    pub root: i32,
    /// Normalized quality string, e.g. "maj", "min", "min7", "dim triad".
    pub quality: String,
    /// Per-chord inversion from `^0`-`^3` ("root inv".."3rd inv");
    /// None means "use the current inversion mode" (JS INVERSION = null).
    pub inversion: Option<String>,
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
    pub upper_inversion: Option<String>,
    pub lower_root: i32,
    pub lower_quality: String,
    pub lower_inversion: Option<String>,
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
