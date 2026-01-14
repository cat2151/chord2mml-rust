Last updated: 2026-01-15

# Project Overview

## プロジェクト概要
- コード進行をMML（Music Macro Language）に変換するRust製のライブラリおよびCLIツールです。
- Tree-sitterを用いた堅牢な構文解析により、CSTからASTを経てMMLを生成します。
- 純粋なRustネイティブアプリケーションとして動作し、WebアプリケーションへのWASM統合も視野に入れた設計です。

## 技術スタック
- フロントエンド:
    - **TypeScript**: Webアプリケーション開発のための型安全なプログラミング言語。
    - **Vite**: 高速な開発サーバーと本番ビルドを提供するフロントエンドツール。
    - **WASM (WebAssembly)**: Rustで書かれたコアロジックをWebブラウザで実行可能にするバイナリ形式。
- 音楽・オーディオ:
    - **MML (Music Macro Language)**: 音楽をテキスト形式で記述するための簡易プログラミング言語。本プロジェクトの出力形式です。
- 開発ツール:
    - **Rust**: 高性能で安全なシステムプログラミング言語であり、本プロジェクトの主要言語です。
    - **Tree-sitter**: 任意の言語の堅牢な構文解析ツリーとパーサーを生成するためのフレームワーク。
    - **tree-sitter-cli**: Tree-sitterグラマーの生成、テスト、管理に使用されるコマンドラインツール。
    - **Node.js**: `tree-sitter-cli`の実行環境として使用されます。
    - **Cargo**: Rustプロジェクトの公式なビルドシステムとパッケージマネージャー。
- テスト:
    - **Rust標準テストフレームワーク**: `cargo test`コマンドを通じて、Rustコードのユニットテストおよび統合テストが実行されます。
- ビルドツール:
    - **Cargo**: Rustクレート（ライブラリ、CLIアプリケーション、WASMモジュール）のビルド、テスト、ドキュメンテーション生成を管理します。
    - **Vite**: Webアプリケーション (`chord2mml-web`) の開発サーバーの提供と、本番環境向けのコードビルドを処理します。
    - **tree-sitter-cli**: Tree-sitterパーサーのC言語ソースコードを生成します。
- 言語機能:
    - **Rustの型システム**: メモリ安全性と並行性を保証する強力な静的型付けシステムを活用しています。
    - **TypeScriptの型システム**: JavaScriptに静的型チェックを導入し、Webフロントエンド開発の堅牢性を高めます。
- 自動化・CI/CD:
    - (プロジェクト情報に明示的な記述はありません。)
- 開発標準:
    - (プロジェクト情報に明示的な記述はありません。)

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
- **`.gitignore`**: Gitのバージョン管理から除外するファイルやディレクトリのパターンを定義します。
- **`Cargo.lock`**: Rustプロジェクトの依存関係の正確なバージョンを記録し、ビルドの再現性を保証します。
- **`Cargo.toml`**: プロジェクト全体のメタデータ（名前、バージョンなど）と、ワークスペース内の各クレート定義を管理します。
- **`EXAMPLES.md`**: プロジェクトの様々な使用例やコードスニペットをまとめたドキュメントです。
- **`IMPLEMENTATION.md`**: 実装に関する詳細な説明や設計思想を記述したドキュメントです。
- **`LICENSE`**: プロジェクトのライセンス情報（MIT License）を記載したファイルです。
- **`README.ja.md`**, **`README.md`**: プロジェクトの概要、目的、使い方、ビルド方法などを説明する主要なドキュメント（日本語版と英語版）。
- **`_config.yml`**: GitHub Pagesなどの静的サイトジェネレーターの設定ファイルとして使用されます。
- **`chord2mml-cli/`**: コマンドラインインターフェース (CLI) アプリケーションのクレートです。
    - **`chord2mml-cli/Cargo.toml`**: CLIクレートの依存関係とメタデータを定義します。
    - **`chord2mml-cli/README.md`**: CLIツールの使用方法に関する固有のドキュメントです。
    - **`chord2mml-cli/src/main.rs`**: CLIアプリケーションのエントリーポイントであり、ユーザーからの入力を受け取り、コアライブラリを呼び出してMMLを生成します。
- **`chord2mml-core/`**: コード進行からMMLへの変換ロジックをカプセル化したRustライブラリクレートです。
    - **`chord2mml-core/Cargo.toml`**: コアライブラリクレートの依存関係とメタデータを定義します。
    - **`chord2mml-core/examples/basic.rs`**: コアライブラリの基本的な使用方法を示すサンプルコードです。
    - **`chord2mml-core/src/ast.rs`**: 抽象構文木（AST）のデータ構造を定義します。これはTree-sitterが生成するCSTから変換された、意味的に重要な構造です。
    - **`chord2mml-core/src/lib.rs`**: コアライブラリのメインファイルで、パーシング、AST変換、MML生成の主要なロジックを統合します。
    - **`chord2mml-core/src/mml.rs`**: ASTからMML文字列を生成する具体的なロジックを含みます。
    - **`chord2mml-core/src/note.rs`**: 音符や音階に関するデータ構造やユーティリティ関数を定義します。
    - **`chord2mml-core/src/parser.rs`**: Tree-sitterパーサーのRustラッパーと、CST（具象構文木）からASTへの変換ロジックを実装します。
- **`chord2mml-wasm/`**: WebAssembly (WASM) ターゲット向けのRustライブラリクレートです。
    - **`chord2mml-wasm/Cargo.toml`**: WASMクレートの依存関係とメタデータを定義します。
    - **`chord2mml-wasm/src/lib.rs`**: WebAssemblyモジュールとしてエクスポートされる関数を定義し、RustのコアロジックをWebブラウザで利用可能にします。
- **`chord2mml-web/`**: Webベースのデモンストレーションおよびインターフェースを提供するディレクトリです。
    - **`chord2mml-web/README.md`**: Webインターフェースに関する固有のドキュメントです。
    - **`chord2mml-web/index.html`**: WebアプリケーションのエントリーポイントとなるメインHTMLファイルです。
    - **`chord2mml-web/package.json`**: Webフロントエンドの依存関係、スクリプト、メタデータを管理します。
    - **`chord2mml-web/src/main.ts`**: WebアプリケーションのメインTypeScriptファイルで、WASMモジュールをロードし、ユーザーインターフェースを操作してコード進行の変換と再生を行います。
    - **`chord2mml-web/tsconfig.json`**: TypeScriptコンパイラの設定ファイルです。
    - **`chord2mml-web/vite.config.ts`**: Viteビルドツールの設定ファイルです。
- **`generated-docs/`**: 自動生成されたドキュメントを格納するためのディレクトリです。
- **`issue-notes/`**: 開発中のイシューに関するメモやドラフトが格納されています（主に開発者向け）。
- **`tree-sitter-chord/`**: コード進行記法のTree-sitterグラマー定義を含むディレクトリです。（`_codeql_detected_source_root/` と実質的に同じ内容を含みます。）
    - **`tree-sitter-chord/Cargo.toml`**: Tree-sitterグラマーのRustバインディングに関するメタデータを定義します。
    - **`tree-sitter-chord/binding.gyp`**: Node.jsネイティブモジュール（Tree-sitterバインディング）のビルド設定ファイルです。
    - **`tree-sitter-chord/bindings/node/index.js`**: Node.js環境でTree-sitterグラマーをロードするためのJavaScriptスクリプトです。
    - **`tree-sitter-chord/bindings/rust/build.rs`**: Rustバインディングのビルドプロセスを定義するスクリプトです。
    - **`tree-sitter-chord/bindings/rust/lib.rs`**: Rustバインディングのライブラリコードです。
    - **`tree-sitter-chord/grammar.js`**: コード記法の構文ルールをJavaScript形式で記述したTree-sitterグラマーの定義ファイルです。
    - **`tree-sitter-chord/package.json`**: Node.js関連の依存関係とスクリプト（Tree-sitterグラマー用）を管理します。
    - **`tree-sitter-chord/src/grammar.json`**: Tree-sitterグラマーのJSON形式の定義ファイルです。
    - **`tree-sitter-chord/src/node-types.json`**: Tree-sitterが生成するノードの型定義です。
    - **`tree-sitter-chord/src/parser.c`**: Tree-sitterグラマーから生成されたC言語のパーサーコードです。
    - **`tree-sitter-chord/src/tree_sitter/parser.h`**: 生成されたパーサーのヘッダーファイルです。

## 関数詳細説明
- **`convert(input: &str) -> Result<String, Error>`** (chord2mml-core/src/lib.rs):
    - **役割**: 入力されたコード進行のテキストを解析し、MML形式の文字列に変換する、ライブラリのコア機能を提供します。
    - **引数**: `input` - 変換対象となるコード進行を表す文字列（例: "C-F-G-C"）。
    - **戻り値**: 成功時にはMML文字列を`Ok(String)`で、失敗時にはエラー情報を`Err(Error)`で返します。
    - **機能**: Tree-sitterを用いてCSTを構築し、それをASTに変換した後、最終的にMML文字列を生成する一連の変換ロジックを担います。
- **`main()`** (chord2mml-cli/src/main.rs):
    - **役割**: コマンドラインインターフェース（CLI）アプリケーションのエントリーポイントです。
    - **引数**: なし（コマンドライン引数はRustの`std::env::args`などで内部的に処理されます）。
    - **戻り値**: なし（プログラムの実行結果としてMMLを標準出力に出力します）。
    - **機能**: コマンドライン引数または標準入力からコード進行の文字列を受け取り、`chord2mml-core`クレートの`convert`関数を呼び出してMMLを生成し、その結果を標準出力に表示します。
- **`showStatus(message: string)`** (chord2mml-web/src/main.ts):
    - **役割**: WebUI上でユーザーに現在の状態や処理に関するメッセージを表示します。
    - **引数**: `message` - Webページに表示するステータス文字列。
    - **戻り値**: なし。
    - **機能**: Webページの特定のDOM要素（例: `id="status"`を持つ`<div>`）のテキストコンテンツを動的に更新し、ユーザーに処理の進捗や結果に関するフィードバックを提供します。
- **`updateOutput(mml: string)`** (chord2mml-web/src/main.ts):
    - **役割**: 変換されたMML文字列をWebUIの出力エリアに表示・更新します。
    - **引数**: `mml` - Webページに表示するMML文字列。
    - **戻り値**: なし。
    - **機能**: `chord2mml-wasm`によって生成されたMML文字列をWebページの出力表示領域（例: `id="output"`を持つ`<textarea>`）にセットし、ユーザーが確認できるようにします。
- **`initialize()`** (chord2mml-web/src/main.ts):
    - **役割**: Webアプリケーションの初期設定と、WASMモジュールのロードを行います。
    - **引数**: なし。
    - **戻り値**: なし。
    - **機能**: Webページがロードされた際に一度だけ実行され、必要なDOM要素の取得、イベントリスナーの設定、`chord2mml-wasm`モジュールの初期化とロードなどを担当し、アプリケーションを動作可能な状態にします。
- **`play()`** (chord2mml-web/src/main.ts):
    - **役割**: 現在WebUIに表示されているMML文字列を基に音声を再生します。
    - **引数**: なし。
    - **戻り値**: なし。
    - **機能**: 表示されているMML文字列を解析し、ブラウザのWeb Audio API（または将来的に`Tone.js`などのライブラリ）を利用して音符として再生します。
- **`catch()`** (tree-sitter-chord/bindings/node/index.js):
    - **役割**: Node.js環境でTree-sitterバインディングをロードする際のエラーを捕捉するための一般的なJavaScriptの機能。
    - **引数**: 通常はエラーオブジェクト。
    - **戻り値**: なし（エラー処理を実行）。
    - **機能**: `try...catch`ブロックの一部として、モジュールのロードやパス解決中に発生する例外を検知し、適切なエラーメッセージの出力や代替パスの試行などのエラーハンドリングを行います。
- **`if()`** (tree-sitter-chord/bindings/node/index.js):
    - **役割**: Node.js環境でTree-sitterバインディングをロードする際の条件分岐を制御するための一般的なJavaScriptの機能。
    - **引数**: 評価される真偽値。
    - **戻り値**: なし（条件に基づいて異なるコードパスを実行）。
    - **機能**: 環境変数やビルドパスの存在など、特定の条件に応じて異なるバインディングファイルを選択してロードするなど、ロジックの流れを制御します。

## 関数呼び出し階層ツリー
```
- WebアプリケーションUI関連のフロー (chord2mml-web/src/main.ts)
  - initialize()
  - showStatus(message: string)
  - updateOutput(mml: string)
    - play()
- Tree-sitter Node.jsバインディング内部関数 (tree-sitter-chord/bindings/node/index.js)
  - catch()
  - if()

---
Generated at: 2026-01-15 07:02:37 JST
