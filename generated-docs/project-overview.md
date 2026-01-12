Last updated: 2026-01-13

# Project Overview

## プロジェクト概要
- コード進行を音楽マクロ言語（MML）に変換するRust製の堅牢なライブラリおよびCLIツールです。
- Tree-sitterによる正確な構文解析とCSTからASTへの変換パイプラインを核に構築されています。
- 開発者がコード進行からMMLを効率的に生成し、ネイティブアプリケーションやWebフロントエンドで利用できるように設計されています。

## 技術スタック
- フロントエンド:
    - **TypeScript**: Webインターフェース開発に使用されるJavaScriptのスーパーセットで、型安全な開発を可能にします。
    - **HTML**: Webページの構造を定義するためのマークアップ言語です。
    - **Vite**: 高速な開発体験を提供する、次世代のフロントエンドビルドツールです。
    - **WASM (WebAssembly)** (将来的な導入予定): RustコードをWebブラウザで高速に実行するためのバイナリ形式です。
- 音楽・オーディオ:
    - **MML (Music Macro Language)**: 音楽を表現するためのテキストベースのマクロ言語で、このプロジェクトの変換ターゲットです。
    - **Tone.js 関連ライブラリ** (将来的な導入予定): `tonejs-mml-to-json` (MML解析) と `tonejs-json-sequencer` (音声再生) は、MMLの高度な処理と音声出力機能の統合を目的としています。
- 開発ツール:
    - **Node.js**: JavaScript実行環境で、特にTree-sitterグラマーのビルドツール (`tree-sitter-cli`) の実行に必要です。
    - **CodeQL**: セキュリティ脆弱性分析ツールで、コードベースの品質維持に貢献します。
- テスト:
    - **Cargo test**: Rustに標準搭載されているテストフレームワークで、ユニットテストや統合テストの実行に使用されます。
- ビルドツール:
    - **Rust Cargo**: Rustプロジェクトのビルド、依存関係管理、テスト実行などを一元的に行うツールです。
    - **tree-sitter-cli**: Tree-sitterグラマーをコンパイルし、パーサーを生成するためのコマンドラインツールです。
- 言語機能:
    - **Rust**: システムプログラミング言語で、パフォーマンスと安全性に優れ、本プロジェクトのコアロジックに使用されています。
    - **Tree-sitter**: 高速で堅牢な構文解析エンジンで、コード記法のCST（具象構文木）を生成します。
    - **JavaScript**: Tree-sitterグラマーの定義やNode.jsバインディング、Webフロントエンドの一部で使用されます。
- 自動化・CI/CD:
    - (特になし)
- 開発標準:
    - **MIT License**: ソフトウェアの利用、改変、再配布に関するオープンソースライセンスです。

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
-   `.gitignore`: Gitのバージョン管理から除外するファイルやディレクトリを指定します。
-   `Cargo.lock`: Rustプロジェクトの依存関係の正確なバージョンを記録し、ビルドの一貫性を保証します。
-   `Cargo.toml`: Rustプロジェクトのマニフェストファイルで、プロジェクトのメタデータ、依存関係、ビルド設定を定義します。
-   `EXAMPLES.md`: プロジェクトの様々な使用例やコードスニペットを説明するドキュメントです。
-   `IMPLEMENTATION.md`: プロジェクトの実装の詳細や技術的な決定事項を記述するドキュメントです。
-   `LICENSE`: プロジェクトのライセンス情報（MIT License）が記載されています。
-   `README.ja.md`: プロジェクトの概要、使い方、機能などを日本語で説明する主要なドキュメントです。
-   `README.md`: プロジェクトの概要、使い方、機能などを英語で説明する主要なドキュメントです。
-   `_codeql_detected_source_root/`: CodeQLによるコード解析の対象として検出されたルートディレクトリです。
    -   `_codeql_detected_source_root/Cargo.toml`: CodeQL解析用のCargo設定ファイルです。
    -   `_codeql_detected_source_root/binding.gyp`: Node.jsネイティブモジュールをビルドするための設定ファイルです。
    -   `_codeql_detected_source_root/bindings/node/binding.cc`: Tree-sitterパーサーのNode.jsバインディングのC++実装です。
    -   `_codeql_detected_source_root/bindings/node/index.js`: Tree-sitterパーサーのNode.jsバインディングのエントリーポイントです。
    -   `_codeql_detected_source_root/bindings/rust/build.rs`: Tree-sitterパーサーのRustバインディングのビルドスクリプトです。
    -   `_codeql_detected_source_root/bindings/rust/lib.rs`: Tree-sitterパーサーのRustバインディングのライブラリコードです。
    -   `_codeql_detected_source_root/grammar.js`: コード記法の構文ルールを定義するTree-sitterグラマーのJavaScriptファイルです。
    -   `_codeql_detected_source_root/package.json`: Node.jsプロジェクトのメタデータと依存関係を記述するファイルです。
    -   `_codeql_detected_source_root/src/grammar.json`: Tree-sitterグラマーのJSON形式の定義ファイルです。
    -   `_codeql_detected_source_root/src/node-types.json`: Tree-sitterパーサーが生成する構文ノードの型定義ファイルです。
    -   `_codeql_detected_source_root/src/parser.c`: Tree-sitterグラマーから自動生成されたC言語のパーサーコードです。
    -   `_codeql_detected_source_root/src/tree_sitter/parser.h`: Tree-sitterパーサーのC言語ヘッダーファイルです。
-   `_config.yml`: Jekyllなどの静的サイトジェネレーターの設定ファイルで、GitHub Pagesなどで利用されることがあります。
-   `chord2mml-cli/`: コマンドラインインターフェース（CLI）アプリケーション関連のファイル群を格納するディレクトリです。
    -   `chord2mml-cli/Cargo.toml`: CLIアプリケーションのCargo設定ファイルです。
    -   `chord2mml-cli/README.md`: CLIツールの使い方や機能に関する説明ドキュメントです。
    -   `chord2mml-cli/src/main.rs`: CLIアプリケーションのエントリーポイントとなるRustソースファイルで、ユーザーからの入力を処理し、コアライブラリを呼び出します。
-   `chord2mml-core/`: コード進行からMMLへの変換を行う主要なロジックを含むRustライブラリのファイル群を格納するディレクトリです。
    -   `chord2mml-core/Cargo.toml`: コアライブラリのCargo設定ファイルです。
    -   `chord2mml-core/examples/basic.rs`: コアライブラリの基本的な使用方法を示すRustのサンプルコードです。
    -   `chord2mml-core/src/ast.rs`: 抽象構文木（AST）のデータ構造を定義するRustファイルです。
    -   `chord2mml-core/src/lib.rs`: コアライブラリの主要な機能（パーサー、AST変換、MML生成）を統合するメインファイルです。
    -   `chord2mml-core/src/mml.rs`: ASTからMML文字列を生成するためのロジックを含むRustファイルです。
    -   `chord2mml-core/src/note.rs`: 音楽的なノートや音程に関する定義を含むRustファイルです。
    -   `chord2mml-core/src/parser.rs`: Tree-sitterパーサーを利用してCST（具象構文木）をASTに変換するロジックを含むRustファイルです。
-   `chord2mml-wasm/`: WebAssembly (WASM) 対応を目的としたサブプロジェクトのファイル群を格納するディレクトリです。（WIP）
    -   `chord2mml-wasm/Cargo.toml`: WASMビルド用のCargo設定ファイルです。
    -   `chord2mml-wasm/src/lib.rs`: WASMモジュールとして公開されるRustコードです。
-   `chord2mml-web/`: Webインターフェースアプリケーションのファイル群を格納するディレクトリです。
    -   `chord2mml-web/README.md`: Webインターフェースの説明ドキュメントです。
    -   `chord2mml-web/index.html`: WebアプリケーションのメインHTMLファイルです。
    -   `chord2mml-web/package.json`: WebアプリケーションのNode.jsプロジェクト設定ファイルです。
    -   `chord2mml-web/src/main.ts`: Webアプリケーションの主要なTypeScriptコードで、WASMモジュールのロード、UI操作、MML変換処理を扱います。
    -   `chord2mml-web/tsconfig.json`: TypeScriptコンパイラの設定ファイルです。
    -   `chord2mml-web/vite.config.ts`: Viteビルドツールの設定ファイルです。
-   `generated-docs/`: 自動生成されたドキュメントを格納するためのディレクトリです。
-   `issue-notes/`: 開発中に発生した課題や検討事項をメモとして残しているディレクトリです。
-   `tree-sitter-chord/`: Tree-sitterグラマーの定義とその関連ファイルを格納するディレクトリです。
    -   `tree-sitter-chord/Cargo.toml`: Tree-sitterグラマーのRustバインディング用のCargo設定ファイルです。
    -   `tree-sitter-chord/binding.gyp`: Node.jsネイティブモジュールビルド設定ファイルです。
    -   `tree-sitter-chord/bindings/node/binding.cc`: Node.jsバインディングのC++実装です。
    -   `tree-sitter-chord/bindings/node/index.js`: Tree-sitterパーサーのNode.jsバインディングのエントリーポイントです。
    -   `tree-sitter-chord/bindings/rust/build.rs`: Rustバインディングのビルドスクリプトです。
    -   `tree-sitter-chord/bindings/rust/lib.rs`: Rustバインディングのライブラリコードです。
    -   `tree-sitter-chord/grammar.js`: Tree-sitterグラマーのJavaScript定義ファイルです。
    -   `tree-sitter-chord/package.json`: Node.jsプロジェクトのメタデータと依存関係を記述するファイルです。
    -   `tree-sitter-chord/src/grammar.json`: Tree-sitterグラマーのJSON形式の定義ファイルです。
    -   `tree-sitter-chord/src/node-types.json`: Tree-sitterパーサーが生成するノードの型定義ファイルです。
    -   `tree-sitter-chord/src/parser.c`: Tree-sitterグラマーから自動生成されたC言語パーサーコードです。
    -   `tree-sitter-chord/src/tree_sitter/parser.h`: Tree-sitterパーサーのC言語ヘッダーファイルです。

## 関数詳細説明
-   `catch` (`_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`):
    -   役割: モジュールロード時のエラーを捕捉し、適切なエラーハンドリングを行うために使用されます。
    -   引数: (おそらく `error`: エラーオブジェクト)
    -   戻り値: なし
-   `if` (`_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`):
    -   役割: モジュールロードの際に、環境やビルド設定（例: デバッグ/リリース）に基づいて異なるパスを条件分岐するために使用されます。
    -   引数: (おそらく `condition`: 評価される条件式)
    -   戻り値: なし
-   `showStatus` (`chord2mml-web/src/main.ts`):
    -   役割: Webユーザーインターフェース上に、アプリケーションの現在の状態や処理メッセージを表示します。
    -   引数: (おそらく `message`: 表示するステータスメッセージの文字列)
    -   戻り値: なし
-   `updateOutput` (`chord2mml-web/src/main.ts`):
    -   役割: Web UI上の出力エリアを更新し、変換されたMMLやその他の結果を表示します。
    -   引数: (おそらく `mmlOutput`: 表示するMML文字列または関連データ)
    -   戻り値: なし
-   `initialize` (`chord2mml-web/src/main.ts`):
    -   役割: Webアプリケーションの初期設定を行います。これには、WebAssemblyモジュールのロードやイベントリスナーの登録などが含まれる可能性があります。
    -   引数: なし
    -   戻り値: (おそらく `Promise<void>`: 非同期処理の完了を示す)
-   `play` (`chord2mml-web/src/main.ts`):
    -   役割: 生成されたMMLデータに基づき、音楽を再生する機能を提供します。
    -   引数: (おそらく `mmlData`: 再生するMMLデータ)
    -   戻り値: なし

## 関数呼び出し階層ツリー
```
- catch (_codeql_detected_source_root/bindings/node/index.js)
  - showStatus (chord2mml-web/src/main.ts)
    - updateOutput ()
      - initialize ()
      - play ()
- if (_codeql_detected_source_root/bindings/node/index.js)

---
Generated at: 2026-01-13 07:02:15 JST
