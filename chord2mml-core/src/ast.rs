//! Abstract Syntax Tree (AST) data structures for chord representation
//!
//! This module defines the AST types used to represent parsed chord notation.

/// AST structure representing a chord (abstracted from CST)
#[derive(Debug, Clone, PartialEq)]
pub struct ASTChord {
    pub root: String,
    pub accidental: Option<Accidental>,
    pub quality: ChordQuality,
    pub bass: Option<String>,
}

/// Accidental modifiers for notes
#[derive(Debug, Clone, PartialEq)]
pub enum Accidental {
    Sharp,
    Flat,
}

/// Chord quality types
#[derive(Debug, Clone, PartialEq)]
pub enum ChordQuality {
    Major,
    Minor,
    Diminished,
    Augmented,
    Dominant7,
    Major7,
    Sus4,
    Sus2,
}

/// AST structure representing the input (either a single chord or progression)
#[derive(Debug, Clone, PartialEq)]
pub enum ASTRoot {
    SingleChord(ASTChord),
    ChordProgression(Vec<ASTChord>),
}
