// Browser end-to-end test: serves the built dist/ and drives the page in
// headless Chromium, verifying the full in-browser pipeline
// (web-tree-sitter + chord2mml-wasm) actually renders MML output.
// Prerequisites: npm run build:web (and public/wasm built via build:wasm).
import { createServer } from 'http';
import { readFile } from 'fs/promises';
import { existsSync } from 'fs';
import { join, dirname, extname } from 'path';
import { fileURLToPath } from 'url';
import { chromium } from 'playwright';

const distDir = join(dirname(fileURLToPath(import.meta.url)), '..', 'dist');
// Optionally serve dist under a URL prefix (e.g. BASE_PATH=/chord2mml-rust/)
// to verify a build made with the matching VITE_BASE_PATH.
const basePath = process.env.BASE_PATH ?? '/';

if (!existsSync(join(distDir, 'index.html'))) {
  console.error('✗ dist/index.html not found. Run: npm run build:web');
  process.exit(1);
}

const mime = {
  '.html': 'text/html',
  '.js': 'text/javascript',
  '.mjs': 'text/javascript',
  '.css': 'text/css',
  '.wasm': 'application/wasm',
  '.json': 'application/json',
};

const server = createServer(async (req, res) => {
  let urlPath = decodeURIComponent(new URL(req.url, 'http://localhost').pathname);
  if (urlPath.startsWith(basePath)) {
    urlPath = '/' + urlPath.slice(basePath.length);
  }
  const filePath = join(distDir, urlPath === '/' ? 'index.html' : urlPath.slice(1));
  try {
    const data = await readFile(filePath);
    res.writeHead(200, { 'Content-Type': mime[extname(filePath)] ?? 'application/octet-stream' });
    res.end(data);
  } catch {
    res.writeHead(404);
    res.end('not found');
  }
});

await new Promise((resolve) => server.listen(0, resolve));
const port = server.address().port;

let failed = 0;
const browser = await chromium.launch();
try {
  const page = await browser.newPage();
  page.on('console', (msg) => {
    if (msg.type() === 'error') console.error(`  [browser console] ${msg.text()}`);
  });
  await page.goto(`http://localhost:${port}${basePath}`);

  // Initial value "C" converts automatically after init
  await page.waitForFunction(
    () => document.getElementById('output')?.textContent?.includes("'"),
    null,
    { timeout: 15000 }
  );
  const initial = await page.locator('#output').textContent();
  if (initial === "v11'c1eg'") {
    console.log(`✓ initial C -> ${initial}`);
  } else {
    console.error(`✗ initial C: expected v11'c1eg', got ${initial}`);
    failed++;
  }

  // Type progressions (JS-spec whitespace separator and legacy hyphen)
  const progressions = [
    ['Dm G7 C', "v11'd1fa''g1b<df''c1eg'", 'd1fa'],
    ['C-F-G-C', "v11'c1eg''f1a<c''g1b<d''c1eg'", 'f1a'],
  ];
  for (const [input, expected, marker] of progressions) {
    await page.locator('#chordInput').fill(input);
    await page.waitForFunction(
      (m) => document.getElementById('output')?.textContent?.includes(m),
      marker,
      { timeout: 5000 }
    );
    const actual = await page.locator('#output').textContent();
    if (actual === expected) {
      console.log(`✓ ${input} -> ${actual}`);
    } else {
      console.error(`✗ ${input}: expected ${expected}, got ${actual}`);
      failed++;
    }
  }
} catch (e) {
  console.error('✗ browser test error:', e);
  failed++;
} finally {
  await browser.close();
  server.close();
}

if (failed > 0) {
  console.error(`${failed} browser test(s) failed`);
  process.exit(1);
}
console.log('All browser tests passed');
