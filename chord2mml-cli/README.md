# chord2mml-cli

Command-line interface for converting chord notation to MML (Music Macro Language).

## Features

- Convert single chords: `C` → `v11'c1eg'`
- Convert chord progressions: `Dm G7 C` → `v11'd1fa''g1b<df''c1eg'`
- Output compatible with the original JS [chord2mml](https://github.com/cat2151/chord2mml) (mmlabc format)
- Uses Tree-sitter for robust parsing
- Pure Rust implementation

## Installation

Build from source:

```bash
cargo build --release -p chord2mml-cli
```

The binary will be available at `target/release/chord2mml`.

## Usage

### Command-line argument

```bash
chord2mml "C"
# Output: v11'c1eg'

chord2mml "Dm G7 C"
# Output: v11'd1fa''g1b<df''c1eg'
```

### Interactive mode (stdin)

```bash
chord2mml
# Enter chord notation interactively
```

### Pipeline

```bash
echo "Dm G7 C" | chord2mml
# Output: v11'd1fa''g1b<df''c1eg'
```

## Supported Notation

- Roots `A`–`G` with accidentals `#`/`＃`/`♯`/`b`/`♭`
- Qualities: (major), `m`/`min`, `maj7`/`M7`/`△`, `m7`/`min7`, `7`, `dim`, `aug`/`+`, `sus2`, `sus4`
- Slash chords (chord over bass note): `F/C`
- Progression separators: whitespace, ` - `, `→`, `・` (and legacy unspaced `-`)

See the roadmap in the repository README for what arrives next.

## Output Format

The output is mmlabc-style MML, identical to the JS chord2mml:
- Leading `v11` volume command
- Each chord wrapped in `'...'`, notes as lowercase letters, sharp `+` / flat `-`
- `<` / `>` move the octave up / down
- The digit after the first note of a chord is the note length (1=whole note)

Example:
- `v11'c1eg'` = C major chord (C, E, G) as a whole note
- `v11'c1eg''f1a<c'` = C major followed by F major

## License

MIT License
