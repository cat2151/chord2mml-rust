#!/usr/bin/env node
// Copy the committed tree-sitter-chord grammar WASM into public/ so Vite
// serves it at the site root (tonejs-mml-to-json pattern: the grammar wasm
// is built once with tree-sitter-cli and committed, not built per-deploy).
import { mkdirSync, copyFileSync, existsSync } from 'fs';
import { dirname, join } from 'path';
import { fileURLToPath } from 'url';

const __dirname = dirname(fileURLToPath(import.meta.url));
const webRoot = join(__dirname, '..');
const repoRoot = join(webRoot, '..');

const grammarWasm = join(repoRoot, 'tree-sitter-chord', 'tree-sitter-chord.wasm');
if (!existsSync(grammarWasm)) {
  console.error('✗ tree-sitter-chord.wasm not found.');
  console.error(`  Expected at: ${grammarWasm}`);
  console.error('  Build it with: npx tree-sitter-cli@0.20.8 build-wasm (in tree-sitter-chord/)');
  process.exit(1);
}

mkdirSync(join(webRoot, 'public'), { recursive: true });
copyFileSync(grammarWasm, join(webRoot, 'public', 'tree-sitter-chord.wasm'));
console.log('✓ Copied tree-sitter-chord.wasm to public/');
