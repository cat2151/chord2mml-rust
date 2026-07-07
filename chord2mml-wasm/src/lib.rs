//! WASM bindings for chord2mml-core.
//!
//! This crate builds for `wasm32-unknown-unknown` with chord2mml-core's
//! default features (no tree-sitter C dependency). Parsing happens in the
//! browser via web-tree-sitter (JavaScript) + tree-sitter-chord.wasm; the
//! resulting CST is passed here as JSON and converted to MML in Rust.
//! This follows the architecture proven in tonejs-mml-to-json.

use wasm_bindgen::prelude::*;

/// Convert a CST JSON (produced by web-tree-sitter) to MML.
///
/// # Example (JavaScript)
/// ```javascript
/// import init, { convert_cst } from './chord2mml_wasm.js';
///
/// await init();
/// const tree = parser.parse('C');           // web-tree-sitter
/// const cstJson = serializeCst(tree.rootNode);
/// const mml = convert_cst(JSON.stringify(cstJson));
/// console.log(mml); // "v11'c1eg'"
/// ```
#[wasm_bindgen]
pub fn convert_cst(cst_json: &str) -> Result<String, JsValue> {
    chord2mml_core::convert_cst(cst_json).map_err(|e| JsValue::from_str(&e.to_string()))
}

#[cfg(test)]
mod tests {
    use super::*;
    use wasm_bindgen_test::*;

    const C_MAJOR_CST: &str = r#"{
        "type": "source_file",
        "children": [
            {
                "type": "chord",
                "text": "C",
                "fields": {
                    "root": [{
                        "type": "root",
                        "text": "C",
                        "fields": { "note": [{ "type": "note", "text": "C" }] }
                    }]
                }
            }
        ]
    }"#;

    #[wasm_bindgen_test]
    fn test_convert_cst_c_major() {
        let result = convert_cst(C_MAJOR_CST).unwrap();
        assert_eq!(result, "v11'c1eg'");
    }

    #[wasm_bindgen_test]
    fn test_convert_cst_empty() {
        let result = convert_cst("");
        assert!(result.is_err());
    }
}
