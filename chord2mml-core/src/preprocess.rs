//! Dialect preprocessing (port of chord2mml_preprocess.ts).
//!
//! Chord progressions written by LLMs (and humans) come in dialects the
//! grammar does not accept directly. Each transform rewrites one dialect;
//! the caller tries the original input first, then every combination and
//! ordering of the transforms until one parses (JS chord2mml.parse's
//! brute-force contract).
//!
//! Pure string processing — shared by the native path (`convert`) and the
//! WASM path (`preprocess_candidates` via chord2mml-wasm, with the parsing
//! retry loop running in JavaScript where web-tree-sitter lives).

use std::ops::Range;

#[derive(Clone, Debug)]
struct MappedChar {
    value: char,
    source_range: Range<usize>,
}

/// A dialect candidate whose characters retain their origin in the caller's
/// UTF-8 input. Inserted characters use an empty range at the insertion point.
#[derive(Clone, Debug)]
pub(crate) struct MappedText {
    text: String,
    chars: Vec<MappedChar>,
}

impl MappedText {
    fn from_input(input: &str) -> Self {
        let chars = input
            .char_indices()
            .map(|(start, value)| MappedChar {
                value,
                source_range: start..start + value.len_utf8(),
            })
            .collect();
        Self {
            text: input.to_string(),
            chars,
        }
    }

    fn from_chars(chars: Vec<MappedChar>) -> Self {
        let text = chars.iter().map(|mapped| mapped.value).collect();
        Self { text, chars }
    }

    #[cfg(any(feature = "tree-sitter", test))]
    pub(crate) fn as_str(&self) -> &str {
        &self.text
    }

    /// Map a candidate UTF-8 byte range back to the original input.
    #[cfg(any(feature = "tree-sitter", test))]
    pub(crate) fn map_source_range(&self, range: Range<usize>) -> Option<Range<usize>> {
        if range.start > range.end
            || range.end > self.text.len()
            || !self.text.is_char_boundary(range.start)
            || !self.text.is_char_boundary(range.end)
        {
            return None;
        }
        if range.is_empty() {
            let offset = self.map_boundary(range.start)?;
            return Some(offset..offset);
        }

        let mut candidate_offset = 0;
        let mut source_start = None;
        let mut source_end = None;
        for mapped in &self.chars {
            let candidate_end = candidate_offset + mapped.value.len_utf8();
            if candidate_offset < range.end && candidate_end > range.start {
                source_start.get_or_insert(mapped.source_range.start);
                source_end = Some(mapped.source_range.end);
            }
            candidate_offset = candidate_end;
            if candidate_offset >= range.end {
                break;
            }
        }
        Some(source_start?..source_end?)
    }

    #[cfg(any(feature = "tree-sitter", test))]
    fn map_boundary(&self, boundary: usize) -> Option<usize> {
        if boundary == 0 {
            return Some(
                self.chars
                    .first()
                    .map_or(0, |mapped| mapped.source_range.start),
            );
        }

        let mut candidate_offset = 0;
        for mapped in &self.chars {
            if boundary == candidate_offset {
                return Some(mapped.source_range.start);
            }
            candidate_offset += mapped.value.len_utf8();
            if boundary == candidate_offset {
                return Some(mapped.source_range.end);
            }
        }
        None
    }
}

/// Dialect: replace hyphens with a middle dot (e.g. 1-3 → 1・3).
/// A hyphen right after a chord root letter [A-G] or an accidental
/// [#＃♯b♭] is part of a chord quality (e.g. C-7 = Cmin7) and is kept.
/// (JS replaceHyphenToDot; the left scan skips whitespace.)
fn replace_hyphen_to_dot(mut input: MappedText) -> MappedText {
    for i in 0..input.chars.len() {
        if input.chars[i].value != '-' {
            continue;
        }
        let left = input.chars[..i]
            .iter()
            .rev()
            .map(|mapped| mapped.value)
            .find(|ch| !ch.is_whitespace());
        let keep = matches!(
            left,
            Some('A'..='G') | Some('#') | Some('＃') | Some('♯') | Some('b') | Some('♭')
        );
        if !keep {
            input.chars[i].value = '・';
        }
    }
    MappedText::from_chars(input.chars)
}

/// Dialect: unify lowercase roman-numeral minor notation (e.g. ii → IIm).
/// (JS replaceMinorRomanNumerals: \b before, no [a-zA-Z] after,
/// longest numerals first.)
fn replace_minor_roman_numerals(mut input: MappedText) -> MappedText {
    for (pattern, replacement) in [
        ("vii", "VIIm"),
        ("iii", "IIIm"),
        ("vi", "VIm"),
        ("iv", "IVm"),
        ("ii", "IIm"),
        ("v", "Vm"),
        ("i", "Im"),
    ] {
        input = replace_word(input, pattern, replacement);
    }
    input
}

/// Replace `pattern` with `replacement` where the JS regex
/// `\bpattern(?![a-zA-Z])` would match: no word character ([A-Za-z0-9_])
/// before, no ASCII letter after.
fn replace_word(input: MappedText, pattern: &str, replacement: &str) -> MappedText {
    let pattern: Vec<char> = pattern.chars().collect();
    let replacement: Vec<char> = replacement.chars().collect();
    debug_assert_eq!(replacement.len(), pattern.len() + 1);

    let mut out = Vec::with_capacity(input.chars.len() + 1);
    let mut i = 0;
    while i < input.chars.len() {
        let matches_pattern = input.chars[i..]
            .iter()
            .map(|mapped| mapped.value)
            .take(pattern.len())
            .eq(pattern.iter().copied());
        if matches_pattern && input.chars.len() - i >= pattern.len() {
            let prev_ok = i == 0
                || !(input.chars[i - 1].value.is_ascii_alphanumeric()
                    || input.chars[i - 1].value == '_');
            let next = input
                .chars
                .get(i + pattern.len())
                .map(|mapped| mapped.value);
            let next_ok = next.is_none_or(|c| !c.is_ascii_alphabetic());
            if prev_ok && next_ok {
                let insertion_point = input.chars[i + pattern.len() - 1].source_range.end;
                for (replacement_index, value) in replacement.iter().copied().enumerate() {
                    let source_range = input
                        .chars
                        .get(i + replacement_index)
                        .filter(|_| replacement_index < pattern.len())
                        .map_or(insertion_point..insertion_point, |mapped| {
                            mapped.source_range.clone()
                        });
                    out.push(MappedChar {
                        value,
                        source_range,
                    });
                }
                i += pattern.len();
                continue;
            }
        }
        out.push(input.chars[i].clone());
        i += 1;
    }
    MappedText::from_chars(out)
}

const TRANSFORMS: [Transform; 2] = [replace_hyphen_to_dot, replace_minor_roman_numerals];

/// All candidate rewrites of the input, in the JS trial order: the
/// original first, then every subset of the transforms in every order
/// (JS getAllCombinations), deduplicated.
pub fn preprocess_candidates(input: &str) -> Vec<String> {
    preprocess_candidates_with_source_map(input)
        .into_iter()
        .map(|candidate| candidate.text)
        .collect()
}

/// All candidate rewrites together with byte-range mappings to `input`.
pub(crate) fn preprocess_candidates_with_source_map(input: &str) -> Vec<MappedText> {
    let original = MappedText::from_input(input);
    let mut candidates = vec![original.clone()];

    for seq in transform_sequences() {
        let mut candidate = original.clone();
        for &f in &seq {
            candidate = f(candidate);
        }
        if !candidates
            .iter()
            .any(|existing| existing.text == candidate.text)
        {
            candidates.push(candidate);
        }
    }

    candidates
}

type Transform = fn(MappedText) -> MappedText;
type TransformSequence = Vec<Transform>;

/// JS getAllCombinations order for two transforms:
/// [], [f0], [f1], then the permutations of [f0, f1].
fn transform_sequences() -> Vec<TransformSequence> {
    let n = TRANSFORMS.len();
    let mut subsets: Vec<TransformSequence> = Vec::new();
    for mask in 0..(1u32 << n) {
        let seq: TransformSequence = (0..n)
            .filter(|j| mask & (1 << j) != 0)
            .map(|j| TRANSFORMS[j])
            .collect();
        subsets.push(seq);
    }

    let mut sequences = Vec::new();
    for seq in subsets {
        if seq.len() <= 1 {
            sequences.push(seq);
        } else {
            permute(&seq, &mut Vec::new(), &mut sequences);
        }
    }
    sequences
}

fn permute(
    remaining: &[Transform],
    current: &mut TransformSequence,
    out: &mut Vec<TransformSequence>,
) {
    if remaining.is_empty() {
        out.push(current.clone());
        return;
    }
    for (i, &f) in remaining.iter().enumerate() {
        let mut rest = remaining.to_vec();
        rest.remove(i);
        current.push(f);
        permute(&rest, current, out);
        current.pop();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn rewritten(transform: Transform, input: &str) -> String {
        transform(MappedText::from_input(input)).text
    }

    // Expected values from the JS test suite (preprocessChord block)
    #[test]
    fn test_hyphen_to_dot() {
        assert_eq!(rewritten(replace_hyphen_to_dot, "1-3"), "1・3");
        assert_eq!(rewritten(replace_hyphen_to_dot, "C-7"), "C-7");
        assert_eq!(rewritten(replace_hyphen_to_dot, "C-7-D-7"), "C-7・D-7");
        assert_eq!(rewritten(replace_hyphen_to_dot, "F#-7"), "F#-7");
        assert_eq!(rewritten(replace_hyphen_to_dot, "I-IV-V"), "I・IV・V");
    }

    #[test]
    fn test_minor_roman_numerals() {
        assert_eq!(rewritten(replace_minor_roman_numerals, "ii"), "IIm");
        assert_eq!(rewritten(replace_minor_roman_numerals, "ii V I"), "IIm V I");
        assert_eq!(rewritten(replace_minor_roman_numerals, "vii"), "VIIm");
        // No replacement inside words or before letters
        assert_eq!(rewritten(replace_minor_roman_numerals, "inv"), "inv");
        assert_eq!(rewritten(replace_minor_roman_numerals, "ii7"), "IIm7");
    }

    #[test]
    fn test_candidates_start_with_original() {
        let candidates = preprocess_candidates("ii-V-I");
        assert_eq!(candidates[0], "ii-V-I");
        assert!(candidates.contains(&"IIm・V・I".to_string()));
    }

    #[test]
    fn mapped_candidate_composes_length_and_unicode_rewrites() {
        let candidates = preprocess_candidates_with_source_map("ii-V-I");
        let candidate = candidates
            .iter()
            .find(|candidate| candidate.as_str() == "IIm・V・I")
            .unwrap();

        assert_eq!(candidate.map_source_range(0..3), Some(0..2));
        assert_eq!(candidate.map_source_range(3..6), Some(2..3));
        assert_eq!(candidate.map_source_range(6..7), Some(3..4));
        assert_eq!(candidate.map_source_range(10..11), Some(5..6));
    }
}
