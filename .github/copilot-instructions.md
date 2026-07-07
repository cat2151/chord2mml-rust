# Copilot Instructions for chord2mml-rust

## Project Overview

コード進行（例: `Dm G7 C`）をMML（Music Macro Language）形式（例: `v11'd1fa''g1b<df''c1eg'`）に変換するRustライブラリ・CLIツール。出力は元のJS版 [chord2mml](https://github.com/cat2151/chord2mml) と互換であり、**JS版の約100テストが唯一の仕様**（`chord2mml-core/tests/corpus/` のゴールデンコーパスに段階移植中。期待値はJS版の実行結果から生成する）。

## Architecture

```
tree-sitter-chord/   → Tree-sitter文法定義 (grammar.js) + コミット済み文法WASM (tree-sitter-chord.wasm)
chord2mml-core/      → 変換コアライブラリ（feature "tree-sitter" でネイティブパーサー有効化）
chord2mml-cli/       → CLIツール（tree-sitter featureを有効化）
chord2mml-wasm/      → WASM用ラッパー（default features、C依存なしでwasm32-unknown-unknownビルド可）
chord2mml-web/       → ブラウザデモ（web-tree-sitter + Vite）
```

### Data Flow (重要)

tonejs-mml-to-json の実証済みパターン。両経路とも意味論は `cst_to_ast.rs` に一本化されている:
```
[ネイティブ] 入力 → tree-sitter Rustクレート(parser.rs, feature "tree-sitter") → CST JSON化
[ブラウザ]   入力 → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST JSON (src/cst-serializer.js)
共通:       CST JSON → cst_to_ast.rs → AST → mml.rs → MML出力
```

各モジュールの責務:
- [ast.rs](../chord2mml-core/src/ast.rs): `ASTChord`, `ChordQuality`などの型定義
- [cst_to_ast.rs](../chord2mml-core/src/cst_to_ast.rs): CST(JSON) → AST変換（共有意味論レイヤー、ここに文法の意味を実装する）
- [parser.rs](../chord2mml-core/src/parser.rs): ネイティブ専用。tree-sitterでパースしCSTをJSON同形に変換して cst_to_ast へ渡す
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

# WASMビルド（default features、tree-sitterのC依存を含めないこと）
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# ブラウザ経路のテスト（web-tree-sitter + Rust WASM をNodeで実行）
cd chord2mml-web && npm install && npm run build:wasm && npm test

# ブラウザ実動作テスト（headless Chromium）
cd chord2mml-web && npm run build:web && npm run test:browser

# 文法WASMの再生成（grammar.js変更時のみ。WSL等のdocker環境で実行しコミットする）
cd tree-sitter-chord && npx tree-sitter-cli@0.20.8 build-wasm --docker
```

## Key Conventions

### コード追加時のパターン
新しいコードタイプ（例: `Csus4`）を追加する場合:
1. [grammar.js](../tree-sitter-chord/grammar.js) の `quality` に追加（必要なら）→ `tree-sitter generate` と文法WASM再生成
2. [cst_to_ast.rs](../chord2mml-core/src/cst_to_ast.rs) の `parse_chord_quality` に対応追加
3. [mml.rs](../chord2mml-core/src/mml.rs) の `chord_to_mml` にMML生成ロジック追加
4. テストを追加（ネイティブ + `chord2mml-web` のWASM経路テスト）

### MML出力形式（JS版互換）
- 先頭に `v11`、単一コード: `v11'c1eg'`（シングルクォートで囲み、音名連結）
- コード進行: `v11'c1eg''f1a<c'`（**スペースなし**で連結）
- シャープ: `+`（例 `c+`）、フラット: `-`（例 `d-`）、オクターブ: `<`（上）`>`（下）
- 各コードの最初の音名の直後の数字は音長（1=全音符）
- **旧 `'c;e;g'` 形式は廃止済み**。古いドキュメント・コードを見ても復活させないこと

### テストの書き方
仕様追加は原則ゴールデンコーパス（`chord2mml-core/tests/corpus/*.json`）に追加する。
期待値は必ずJS版（`N:\notM2\projects\chord2mml` / cat2151/chord2mml）を実行して得ること（発明しない）。
```rust
#[test]
fn test_convert_c_major() {
    let result = convert("C").unwrap();
    assert_eq!(result, "v11'c1eg'");
}
```

## Current Implementation Status

**実装済み（Phase 1）**: maj / min / maj7 / min7 / 7 / dim / aug / sus2 / sus4、全角半角の #♭、分数コード（chord over bass note）、コード進行（空白・` - `・`→`・`・` 区切り）
**未実装（Wave A〜G で移植予定）**: テンション(6,9,11,13)、add/omit/♭5/#5、オンコード・ポリコード・転回形、drop系ボイシング、小節・音長、度数記法、キー/スケール、インラインMML、MIDI PC、方言プリプロセス — 詳細は README のロードマップ参照

## Important Notes

- **AIコード生成プロジェクト**: このリポジトリはAI自動運転の実験場。READMEにはハルシネーション由来の記述が含まれる可能性あり
- **コード進行の区切り**: JS版仕様は空白・` - `（スペース付きハイフン）・`→`・`・`。スペースなしハイフン（`C-F-G-C`）は当面サポートするが、`-`をマイナー表記（`C-7`）として導入する際に扱いを再検討する（ユーザー確認必須）
- **Windows対応必須**: CIでWindows GNUクロスコンパイルチェックあり。parser.c はUTF-8リテラルを含むため MSVC には `/utf-8` フラグが必要（build.rs 設定済み）
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
