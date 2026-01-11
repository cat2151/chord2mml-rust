import { defineConfig } from 'vite';

export default defineConfig({
  base: process.env.VITE_BASE_PATH || '/',
  build: {
    outDir: 'dist',
    assetsDir: 'assets',
  },
  server: {
    port: 3000,
    open: false,
    fs: {
      allow: ['..']
    }
  },
  optimizeDeps: {
    exclude: ['tonejs-mml-to-json']
  }
});
