use wasm_bindgen::prelude::*;

/// Convert a chord notation to MML (Music Macro Language) format
/// This is the WASM-exposed function that can be called from JavaScript
///
/// # Example (JavaScript)
/// ```javascript
/// import init, { convert_chord } from './chord2mml_wasm.js';
/// 
/// await init();
/// const mml = convert_chord('C');
/// console.log(mml); // "c;e;g"
/// ```
#[wasm_bindgen]
pub fn convert_chord(chord: &str) -> Result<String, JsValue> {
    // Enable better error messages in debug mode
    #[cfg(feature = "console_error_panic_hook")]
    console_error_panic_hook::set_once();

    chord2mml_core::convert(chord)
        .map_err(|e| JsValue::from_str(&e.to_string()))
}

/// Initialize the WASM module (called automatically by wasm-bindgen)
#[wasm_bindgen(start)]
pub fn start() {
    // Set up panic hook for better error messages in the browser console
    #[cfg(feature = "console_error_panic_hook")]
    console_error_panic_hook::set_once();
}

#[cfg(test)]
mod tests {
    use super::*;
    use wasm_bindgen_test::*;

    #[wasm_bindgen_test]
    fn test_convert_chord_c_major() {
        let result = convert_chord("C").unwrap();
        assert_eq!(result, "c;e;g");
    }

    #[wasm_bindgen_test]
    fn test_convert_chord_empty() {
        let result = convert_chord("");
        assert!(result.is_err());
    }
}
