# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application for converting chord progressions to MML (Music Macro Language), written in Rust.

## Notes
- WIP (Work In Progress)
- Frequent breaking changes may occur.
- This project aims for AI-driven development to minimize user effort.
- We plan to develop an AI-driven development system for this purpose (or rather, use this repository as a development platform for such a system).
- The content below is largely AI-generated and likely contains errors or information that may not align with user intent.

## Overview

This project is a complete rewrite of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now implemented using **Rust + Tree-sitter**.

The **output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). Approximately 100 tests from the JS version are being gradually ported as specifications (for ported cases, refer to the golden corpus in `chord2mml-core/tests/corpus/`).

### Key Features

-   **Tree-sitter Parser**: Robust and accurate syntax analysis.
-   **JS Version Compatible Output**: MML format directly usable by `obsidian-plugin-mmlabc` and similar tools.
-   **Native & Browser Support**: CLI/library functionality, plus a browser demo powered by WASM + web-tree-sitter.
-   **Golden Corpus**: Tests using expected values from the JS version's execution results are shared across both native and WASM paths.

## Architecture

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitter grammar definition + grammar WASM
├── chord2mml-core/      # Rust core conversion library
├── chord2mml-cli/       # Command Line Interface
├── chord2mml-wasm/      # WASM bindings (C-independent)
└── chord2mml-web/       # Browser demo (web-tree-sitter + Vite)
```

### Data Flow

This project follows the pattern established in [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json). The pipeline ports the four-stage structure of the JS version.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser] Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common: CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Key Point: To avoid including Tree-sitter's C dependencies in Rust's WASM build, `chord2mml-core` is Tree-sitter-independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by spaces, " - ", or "→"; hyphen separation is also temporarily available)
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

### Build & Test

```bash
# Entire workspace (native)
cargo test --workspace --all-features

# WASM (verify it can be built without C dependencies)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (web-tree-sitter + Rust WASM executed with Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation tests (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Using approximately 100 tests from the JS version as the specification, porting will proceed in the following order (maintaining native + WASM path tests in each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment restored
- [x] **Phase 1**: JS version compatible output format (`v11'c1eg'`) and 4-stage pipeline, basic chords
  - Major/minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width #♭, slash chords (bass notes), chord progressions
- [x] **Wave A**: Tensions (6, 9, 11, 13), 7sus family, quartal (4.N), maj9 family (`maj7,add9`)
- [x] **Wave B**: Modifiers (add, omit, ♭5, #5), `-` notation for minor (`C-`, `C-7`)
- [x] **Wave C**: On-chords (EonC), polychords (US), inversions (^N, 1st inv etc.)
- [x] **Wave D**: Voicings (drop2/drop4/drop2and4/close/open triad), bass mode (bass is root), octave specification (octave up/down, `'`/`,`)
- [ ] **Wave E**: Measures and note lengths (`|`, `/ `), roman numeral notation, key/scale
- [ ] **Wave F**: Inline MML/ABC, MIDI program change, tempo
- [ ] **Wave G**: Dialect preprocessing (support for LLM-generated chord progressions)

## Development Policy

### Differences from Original chord2mml

| Item | chord2mml (Old) | chord2mml-rust (New) |
|------|---------------|-------------------|
| Parser | Peggy.js | Tree-sitter |
| Language | JavaScript/TypeScript | Rust |
| Runtime | Browser | Native (CLI) + Browser (WASM) |
| Output | `v11'c1eg'` format | Same (Compatible) |

### Design Philosophy

1.  **JS Version Tests as Specification**: Functionality is based on the JS version's tests (to prevent hallucinations).
2.  **Consistency Across Paths**: Native and WASM paths share the same semantic code (`cst_to_ast`).
3.  **Test-Driven Development**: Comprehensive verification through a golden corpus.

## Build Requirements

-   Rust 1.70 or later (C compiler also required for native builds)
-   Node.js 20 or later (for browser demo and WASM path tests)
-   Only for regenerating grammar WASM: tree-sitter-cli + docker or emscripten

## License

MIT License

## Related Projects

-   [chord2mml](https://github.com/cat2151/chord2mml) - The original JavaScript version (source of specification)
-   [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - Reference implementation of tree-sitter + WASM architecture
-   [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library

## Contributing

Issues and Pull Requests are welcome.

## Author

cat2151

## Reference Links

-   [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Syntax parsing library
-   [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture explanation