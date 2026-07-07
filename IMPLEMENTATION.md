# Implementation Summary

現在の実装状態のサマリ。詳細なロードマップは [README.ja.md](README.ja.md)、
エージェント向けの規約は [.github/copilot-instructions.md](.github/copilot-instructions.md) を参照。

## 方針（2026-07 再始動）

- **JS版 [chord2mml](https://github.com/cat2151/chord2mml) の約100テストが唯一の仕様**。出力形式もJS版互換（`C` → `v11'c1eg'`）
- 仕様は `chord2mml-core/tests/corpus/*.json` のゴールデンコーパスとして移植する。期待値はJS版を実際に実行して生成する
- WASMアーキテクチャは [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) の実証済みパターンに準拠（tree-sitterのC依存をRust WASMに含めない）

## パイプライン（JS版の4段構成を移植）

```
[ネイティブ] 入力 → tree-sitter Rustクレート (parser.rs, feature "tree-sitter") → CST JSON化
[ブラウザ]   入力 → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST JSON (cst-serializer.js)
共通:       CST JSON → cst_to_ast.rs → イベント配列AST → ast2ast.rs → ast2notes.rs → notes2mml.rs → MML
```

- `cst_to_ast.rs`: ルートを半音数値(C=0..B=11)へ解決、クオリティをJS版の正規化文字列（`maj`, `min7`, `dim triad` 等）へ変換
- `ast2ast.rs`: スラッシュコードのモード解決（デフォルト: chord over bass note）、小節→音長（小節なしは全音符=1）
- `ast2notes.rs`: クオリティ→音程テーブル（JS版 getNotesWithoutOmit の移植）、ベース音の上へのスタック
- `notes2mml.rs`: `v11` プレフィックス、`'...'` 囲み、`+`/`-`、`<`/`>`、音長数字（JS版 notesToMml の移植）

## 検証

```bash
cargo test --workspace --all-features                                   # ネイティブ（コーパス含む）
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release # WASM安全性
cd chord2mml-web && npm test                                            # WASM経路で同一コーパス
cd chord2mml-web && npm run build:web && npm run test:browser           # 実ブラウザ(headless Chromium)
```

## 実装済み / 未実装

- 実装済み: 基本コード（maj/min/maj7/min7/7/dim/aug/sus2/sus4）、全角半角#♭、分数コード、コード進行
- 未実装: README のロードマップ Wave A〜G を参照（テンション、add/omit、転回形、drop、小節、度数、キー/スケール等）
