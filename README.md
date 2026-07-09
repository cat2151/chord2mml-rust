# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application that converts chord progressions to MML (Music Macro Language). Written in Rust.

## Warning
- Frequent breaking changes may occur.
- The following text may contain AI-generated content. It might contain errors or content that does not match the user's intent.

## Overview

This project is a complete rewrite of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now reimagined as **Rust + Tree-sitter**.

The **output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). Approximately 100 tests from the JS version were progressively ported as specifications. For ported cases, please refer to the golden corpus in `chord2mml-core/tests/corpus/`.

### Past Challenges and This Project's Goals
- [chord2mml](https://github.com/cat2151/chord2mml) was difficult to use when wanting to play chord progressions locally with Rust.
- Therefore, this project was rewritten using Rust + Tree-sitter.
- As a result, it is proving useful in https://github.com/cat2151/clap-mml-render-tui/blob/main/README.ja.md (allowing immediate playback of chord progressions by simply providing the chord progression string as a command-line argument).

### Key Features

- **Tree-sitter Parser**: Robust and accurate syntax analysis.
- **JS Version Compatible Output**: MML format directly usable with tools like obsidian-plugin-mmlabc.
- **Native + Browser Support**: In addition to CLI/library, a browser demo powered by WASM + web-tree-sitter.
- **Golden Corpus**: Tests where the JS version's output serves as the expected value, shared across both native and WASM paths.

## Architecture

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitter grammar definition + grammar WASM
├── chord2mml-core/      # Core conversion library in Rust
├── chord2mml-cli/       # Command Line Interface
├── chord2mml-wasm/      # WASM bindings (C-independent)
└── chord2mml-web/       # Browser demo (web-tree-sitter + Vite)
```

### Data Flow

Follows a proven pattern from [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json). The pipeline is a port of the JS version's four-stage structure.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser]   Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common:       CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Key point: To avoid including tree-sitter's C dependency in Rust's WASM build, `chord2mml-core` is tree-sitter independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by spaces, " - ", or "->". Hyphen-separated also usable for now.)
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

# Run (from stdin)
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

## Build and Test

```bash
# Whole workspace (native)
cargo test --workspace --all-features

# WASM (verify build without C dependency)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (web-tree-sitter + Rust WASM executed with Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation test (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Approximately 100 tests from the JS version served as the specification, and were ported in the following order (maintaining both native and WASM path tests for each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment restored
- [x] **Phase 1**: JS version compatible output format (`v11'c1eg'`), 4-stage pipeline, basic chords
  - Major/minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width sharps/flats, slash chords (bass note), chord progressions
- [x] **Wave A**: Tensions (6, 9, 11, 13), 7sus-family, quartal (4.N), maj9-family (`maj7,add9`)
- [x] **Wave B**: Modifications (add, omit, ♭5, #5), minor notation with `-` (`C-`, `C-7`)
- [x] **Wave C**: On-chords (EonC), polychords (US), inversions (^N, 1st inv, etc.)
- [x] **Wave D**: Voicings (drop2/drop4/drop2and4/close/open triad), bass mode (bass is root), octave specification (octave up/down, `'`/`,`)
- [x] **Wave E**: Bars and note lengths (`|`, `/ `), degree notation (Roman numerals/Arabic numerals), key/scale (church modes, sharp/flat spellings)
- [x] **Wave F**: Inline MML/ABC, MIDI Program Change (GM instrument names PC000-127), Tempo (BPM/Tempo)
- [x] **Wave G**: Dialect preprocessing (LLM-generated chord progression support: hyphen dialect, lowercase Roman numerals, exhaustive conversion combinations)

**All waves completed**: The golden corpus of 324 cases (319 JS-verified + 5 Rust extensions), based on the JS version's test suite, has passed entirely on both native and WASM paths. Verification against the JS version can be re-run using `scripts/verify-corpus-vs-js.mjs`.

## Development Policy

### Differences from the original chord2mml

| Item              | chord2mml (Old)     | chord2mml-rust (New)       |
|-------------------|---------------------|----------------------------|
| Parser            | Peggy.js            | Tree-sitter                |
| Language          | JavaScript/TypeScript | Rust                       |
| Runtime Environment | Browser             | Native (CLI) + Browser (WASM) |
| Output            | `v11'c1eg'` format | Same (Compatible)          |

### Design Philosophy

1.  **JS version tests as specification**: Functionality is based on JS version tests (to prevent hallucinations).
2.  **Consistency across both paths**: Native and WASM paths use the same semantic code (cst_to_ast).
3.  **Test-driven**: Comprehensive verification with a golden corpus.

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

## Reference Links

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Syntax parsing library
- [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture explanation