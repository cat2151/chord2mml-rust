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

/// Dialect: replace hyphens with a middle dot (e.g. 1-3 → 1・3).
/// A hyphen right after a chord root letter [A-G] or an accidental
/// [#＃♯b♭] is part of a chord quality (e.g. C-7 = Cmin7) and is kept.
/// (JS replaceHyphenToDot; the left scan skips whitespace.)
fn replace_hyphen_to_dot(s: &str) -> String {
    let chars: Vec<char> = s.chars().collect();
    let mut out = String::with_capacity(s.len());
    for (i, &c) in chars.iter().enumerate() {
        if c != '-' {
            out.push(c);
            continue;
        }
        let left = chars[..i].iter().rev().find(|ch| !ch.is_whitespace());
        let keep = matches!(
            left,
            Some('A'..='G') | Some('#') | Some('＃') | Some('♯') | Some('b') | Some('♭')
        );
        out.push(if keep { '-' } else { '・' });
    }
    out
}

/// Dialect: unify lowercase roman-numeral minor notation (e.g. ii → IIm).
/// (JS replaceMinorRomanNumerals: \b before, no [a-zA-Z] after,
/// longest numerals first.)
fn replace_minor_roman_numerals(s: &str) -> String {
    let mut result = s.to_string();
    for (pattern, replacement) in [
        ("vii", "VIIm"),
        ("iii", "IIIm"),
        ("vi", "VIm"),
        ("iv", "IVm"),
        ("ii", "IIm"),
        ("v", "Vm"),
        ("i", "Im"),
    ] {
        result = replace_word(&result, pattern, replacement);
    }
    result
}

/// Replace `pattern` with `replacement` where the JS regex
/// `\bpattern(?![a-zA-Z])` would match: no word character ([A-Za-z0-9_])
/// before, no ASCII letter after.
fn replace_word(s: &str, pattern: &str, replacement: &str) -> String {
    let mut out = String::with_capacity(s.len());
    let mut i = 0;
    while i < s.len() {
        if s[i..].starts_with(pattern) {
            let prev_ok = s[..i]
                .chars()
                .last()
                .is_none_or(|c| !(c.is_ascii_alphanumeric() || c == '_'));
            let next = s[i + pattern.len()..].chars().next();
            let next_ok = next.is_none_or(|c| !c.is_ascii_alphabetic());
            if prev_ok && next_ok {
                out.push_str(replacement);
                i += pattern.len();
                continue;
            }
        }
        let c = s[i..].chars().next().unwrap();
        out.push(c);
        i += c.len_utf8();
    }
    out
}

const TRANSFORMS: [fn(&str) -> String; 2] = [replace_hyphen_to_dot, replace_minor_roman_numerals];

/// All candidate rewrites of the input, in the JS trial order: the
/// original first, then every subset of the transforms in every order
/// (JS getAllCombinations), deduplicated.
pub fn preprocess_candidates(input: &str) -> Vec<String> {
    let mut candidates = vec![input.to_string()];

    for seq in transform_sequences() {
        let mut candidate = input.to_string();
        for &f in &seq {
            candidate = f(&candidate);
        }
        if !candidates.contains(&candidate) {
            candidates.push(candidate);
        }
    }

    candidates
}

type Transform = fn(&str) -> String;
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

    // Expected values from the JS test suite (preprocessChord block)
    #[test]
    fn test_hyphen_to_dot() {
        assert_eq!(replace_hyphen_to_dot("1-3"), "1・3");
        assert_eq!(replace_hyphen_to_dot("C-7"), "C-7");
        assert_eq!(replace_hyphen_to_dot("C-7-D-7"), "C-7・D-7");
        assert_eq!(replace_hyphen_to_dot("F#-7"), "F#-7");
        assert_eq!(replace_hyphen_to_dot("I-IV-V"), "I・IV・V");
    }

    #[test]
    fn test_minor_roman_numerals() {
        assert_eq!(replace_minor_roman_numerals("ii"), "IIm");
        assert_eq!(replace_minor_roman_numerals("ii V I"), "IIm V I");
        assert_eq!(replace_minor_roman_numerals("vii"), "VIIm");
        // No replacement inside words or before letters
        assert_eq!(replace_minor_roman_numerals("inv"), "inv");
        assert_eq!(replace_minor_roman_numerals("ii7"), "IIm7");
    }

    #[test]
    fn test_candidates_start_with_original() {
        let candidates = preprocess_candidates("ii-V-I");
        assert_eq!(candidates[0], "ii-V-I");
        assert!(candidates.contains(&"IIm・V・I".to_string()));
    }
}
