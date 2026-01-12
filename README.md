# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

A library and application for converting chord progressions to MML (Music Macro Language). Written in Rust.

## Note
- WIP
- Frequent breaking changes
- Intended to progress with AI automation, minimizing user workload
- Planning to develop an AI autonomous development system for this purpose (or rather, using this repository for the development of such a system)
- The following content is mostly AI-generated and likely contains errors or deviates from the user's intent.

## Overview

This project is a complete re-implementation of [chord2mml](https://github.com/cat2151/chord2mml), which was originally built with Peggy.js + JavaScript, now rebuilt using Rust + WASM + TypeScript.

### Key Features

- **Rust Parser Core**: A simple and fast string-matching parser (with plans to migrate to a Tree-sitter base in the future)
- **Library Crate**: Directly usable from native Rust applications
- **WASM Support**: Operates in browsers
- **TypeScript Integration**: For use as a web application

## Architecture

```
chord2mml-rust/
├── chord2mml-core/     # Rust conversion core library
├── chord2mml-wasm/     # WASM bindings
└── chord2mml-web/      # TypeScript + Web application
```

### Components

1. **chord2mml-core**: A Rust library that parses chord progressions and converts them to MML.
   - Simple string-matching for parsing (Tree-sitter planned for Phase 3)
   - Usable from native applications

2. **chord2mml-wasm**: WASM Bindings
   - Compiles the Rust Core to WebAssembly
   - Provides an interface for calling from JavaScript

3. **chord2mml-web**: Browser Application
   - Implemented in TypeScript
   - Direct audio playback using the Web Audio API (integration with tonejs-like libraries planned for Phase 2 and beyond)
   - Input chord progressions in a textarea for real-time conversion and playback

## Demo

In the web application, entering "C" into the textarea converts it to "c;e;g", and a C major triad (C E G) is played.

Try it out: [https://cat2151.github.io/chord2mml-rust/](https://cat2151.github.io/chord2mml-rust/)

## Usage

### Web Application

1. Open https://cat2151.github.io/chord2mml-rust/ in your browser.
2. Enter a chord progression into the textarea (e.g., `C`, `Dm`, `G7`).
3. It will automatically convert to MML and play the sound.

### As a Rust Library

```rust
use chord2mml_core::convert;

fn main() {
    let chord = "C";
    let mml = convert(chord);
    println!("MML: {}", mml); // "c;e;g"
}
```

### How to Build

#### Rust Library

```bash
cd chord2mml-core
cargo build --release
cargo test
```

#### WASM

```bash
cd chord2mml-wasm
wasm-pack build --target web
```

#### Web Application

```bash
cd chord2mml-web
npm install
npm run build
npm run dev  # Start development server
```

## Roadmap

### Phase 1: Basic Feature Implementation ✅

- [x] Project structure setup
- [x] Basic chord conversion functionality (C → c;e;g)
- [x] WASM bindings
- [x] Basic web application features
- [x] Basic audio playback using the Web Audio API

### Phase 2: Porting Original chord2mml Tests

Port tests from the original [chord2mml](https://github.com/cat2151/chord2mml) repository and comprehensively support the following chords:

**Current Implementation Status**: Major and minor chords are fully implemented. Other chord types are only recognized by the parser, but MML conversion is not yet implemented.

#### Major Chords
- [x] C (C E G)
- [ ] C6 (C E G A)
- [ ] CM7, Cmaj7 (C E G B) ※Parser only, MML conversion not implemented
- [ ] Cadd9 (C E G D)
- [ ] C69 (C E G A D)

#### Minor Chords
- [x] Cm (C Eb G)
- [ ] Cm6 (C Eb G A)
- [ ] Cm7 (C Eb G Bb)
- [ ] CmM7, Cm(maj7) (C Eb G B)
- [ ] Cm7-5, Cm7(♭5) (C Eb Gb Bb)

#### Seventh Chords
- [ ] C7 (C E G Bb) ※Parser only, MML conversion not implemented
- [ ] C7sus4 (C F G Bb)
- [ ] C7-5, C7(♭5) (C E Gb Bb)
- [ ] C7+5, C7(#5), Caug7 (C E G# Bb)
- [ ] C7-9, C7(♭9) (C E G Bb Db)
- [ ] C7+9, C7(#9) (C E G Bb D#)

#### Diminished & Augmented Chords
- [ ] Cdim, Cdim7 (C Eb Gb A) ※Parser only, MML conversion not implemented
- [ ] Caug, C+, C(#5) (C E G#) ※Parser only, MML conversion not implemented

#### Suspended Chords
- [ ] Csus4 (C F G) ※Parser only, MML conversion not implemented
- [ ] Csus2 (C D G) ※Parser only, MML conversion not implemented

#### Inversions and Bass Designations
- [ ] C/E (First Inversion: E G C) ※Parser only, MML conversion not implemented
- [ ] C/G (Second Inversion: G C E) ※Parser only, MML conversion not implemented
- [ ] C/D (On-chord: D C E G) ※Parser only, MML conversion not implemented

#### Other Chords
- [ ] 9th, 11th, 13th Chords
- [ ] Tension notes
- [ ] Complex combinations of accidentals

#### Feature Enhancements
- [ ] Octave specification
- [ ] Rhythm and note length specification
- [x] Continuous input of multiple chords (chord progressions)
- [ ] Automatic generation of chord progression patterns

### Phase 3: Advanced Features

- [ ] Support for more complex chord progressions
- [ ] Integration of Tree-sitter and grammar implementation
- [ ] Integration of tonejs-mml-to-json and tonejs-json-sequencer
- [ ] Performance improvements
- [ ] Enhanced error handling
- [ ] Documentation improvements

## Development Policy

### Differences from the Original chord2mml

| Item | chord2mml (Old) | chord2mml-rust (New) |
|------|---------------|--------------------|
| Parser | Peggy.js | String matching (Tree-sitter planned for future) |
| Language | JavaScript/TypeScript | Rust + TypeScript |
| Runtime Environment | Browser-only | Native + WASM |
| Library Usage | Difficult | Easy (Rust crate) |

### Design Philosophy

1. **Simplicity**: Avoiding complexity and prioritizing maintainability.
2. **Type Safety**: Leveraging Rust's strong type system.
3. **Test-Driven**: Comprehensive test coverage.
4. **Performance**: Conversion optimized for Rust's high speed.

## Target Platforms

- **Rust Library**: All Rust-supported environments
- **WASM**: Modern browsers (Chrome, Firefox, Safari, Edge)
- **Web App**: Modern browsers

## Technology Stack

- **Rust**: 1.70 or later
- **wasm-pack**: WASM build tool
- **TypeScript**: Web application
- **Web Audio API**: Audio playback

### Planned Future Integrations

- **Tree-sitter**: For more robust parsing (Phase 3)
- **tonejs-mml-to-json**: Advanced MML parsing (Phase 3)
- **tonejs-json-sequencer**: More feature-rich audio playback (Phase 3)

## Testing

```bash
# Rust core tests
cd chord2mml-core
cargo test

# WASM integration tests
cd chord2mml-wasm
wasm-pack test --node

# Web app tests
cd chord2mml-web
npm test
```

## Build Requirements

- Rust 1.70 or later
- Node.js 18 or later
- wasm-pack

## License

MIT License

## Related Projects

- [chord2mml](https://github.com/cat2151/chord2mml) - Original JavaScript version
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - MML parsing library
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - Audio playback library

## Contributing

Issues and Pull Requests are welcome.

## Author

cat2151

## Reference Links

- [Project Page](https://cat2151.github.io/chord2mml-rust/)
- [Original chord2mml Demo](https://cat2151.github.io/chord2mml/dist/)