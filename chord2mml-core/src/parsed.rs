//! Public structured result of parsing chord notation.
//!
//! The semantic [`Event`] stream remains the source of truth for musical
//! meaning. [`ParsedItem`] adds only the original text of key and chord CST
//! nodes so callers can display or persist notation without parsing it again.

use std::ops::Range;

#[cfg(feature = "tree-sitter")]
use anyhow::anyhow;
use anyhow::Result;

use crate::{events_to_mml, Event};

/// A key or chord item found in the parsed source, in source order.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum ParsedItem {
    /// A key directive such as `key:G`.
    Key {
        /// The directive text as it appeared in the successfully parsed input.
        text: String,
        /// UTF-8 byte range in the original input passed to [`crate::parse`].
        ///
        /// This is `None` only for CST JSON that did not include source ranges.
        /// Unlike `text`, the range always refers to the caller's input rather
        /// than a successfully parsed dialect rewrite.
        source_range: Option<Range<usize>>,
        /// The key root normalized to one of the twelve pitch classes.
        pitch_class: u8,
        /// Index of the matching [`Event::Key`] in [`ParsedInput::events`].
        event_index: usize,
    },
    /// A chord such as `Isus4` or `G7`.
    Chord {
        /// The chord text as it appeared in the successfully parsed input.
        text: String,
        /// UTF-8 byte range in the original input passed to [`crate::parse`].
        ///
        /// This is `None` only for CST JSON that did not include source ranges.
        /// The text can come from a normalized dialect candidate (for example,
        /// `IIm`), while this range still slices the caller's text (for example,
        /// `ii`).
        source_range: Option<Range<usize>>,
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

    #[cfg(feature = "tree-sitter")]
    pub(crate) fn remap_source_ranges(
        &mut self,
        mut map: impl FnMut(Range<usize>) -> Option<Range<usize>>,
    ) -> Result<()> {
        for item in &mut self.items {
            let source_range = match item {
                ParsedItem::Key { source_range, .. } | ParsedItem::Chord { source_range, .. } => {
                    source_range
                }
            };
            let Some(candidate_range) = source_range.take() else {
                continue;
            };
            *source_range = Some(map(candidate_range.clone()).ok_or_else(|| {
                anyhow!(
                    "Failed to map parsed source range {}..{} to the original input",
                    candidate_range.start,
                    candidate_range.end
                )
            })?);
        }
        Ok(())
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
