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
1. **まず過去PRを参照し、類似の問題があったかを確認する**
2. **その場しのぎのフォールバック実装は厳禁**
3. **動作しているコード・ワークフロー・機能の削除は原則禁止**

### 禁止事項（具体例）
以下のような対処は**絶対に行ってはならない**：

❌ **ワークフローの削除**
  - 例: CIでWASMビルドが失敗するからといって、deploy-pages.ymlを丸ごと削除
  - 理由: GitHub Pagesデプロイ機能全体が失われる

❌ **エラーを回避するためのフィーチャー削除**
  - 例: tree-sitterがWASMでコンパイルできないから、tree-sitter機能を削除
  - 理由: コア機能が失われる

❌ **エラーを隠蔽するだけの対処**
  - 例: テストを#[ignore]にする、エラーをpanic!からOkに変える
  - 理由: 問題の本質を隠すだけで解決していない

### 推奨する対処手順

#### 1. 問題分析フェーズ
```
- エラーの根本原因を特定
- 影響範囲を調査
- 過去の類似事例を検索
- アーキテクチャ上の制約を理解
```

#### 2. 解決策検討フェーズ
複数の選択肢を比較検討する：

**選択肢A: 根本的な修正**
  - 例: tree-sitter WASM問題 → wasm32-wasi target使用、または純RustパーサーでWASM専用実装
  - メリット: 機能を失わない
  - デメリット: 実装コストが高い

**選択肢B: アーキテクチャ変更**
  - 例: WASM版は別パーサー、ネイティブ版はtree-sitter使用
  - メリット: 両方の環境で機能する
  - デメリット: メンテナンスコスト増加

**選択肢C: 機能の一時的無効化**
  - 例: WASMデプロイを一時的に停止（ワークフローは残す）
  - メリット: 将来の修正が容易
  - デメリット: 一部機能が使えない

#### 3. ユーザー提案フェーズ
**必ず以下を含めてユーザーに提案**：
```markdown
## 問題の根本原因
[技術的詳細]

## 検討した解決策
1. [選択肢A] 根本的修正
   - 実装方法: ...
   - メリット: ...
   - デメリット: ...
   - 工数見積: ...

2. [選択肢B] アーキテクチャ変更
   - 実装方法: ...
   - メリット: ...
   - デメリット: ...
   - 工数見積: ...

3. [選択肢C] 機能の一時的無効化
   - 実装方法: ...
   - メリット: ...
   - デメリット: ...
   - 工数見積: ...

## 推奨案
[理由を含めて推奨する選択肢を提示]

## ユーザーの判断を仰ぎたい点
- [重要な判断ポイント1]
- [重要な判断ポイント2]
```

### 判断チェックリスト

変更を実装する前に、以下をすべて確認：

- [ ] この変更で失われる機能はないか？
- [ ] 他の解決策を3つ以上検討したか？
- [ ] ユーザーに提案し、承認を得たか？
- [ ] 将来の修正・改善の道を閉ざしていないか？
- [ ] テストカバレッジが維持されているか？
- [ ] ドキュメントの更新が必要か？

### エスカレーションが必要なケース

以下の場合は、**実装せずに必ずユーザーに相談**：

1. **アーキテクチャの大幅な変更が必要**
   - 例: パーサーライブラリの変更、ビルドシステムの変更

2. **既存機能の削除・無効化が必要**
   - 例: WASMサポート廃止、特定コードタイプのサポート終了

3. **外部依存の根本的な制約に直面**
   - 例: ライブラリのWASM非対応、プラットフォーム制限

4. **解決策の工数が大きい（3時間以上）**
   - 例: 大規模なリファクタリング、新規実装

5. **複数の利害関係者に影響**
   - 例: CI/CDパイプライン変更、API変更
