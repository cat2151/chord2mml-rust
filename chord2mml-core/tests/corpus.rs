//! Golden-corpus test: runs every case in tests/corpus/*.json through the
//! native pipeline and compares with the expected output.
//!
//! The corpus is the spec, extracted from the original JS chord2mml's test
//! suite and verified by executing the JS implementation (see the restart
//! plan). The same corpus is run through the WASM path by
//! chord2mml-web/test/wasm-path-test.mjs.

use serde::Deserialize;

#[derive(Deserialize)]
struct Case {
    input: String,
    expected: String,
}

#[test]
fn basic_corpus() {
    let corpus_json = include_str!("corpus/basic.json");
    let cases: Vec<Case> = serde_json::from_str(corpus_json).expect("corpus JSON");

    let mut failures = Vec::new();
    for case in &cases {
        match chord2mml_core::convert(&case.input) {
            Ok(actual) => {
                if actual != case.expected {
                    failures.push(format!(
                        "{:?}: expected {:?}, got {:?}",
                        case.input, case.expected, actual
                    ));
                }
            }
            Err(e) => failures.push(format!("{:?}: error {}", case.input, e)),
        }
    }

    assert!(
        failures.is_empty(),
        "{} corpus case(s) failed:\n{}",
        failures.len(),
        failures.join("\n")
    );
}
