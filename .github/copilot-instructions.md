# Copilot Instructions for chord2mml-rust

## Project Overview

コード進行（例: `C-F-G-C`）をMML（Music Macro Language）形式（例: `'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'`）に変換するRustライブラリ・CLIツール。

## Architecture

```
tree-sitter-chord/   → Tree-sitter文法定義 (grammar.js)
chord2mml-core/      → 変換コアライブラリ
chord2mml-cli/       → CLIツール
chord2mml-wasm/      → WASM用ラッパー（未完成）
```

### Data Flow (重要)
```
入力 → Tree-sitter Parser → CST → parser.rs → AST → mml.rs → MML出力
```

各モジュールの責務:
- [ast.rs](../chord2mml-core/src/ast.rs): `ASTChord`, `ChordQuality`などの型定義
- [parser.rs](../chord2mml-core/src/parser.rs): Tree-sitter CST → AST変換
- [mml.rs](../chord2mml-core/src/mml.rs): AST → MML文字列生成
- [note.rs](../chord2mml-core/src/note.rs): 音符の変換・転調ロジック

## Build & Test Commands

```bash
# ワークスペース全体のビルド・テスト
cargo build --all --release
cargo test --all

# コアライブラリのみ
cd chord2mml-core && cargo test

# 例の実行
cd chord2mml-core && cargo run --example basic

# CLI実行
cargo run -p chord2mml-cli -- "C-F-G-C"
```

## Key Conventions

### コード追加時のパターン
新しいコードタイプ（例: `Csus4`）を追加する場合:
1. [grammar.js](../tree-sitter-chord/grammar.js) の `quality` に追加（必要なら）
2. [parser.rs](../chord2mml-core/src/parser.rs) の `parse_chord_quality`/`parse_quality_text` に対応追加
3. [mml.rs](../chord2mml-core/src/mml.rs) の `chord_to_mml` にMML生成ロジック追加
4. テストを追加

### MML出力形式
- 単一コード: `'c;e;g'`（シングルクォートで囲み、セミコロン区切り）
- コード進行: `'c;e;g' 'f;a;c'`（スペース区切り）
- シャープ: `c+`, フラット: `c-`

### テストの書き方
```rust
#[test]
fn test_convert_c_major() {
    let result = convert("C").unwrap();
    assert_eq!(result, "'c;e;g'");
}
```

## Current Implementation Status

**実装済み**: Major, Minor コードのみ  
**パーサーのみ対応（MML変換未実装）**: 7, maj7, dim, aug, sus4, sus2, スラッシュコード

## Important Notes

- **AIコード生成プロジェクト**: このリポジトリはAI自動運転の実験場。READMEにはハルシネーション由来の記述が含まれる可能性あり
- **ハイフンはコード区切り専用**: コード進行の区切りにのみハイフン使用（`C-F-G-C`）
- **Windows対応必須**: CIでWindows GNUクロスコンパイルチェックあり
- **issue-notes/**: 各Issueの作業メモが格納されている

## File Structure Reference

- 開発状況: [generated-docs/development-status.md](../generated-docs/development-status.md)
- 実装サマリ: [IMPLEMENTATION.md](../IMPLEMENTATION.md)
- 使用例: [EXAMPLES.md](../EXAMPLES.md)

## CIエラーのissueへの対処
- まず過去PRを参照し、類似の問題があったかを確認する。
- その場しのぎのフォールバック実装は禁止。
  - かわりに、「アーキテクチャの修正が必要」などを検討し、userに提案すること。
