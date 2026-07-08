// End-to-end test of the WASM path without a browser:
//   input → web-tree-sitter (Node) + tree-sitter-chord.wasm → CST JSON
//         → chord2mml-wasm convert_cst (Rust WASM) → MML
// This is the same pipeline the browser runs, so it verifies the full
// WASM-safe architecture (tonejs-mml-to-json pattern).
//
// Runs the same golden corpus as the native test
// (chord2mml-core/tests/corpus/*.json), guaranteeing both paths agree.
import { readFile, readdir } from 'fs/promises';
import { fileURLToPath } from 'url';
import { Parser, Language } from 'web-tree-sitter';
import init, { convert_cst, preprocess_candidates } from '../public/wasm/chord2mml_wasm.js';
import { convertWithPreprocess } from '../src/convert.js';

const corpusDir = new URL('../../chord2mml-core/tests/corpus/', import.meta.url);
const corpusFiles = (await readdir(corpusDir)).filter((f) => f.endsWith('.json')).sort();
if (corpusFiles.length === 0) {
  console.error('✗ no corpus files found');
  process.exit(1);
}
const cases = [];
for (const file of corpusFiles) {
  cases.push(...JSON.parse(await readFile(new URL(file, corpusDir), 'utf8')));
}

async function main() {
  // Initialize the Rust WASM module from bytes (no fetch in Node)
  const wasmBytes = await readFile(
    new URL('../public/wasm/chord2mml_wasm_bg.wasm', import.meta.url)
  );
  await init({ module_or_path: wasmBytes });

  // Initialize web-tree-sitter and the chord grammar
  await Parser.init();
  const language = await Language.load(
    fileURLToPath(new URL('../public/tree-sitter-chord.wasm', import.meta.url))
  );
  const parser = new Parser();
  parser.setLanguage(language);

  let failed = 0;
  let passed = 0;
  const wasm = { convert_cst, preprocess_candidates };
  for (const { input, expected } of cases) {
    let actual;
    try {
      actual = convertWithPreprocess(parser, wasm, input);
    } catch (e) {
      console.error(`✗ ${input}: ${e}`);
      failed++;
      continue;
    }
    if (actual === expected) {
      passed++;
    } else {
      console.error(`✗ ${input}: expected ${expected}, got ${actual}`);
      failed++;
    }
  }

  if (failed > 0) {
    console.error(`${failed} of ${failed + passed} corpus case(s) failed on the WASM path`);
    process.exit(1);
  }
  console.log(`All ${passed} corpus cases passed on the WASM path`);
}

main().catch((e) => {
  console.error(e);
  process.exit(1);
});
