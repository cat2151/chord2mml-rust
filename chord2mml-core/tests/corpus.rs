//! Golden-corpus test: runs every case in tests/corpus/*.json through the
//! native pipeline and compares with the expected output.
//!
//! The corpus is the spec, extracted from the original JS chord2mml's test
//! suite and verified by executing the JS implementation (see the restart
//! plan). The same corpus is run through the WASM path by
//! chord2mml-web/test/wasm-path-test.mjs.

use serde::Deserialize;
use std::path::Path;

#[derive(Deserialize)]
struct Case {
    input: String,
    expected: String,
}

#[test]
fn corpus() {
    let corpus_dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("tests/corpus");
    let mut failures = Vec::new();
    let mut total = 0;
    let mut file_count = 0;

    let mut entries: Vec<_> = std::fs::read_dir(&corpus_dir)
        .expect("corpus dir")
        .filter_map(|e| e.ok())
        .map(|e| e.path())
        .filter(|p| p.extension().is_some_and(|ext| ext == "json"))
        .collect();
    entries.sort();

    for path in entries {
        file_count += 1;
        let name = path.file_name().unwrap().to_string_lossy().to_string();
        let corpus_json = std::fs::read_to_string(&path).expect("corpus file");
        let cases: Vec<Case> = serde_json::from_str(&corpus_json)
            .unwrap_or_else(|e| panic!("{}: invalid corpus JSON: {}", name, e));

        for case in &cases {
            total += 1;
            match chord2mml_core::convert(&case.input) {
                Ok(actual) => {
                    if actual != case.expected {
                        failures.push(format!(
                            "[{}] {:?}: expected {:?}, got {:?}",
                            name, case.input, case.expected, actual
                        ));
                    }
                }
                Err(e) => failures.push(format!("[{}] {:?}: error {}", name, case.input, e)),
            }
        }
    }

    assert!(file_count > 0, "no corpus files found in {:?}", corpus_dir);
    assert!(
        failures.is_empty(),
        "{} of {} corpus case(s) failed:\n{}",
        failures.len(),
        total,
        failures.join("\n")
    );
    println!("all {} corpus cases passed ({} files)", total, file_count);
}
