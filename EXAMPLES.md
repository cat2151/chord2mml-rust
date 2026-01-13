# chord2mml-rust Examples

This directory contains examples demonstrating the chord2mml-rust library and CLI.

## Basic Examples

### Single Chord Conversion

```bash
# Convert a single C major chord
chord2mml "C"
# Output: 'c;e;g'
```

### Chord Progression

```bash
# Convert a chord progression
chord2mml "C-F-G-C"
# Output: 'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'
```

### Minor Chords

```bash
# D minor chord
chord2mml "Dm"
# Output: 'd;f;a'

# Chord progression with minor chords
chord2mml "C-Dm-G-C"
# Output: 'c;e;g' 'd;f;a' 'g;b;d' 'c;e;g'
```

## Using as a Library

Create a file `examples/basic.rs`:

```rust
use chord2mml_core::convert;

fn main() {
    // Convert a single chord
    let mml = convert("C").unwrap();
    println!("C major: {}", mml);
    // Output: C major: 'c;e;g'
    
    // Convert a chord progression
    let progression = convert("C-F-G-C").unwrap();
    println!("Progression: {}", progression);
    // Output: Progression: 'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'
    
    // Handle errors
    match convert("InvalidChord") {
        Ok(mml) => println!("Result: {}", mml),
        Err(e) => eprintln!("Error: {}", e),
    }
}
```

Run with:
```bash
cd chord2mml-core
cargo run --example basic
```

## Pipeline Examples

### Process Multiple Lines

```bash
# Create a file with chord progressions
cat > chords.txt << EOF
C
C-F-G-C
Dm-G-C
EOF

# Convert all progressions
cat chords.txt | while read line; do
    chord2mml "$line"
done
```

### Filter and Convert

```bash
# Only convert lines that don't start with #
grep -v "^#" chords.txt | while read line; do
    chord2mml "$line"
done
```

## Architecture: Tree-sitter Flow

The conversion process follows this flow:

```
Input Text
    ↓
Tree-sitter Parser (grammar.js)
    ↓
CST (Concrete Syntax Tree)
    ↓
AST Converter (parse_chord_node)
    ↓
AST (Abstract Syntax Tree)
    ↓
MML Generator (ast_to_mml)
    ↓
Output MML
```

### Example Flow

For input `"C-F-G"`:

1. **Tree-sitter parsing** creates CST:
   ```
   chord_progression
     ├── chord (C)
     ├── chord (F)
     └── chord (G)
   ```

2. **AST conversion** creates:
   ```rust
   ASTRoot::ChordProgression([
       ASTChord { root: "C", quality: Major, ... },
       ASTChord { root: "F", quality: Major, ... },
       ASTChord { root: "G", quality: Major, ... },
   ])
   ```

3. **MML generation** produces:
   ```
   'c;e;g' 'f;a;c' 'g;b;d'
   ```

## More Examples

See the `tests` directory in `chord2mml-core/src/lib.rs` for more examples.
