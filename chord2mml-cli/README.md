# chord2mml-cli

Command-line interface for converting chord notation to MML (Music Macro Language).

## Features

- Convert single chords: `C` → `c;e;g`
- Convert chord progressions: `C-F-G-C` → `c;e;g f;a;c g;b;d c;e;g`
- Uses Tree-sitter for robust parsing
- Pure Rust implementation

## Installation

Build from source:

```bash
cd chord2mml-cli
cargo build --release
```

The binary will be available at `../target/release/chord2mml`.

## Usage

### Command-line argument

```bash
chord2mml "C"
# Output: c;e;g

chord2mml "C-F-G-C"
# Output: c;e;g f;a;c g;b;d c;e;g
```

### Interactive mode (stdin)

```bash
chord2mml
# Enter chord notation interactively
```

### Pipeline

```bash
echo "C-F-G-C" | chord2mml
# Output: c;e;g f;a;c g;b;d c;e;g
```

## Supported Chords

Currently supported:
- Major chords: `C`, `D`, `E`, `F`, `G`, `A`, `B`
- Minor chords: `Cm`, `Dm`, etc.

## Output Format

The output is in mmlabc format where:
- Notes are lowercase letters
- Chords are represented as semicolon-separated notes
- Multiple chords are space-separated

Example:
- `c;e;g` = C major chord (C, E, G notes)
- `c;e;g f;a;c` = C major followed by F major

## License

MIT License
