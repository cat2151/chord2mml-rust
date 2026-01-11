use anyhow::{anyhow, Result};

/// Convert a chord notation to MML (Music Macro Language) format
/// 
/// # Example
/// ```
/// use chord2mml_core::convert;
/// 
/// let mml = convert("C").unwrap();
/// assert_eq!(mml, "c;e;g");
/// ```
pub fn convert(chord: &str) -> Result<String> {
    let chord = chord.trim();
    
    if chord.is_empty() {
        return Err(anyhow!(
            "Empty chord input. Please provide a chord notation (e.g., 'C', 'Dm', 'G7')."
        ));
    }
    
    // Validate input length to prevent potential issues
    if chord.len() > 100 {
        return Err(anyhow!(
            "Chord notation too long (max 100 characters)."
        ));
    }
    
    // Parse the chord notation
    let parsed = parse_chord(chord)?;
    
    // Convert to MML
    let mml = chord_to_mml(&parsed)?;
    
    Ok(mml)
}

/// Internal structure representing a parsed chord
#[derive(Debug, Clone, PartialEq)]
struct ParsedChord {
    root: String,
    quality: ChordQuality,
    bass: Option<String>,
}

#[derive(Debug, Clone, PartialEq)]
enum ChordQuality {
    Major,
    // The following variants are placeholders for Phase 2 implementation
    Minor,
    Diminished,
    Augmented,
    Dominant7,
    Major7,
    Minor7,
    // Add more as needed
}

/// Parse chord notation into structured data
fn parse_chord(chord: &str) -> Result<ParsedChord> {
    // Simple parser for basic chords
    // Start with support for C major only
    
    if chord == "C" {
        return Ok(ParsedChord {
            root: "C".to_string(),
            quality: ChordQuality::Major,
            bass: None,
        });
    }
    
    Err(anyhow!("Unsupported chord: {}", chord))
}

/// Convert parsed chord to MML notes
fn chord_to_mml(parsed: &ParsedChord) -> Result<String> {
    match (&parsed.root[..], &parsed.quality) {
        ("C", ChordQuality::Major) => {
            // C major: C, E, G (ド, ミ, ソ)
            Ok("c;e;g".to_string())
        }
        _ => {
            let quality_name = match parsed.quality {
                ChordQuality::Major => "major",
                ChordQuality::Minor => "minor",
                ChordQuality::Diminished => "diminished",
                ChordQuality::Augmented => "augmented",
                ChordQuality::Dominant7 => "7",
                ChordQuality::Major7 => "maj7",
                ChordQuality::Minor7 => "m7",
            };
            Err(anyhow!(
                "Conversion not implemented for chord: {}{}", 
                parsed.root, 
                quality_name
            ))
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert_c_major() {
        let result = convert("C").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[test]
    fn test_convert_empty_input() {
        let result = convert("");
        assert!(result.is_err());
    }

    #[test]
    fn test_convert_whitespace_trimmed() {
        let result = convert("  C  ").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[test]
    fn test_parse_c_major() {
        let parsed = parse_chord("C").unwrap();
        assert_eq!(parsed.root, "C");
        assert_eq!(parsed.quality, ChordQuality::Major);
        assert_eq!(parsed.bass, None);
    }

    #[test]
    fn test_chord_to_mml_c_major() {
        let parsed = ParsedChord {
            root: "C".to_string(),
            quality: ChordQuality::Major,
            bass: None,
        };
        let mml = chord_to_mml(&parsed).unwrap();
        assert_eq!(mml, "c;e;g");
    }
}
