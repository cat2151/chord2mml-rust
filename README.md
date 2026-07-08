# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application written in Rust that converts chord progressions into MML (Music Macro Language).

## Note
- WIP (Work In Progress)
- Frequent breaking changes
- We plan to proceed with AI-driven development to minimize user workload.
- We intend to develop an AI-driven automation system for this purpose (or rather, use this repository for developing such a system).
- The following content is largely AI-generated and likely to contain errors or diverge from the user's intent.

## Overview

This project is a re-implementation of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now rebuilt with **Rust + Tree-sitter**.

The **output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). We are gradually porting approximately 100 tests from the JS version as specifications (for ported cases, refer to the golden corpus in `chord2mml-core/tests/corpus/`).

### Key Features

- **Tree-sitter Parser**: Robust and accurate syntax parsing
- **JS Version Compatible Output**: MML format directly usable by tools like obsidian-plugin-mmlabc
- **Native + Browser Support**: CLI/library in addition to browser demo via WASM + web-tree-sitter
- **Golden Corpus**: Tests using the JS version's output as expected values, shared across both native and WASM paths

## Architecture

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitter grammar definition + grammar WASM
├── chord2mml-core/      # Rust core conversion library
├── chord2mml-cli/       # Command-line interface
├── chord2mml-wasm/      # WASM bindings (C-dependency free)
└── chord2mml-web/       # Browser demo (web-tree-sitter + Vite)
```

### Data Flow

This project follows the pattern established by [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json). The pipeline is a port of the JS version's four-stage structure.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser] Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common: CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Key point: To avoid including Tree-sitter's C dependencies in Rust's WASM build, `chord2mml-core` is tree-sitter-independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by space, " - ", →, or ・・. Hyphen separation also temporarily available)
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

# WASM (verify it can be built without C dependencies)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (web-tree-sitter + Rust WASM executed with Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation test (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Using the approximately 100 tests from the JS version as specifications, we will proceed with porting in the following order (maintaining both native and WASM path tests in each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment restored
- [x] **Phase 1**: JS-compatible output format (`v11'c1eg'`) and 4-stage pipeline, basic chords
  - Major/minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width sharps/flats, slash chords (bass notes), chord progressions
- [x] **Wave A**: Tensions (6, 9, 11, 13), 7sus types, quartal (4.N), maj9 types (`maj7,add9`)
- [x] **Wave B**: Modifications (add, omit, ♭5, #5), minor notation with `-` (`C-`, `C-7`)
- [x] **Wave C**: On-chords (EonC), polychords (US), inversions (^N, 1st inv etc.)
- [x] **Wave D**: Voicing (drop2/drop4/drop2and4/close/open triad), bass mode (bass is root), octave specification (octave up/down, `'`/`,`)
- [x] **Wave E**: Measures and note lengths (`|`, `/ `), degree notation (Roman numerals/Arabic numerals), keys/scales (church modes, sharp/flat spelling)
- [ ] **Wave F**: Inline MML/ABC, MIDI program change, tempo
- [ ] **Wave G**: Dialect pre-processing (support for LLM-generated chord progressions)

## Development Policy

### Differences from the original chord2mml

| Item | chord2mml (Old) | chord2mml-rust (New) |
|------|---------------|-------------------|
| Parser | Peggy.js | Tree-sitter |
| Language | JavaScript/TypeScript | Rust |
| Environment | Browser | Native (CLI) + Browser (WASM) |
| Output | `v11'c1eg'` format | Same (compatible) |

### Design Philosophy

1.  **JS version tests as specification**: Functionality is based on tests from the JS version (preventing hallucinations).
2.  **Consistency across paths**: Native and WASM execution paths use identical semantic code (`cst_to_ast`).
3.  **Test-driven**: Comprehensive verification via golden corpus.

## Build Requirements

- Rust 1.70 or later (C compiler also required for native builds)
- Node.js 20 or later (for browser demo and WASM path tests)
- Only when regenerating grammar WASM: tree-sitter-cli + docker or emscripten

## License

MIT License

## Related Projects

- [chord2mml](https://github.com/cat2151/chord2mml) - Original JavaScript version (source of specification)
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - Reference implementation for tree-sitter + WASM architecture
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library

## Contribution

Issues and Pull Requests are welcome.

## Author

cat2151

## References

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Syntax parsing library
- [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture explanation