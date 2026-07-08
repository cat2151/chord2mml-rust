# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application written in Rust that converts chord progressions into MML (Music Macro Language).

## Warning
- Frequent breaking changes are expected.
- The following text includes AI-generated content and may contain errors or deviate from the user's intent.

## Overview

This project is a complete rewrite of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now using **Rust + Tree-sitter**.

**The output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). Approximately 100 tests from the JS version were incrementally ported as specifications. For ported cases, please refer to the golden corpus in `chord2mml-core/tests/corpus/`.

### Previous Challenges and What This Project Aims For
- [chord2mml](https://github.com/cat2151/chord2mml) was difficult to use when trying to play chord progressions locally in Rust.
- Therefore, we decided to rewrite this project using Rust + Tree-sitter.

### Key Features

- **Tree-sitter Parser**: Robust and accurate syntax analysis.
- **JS-compatible Output**: MML format directly usable by tools like obsidian-plugin-mmlabc.
- **Native + Browser Support**: In addition to CLI/library, a browser demo powered by WASM + web-tree-sitter.
- **Golden Corpus**: Tests based on JS version execution results are shared across both native and WASM paths.

## Architecture

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitter grammar definition + grammar WASM
├── chord2mml-core/      # Core conversion library in Rust
├── chord2mml-cli/       # Command Line Interface
├── chord2mml-wasm/      # WASM binding (no C dependency)
└── chord2mml-web/       # Browser demo (web-tree-sitter + Vite)
```

### Data Flow

This project follows patterns proven in [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json). The pipeline is a port of the 4-stage structure from the JS version.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser]  Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common:    CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Note: To avoid including tree-sitter's C dependency in the Rust WASM build, `chord2mml-core` is tree-sitter independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by spaces, " - ", "→", or "・・". Hyphen separation is also temporarily available.)
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

# WASM (verify build without C dependency)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (web-tree-sitter + Rust WASM executed in Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation test (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Approximately 100 tests from the JS version were used as the specification and ported in the following order (maintaining tests for both native and WASM paths in each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment revived
- [x] **Phase 1**: JS-compatible output format (`v11'c1eg'`) and 4-stage pipeline, basic chords
  - Major/minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width #♭, slash chords (bass notes), chord progressions
- [x] **Wave A**: Tensions (6, 9, 11, 13), 7sus variations, quartal (4.N), maj9 variations (`maj7,add9`)
- [x] **Wave B**: Modifiers (add, omit, ♭5, #5), minor chords with `-` notation (`C-`, `C-7`)
- [x] **Wave C**: On-chords (EonC), polychords (US), inversions (^N, 1st inv, etc.)
- [x] **Wave D**: Voicings (drop2/drop4/drop2and4/close/open triad), bass mode (bass is root), octave specification (octave up/down, `'/`)
- [x] **Wave E**: Measures and durations (`|`, `/ `), degree notation (Roman numerals/Arabic numerals), key/scale (modal scales, sharp/flat spellings)
- [x] **Wave F**: Inline MML/ABC, MIDI Program Change (GM instrument names PC000-127), Tempo (BPM/Tempo)
- [x] **Wave G**: Dialect preprocessing (support for LLM-generated chord progressions: hyphen dialect, lowercase Roman numerals, exhaustive conversion combinations)

**All waves completed**: The golden corpus of 324 cases (319 verified by JS + 5 Rust extensions) based on the JS version's test suite has passed across both native and WASM paths. Comparison with the JS version can be re-verified using `scripts/verify-corpus-vs-js.mjs`.

## Development Policy

### Differences from the Original chord2mml

| Item | chord2mml (Old) | chord2mml-rust (New) |
|------|---------------|-------------------|
| Parser | Peggy.js | Tree-sitter |
| Language | JavaScript/TypeScript | Rust |
| Runtime | Browser | Native (CLI) + Browser (WASM) |
| Output | `v11'c1eg'` format | Same (compatible) |

### Design Philosophy

1. **JS Version Tests as Specification**: Functionality is based on JS version tests (to prevent hallucinations).
2. **Path Consistency**: Both native and WASM paths use the same semantic code (`cst_to_ast`).
3. **Test-Driven**: Comprehensive verification using a golden corpus.

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

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Parsing library
- [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture description