# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application for converting chord progressions to MML (Music Macro Language), written in Rust.

## Note
- WIP
- Frequent breaking changes
- Aiming to minimize user workload through AI autonomous driving.
- Intending to develop an AI autonomous driving system for this purpose (or rather, using this repository for the development of an AI autonomous driving system).
- The following content is mostly AI-generated, highly likely to contain errors, and may not align with the user's intentions.

## Overview

This project is a complete rewrite of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now implemented as **Rust + Tree-sitter**.

**The output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). Approximately 100 tests from the JS version are being gradually ported as specifications (refer to the golden corpus in `chord2mml-core/tests/corpus/` for ported cases).

### Key Features

- **Tree-sitter Parser**: Robust and accurate syntax parsing
- **JS Version Compatible Output**: MML format directly usable by `obsidian-plugin-mmlabc` and similar tools
- **Native + Browser Support**: In addition to CLI/library, a browser demo using WASM + web-tree-sitter
- **Golden Corpus**: Tests where the JS version's output is the expected value, shared across both native and WASM paths

## Architecture

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitter grammar definition + grammar WASM
├── chord2mml-core/      # Core conversion library in Rust
├── chord2mml-cli/       # Command-line interface
├── chord2mml-wasm/      # WASM bindings (C-dependency free)
└── chord2mml-web/       # Browser demo (web-tree-sitter + Vite)
```

### Data Flow

The pattern proven in [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) is followed. The pipeline is a port of the 4-stage configuration from the JS version.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser]   Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common:       CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Point: To avoid including tree-sitter's C dependencies in Rust's WASM build, `chord2mml-core` is tree-sitter-independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by spaces, " - ", or "→". Hyphen separation is also temporarily available.)
$ chord2mml "Dm G7 C"
v11'd1fa''g1b<df''c1eg'

$ chord2mml "C-F-G-C"
v11'c1eg''f1a<c''g1b<d''c1eg'
```

## Usage

### CLI Tool

```bash
# Build
cargo build --release -p chord2mml-cli

# Run (from arguments)
chord2mml "Dm G7 C"

# Run (from standard input)
echo "Dm G7 C" | chord2mml
```

### As a Rust Library

```rust
use chord2mml_core::convert;

fn main() {
    // Single chord
    let mml = convert("C").unwrap();
    println!("MML: {}", mml); // "v11'c1eg'"

    // Chord progression
    let mml = convert("Dm G7 C").unwrap();
    println!("MML: {}", mml); // "v11'd1fa''g1b<df''c1eg'"
}
```

### Build and Test

```bash
# Entire workspace (native)
cargo test --workspace --all-features

# WASM (verify build without C dependencies)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (run web-tree-sitter + Rust WASM with Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation tests (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Using approximately 100 tests from the JS version as specifications, porting will proceed in the following order (maintaining tests for both native + WASM paths in each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment revived
- [x] **Phase 1**: JS version compatible output format (`v11'c1eg'`) and 4-stage pipeline, basic chords
  - Major/minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width #♭, slash chords (bass notes), chord progressions
- [ ] **Wave A**: Tensions (6, 9, 11, 13), 7sus family, Quartal (4.N)
- [ ] **Wave B**: Modifiers (add, omit, ♭5, #5), minor notation with `-` (`C-7`)
- [ ] **Wave C**: On-chords (EonC), Polychords (US), Inversions (^N, 1st inv, etc.)
- [ ] **Wave D**: Voicings (drop2, etc.), Bass Mode, Octave Specification
- [ ] **Wave E**: Measures and Note Lengths (`|`, `/ `), Scale Degree Notation, Key/Scale
- [ ] **Wave F**: Inline MML/ABC, MIDI Program Change, Tempo
- [ ] **Wave G**: Dialect Preprocessing (support for LLM-generated chord progressions)

## Development Policy

### Differences from the Original chord2mml

| Item              | chord2mml (Old)     | chord2mml-rust (New)        |
|-------------------|---------------------|-----------------------------|
| Parser            | Peggy.js            | Tree-sitter                 |
| Language          | JavaScript/TypeScript | Rust                        |
| Runtime Environment | Browser             | Native (CLI) + Browser (WASM) |
| Output            | `v11'c1eg'` format | Same (Compatible)           |

### Design Philosophy

1.  **JS Version Tests as Specification**: Functionality is based on JS version tests (to prevent hallucinations).
2.  **Path Consistency**: Native and WASM paths use the same semantic code (cst_to_ast).
3.  **Test-Driven**: Comprehensive verification using golden corpus.

## Build Requirements

- Rust 1.70 or later (C compiler also required for native builds)
- Node.js 20 or later (for browser demo and WASM path tests)
- Only for regenerating grammar WASM: tree-sitter-cli + docker or emscripten

## License

MIT License

## Related Projects

- [chord2mml](https://github.com/cat2151/chord2mml) - Original JavaScript version (source of specification)
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - Reference implementation of tree-sitter + WASM architecture
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library

## Contributing

Issues and Pull Requests are welcome.

## Author

cat2151

## Reference Links

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Syntax parsing library
- [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture explanation