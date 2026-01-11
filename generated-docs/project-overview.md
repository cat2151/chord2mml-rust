Last updated: 2026-01-12

# Project Overview

## プロジェクト概要
- コード進行をMML形式（Music Macro Language）に変換し、Webブラウザで音を鳴らせるアプリケーションです。
- Rust言語で開発された高速な変換コアと、WebAssemblyによるブラウザ対応が特徴です。
- 開発者はRustライブラリとしても利用でき、将来的にはより高度な構文解析機能が導入されます。

## 技術スタック
- フロントエンド:
    - **TypeScript**: Webアプリケーション（`chord2mml-web`）の開発に使用される、JavaScriptに静的型付けを追加した言語。コードの堅牢性と保守性を向上させます。
    - **JavaScript**: WebAssembly（WASM）モジュールのロードと連携、Web Audio APIの操作、およびTree-sitterパーサーのNode.jsバインディングのラッパーとして使用されます。
    - **Web Audio API**: ブラウザ上で直接音声を生成・加工・再生するためのAPI。現在のWebアプリケーションでの音声再生に利用されています。
- 音楽・オーディオ:
    - **Web Audio API**: 現在、WebアプリケーションでMMLを音声に変換し、ブラウザで再生するために使用されています。
    - **tonejs-mml-to-json (将来導入予定)**: MMLをJSON形式に解析するためのライブラリ。より高度なMML処理を目指しています。
    - **tonejs-json-sequencer (将来導入予定)**: JSON形式のシーケンスデータを基に音楽を再生するためのライブラリ。Web Audio APIと連携し、より表現豊かな演奏を可能にします。
- 開発ツール:
    - **wasm-pack**: Rustで書かれたコードをWebAssemblyにコンパイルし、Webアプリケーションから利用可能な形式にパッケージ化するためのツール。
    - **Node.js**: Webアプリケーションの開発環境（パッケージ管理、ビルドスクリプト実行）や、Tree-sitterパーサーのNode.jsバインディングのテスト環境として使用されます。
    - **npm**: Node.jsのパッケージマネージャー。Webアプリケーションの依存関係の管理とスクリプト実行に利用されます。
    - **Vite**: 高速な開発サーバーとバンドル機能を提供するフロントエンドビルドツール。Webアプリケーションのビルドに使用されます。
    - **Tree-sitter (パーサーコアとして将来導入予定)**: コードの構文解析を行うためのパーサー生成フレームワーク。より堅牢で複雑なコード進行の解析を実現するために、将来的にRustコアに導入される予定です。関連ファイルは既にプロジェクト内に存在します。
- テスト:
    - **Cargo Test**: Rustコードのユニットテストを実行するためのRust標準テストツール。`chord2mml-core`や`chord2mml-wasm`のテストに使用されます。
    - **wasm-pack test --node**: WebAssemblyモジュールのNode.js環境での統合テストを実行するためのコマンド。
    - **npm test**: Webアプリケーション（`chord2mml-web`）のテストを実行するためのスクリプト。
- ビルドツール:
    - **Cargo**: Rustプロジェクトのビルドシステムおよびパッケージマネージャー。Rustライブラリ (`chord2mml-core`) やWASMバインディング (`chord2mml-wasm`) のビルドに使用されます。
    - **wasm-pack**: RustコードをWebAssemblyにコンパイルする際の主要なビルドツール。
    - **Vite**: Webアプリケーション (`chord2mml-web`) の開発と本番ビルドを行うためのツール。
- 言語機能:
    - **Rust**: 高性能でメモリ安全なシステムプログラミング言語。プロジェクトのコアロジックを担い、強力な型システムと所有権システムにより、高い信頼性と実行速度を提供します。
    - **TypeScript**: JavaScriptに静的型付けを追加することで、大規模なWebアプリケーション開発におけるコードの品質と保守性を向上させる言語。
- 自動化・CI/CD: 該当なし (提供情報に基づくと、具体的なCI/CDパイプラインや自動化ツールに関する記述はありません。)
- 開発標準: 該当なし (提供情報に基づくと、具体的なコード品質ツールや統一ルールに関する記述はありません。)

## ファイル階層ツリー
```
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
```

## ファイル詳細説明
-   **README.ja.md / README.md**: プロジェクトの概要、使い方、アーキテクチャ、技術スタックなどの全体像を説明するドキュメントで、日本語版と英語版が用意されています。
-   **Cargo.toml**: 各Rustクレート（プロジェクトのサブコンポーネント）の依存関係、メタデータ、ビルド設定を定義するファイルです。
-   **Cargo.lock**: `Cargo.toml`に基づいて解決された、プロジェクトが使用する正確な依存関係のバージョンを記録するファイル。
-   **LICENSE**: プロジェクトのライセンス情報（MIT License）を記載しています。
-   **_config.yml**: GitHub Pagesなどのウェブサイト設定に関連するファイルである可能性があります。
-   **_codeql_detected_source_root/**: CodeQLによって自動検出されたソースルートを示すディレクトリ。`tree-sitter-chord`と関連するTree-sitterパーサーのソースコードが含まれている可能性があります。
-   **_codeql_detected_source_root/bindings/node/index.js**: Tree-sitterパーサーのNode.jsバインディングをロードするためのJavaScriptラッパー。
-   **_codeql_detected_source_root/grammar.js**: Tree-sitterパーサーの構文をJavaScriptで定義したファイル。
-   **chord2mml-core/**: コード進行をMMLに変換するRustで書かれたコアロジックを格納するディレクトリです。
    -   **chord2mml-core/Cargo.toml**: `chord2mml-core`クレートの依存関係とメタデータ。
    -   **chord2mml-core/src/lib.rs**: コード進行をパースしてMMLに変換する主要なRustライブラリのコードが含まれています。
-   **chord2mml-wasm/**: `chord2mml-core`の機能をWebAssembly（WASM）としてビルドするためのコードを格納するディレクトリです。
    -   **chord2mml-wasm/Cargo.toml**: `chord2mml-wasm`クレートの依存関係とメタデータ。
    -   **chord2mml-wasm/src/lib.rs**: Rustコア機能をWebアプリケーションから呼び出せるようにするためのWASMバインディングロジックを実装しています。
-   **chord2mml-web/**: ブラウザ上で動作するWebアプリケーションのソースコードを格納するディレクトリです。
    -   **chord2mml-web/README.md**: Webアプリケーションに関する詳細な情報。
    -   **chord2mml-web/index.html**: WebアプリケーションのエントリーポイントとなるHTMLファイル。ユーザーインターフェースの骨格を定義します。
    -   **chord2mml-web/package.json**: Webアプリケーションの依存関係、ビルドスクリプト、メタデータを定義するNode.jsパッケージ設定ファイル。
    -   **chord2mml-web/src/main.ts**: Webアプリケーションのメインスクリプト。WASMモジュールのロード、ユーザー入力の処理、MML変換結果の表示、Web Audio APIによる音声再生を制御します。
    -   **chord2mml-web/tsconfig.json**: TypeScriptコンパイラの設定ファイル。
    -   **chord2mml-web/vite.config.ts**: Viteビルドツールの設定ファイル。Webアプリケーションの開発サーバーや本番ビルドの設定を定義します。
-   **generated-docs/**: プロジェクトから自動生成されたドキュメント（例：Rustの`cargo doc`で生成されるAPIドキュメント）が格納される可能性があるディレクトリです。
-   **issue-notes/2.md**: 特定のIssueに関連する開発者向けのメモや詳細情報を記録したファイル。
-   **tree-sitter-chord/**: コード進行を解析するためのTree-sitterパーサーに関連するファイルを格納するディレクトリです。これは将来的なパーサーの移行のために用意されています。
    -   **tree-sitter-chord/Cargo.toml**: `tree-sitter-chord`クレート（Tree-sitterパーサーのRustバインディング）の依存関係。
    -   **tree-sitter-chord/binding.gyp**: Node.jsネイティブモジュールのビルド設定ファイル。
    -   **tree-sitter-chord/bindings/node/binding.cc**: Tree-sitterパーサーのNode.jsネイティブバインディングのC++実装。
    -   **tree-sitter-chord/bindings/node/index.js**: Node.js環境でTree-sitterパーサーをロード・利用するためのJavaScriptラッパー。
    -   **tree-sitter-chord/bindings/rust/build.rs**: RustクレートがCライブラリをビルドするためのスクリプト。
    -   **tree-sitter-chord/bindings/rust/lib.rs**: Tree-sitterパーサーのRustバインディングライブラリ。
    -   **tree-sitter-chord/grammar.js**: Tree-sitterパーサーの構文定義をJavaScriptで記述したファイル。
    -   **tree-sitter-chord/src/grammar.json**: Tree-sitterパーサーの構文定義をJSON形式で表現したファイル。
    -   **tree-sitter-chord/src/node-types.json**: Tree-sitterパーサーが生成するASTノードの型定義。
    -   **tree-sitter-chord/src/parser.c**: Tree-sitterのCLIツールによって生成されたC言語のパーサー実装。
    -   **tree-sitter-chord/src/tree_sitter/parser.h**: Tree-sitterパーサーのC言語ヘッダーファイル。

## 関数詳細説明
-   **catch** ( `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js` )
    -   **役割**: Tree-sitterパーサーのNode.jsバインディングをロードする際に発生したエラーを捕捉し、適切に処理する機能の一部です。
    -   **機能**: 通常、try-catchブロック内で使用され、指定されたモジュールのロード失敗などの例外を捕らえ、エラーメッセージを出力するなどの処理を行います。
-   **if** ( `_codeql_detected_source_root/bindings/node/index.js`, `tree-sitter-chord/bindings/node/index.js` )
    -   **役割**: 条件分岐を行い、特定の条件に基づいて異なるモジュールをロードするかどうかを判断する機能です。
    -   **機能**: 例えば、デバッグビルドとリリースビルドのどちらのTree-sitterバインディングをロードするかを決定する際に用いられます。
-   **showStatus** ( `chord2mml-web/src/main.ts` )
    -   **役割**: Webアプリケーションのユーザーインターフェース上で、現在の処理状況やメッセージを表示するための関数です。
    -   **機能**: 主に、ユーザーへのフィードバック（例: 「WASMモジュールをロード中...」）を提供するために使用されます。
-   **updateOutput** ( `chord2mml-web/src/main.ts` )
    -   **役割**: WebアプリケーションのUI上のMML出力エリアを更新する関数です。
    -   **機能**: コード進行の変換結果であるMML文字列を、ユーザーインターフェースの指定された要素に表示します。
-   **initialize** ( `chord2mml-web/src/main.ts` )
    -   **役割**: WebアプリケーションやWASMモジュールの初期化処理を実行する関数です。
    -   **機能**: WASMモジュールのロード、イベントリスナーの設定、初期状態のUI更新など、アプリケーションが動作を開始するために必要な準備を行います。
-   **constructor** ( `chord2mml-web/src/main.ts` )
    -   **役割**: クラスインスタンスが生成される際に呼び出される特殊な関数です。
    -   **機能**: クラスのプロパティを初期化したり、インスタンス固有のセットアップを行ったりします。Web Audio APIやTone.js関連ライブラリのインスタンス初期化の一部である可能性があります。
-   **play** ( `chord2mml-web/src/main.ts` )
    -   **役割**: 生成されたMMLに基づいて音声を再生する関数です。
    -   **機能**: Web Audio APIや将来的に導入されるTone.js系のライブラリを利用し、MMLを解析して音符を生成し、ブラウザ上で実際に音を鳴らします。

## 関数呼び出し階層ツリー
```
- catch (_codeql_detected_source_root/bindings/node/index.js)
- if (_codeql_detected_source_root/bindings/node/index.js)
- showStatus (chord2mml-web/src/main.ts)
  - updateOutput ()
  - initialize ()
  - constructor (undefined)

---
Generated at: 2026-01-12 07:02:11 JST
