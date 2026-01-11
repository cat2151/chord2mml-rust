Last updated: 2026-01-12


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

このプロジェクトは、[chord2mml](https://github.com/cat2151/chord2mml)で Peggy.js + JavaScript で作っていたものを、Rust + WASM + TypeScript として新たに作り直したものです。

### 主な特徴

- **Rustパーサーコア**: シンプルで高速な文字列マッチングパーサー（将来的にTree-sitterベースに移行予定）
- **ライブラリクレート**: Rustのネイティブアプリケーションから直接利用可能
- **WASM対応**: ブラウザ上でも動作
- **TypeScript統合**: Webアプリケーションとしての利用

## アーキテクチャ

```
chord2mml-rust/
├── chord2mml-core/     # Rustによる変換コアライブラリ
├── chord2mml-wasm/     # WASM バインディング
└── chord2mml-web/      # TypeScript + Webアプリケーション
```

### コンポーネント

1. **chord2mml-core**: コード進行をパースしてMMLに変換するRustライブラリ
   - シンプルな文字列マッチングによる構文解析（Phase 3でTree-sitter導入予定）
   - ネイティブアプリケーションから利用可能

2. **chord2mml-wasm**: WASMバインディング
   - Rust CoreをWebAssemblyにコンパイル
   - JavaScriptからの呼び出しインターフェース

3. **chord2mml-web**: ブラウザアプリケーション
   - TypeScriptで実装
   - Web Audio APIによる直接的な音声再生（Phase 2以降でtonejs系ライブラリ統合予定）
   - textareaでコード進行を入力し、リアルタイムで変換・再生

## デモ

Webアプリケーションでは、textareaに「C」を入力すると「c;e;g」に変換され、
ドミソの和音が鳴ります。

試してみる: [https://cat2151.github.io/chord2mml-rust/](https://cat2151.github.io/chord2mml-rust/)

## 使い方

### Webアプリケーション

1. ブラウザで https://cat2151.github.io/chord2mml-rust/ を開く
2. textareaにコード進行を入力（例: `C`, `Dm`, `G7`）
3. 自動的にMMLに変換され、音が鳴ります

### Rustライブラリとして

```rust
use chord2mml_core::convert;

fn main() {
    let chord = "C";
    let mml = convert(chord);
    println!("MML: {}", mml); // "c;e;g"
}
```

### ビルド方法

#### Rustライブラリ

```bash
cd chord2mml-core
cargo build --release
cargo test
```

#### WASM

```bash
cd chord2mml-wasm
wasm-pack build --target web
```

#### Webアプリケーション

```bash
cd chord2mml-web
npm install
npm run build
npm run dev  # 開発サーバー起動
```

## ロードマップ

### Phase 1: 基本機能の実装 ✅

- [x] プロジェクト構造の構築
- [x] 基本的なコード変換機能（C → c;e;g）
- [x] WASMバインディング
- [x] Webアプリケーションの基本機能
- [x] Web Audio APIによる基本的な音声再生

### Phase 2: 元のchord2mmlテストの移植

元の[chord2mml](https://github.com/cat2151/chord2mml)リポジトリにあるテストを移植し、
以下の和音を網羅的にサポートします：

#### メジャー系コード
- [x] C (ド・ミ・ソ)
- [ ] C6 (ド・ミ・ソ・ラ)
- [ ] CM7, Cmaj7 (ド・ミ・ソ・シ)
- [ ] Cadd9 (ド・ミ・ソ・レ)
- [ ] C69 (ド・ミ・ソ・ラ・レ)

#### マイナー系コード
- [ ] Cm (ド・ミ♭・ソ)
- [ ] Cm6 (ド・ミ♭・ソ・ラ)
- [ ] Cm7 (ド・ミ♭・ソ・シ♭)
- [ ] CmM7, Cm(maj7) (ド・ミ♭・ソ・シ)
- [ ] Cm7-5, Cm7(♭5) (ド・ミ♭・ソ♭・シ♭)

#### セブンス系コード
- [ ] C7 (ド・ミ・ソ・シ♭)
- [ ] C7sus4 (ド・ファ・ソ・シ♭)
- [ ] C7-5, C7(♭5) (ド・ミ・ソ♭・シ♭)
- [ ] C7+5, C7(#5), Caug7 (ド・ミ・ソ#・シ♭)
- [ ] C7-9, C7(♭9) (ド・ミ・ソ・シ♭・レ♭)
- [ ] C7+9, C7(#9) (ド・ミ・ソ・シ♭・レ#)

#### ディミニッシュ・オーギュメント系
- [ ] Cdim, Cdim7 (ド・ミ♭・ソ♭・ラ)
- [ ] Caug, C+, C(#5) (ド・ミ・ソ#)

#### サスペンド系
- [ ] Csus4 (ド・ファ・ソ)
- [ ] Csus2 (ド・レ・ソ)

#### 転回形とベース指定
- [ ] C/E (第一転回形: ミ・ソ・ド)
- [ ] C/G (第二転回形: ソ・ド・ミ)
- [ ] C/D (オンコード: レ・ド・ミ・ソ)

#### その他の和音
- [ ] 9th, 11th, 13th コード
- [ ] テンションノート
- [ ] 複雑な変化記号の組み合わせ

#### 機能拡張
- [ ] オクターブ指定
- [ ] リズム・音長指定
- [ ] 複数コードの連続入力
- [ ] コード進行パターンの自動生成

### Phase 3: 高度な機能

- [ ] より複雑なコード進行のサポート
- [ ] Tree-sitterの導入とグラマーの実装
- [ ] tonejs-mml-to-json と tonejs-json-sequencer の統合
- [ ] パフォーマンス改善
- [ ] エラーハンドリングの強化
- [ ] ドキュメント整備

## 開発方針

### 元のchord2mmlとの違い

| 項目 | chord2mml (旧) | chord2mml-rust (新) |
|------|---------------|-------------------|
| パーサー | Peggy.js | 文字列マッチング（Tree-sitterは今後導入予定） |
| 言語 | JavaScript/TypeScript | Rust + TypeScript |
| 実行環境 | ブラウザ専用 | ネイティブ + WASM |
| ライブラリ利用 | 困難 | 容易（Rustクレート） |

### 設計思想

1. **シンプルさ**: 複雑さを避け、メンテナンス性を重視
2. **型安全性**: Rustの強力な型システムを活用
3. **テスト駆動**: 包括的なテストカバレッジ
4. **パフォーマンス**: Rustの高速性を活かした変換

## 対象プラットフォーム

- **Rust ライブラリ**: すべてのRustサポート環境
- **WASM**: モダンブラウザ（Chrome, Firefox, Safari, Edge）
- **Webアプリ**: モダンブラウザ

## 技術スタック

- **Rust**: 1.70以降
- **wasm-pack**: WASMビルドツール
- **TypeScript**: Webアプリケーション
- **Web Audio API**: 音声再生

### 将来的な導入予定

- **Tree-sitter**: より堅牢な構文解析（Phase 3）
- **tonejs-mml-to-json**: MML解析の高度化（Phase 3）
- **tonejs-json-sequencer**: より高機能な音声再生（Phase 3）

## テスト

```bash
# Rustコアのテスト
cd chord2mml-core
cargo test

# WASM統合テスト
cd chord2mml-wasm
wasm-pack test --node

# Webアプリのテスト
cd chord2mml-web
npm test
```

## ビルド要件

- Rust 1.70以降
- Node.js 18以降
- wasm-pack

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

- [プロジェクトページ](https://cat2151.github.io/chord2mml-rust/)
- [元のchord2mmlデモ](https://cat2151.github.io/chord2mml/dist/)


依存関係:
{}

## ファイル階層ツリー
📄 .gitignore
📄 Cargo.lock
📄 Cargo.toml
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
📁 chord2mml-core/
  📄 Cargo.toml
  📁 src/
    📄 lib.rs
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
  📖 2.md
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

**_codeql_detected_source_root/grammar.js** (51行, 968バイト)
  - 関数: なし
  - インポート: なし

**chord2mml-web/index.html** (220行, 5215バイト)
  - 関数: なし
  - インポート: なし

**chord2mml-web/src/main.ts** (164行, 4859バイト)
  - 関数: showStatus, updateOutput, initialize, constructor, if, catch, play
  - インポート: ../public/wasm/chord2mml_wasm.js, tonejs-mml-to-json, tone

**chord2mml-web/vite.config.ts** (20行, 320バイト)
  - 関数: なし
  - インポート: vite

**tree-sitter-chord/bindings/node/index.js** (20行, 461バイト)
  - 関数: catch, if
  - インポート: ../../build/Release/tree_sitter_chord_binding, ../../build/Debug/tree_sitter_chord_binding, ../../src/node-types.json

**tree-sitter-chord/grammar.js** (51行, 968バイト)
  - 関数: なし
  - インポート: なし

## 関数呼び出し階層
- catch (_codeql_detected_source_root/bindings/node/index.js)
- if (_codeql_detected_source_root/bindings/node/index.js)
- showStatus (chord2mml-web/src/main.ts)
  - updateOutput ()
  - initialize ()
  - constructor (undefined)


## プロジェクト構造（ファイル一覧）
README.ja.md
README.md
_codeql_detected_source_root/bindings/node/index.js
_codeql_detected_source_root/grammar.js
_codeql_detected_source_root/package.json
_codeql_detected_source_root/src/grammar.json
_codeql_detected_source_root/src/node-types.json
chord2mml-web/README.md
chord2mml-web/index.html
chord2mml-web/package.json
chord2mml-web/src/main.ts
chord2mml-web/tsconfig.json
chord2mml-web/vite.config.ts
issue-notes/2.md
tree-sitter-chord/bindings/node/index.js
tree-sitter-chord/grammar.js
tree-sitter-chord/package.json
tree-sitter-chord/src/grammar.json
tree-sitter-chord/src/node-types.json

上記の情報を基に、プロンプトで指定された形式でプロジェクト概要を生成してください。
特に以下の点を重視してください：
- 技術スタックは各カテゴリごとに整理して説明
- ファイル階層ツリーは提供された構造をそのまま使用
- ファイルの説明は各ファイルの実際の内容と機能に基づく
- 関数の説明は実際に検出された関数の役割に基づく
- 関数呼び出し階層は実際の呼び出し関係に基づく


---
Generated at: 2026-01-12 07:01:37 JST
