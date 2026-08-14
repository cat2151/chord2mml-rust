//! Public structured result of parsing chord notation.
//!
//! The semantic [`Event`] stream remains the source of truth for musical
//! meaning. [`ParsedItem`] adds only the original text of key and chord CST
//! nodes so callers can display or persist notation without parsing it again.

use anyhow::Result;

use crate::{events_to_mml, Event};

/// A key or chord item found in the parsed source, in source order.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum ParsedItem {
    /// A key directive such as `key:G`.
    Key {
        /// The directive text as it appeared in the successfully parsed input.
        text: String,
        /// The key root normalized to one of the twelve pitch classes.
        pitch_class: u8,
        /// Index of the matching [`Event::Key`] in [`ParsedInput::events`].
        event_index: usize,
    },
    /// A chord such as `Isus4` or `G7`.
    Chord {
        /// The chord text as it appeared in the successfully parsed input.
        text: String,
        /// Index of the matching chord event in [`ParsedInput::events`].
        event_index: usize,
    },
}

/// Structured chord notation produced by the shared Tree-sitter/CST semantic
/// parser.
#[derive(Debug, Clone, PartialEq)]
pub struct ParsedInput {
    normalized_input: String,
    events: Vec<Event>,
    items: Vec<ParsedItem>,
}

impl ParsedInput {
    pub(crate) fn new(
        normalized_input: String,
        events: Vec<Event>,
        items: Vec<ParsedItem>,
    ) -> Self {
        Self {
            normalized_input,
            events,
            items,
        }
    }

    /// The input candidate that successfully parsed.
    ///
    /// This can differ from the caller's text when a supported dialect rewrite
    /// from [`crate::preprocess_candidates`] was needed.
    pub fn normalized_input(&self) -> &str {
        &self.normalized_input
    }

    /// Semantic events with roots already resolved to semitone offsets.
    pub fn events(&self) -> &[Event] {
        &self.events
    }

    /// Key and chord source items in their original order.
    pub fn items(&self) -> &[ParsedItem] {
        &self.items
    }

    /// Consume the parsed input and return its semantic events.
    pub fn into_events(self) -> Vec<Event> {
        self.events
    }

    /// Render this already-parsed event stream as MML without parsing the text
    /// again.
    pub fn to_mml(&self) -> Result<String> {
        events_to_mml(self.events.clone())
    }
}
