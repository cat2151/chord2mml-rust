use chord2mml_core::convert;

fn main() {
    println!("=== chord2mml-rust Basic Examples ===\n");
    
    // Example 1: Single chord
    println!("Example 1: Single C major chord");
    let result = convert("C").unwrap();
    println!("  Input:  C");
    println!("  Output: {}\n", result);
    
    // Example 2: Chord progression
    println!("Example 2: Chord progression");
    let result = convert("C-F-G-C").unwrap();
    println!("  Input:  C-F-G-C");
    println!("  Output: {}\n", result);
    
    // Example 3: Minor chord
    println!("Example 3: D minor chord");
    let result = convert("Dm").unwrap();
    println!("  Input:  Dm");
    println!("  Output: {}\n", result);
    
    // Example 4: Mixed major/minor progression
    println!("Example 4: Mixed major/minor progression");
    let result = convert("C-Dm-G-C").unwrap();
    println!("  Input:  C-Dm-G-C");
    println!("  Output: {}\n", result);
    
    // Example 5: Error handling
    println!("Example 5: Error handling");
    println!("  Input:  InvalidChord");
    match convert("InvalidChord") {
        Ok(mml) => println!("  Output: {}", mml),
        Err(e) => println!("  Error:  {}\n", e),
    }
    
    // Example 6: All major chords
    println!("Example 6: All natural major chords");
    for chord in &["C", "D", "E", "F", "G", "A", "B"] {
        let result = convert(chord).unwrap();
        println!("  {} -> {}", chord, result);
    }
}
