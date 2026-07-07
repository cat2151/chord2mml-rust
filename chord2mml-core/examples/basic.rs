use chord2mml_core::convert;

fn main() {
    println!("=== chord2mml-rust Basic Examples ===\n");

    // Example 1: Single chord
    println!("Example 1: Single C major chord");
    let result = convert("C").unwrap();
    println!("  Input:  C");
    println!("  Output: {}\n", result); // v11'c1eg'

    // Example 2: Chord progression (whitespace-separated, JS spec)
    println!("Example 2: Chord progression");
    let result = convert("Dm G7 C").unwrap();
    println!("  Input:  Dm G7 C");
    println!("  Output: {}\n", result); // v11'd1fa''g1b<df''c1eg'

    // Example 3: Qualities
    println!("Example 3: Chord qualities");
    for chord in &["Cm", "Cmaj7", "Cm7", "C7", "Csus4", "Cdim", "Caug"] {
        let result = convert(chord).unwrap();
        println!("  {} -> {}", chord, result);
    }
    println!();

    // Example 4: Slash chord (chord over bass note)
    println!("Example 4: Slash chord");
    let result = convert("F/C").unwrap();
    println!("  Input:  F/C");
    println!("  Output: {}\n", result); // v11'>c1fa<c'

    // Example 5: Error handling
    println!("Example 5: Error handling");
    println!("  Input:  InvalidChord");
    match convert("InvalidChord") {
        Ok(mml) => println!("  Output: {}", mml),
        Err(e) => println!("  Error:  {}\n", e),
    }

    // Example 6: All natural major chords
    println!("Example 6: All natural major chords");
    for chord in &["C", "D", "E", "F", "G", "A", "B"] {
        let result = convert(chord).unwrap();
        println!("  {} -> {}", chord, result);
    }
}
