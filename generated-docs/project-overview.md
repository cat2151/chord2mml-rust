Last updated: 2026-01-14

# Project Overview

## プロジェクト概要
- コード進行テキストをMML（Music Macro Language）へ変換するRust製のライブラリおよびCLIツールです。
- Tree-sitterによる堅牢な構文解析と、CSTからASTを経てMMLを生成する独自の変換パイプラインが特徴です。
- 音楽のコード進行をプログラムで簡単に扱い、MMLとして出力することで、音楽制作や学習を支援します。

## 技術スタック
- フロントエンド:
    - TypeScript: WebベースのデモUI (`chord2mml-web`) の開発に使用される言語。静的型付けにより大規模開発の堅牢性を高めます。
    - Vite: モダンなフロントエンドビルドツール。高速な開発サーバーと最適化されたビルドを提供し、Web UI開発を効率化します。
- 音楽・オーディオ: (このプロジェクトはMMLを生成することに特化しており、直接的な音楽・オーディオ再生技術は含みません。MML生成が音楽表現の基盤となります。)
- 開発ツール:
    - Rust: プロジェクトの主要開発言語。高いパフォーマンスとメモリ安全性を提供し、堅牢な変換ロジックを構築します。
    - Tree-sitter: 構文解析エンジン。コード記法の堅牢かつ効率的なパース（解析）のために使用されます。
    - Node.js: `tree-sitter-cli` などのツールを実行するためのJavaScriptランタイム環境です。
    - tree-sitter-cli: Tree-sitterのグラマー定義ファイルを生成・管理するためのコマンドラインツールです。
- テスト:
    - `cargo test`: Rustの標準テストフレームワーク。各クレート（ライブラリ、CLI）の機能が正しく動作することを確認するための包括的な単体・統合テストを実行します。
- ビルドツール:
    - Cargo: Rustの公式ビルドシステムおよびパッケージマネージャー。プロジェクトのコンパイル、依存関係管理、テスト実行などを一元的に行います。
    - Vite: Web UI (`chord2mml-web`) の開発および本番向けビルドを行います。
- 言語機能:
    - Rust言語機能: 豊富な標準ライブラリ、パターンマッチング、所有権システム、マクロなどを活用し、高性能で安全なコードを実現します。
    - Tree-sitterグラマー定義言語: 特定の構文（この場合はコード記法）を定義するためのDSL（ドメイン固有言語）として使用されます。
- 自動化・CI/CD: (プロジェクト情報には具体的な自動化・CI/CDツールに関する記述はありません。)
- 開発標準: (プロジェクト情報には具体的な開発標準・コード品質ツールに関する記述はありません。)

## ファイル階層ツリー
```
.
├── .gitignore
├── Cargo.lock
├── Cargo.toml
├── EXAMPLES.md
├── IMPLEMENTATION.md
├── LICENSE
├── README.ja.md
├── README.md
├── _codeql_detected_source_root/
│   ├── Cargo.toml
│   ├── binding.gyp
│   ├── bindings/
│   │   ├── node/
│   │   │   ├── binding.cc
│   │   │   └── index.js
│   │   └── rust/
│   │       ├── build.rs
│   │       └── lib.rs
│   ├── grammar.js
│   ├── package.json
│   └── src/
│       ├── grammar.json
│       ├── node-types.json
│       ├── parser.c
│       └── tree_sitter/
│           └── parser.h
├── _config.yml
├── chord2mml-cli/
│   ├── Cargo.toml
│   ├── README.md
│   └── src/
│       └── main.rs
├── chord2mml-core/
│   ├── Cargo.toml
│   ├── examples/
│   │   └── basic.rs
│   └── src/
│       ├── ast.rs
│       ├── lib.rs
│       ├── mml.rs
│       ├── note.rs
│       └── parser.rs
├── chord2mml-wasm/
│   ├── Cargo.toml
│   └── src/
│       └── lib.rs
├── chord2mml-web/
│   ├── README.md
│   ├── index.html
│   ├── package.json
│   ├── src/
│   │   └── main.ts
│   ├── tsconfig.json
│   └── vite.config.ts
├── generated-docs/
├── issue-notes/
│   ├── 11.md
│   ├── 13.md
│   ├── 15.md
│   ├── 17.md
│   ├── 19.md
│   ├── 2.md
│   ├── 20.md
│   ├── 21.md
│   ├── 22.md
│   ├── 5.md
│   ├── 7.md
│   └── 9.md
└── tree-sitter-chord/
    ├── Cargo.toml
    ├── binding.gyp
    ├── bindings/
    │   ├── node/
    │   │   ├── binding.cc
    │   │   └── index.js
    │   └── rust/
    │       ├── build.rs
    │       └── lib.rs
    ├── grammar.js
    ├── package.json
    └── src/
        ├── grammar.json
        ├── node-types.json
        ├── parser.c
        └── tree_sitter/
            └── parser.h
```

## ファイル詳細説明

-   `.gitignore`: Gitによるバージョン管理から除外するファイルやディレクトリを指定します。
-   `Cargo.lock`: Rustプロジェクトの依存関係の正確なバージョンを記録します。
-   `Cargo.toml`: Rustプロジェクトのマニフェストファイル。プロジェクトのメタデータ、依存関係、ビルド設定などを定義します。
-   `EXAMPLES.md`: プロジェクトの具体的な使用例やデモンストレーションを記述したMarkdownファイルです。
-   `IMPLEMENTATION.md`: プロジェクトの実装に関する詳細な説明や設計思想が記述されたMarkdownファイルです。
-   `LICENSE`: プロジェクトのライセンス情報（MIT License）を記述したファイルです。
-   `README.ja.md`: プロジェクトの日本語での概要、使い方、特徴などをまとめたメインのドキュメントファイルです。
-   `README.md`: プロジェクトの英語での概要、使い方、特徴などをまとめたメインのドキュメントファイルです。
-   `_codeql_detected_source_root/` ディレクトリ:
    -   `bindings/node/index.js`: Node.js環境でTree-sitterパーサーをロードするためのJavaScriptバインディングスクリプトです。
    -   `grammar.js`: Tree-sitterの文法定義ファイル。コード記法の構文ルール（例: C, Dm, G7）を記述します。
    -   `package.json`: Node.jsモジュールのメタデータや依存関係を定義します。
    -   `src/grammar.json`: `grammar.js` から生成されたJSON形式の文法定義です。
    -   `src/node-types.json`: Tree-sitterが生成するノードの型情報を定義します。
    -   `src/parser.c`: `grammar.js` から生成されたC言語のパーサーソースコードです。
    -   `src/tree_sitter/parser.h`: C言語パーサーのヘッダーファイルです。
-   `chord2mml-cli/` ディレクトリ:
    -   `Cargo.toml`: CLIアプリケーションの依存関係とメタデータを定義します。
    -   `README.md`: CLIツールの使い方や詳細を記述します。
    -   `src/main.rs`: コマンドラインインターフェースのメインエントリーポイント。`chord2mml-core` ライブラリを利用してコード進行の変換処理を行います。
-   `chord2mml-core/` ディレクトリ:
    -   `Cargo.toml`: コアライブラリの依存関係とメタデータを定義します。
    -   `examples/basic.rs`: `chord2mml-core` ライブラリの基本的な使用方法を示すサンプルコードです。
    -   `src/ast.rs`: 抽象構文木（AST: Abstract Syntax Tree）のデータ構造を定義します。CSTから変換された、意味のあるコード進行の構造を表現します。
    -   `src/lib.rs`: `chord2mml-core` ライブラリの主要な機能（変換関数など）を公開するエントリーポイントです。
    -   `src/mml.rs`: ASTをMML文字列に変換するロジックを実装します。
    -   `src/note.rs`: 音符、音階、和音の構成音など、音楽的な要素に関するユーティリティ関数やデータ構造を定義します。
    -   `src/parser.rs`: Tree-sitterパーサーと連携し、具象構文木（CST）を抽象構文木（AST）に変換するロジックを実装します。
-   `chord2mml-wasm/` ディレクトリ:
    -   `Cargo.toml`: WASMターゲット向けのクレートの依存関係とメタデータを定義します。
    -   `src/lib.rs`: RustコードをWebAssemblyにコンパイルするためのライブラリエントリーポイントです（現在WIP）。
-   `chord2mml-web/` ディレクトリ:
    -   `README.md`: Webアプリケーションの概要と使い方を記述します。
    -   `index.html`: WebアプリケーションのメインとなるHTMLファイル。ユーザーインターフェースを構成します。
    -   `package.json`: Webアプリケーションのフロントエンド関連の依存関係とスクリプトを定義します。
    -   `src/main.ts`: Webアプリケーションの主要なロジックを記述したTypeScriptファイル。UI操作、WASMモジュールの呼び出しなどを管理します。
    -   `tsconfig.json`: TypeScriptコンパイラの設定ファイル。
    -   `vite.config.ts`: Viteビルドツールの設定ファイル。
-   `generated-docs/`: 自動生成されたドキュメントを格納するディレクトリ（想定）。
-   `issue-notes/`: 開発中のIssueに関するメモや詳細情報を格納するMarkdownファイル群です。
-   `tree-sitter-chord/` ディレクトリ:
    -   `Cargo.toml`: Tree-sitterグラマーのRustバインディングに関する依存関係とメタデータを定義します。
    -   `grammar.js`: `_codeql_detected_source_root/grammar.js` と同様に、Tree-sitterの文法定義ファイルです。
    -   `bindings/node/index.js`: `_codeql_detected_source_root/bindings/node/index.js` と同様に、Node.js環境でTree-sitterパーサーをロードするためのJavaScriptバインディングスクリプトです。
    -   `src/parser.c`: `_codeql_detected_source_root/src/parser.c` と同様に、C言語のパーサーソースコードです。

## 関数詳細説明

-   `catch` (ファイル: `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`)
    -   役割: Try-catchブロックの一部として、Promiseの実行中に発生したエラーを捕捉し、適切に処理します。
    -   引数: `error` (捕捉されたエラーオブジェクト)。
    -   戻り値: なし（通常、エラー処理ロジックを実行）。
-   `if` (ファイル: `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js`)
    -   役割: 条件に基づいてコードの実行パスを分岐させます。ここでは、デバッグビルドとリリースビルドのバインディングをロードする条件分岐に使用されます。
    -   引数: `condition` (真偽値に評価される式)。
    -   戻り値: なし（条件に応じたコードブロックを実行）。
-   `showStatus` (ファイル: `chord2mml-web/src/main.ts`)
    -   役割: Web UI上のステータス表示エリアにメッセージを更新し、ユーザーに現在の状態を伝えます。
    -   引数: `message` (string) - 表示するステータスメッセージ。
    -   戻り値: なし。
-   `updateOutput` (ファイル: `chord2mml-web/src/main.ts`)
    -   役割: Web UI上の出力エリア（例: MML変換結果を表示するテキストボックス）を更新します。
    -   引数: `output` (string) - 出力エリアに表示するコンテンツ。
    -   戻り値: なし。
-   `initialize` (ファイル: `chord2mml-web/src/main.ts`)
    -   役割: Webアプリケーションの初期設定やWASMモジュールのロードなど、初期化処理を実行します。
    -   引数: なし。
    -   戻り値: なし。
-   `play` (ファイル: `chord2mml-web/src/main.ts`)
    -   役割: MML変換された結果を元に、音楽を再生する機能を提供します（詳細はプロジェクト情報にないため、抽象的な役割として記述）。
    -   引数: なし。
    -   戻り値: なし。

## 関数呼び出し階層ツリー
```
- catch (_codeql_detected_source_root/bindings/node/index.js)
  - showStatus (chord2mml-web/src/main.ts)
    - updateOutput ()
      - initialize ()
      - play ()
- if (_codeql_detected_source_root/bindings/node/index.js)

---
Generated at: 2026-01-14 07:02:08 JST
