# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application that converts chord progressions into MML (Music Macro Language). Written in Rust.

## Note
- WIP
- Frequent breaking changes
- Proceeding with AI automation to minimize user workload
- Intending to develop an AI automation system for this purpose (or rather, using this repository for the development of an AI automation system)
- The following content is mostly AI-generated, highly likely to contain errors, and may not align with user intent.

## Overview

This project is a complete rewrite of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now reimplemented as **Rust + Tree-sitter**.

The **output is compatible with the JS version** (e.g., `C` → `v11'c1eg'`). Approximately 100 tests from the JS version are being gradually ported as specifications (refer to the golden corpus in `chord2mml-core/tests/corpus/` for ported cases).

### Key Features

- **Tree-sitter Parser**: Robust and precise syntax parsing
- **JS Version Compatible Output**: MML format directly usable by tools like obsidian-plugin-mmlabc
- **Native + Browser Support**: In addition to CLI/library, includes a browser demo using WASM + web-tree-sitter
- **Golden Corpus**: Tests that use the JS version's output as expected values, shared across both native and WASM paths

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

This follows the proven pattern from [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json). The pipeline is a port of the JS version's 4-stage structure.

```
[Native] Input → tree-sitter Rust crate → CST
[Browser]   Input → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
Common:       CST → cst_to_ast → Event Array AST → ast2ast → ast2notes → notes2mml → MML
```

Key point: To avoid including tree-sitter's C dependency in the Rust WASM build, `chord2mml-core` is tree-sitter independent by default (the `tree-sitter` feature is enabled by the CLI).

## Demo

### Browser

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLI Tool

```bash
# Single chord
$ chord2mml "C"
v11'c1eg'

# Chord progression (separated by spaces, " - ", or " → ". Hyphen separation is also temporarily available.)
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
# Whole workspace (native)
cargo test --workspace --all-features

# WASM (verify build without C dependency)
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# Browser path tests (run web-tree-sitter + Rust WASM with Node)
cd chord2mml-web && npm install && npm run build:wasm && npm test

# Browser actual operation tests (headless Chromium)
cd chord2mml-web && npm run build:web && npm run test:browser
```

## Roadmap

Using approximately 100 tests from the JS version as specifications, porting will proceed in the following order (maintaining tests for both native and WASM paths in each wave).

- [x] **Phase 0**: WASM-safe architecture + CI + Pages deployment restored
- [x] **Phase 1**: JS version compatible output format (`v11'c1eg'`), 4-stage pipeline, basic chords
  - Major/Minor/maj7/min7/7/dim/aug/sus2/sus4, full-width/half-width #♭, slash chords (bass note), chord progressions
- [x] **Wave A**: Tensions (6, 9, 11, 13), 7sus family, Quartal (4.N), maj9 family (`maj7,add9`)
- [ ] **Wave B**: Modifiers (add, omit, ♭5, #5), minor notation with `-` (`C-7`)
- [ ] **Wave C**: On-chords (EonC), Polychords (US), Inversions (^N, 1st inv, etc.)
- [ ] **Wave D**: Voicings (drop2, etc.), Bass mode, Octave specification
- [ ] **Wave E**: Bars and note lengths (`|`, `/ `), Degree notation, Key/Scale
- [ ] **Wave F**: Inline MML/ABC, MIDI program change, Tempo
- [ ] **Wave G**: Dialect preprocessing (support for LLM-generated chord progressions)

## Development Policy

### Differences from the original chord2mml

| Item               | chord2mml (Old)     | chord2mml-rust (New)     |
|--------------------|---------------------|--------------------------|
| Parser             | Peggy.js            | Tree-sitter              |
| Language           | JavaScript/TypeScript | Rust                     |
| Runtime Environment| Browser             | Native (CLI) + Browser (WASM) |
| Output             | `v11'c1eg'` format | Same (compatible)        |

### Design Philosophy

1. **JS Version Tests as Specification**: Functionality is based on JS version tests (to prevent hallucinations)
2. **Consistent Paths**: Native and WASM share the same semantic code (cst_to_ast)
3. **Test-Driven**: Comprehensive validation using golden corpus

## Build Requirements

- Rust 1.70 or later (C compiler also required for native builds)
- Node.js 20 or later (for browser demo and WASM path testing)
- Only for grammar WASM regeneration: tree-sitter-cli + docker or emscripten

## License

MIT License

## Related Projects

- [chord2mml](https://github.com/cat2151/chord2mml) - Original JavaScript version (source of specification)
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - Reference implementation for tree-sitter + WASM architecture
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library

## Contributing

Issues and Pull Requests are welcome.

## Author

cat2151

## Reference Links

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - Syntax parsing library
- [EXAMPLES.md](EXAMPLES.md) - More detailed usage examples and architecture explanation