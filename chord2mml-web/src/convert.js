// Shared conversion with dialect-preprocess retry, used by the web app
// and the Node WASM-path test. Mirrors the JS chord2mml.parse contract:
// try the input as written, then every dialect rewrite (candidates come
// from the Rust preprocess_candidates), and report the first candidate's
// error if nothing converts.
import { nodeToCSTJson } from './cst-serializer.js';

export function convertWithPreprocess(parser, wasm, input) {
  const candidates = JSON.parse(wasm.preprocess_candidates(input));
  let firstError = null;

  for (const candidate of candidates) {
    const tree = parser.parse(candidate);
    if (!tree || tree.rootNode.hasError) {
      firstError ??= new Error(`コード表記を解釈できません: ${candidate}`);
      continue;
    }
    try {
      return wasm.convert_cst(JSON.stringify(nodeToCSTJson(tree.rootNode)));
    } catch (e) {
      firstError ??= e instanceof Error ? e : new Error(String(e));
    }
  }

  throw firstError ?? new Error('入力が空です');
}
