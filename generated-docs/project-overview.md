Last updated: 2026-01-16

# Project Overview

## プロジェクト概要
- コード進行テキストをMML（Music Macro Language）へ変換するライブラリ・アプリケーションです。
- RustとTree-sitterを活用し、堅牢な構文解析と高速な変換を実現しています。
- コマンドラインツールとして、またRustライブラリとしても利用可能な純粋なネイティブアプリケーションです。

## 技術スタック
- フロントエンド: **TypeScript** (Webアプリケーションのロジック開発), **Vite** (Webフロントエンドの高速なビルドツール), **HTML** (Webアプリケーションの構造定義)
- 音楽・オーディオ: **MML (Music Macro Language)** (音楽表現のためのテキストベースの言語)
- 開発ツール: **Rust** (システムプログラミング言語、高いパフォーマンスと安全性を提供), **Tree-sitter** (高速で正確な構文解析エンジン), **tree-sitter-cli** (Tree-sitterグラマー生成・管理ツール), **Node.js** (Tree-sitter CLIの実行環境、Web関連ツールの実行)
- テスト: **Rust標準テストフレームワーク** (`cargo test`による統合テスト、単体テスト)
- ビルドツール: **Cargo** (Rustプロジェクトのパッケージマネージャー兼ビルドシステム), **Vite** (Webフロントエンドのモダンなビルドツール)
- 言語機能: **Rust** (所有権システム、強力な型推論、パターンマッチングなどの高水準な機能), **TypeScript** (JavaScriptに型システムを追加し、大規模開発を支援)
- 自動化・CI/CD: (特になし。ただし、CodeQL関連ファイルから静的解析の可能性があるが、来訪者向けに明記しない。)
- 開発標準: (特定のツールは明記されていないが、Rustの型安全性とテスト駆動開発を重視する設計思想)

## ファイル階層ツリー
```
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
  📖 27.md
  📖 29.md
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
```

## ファイル詳細説明
- **`.gitignore`**: Gitによるバージョン管理から除外すべきファイルやディレクトリを定義します。
- **`Cargo.lock`**: Rustプロジェクトの依存クレートの正確なバージョンとハッシュを記録し、再現可能なビルドを保証します。
- **`Cargo.toml`**: Rustプロジェクトのメタデータ、依存関係、ビルド設定などを定義するマニフェストファイルです。
- **`EXAMPLES.md`**: プロジェクトの使用例や、詳細なアーキテクチャ説明が記載されたマークダウンファイルです。
- **`IMPLEMENTATION.md`**: プロジェクトの実装に関する詳細な説明が記載されたマークダウンファイルです。
- **`LICENSE`**: プロジェクトのライセンス情報（MIT License）を記載したファイルです。
- **`README.ja.md`**: プロジェクトの日本語版概要を説明するマークダウンファイルです。
- **`README.md`**: プロジェクトの英語版概要を説明するマークダウンファイルです。
- **`_codeql_detected_source_root/`**: 静的解析ツールCodeQLが検出したソースコードのルートディレクトリを示すものです。
    - **`_codeql_detected_source_root/bindings/node/index.js`**: Tree-sitterパーサーをNode.js環境で利用するためのバインディングのエントリーポイントです。
    - **`_codeql_detected_source_root/grammar.js`**: Tree-sitterパーサーの文法規則をJavaScript形式で定義したファイルです。
    - **`_codeql_detected_source_root/package.json`**: Node.jsプロジェクトのメタデータと依存関係を定義します。
    - **`_codeql_detected_source_root/src/grammar.json`**: Tree-sitterグラマーのJSON形式での表現です。
    - **`_codeql_detected_source_root/src/node-types.json`**: Tree-sitterが生成する構文木のノードタイプを定義します。
- **`_config.yml`**: GitHub Pagesなどの設定に使用される可能性のある設定ファイルです。
- **`chord2mml-cli/`**: コマンドラインインターフェース（CLI）ツールを格納するディレクトリです。
    - **`chord2mml-cli/Cargo.toml`**: CLIクレートのRustプロジェクト設定ファイルです。
    - **`chord2mml-cli/README.md`**: CLIツールの使い方や機能に関する説明が記載されています。
    - **`chord2mml-cli/src/main.rs`**: CLIツールのメインエントリーポイントで、コマンドライン引数の解析とコアライブラリの呼び出しを行います。
- **`chord2mml-core/`**: コード進行からMMLへの変換ロジックを実装したコアライブラリのディレクトリです。
    - **`chord2mml-core/Cargo.toml`**: コアライブラリクレートのRustプロジェクト設定ファイルです。
    - **`chord2mml-core/examples/basic.rs`**: コアライブラリの基本的な使用方法を示すサンプルコードです。
    - **`chord2mml-core/src/ast.rs`**: 抽象構文木（AST）のデータ構造と関連するロジックを定義します。
    - **`chord2mml-core/src/lib.rs`**: コアライブラリのエントリーポイントであり、主要な変換関数を公開します。
    - **`chord2mml-core/src/mml.rs`**: ASTからMML文字列への変換ロジックを実装します。
    - **`chord2mml-core/src/note.rs`**: 音符、和音、およびそれらの操作に関連するデータ構造と関数を定義します。
    - **`chord2mml-core/src/parser.rs`**: Tree-sitterが生成するCST（具象構文木）を、プロジェクト独自のASTへ変換するロジックを実装します。
- **`chord2mml-wasm/`**: 将来的にWebAssembly（WASM）対応を目指すためのクレートを格納するディレクトリです。
    - **`chord2mml-wasm/Cargo.toml`**: WASMクレートのRustプロジェクト設定ファイルです。
    - **`chord2mml-wasm/src/lib.rs`**: WASMターゲット向けのエントリーポイントとなるライブラリコードです。
- **`chord2mml-web/`**: Webアプリケーションのフロントエンドコードを格納するディレクトリです。
    - **`chord2mml-web/README.md`**: Webフロントエンドに関する説明が記載されています。
    - **`chord2mml-web/index.html`**: WebアプリケーションのメインとなるHTMLファイルです。
    - **`chord2mml-web/package.json`**: Webフロントエンドの依存関係、スクリプト、メタデータを定義します。
    - **`chord2mml-web/src/main.ts`**: Webアプリケーションの主要なTypeScriptファイルで、UI操作、WASMモジュールのロード、MML変換・再生などのロジックを管理します。
    - **`chord2mml-web/tsconfig.json`**: TypeScriptコンパイラの設定ファイルです。
    - **`chord2mml-web/vite.config.ts`**: Viteビルドツールの設定ファイルで、開発サーバーやビルドオプションを定義します。
- **`generated-docs/`**: 自動生成されたドキュメントを格納するためのディレクトリです。
- **`issue-notes/`**: 開発中に発生した課題や検討事項を記録したマークダウンファイル群です。
- **`tree-sitter-chord/`**: コード進行のTree-sitterグラマー定義とそれに関連するファイル群を格納するディレクトリです。
    - **`tree-sitter-chord/Cargo.toml`**: Tree-sitterグラマーのRustバインディングクレートのプロジェクト設定ファイルです。
    - **`tree-sitter-chord/binding.gyp`**: Node.jsネイティブモジュールをビルドするための設定ファイルです。
    - **`tree-sitter-chord/bindings/node/index.js`**: Tree-sitterグラマーをNode.jsから利用するためのバインディングのエントリーポイントです。
    - **`tree-sitter-chord/bindings/rust/build.rs`**: Rustバインディングをビルドするためのスクリプトです。
    - **`tree-sitter-chord/bindings/rust/lib.rs`**: Tree-sitterグラマーのRustバインディングコードです。
    - **`tree-sitter-chord/grammar.js`**: Tree-sitterグラマーの文法規則をJavaScript形式で定義したファイルです。
    - **`tree-sitter-chord/package.json`**: Tree-sitterグラマーのNode.jsパッケージ設定ファイルです。
    - **`tree-sitter-chord/src/grammar.json`**: Tree-sitterグラマーのJSON形式での表現です。
    - **`tree-sitter-chord/src/node-types.json`**: Tree-sitterが生成する構文木のノードタイプを定義します。
    - **`tree-sitter-chord/src/parser.c`**: Tree-sitterグラマー定義から生成されたC言語製のパーサー実装ファイルです。
    - **`tree-sitter-chord/src/tree_sitter/parser.h`**: Tree-sitterパーサーのC言語ヘッダーファイルです。

## 関数詳細説明
- **`catch`**
    - **役割**: 例外発生時にエラーを捕捉し、適切な処理を実行します。主にNode.jsバインディングのロード失敗時に使用されます。
    - **引数**: なし（一般的なJavaScriptのtry-catchブロックの`catch`句）
    - **戻り値**: なし
    - **ファイル**: `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`
- **`if`**
    - **役割**: 特定の条件に基づいて処理の分岐を行います。主にNode.jsバインディングのパス解決に使用されます。
    - **引数**: なし（一般的なJavaScriptの条件分岐構文）
    - **戻り値**: なし
    - **ファイル**: `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`
- **`showStatus`**
    - **役割**: Webアプリケーションのユーザーインターフェース上に、現在の処理状況やエラーメッセージなどのステータス情報を表示します。
    - **引数**: なし（または表示するメッセージなどの内部コンテキスト）
    - **戻り値**: なし
    - **ファイル**: `chord2mml-web/src/main.ts`
- **`updateOutput`**
    - **役割**: WebアプリケーションのUIにおける出力エリア（MML変換結果など）を更新します。
    - **引数**: なし（または更新するデータなどの内部コンテキスト）
    - **戻り値**: なし
    - **ファイル**: `chord2mml-web/src/main.ts`
- **`initialize`**
    - **役割**: Webアプリケーションの初期化処理を行います。WASMモジュールのロードや初期UIの設定などが含まれると推測されます。
    - **引数**: なし
    - **戻り値**: なし（Promise<void> を返す可能性あり）
    - **ファイル**: `chord2mml-web/src/main.ts`
- **`play`**
    - **役割**: 生成されたMMLを音声として再生する、または再生準備に関連する処理を行います。
    - **引数**: なし（または再生するMMLデータなど）
    - **戻り値**: なし
    - **ファイル**: `chord2mml-web/src/main.ts`

## 関数呼び出し階層ツリー
```
- catch (_codeql_detected_source_root/bindings/node/index.js)
  - showStatus (chord2mml-web/src/main.ts)
    - updateOutput ()
      - initialize ()
      - play ()
- if (_codeql_detected_source_root/bindings/node/index.js)

---
Generated at: 2026-01-16 07:02:10 JST
