use anyhow::Result;
use chord2mml_core::convert;
use std::env;
use std::io::{self, BufRead};

fn main() -> Result<()> {
    let args: Vec<String> = env::args().collect();

    if args.len() > 1 {
        // Process command-line arguments
        let input = args[1..].join(" ");
        process_input(&input)?;
    } else {
        // Read from stdin
        println!("chord2mml - Convert chord notation to MML");
        println!("Enter chord notation (e.g., 'C' or 'C-F-G-C'):");
        println!("Press Ctrl+D (Unix) or Ctrl+Z (Windows) to exit\n");

        let stdin = io::stdin();
        for line in stdin.lock().lines() {
            let line = line?;
            if !line.trim().is_empty() {
                process_input(&line)?;
            }
        }
    }

    Ok(())
}

fn process_input(input: &str) -> Result<()> {
    match convert(input) {
        Ok(mml) => {
            println!("{}", mml);
            Ok(())
        }
        Err(e) => {
            eprintln!("Error: {}", e);
            std::process::exit(1);
        }
    }
}
