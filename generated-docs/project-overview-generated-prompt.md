Last updated: 2026-01-14


# プロジェクト概要生成プロンプト（来訪者向け）

## 生成するもの：
- projectを3行で要約する
- プロジェクトで使用されている技術スタックをカテゴリ別に整理して説明する
- プロジェクト全体のファイル階層ツリー（ディレクトリ構造を図解）
- プロジェクト全体のファイルそれぞれの説明
- プロジェクト全体の関数それぞれの説明
- プロジェクト全体の関数の呼び出し階層ツリー

## 生成しないもの：
- Issues情報（開発者向け情報のため）
- 次の一手候補（開発者向け情報のため）
- ハルシネーションしそうなもの（例、存在しない機能や計画を勝手に妄想する等）

## 出力フォーマット：
以下のMarkdown形式で出力してください：

```markdown
# Project Overview

## プロジェクト概要
[以下の形式で3行でプロジェクトを要約]
- [1行目の説明]
- [2行目の説明]
- [3行目の説明]

## 技術スタック
[使用している技術をカテゴリ別に整理して説明]
- フロントエンド: [フロントエンド技術とその説明]
- 音楽・オーディオ: [音楽・オーディオ関連技術とその説明]
- 開発ツール: [開発支援ツールとその説明]
- テスト: [テスト関連技術とその説明]
- ビルドツール: [ビルド・パース関連技術とその説明]
- 言語機能: [言語仕様・機能とその説明]
- 自動化・CI/CD: [自動化・継続的統合関連技術とその説明]
- 開発標準: [コード品質・統一ルール関連技術とその説明]

## ファイル階層ツリー
```
[プロジェクトのディレクトリ構造をツリー形式で表現]
```

## ファイル詳細説明
[各ファイルの役割と機能を詳細に説明]

## 関数詳細説明
[各関数の役割、引数、戻り値、機能を詳細に説明]

## 関数呼び出し階層ツリー
```
[関数間の呼び出し関係をツリー形式で表現]
```
```


以下のプロジェクト情報を参考にして要約を生成してください：

## プロジェクト情報
名前: 
説明: # chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

コード進行をMML（Music Macro Language）に変換するライブラリ・アプリケーション。Rustで書かれています。

## 注意
- WIP
- 破壊的変更を頻繁に行う
- AI自動運転で、userの作業負荷を最小化して進めていくつもり
- そのためのAI自動運転装置を開発するつもり（というよりAI自動運転装置の開発用のリポジトリとして利用するつもり）
- 以下はだいたいAI生成、間違いを含む可能性が高い、userの意図と違うものを含む可能性が高い

## 概要

このプロジェクトは、[chord2mml](https://github.com/cat2151/chord2mml)で Peggy.js + JavaScript で作っていたものを、**Rust + Tree-sitter** として新たに作り直したものです。

### 主な特徴

- **Tree-sitterパーサー**: 堅牢で正確な構文解析
- **CST→AST変換**: Tree-sitterが生成するCST（具象構文木）をAST（抽象構文木）に変換
- **純粋なRustネイティブアプリケーション**: text to text の変換に特化
- **CLIツール**: コマンドラインから直接利用可能
- **ライブラリクレート**: Rustのネイティブアプリケーションから直接利用可能

## アーキテクチャ

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitterグラマー定義
├── chord2mml-core/      # Rustによる変換コアライブラリ（CST→AST→MML）
└── chord2mml-cli/       # コマンドラインインターフェース
```

### データフロー

```
入力テキスト (例: "C-F-G-C")
    ↓
Tree-sitterパーサー
    ↓
CST (Concrete Syntax Tree)
    ↓
AST変換
    ↓
AST (Abstract Syntax Tree)
    ↓
MML生成
    ↓
出力MML (例: "c;e;g f;a;c g;b;d c;e;g")
```

### コンポーネント

1. **tree-sitter-chord**: Tree-sitterグラマー定義
   - コード記法の構文定義（C、Dm、G7など）
   - コード進行のサポート（C-F-G-Cなど）

2. **chord2mml-core**: コード進行をパースしてMMLに変換するRustライブラリ
   - Tree-sitterによる構文解析
   - CST（具象構文木）からAST（抽象構文木）への変換
   - ASTからMMLへの変換
   - ネイティブアプリケーションから利用可能

3. **chord2mml-cli**: コマンドラインツール
   - text to text の変換インターフェース
   - 標準入力/引数からの入力サポート

## デモ

### CLIツール

```bash
# 単一のコード
$ chord2mml "C"
c;e;g

# コード進行
$ chord2mml "C-F-G-C"
c;e;g f;a;c g;b;d c;e;g

# マイナーコード
$ chord2mml "Dm"
d;f;a

# 混合進行
$ chord2mml "C-Dm-G-C"
c;e;g d;f;a g;b;d c;e;g
```

## 使い方

### CLIツール

```bash
# ビルド
cd chord2mml-cli
cargo build --release

# 実行（引数から）
chord2mml "C-F-G-C"

# 実行（標準入力から）
echo "C-F-G-C" | chord2mml

# インタラクティブモード
chord2mml
# コード記法を入力してEnter
```

### Rustライブラリとして

```rust
use chord2mml_core::convert;

fn main() {
    // 単一のコード
    let chord = "C";
    let mml = convert(chord).unwrap();
    println!("MML: {}", mml); // "c;e;g"
    
    // コード進行
    let progression = "C-F-G-C";
    let mml = convert(progression).unwrap();
    println!("MML: {}", mml); // "c;e;g f;a;c g;b;d c;e;g"
}
```

### ビルド方法

#### Rustライブラリとコア

```bash
cd chord2mml-core
cargo build --release
cargo test
```

#### CLIツール

```bash
cd chord2mml-cli
cargo build --release
# バイナリは ../target/release/chord2mml に生成されます
```

#### 例の実行

```bash
cd chord2mml-core
cargo run --example basic
```

## ロードマップ

### Phase 1: Tree-sitterベースの基本実装 ✅

- [x] Tree-sitterグラマーの定義
- [x] 基本的なコード変換機能（C → c;e;g）
- [x] コード進行のサポート（C-F-G-C）
- [x] CST→AST→MML変換パイプライン
- [x] CLIツールの実装
- [x] 包括的なテストの追加

### Phase 2: 元のchord2mmlテストの移植

元の[chord2mml](https://github.com/cat2151/chord2mml)リポジトリにあるテストを移植し、
以下の和音を網羅的にサポートします：

**現在の実装状況**: メジャーコードとマイナーコードは完全に実装済み。その他のコードタイプはパーサーでの認識のみ対応しており、MML変換は未実装です。

#### メジャー系コード
- [x] C (ド・ミ・ソ)
- [ ] C6 (ド・ミ・ソ・ラ)
- [ ] CM7, Cmaj7 (ド・ミ・ソ・シ) ※パーサーのみ対応、MML変換未実装
- [ ] Cadd9 (ド・ミ・ソ・レ)
- [ ] C69 (ド・ミ・ソ・ラ・レ)

#### マイナー系コード
- [x] Cm (ド・ミ♭・ソ)
- [ ] Cm6 (ド・ミ♭・ソ・ラ)
- [ ] Cm7 (ド・ミ♭・ソ・シ♭)
- [ ] CmM7, Cm(maj7) (ド・ミ♭・ソ・シ)
- [ ] Cm7-5, Cm7(♭5) (ド・ミ♭・ソ♭・シ♭)

#### セブンス系コード
- [ ] C7 (ド・ミ・ソ・シ♭) ※パーサーのみ対応、MML変換未実装
- [ ] C7sus4 (ド・ファ・ソ・シ♭)
- [ ] C7-5, C7(♭5) (ド・ミ・ソ♭・シ♭)
- [ ] C7+5, C7(#5), Caug7 (ド・ミ・ソ#・シ♭)
- [ ] C7-9, C7(♭9) (ド・ミ・ソ・シ♭・レ♭)
- [ ] C7+9, C7(#9) (ド・ミ・ソ・シ♭・レ#)

#### ディミニッシュ・オーギュメント系
- [ ] Cdim, Cdim7 (ド・ミ♭・ソ♭・ラ) ※パーサーのみ対応、MML変換未実装
- [ ] Caug, C+, C(#5) (ド・ミ・ソ#) ※パーサーのみ対応、MML変換未実装

#### サスペンド系
- [ ] Csus4 (ド・ファ・ソ) ※パーサーのみ対応、MML変換未実装
- [ ] Csus2 (ド・レ・ソ) ※パーサーのみ対応、MML変換未実装

#### 転回形とベース指定
- [ ] C/E (第一転回形: ミ・ソ・ド) ※パーサーのみ対応、MML変換未実装
- [ ] C/G (第二転回形: ソ・ド・ミ) ※パーサーのみ対応、MML変換未実装
- [ ] C/D (オンコード: レ・ド・ミ・ソ) ※パーサーのみ対応、MML変換未実装

#### その他の和音
- [ ] 9th, 11th, 13th コード
- [ ] テンションノート
- [ ] 複雑な変化記号の組み合わせ

#### 機能拡張
- [ ] オクターブ指定
- [ ] リズム・音長指定
- [x] 複数コードの連続入力（コード進行）
- [ ] コード進行パターンの自動生成

### Phase 3: 高度な機能と統合

- [ ] より複雑なコード進行のサポート
- [ ] すべてのコードタイプの実装完了
- [ ] WASM対応の再実装（必要に応じて）
- [ ] tonejs-mml-to-json と tonejs-json-sequencer の統合（音声再生機能）
- [ ] パフォーマンス改善
- [ ] エラーハンドリングの強化
- [ ] ドキュメント整備

## 開発方針

### 元のchord2mmlとの違い

| 項目 | chord2mml (旧) | chord2mml-rust (新) |
|------|---------------|-------------------|
| パーサー | Peggy.js | Tree-sitter |
| 言語 | JavaScript/TypeScript | Rust |
| 実行環境 | ブラウザ専用 | ネイティブ（CLI） |
| 変換フロー | PEG → AST → MML | Tree-sitter → CST → AST → MML |
| ライブラリ利用 | 困難 | 容易（Rustクレート） |

### 設計思想

1. **シンプルさ**: 複雑さを避け、メンテナンス性を重視
2. **型安全性**: Rustの強力な型システムを活用
3. **テスト駆動**: 包括的なテストカバレッジ
4. **パフォーマンス**: Rustの高速性を活かした変換

## 対象プラットフォーム

- **Rust ライブラリ**: すべてのRustサポート環境
- **CLIツール**: Linux, macOS, Windows

## 技術スタック

- **Rust**: 1.70以降
- **Tree-sitter**: 構文解析エンジン
- **tree-sitter-cli**: グラマー生成ツール

### 将来的な導入予定

- **WASM**: ブラウザでの実行サポート（必要に応じて）
- **tonejs-mml-to-json**: MML解析の高度化
- **tonejs-json-sequencer**: より高機能な音声再生

## テスト

```bash
# Rustコアのテスト
cd chord2mml-core
cargo test

# 全体のテスト
cargo test --all

# 例の実行
cd chord2mml-core
cargo run --example basic
```

## ビルド要件

- Rust 1.70以降
- Node.js 18以降（tree-sitter-cli用）
- tree-sitter-cli（グラマー生成用）

## ライセンス

MIT License

## 関連プロジェクト

- [chord2mml](https://github.com/cat2151/chord2mml) - オリジナルのJavaScript版
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - MML解析ライブラリ
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - 音声再生ライブラリ

## 貢献

Issue や Pull Request を歓迎します。

## 作者

cat2151

## 参考リンク

- [元のchord2mml](https://github.com/cat2151/chord2mml) - オリジナルのJavaScript版
- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - 構文解析ライブラリ
- [EXAMPLES.md](EXAMPLES.md) - より詳しい使用例とアーキテクチャ説明


依存関係:
{}

## ファイル階層ツリー
📄 .gitignore
📄 Cargo.lock
📄 Cargo.toml
📖 EXAMPLES.md
📖 IMPLEMENTATION.md
📄 LICENSE
📖 README.ja.md
📖 README.md
📁 _codeql_detected_source_root/
  📄 Cargo.toml
  📄 binding.gyp
  📁 bindings/
    📁 node/
      📄 binding.cc
      📜 index.js
    📁 rust/
      📄 build.rs
      📄 lib.rs
  📜 grammar.js
  📊 package.json
  📁 src/
    📊 grammar.json
    📊 node-types.json
    📄 parser.c
    📁 tree_sitter/
      📄 parser.h
📄 _config.yml
📁 chord2mml-cli/
  📄 Cargo.toml
  📖 README.md
  📁 src/
    📄 main.rs
📁 chord2mml-core/
  📄 Cargo.toml
  📁 examples/
    📄 basic.rs
  📁 src/
    📄 ast.rs
    📄 lib.rs
    📄 mml.rs
    📄 note.rs
    📄 parser.rs
📁 chord2mml-wasm/
  📄 Cargo.toml
  📁 src/
    📄 lib.rs
📁 chord2mml-web/
  📖 README.md
  🌐 index.html
  📊 package.json
  📁 src/
    📘 main.ts
  📊 tsconfig.json
  📘 vite.config.ts
📁 generated-docs/
📁 issue-notes/
  📖 11.md
  📖 13.md
  📖 15.md
  📖 17.md
  📖 19.md
  📖 2.md
  📖 20.md
  📖 21.md
  📖 22.md
  📖 5.md
  📖 7.md
  📖 9.md
📁 tree-sitter-chord/
  📄 Cargo.toml
  📄 binding.gyp
  📁 bindings/
    📁 node/
      📄 binding.cc
      📜 index.js
    📁 rust/
      📄 build.rs
      📄 lib.rs
  📜 grammar.js
  📊 package.json
  📁 src/
    📊 grammar.json
    📊 node-types.json
    📄 parser.c
    📁 tree_sitter/
      📄 parser.h

## ファイル詳細分析
**_codeql_detected_source_root/bindings/node/index.js** (20行, 461バイト)
  - 関数: catch, if
  - インポート: ../../build/Release/tree_sitter_chord_binding, ../../build/Debug/tree_sitter_chord_binding, ../../src/node-types.json

**_codeql_detected_source_root/grammar.js** (61行, 1327バイト)
  - 関数: なし
  - インポート: なし

**chord2mml-web/index.html** (220行, 5215バイト)
  - 関数: なし
  - インポート: なし

**chord2mml-web/src/main.ts** (172行, 5758バイト)
  - 関数: showStatus, updateOutput, initialize, if, catch, play
  - インポート: ../public/wasm/chord2mml_wasm.js

**chord2mml-web/vite.config.ts** (20行, 320バイト)
  - 関数: なし
  - インポート: vite

**tree-sitter-chord/bindings/node/index.js** (20行, 461バイト)
  - 関数: catch, if
  - インポート: ../../build/Release/tree_sitter_chord_binding, ../../build/Debug/tree_sitter_chord_binding, ../../src/node-types.json

**tree-sitter-chord/grammar.js** (61行, 1327バイト)
  - 関数: なし
  - インポート: なし

## 関数呼び出し階層
- catch (_codeql_detected_source_root/bindings/node/index.js)
  - showStatus (chord2mml-web/src/main.ts)
    - updateOutput ()
      - initialize ()
      - play ()
- if (_codeql_detected_source_root/bindings/node/index.js)


## プロジェクト構造（ファイル一覧）
EXAMPLES.md
IMPLEMENTATION.md
README.ja.md
README.md
_codeql_detected_source_root/bindings/node/index.js
_codeql_detected_source_root/grammar.js
_codeql_detected_source_root/package.json
_codeql_detected_source_root/src/grammar.json
_codeql_detected_source_root/src/node-types.json
chord2mml-cli/README.md
chord2mml-web/README.md
chord2mml-web/index.html
chord2mml-web/package.json
chord2mml-web/src/main.ts
chord2mml-web/tsconfig.json
chord2mml-web/vite.config.ts
issue-notes/11.md
issue-notes/13.md
issue-notes/15.md
issue-notes/17.md
issue-notes/19.md
issue-notes/2.md
issue-notes/20.md
issue-notes/21.md
issue-notes/22.md
issue-notes/5.md
issue-notes/7.md
issue-notes/9.md
tree-sitter-chord/bindings/node/index.js
tree-sitter-chord/grammar.js

上記の情報を基に、プロンプトで指定された形式でプロジェクト概要を生成してください。
特に以下の点を重視してください：
- 技術スタックは各カテゴリごとに整理して説明
- ファイル階層ツリーは提供された構造をそのまま使用
- ファイルの説明は各ファイルの実際の内容と機能に基づく
- 関数の説明は実際に検出された関数の役割に基づく
- 関数呼び出し階層は実際の呼び出し関係に基づく


---
Generated at: 2026-01-14 07:01:42 JST
