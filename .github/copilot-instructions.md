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

### 基本原則
1. **まずユーザーの他のリポジトリで成功している実装パターンを検索する**
2. **その場しのぎのフォールバック実装は厳禁**
3. **動作しているコード・ワークフロー・機能の削除は原則禁止**

### ユーザーの成功パターンを参照する

**重要**: 技術的な問題に直面したら、まずユーザーの他のリポジトリで同様の問題をどう解決したかを調査すること。

**例: tree-sitter + WASM の正しいアーキテクチャ**

`tonejs-mml-to-json` リポジトリで実装済みの成功パターン:

```rust
// rust/Cargo.toml
[features]
default = []  # WASM用: tree-sitterを使わない
tree-sitter = ["dep:tree-sitter", "dep:cc"]  # ネイティブ用のみ

// rust/src/lib.rs
#[cfg(feature = "tree-sitter")]
pub mod mml2ast;  // ネイティブ: tree-sitter Rustクレート使用

#[cfg(not(feature = "tree-sitter"))]
pub mod mml2ast_manual;  // WASM: 手動パーサーまたはCST処理のみ

pub mod cst_to_ast;  // web-tree-sitter (JS版) からのCST処理用
```

**アーキテクチャの要点**:
- **ネイティブビルド**: tree-sitter Rustクレートを使用（feature flag有効）
- **WASMビルド**: web-tree-sitter.js（ブラウザでJavaScript実行）→ CST JSON → Rust WASM（CST処理のみ）
- **キーポイント**: tree-sitterのC依存をRust WASMコンパイラに通さない

### 禁止事項（具体例）

❌ **ワークフローの削除**
  - 例: CIでWASMビルドが失敗 → deploy-pages.ymlを丸ごと削除
  - 正しい対処: ユーザーの成功例を検索 → 同じパターンを適用

❌ **エラーを回避するためのフィーチャー削除**
  - 例: tree-sitterがWASMでコンパイル不可 → tree-sitter機能を削除
  - 正しい対処: web-tree-sitter (JS版) を使う条件付きコンパイル

❌ **代替実装の提案（ユーザーの成功パターンが存在する場合）**
  - 例: wasm32-wasi, pest/nom, 手動パーサーなど
  - 正しい対処: まずユーザーの実装を参照

### 推奨する対処手順

#### 1. ユーザーの成功例を検索
```
1. GitHub code search でユーザーのリポジトリを検索
   例: "tree-sitter user:cat2151"
2. 類似の技術スタック・問題を扱っているリポジトリを特定
3. そのアーキテクチャパターンを理解
4. 同じパターンを現在のプロジェクトに適用できるか検討
```

#### 2. 成功例が見つからない場合のみ、代替案を検討

複数の選択肢を比較検討：

**選択肢A**: （ユーザーの成功例に基づく実装）
**選択肢B**: （別のアプローチ1）
**選択肢C**: （別のアプローチ2）

#### 3. ユーザーに報告・提案

```markdown
## 調査結果

### ユーザーの成功例
- リポジトリ: [repo名]
- アーキテクチャ: [概要]
- 適用可能性: [このプロジェクトに適用できるか]

### 成功例が見つからなかった場合
検索キーワード: "..."
検索結果: なし

### 提案する解決策
[成功例に基づく実装 or 代替案]
```

### 判断チェックリスト

- [ ] ユーザーの他のリポジトリで類似の問題・解決策を検索したか？
- [ ] この変更で失われる機能はないか？
- [ ] ユーザーに提案し、承認を得たか？
- [ ] 将来の修正・改善の道を閉ざしていないか？

### エスカレーションが必要なケース

以下の場合は**実装せずに必ずユーザーに相談**：

1. **ユーザーの成功例が見つからず、新しいアプローチが必要**
2. **既存機能の削除・無効化が必要**
3. **外部依存の根本的な制約に直面**
4. **解決策の工数が大きい（3時間以上）**
5. **複数の利害関係者に影響**
