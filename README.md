# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application for converting chord progressions to MML (Music Macro Language), written in Rust.

## Overview

This project is a rewrite of [chord2mml](https://github.com/cat2151/chord2mml) (originally built with Peggy.js + JavaScript) using Rust + Tree-sitter + WASM + TypeScript.

### Key Features

- **Rust + Tree-sitter**: Fast and robust parser core
- **Library Crate**: Usable directly from Rust native applications
- **WASM Support**: Runs in browsers
- **TypeScript Integration**: Web application support

## Demo

Try it: [https://cat2151.github.io/chord2mml-rust/](https://cat2151.github.io/chord2mml-rust/)

Enter "C" in the textarea → Converts to "c;e;g" → Plays C major chord (Do-Mi-So)

## Quick Start

### Web Application

1. Visit https://cat2151.github.io/chord2mml-rust/
2. Enter chord notation (e.g., `C`, `Dm`, `G7`)
3. It automatically converts to MML and plays the sound

### Rust Library

```rust
use chord2mml_core::convert;

fn main() {
    let chord = "C";
    let mml = convert(chord);
    println!("MML: {}", mml); // "c;e;g"
}
```

## Build

### Rust Library

```bash
cd chord2mml-core
cargo build --release
cargo test
```

### WASM

```bash
cd chord2mml-wasm
wasm-pack build --target web
```

### Web Application

```bash
cd chord2mml-web
npm install
npm run build
```

## License

MIT License

## Related Projects

- [chord2mml](https://github.com/cat2151/chord2mml) - Original JavaScript version
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - MML parser library
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library