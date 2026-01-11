import { defineConfig } from 'vite';

export default defineConfig({
  base: '/chord2mml-rust/',
  build: {
    outDir: 'dist',
    assetsDir: 'assets',
  },
  server: {
    port: 3000,
    open: true,
  },
});
