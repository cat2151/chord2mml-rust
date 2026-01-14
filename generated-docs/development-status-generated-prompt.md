Last updated: 2026-01-15

# 開発状況生成プロンプト（開発者向け）

## 生成するもの：
- 現在openされているissuesを3行で要約する
- 次の一手の候補を3つlistする
- 次の一手の候補3つそれぞれについて、極力小さく分解して、その最初の小さな一歩を書く

## 生成しないもの：
- 「今日のissue目標」などuserに提案するもの
  - ハルシネーションの温床なので生成しない
- ハルシネーションしそうなものは生成しない（例、無価値なtaskや新issueを勝手に妄想してそれをuserに提案する等）
- プロジェクト構造情報（来訪者向け情報のため、別ファイルで管理）

## 「Agent実行プロンプト」生成ガイドライン：
「Agent実行プロンプト」作成時は以下の要素を必ず含めてください：

### 必須要素
1. **対象ファイル**: 分析/編集する具体的なファイルパス
2. **実行内容**: 具体的な分析や変更内容（「分析してください」ではなく「XXXファイルのYYY機能を分析し、ZZZの観点でmarkdown形式で出力してください」）
3. **確認事項**: 変更前に確認すべき依存関係や制約
4. **期待する出力**: markdown形式での結果や、具体的なファイル変更

### Agent実行プロンプト例

**良い例（上記「必須要素」4項目を含む具体的なプロンプト形式）**:
```
対象ファイル: `.github/workflows/translate-readme.yml`と`.github/workflows/call-translate-readme.yml`

実行内容: 対象ファイルについて、外部プロジェクトから利用する際に必要な設定項目を洗い出し、以下の観点から分析してください：
1) 必須入力パラメータ（target-branch等）
2) 必須シークレット（GEMINI_API_KEY）
3) ファイル配置の前提条件（README.ja.mdの存在）
4) 外部プロジェクトでの利用時に必要な追加設定

確認事項: 作業前に既存のworkflowファイルとの依存関係、および他のREADME関連ファイルとの整合性を確認してください。

期待する出力: 外部プロジェクトがこの`call-translate-readme.yml`を導入する際の手順書をmarkdown形式で生成してください。具体的には：必須パラメータの設定方法、シークレットの登録手順、前提条件の確認項目を含めてください。
```

**避けるべき例**:
- callgraphについて調べてください
- ワークフローを分析してください
- issue-noteの処理フローを確認してください

## 出力フォーマット：
以下のMarkdown形式で出力してください：

```markdown
# Development Status

## 現在のIssues
[以下の形式で3行でオープン中のissuesを要約。issue番号を必ず書く]
- [1行目の説明]
- [2行目の説明]
- [3行目の説明]

## 次の一手候補
1. [候補1のタイトル。issue番号を必ず書く]
   - 最初の小さな一歩: [具体的で実行可能な最初のアクション]
   - Agent実行プロンプト:
     ```
     対象ファイル: [分析/編集する具体的なファイルパス]

     実行内容: [具体的な分析や変更内容を記述]

     確認事項: [変更前に確認すべき依存関係や制約]

     期待する出力: [markdown形式での結果や、具体的なファイル変更の説明]
     ```

2. [候補2のタイトル。issue番号を必ず書く]
   - 最初の小さな一歩: [具体的で実行可能な最初のアクション]
   - Agent実行プロンプト:
     ```
     対象ファイル: [分析/編集する具体的なファイルパス]

     実行内容: [具体的な分析や変更内容を記述]

     確認事項: [変更前に確認すべき依存関係や制約]

     期待する出力: [markdown形式での結果や、具体的なファイル変更の説明]
     ```

3. [候補3のタイトル。issue番号を必ず書く]
   - 最初の小さな一歩: [具体的で実行可能な最初のアクション]
   - Agent実行プロンプト:
     ```
     対象ファイル: [分析/編集する具体的なファイルパス]

     実行内容: [具体的な分析や変更内容を記述]

     確認事項: [変更前に確認すべき依存関係や制約]

     期待する出力: [markdown形式での結果や、具体的なファイル変更の説明]
     ```
```


# 開発状況情報
- 以下の開発状況情報を参考にしてください。
- Issue番号を記載する際は、必ず [Issue #番号](../issue-notes/番号.md) の形式でMarkdownリンクとして記載してください。

## プロジェクトのファイル一覧
- .github/actions-tmp/.github/workflows/call-callgraph.yml
- .github/actions-tmp/.github/workflows/call-daily-project-summary.yml
- .github/actions-tmp/.github/workflows/call-issue-note.yml
- .github/actions-tmp/.github/workflows/call-rust-windows-check.yml
- .github/actions-tmp/.github/workflows/call-translate-readme.yml
- .github/actions-tmp/.github/workflows/callgraph.yml
- .github/actions-tmp/.github/workflows/check-recent-human-commit.yml
- .github/actions-tmp/.github/workflows/daily-project-summary.yml
- .github/actions-tmp/.github/workflows/issue-note.yml
- .github/actions-tmp/.github/workflows/rust-windows-check.yml
- .github/actions-tmp/.github/workflows/translate-readme.yml
- .github/actions-tmp/.github_automation/callgraph/codeql-queries/callgraph.ql
- .github/actions-tmp/.github_automation/callgraph/codeql-queries/codeql-pack.lock.yml
- .github/actions-tmp/.github_automation/callgraph/codeql-queries/qlpack.yml
- .github/actions-tmp/.github_automation/callgraph/config/example.json
- .github/actions-tmp/.github_automation/callgraph/docs/callgraph.md
- .github/actions-tmp/.github_automation/callgraph/presets/callgraph.js
- .github/actions-tmp/.github_automation/callgraph/presets/style.css
- .github/actions-tmp/.github_automation/callgraph/scripts/analyze-codeql.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/callgraph-utils.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/check-codeql-exists.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/check-node-version.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/common-utils.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/copy-commit-results.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/extract-sarif-info.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/find-process-results.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/generate-html-graph.cjs
- .github/actions-tmp/.github_automation/callgraph/scripts/generateHTML.cjs
- .github/actions-tmp/.github_automation/check_recent_human_commit/scripts/check-recent-human-commit.cjs
- .github/actions-tmp/.github_automation/project_summary/docs/daily-summary-setup.md
- .github/actions-tmp/.github_automation/project_summary/prompts/development-status-prompt.md
- .github/actions-tmp/.github_automation/project_summary/prompts/project-overview-prompt.md
- .github/actions-tmp/.github_automation/project_summary/scripts/ProjectSummaryCoordinator.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/development/DevelopmentStatusGenerator.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/development/GitUtils.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/development/IssueTracker.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/generate-project-summary.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/overview/CodeAnalyzer.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/overview/ProjectAnalysisOrchestrator.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/overview/ProjectDataCollector.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/overview/ProjectDataFormatter.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/overview/ProjectOverviewGenerator.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/shared/BaseGenerator.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/shared/FileSystemUtils.cjs
- .github/actions-tmp/.github_automation/project_summary/scripts/shared/ProjectFileUtils.cjs
- .github/actions-tmp/.github_automation/translate/docs/TRANSLATION_SETUP.md
- .github/actions-tmp/.github_automation/translate/scripts/translate-readme.cjs
- .github/actions-tmp/.gitignore
- .github/actions-tmp/.vscode/settings.json
- .github/actions-tmp/LICENSE
- .github/actions-tmp/README.ja.md
- .github/actions-tmp/README.md
- .github/actions-tmp/_config.yml
- .github/actions-tmp/generated-docs/callgraph.html
- .github/actions-tmp/generated-docs/callgraph.js
- .github/actions-tmp/generated-docs/development-status-generated-prompt.md
- .github/actions-tmp/generated-docs/development-status.md
- .github/actions-tmp/generated-docs/project-overview-generated-prompt.md
- .github/actions-tmp/generated-docs/project-overview.md
- .github/actions-tmp/generated-docs/style.css
- .github/actions-tmp/googled947dc864c270e07.html
- .github/actions-tmp/issue-notes/10.md
- .github/actions-tmp/issue-notes/11.md
- .github/actions-tmp/issue-notes/12.md
- .github/actions-tmp/issue-notes/13.md
- .github/actions-tmp/issue-notes/14.md
- .github/actions-tmp/issue-notes/15.md
- .github/actions-tmp/issue-notes/16.md
- .github/actions-tmp/issue-notes/17.md
- .github/actions-tmp/issue-notes/18.md
- .github/actions-tmp/issue-notes/19.md
- .github/actions-tmp/issue-notes/2.md
- .github/actions-tmp/issue-notes/20.md
- .github/actions-tmp/issue-notes/21.md
- .github/actions-tmp/issue-notes/22.md
- .github/actions-tmp/issue-notes/23.md
- .github/actions-tmp/issue-notes/24.md
- .github/actions-tmp/issue-notes/25.md
- .github/actions-tmp/issue-notes/26.md
- .github/actions-tmp/issue-notes/27.md
- .github/actions-tmp/issue-notes/28.md
- .github/actions-tmp/issue-notes/29.md
- .github/actions-tmp/issue-notes/3.md
- .github/actions-tmp/issue-notes/30.md
- .github/actions-tmp/issue-notes/4.md
- .github/actions-tmp/issue-notes/7.md
- .github/actions-tmp/issue-notes/8.md
- .github/actions-tmp/issue-notes/9.md
- .github/actions-tmp/package-lock.json
- .github/actions-tmp/package.json
- .github/actions-tmp/src/main.js
- .github/workflows/call-daily-project-summary.yml
- .github/workflows/call-issue-note.yml
- .github/workflows/call-rust-windows-check.yml
- .github/workflows/call-translate-readme.yml
- .github/workflows/deploy-pages.yml
- .gitignore
- Cargo.lock
- Cargo.toml
- EXAMPLES.md
- IMPLEMENTATION.md
- LICENSE
- README.ja.md
- README.md
- _codeql_detected_source_root
- _config.yml
- chord2mml-cli/Cargo.toml
- chord2mml-cli/README.md
- chord2mml-cli/src/main.rs
- chord2mml-core/Cargo.toml
- chord2mml-core/examples/basic.rs
- chord2mml-core/src/ast.rs
- chord2mml-core/src/lib.rs
- chord2mml-core/src/mml.rs
- chord2mml-core/src/note.rs
- chord2mml-core/src/parser.rs
- chord2mml-wasm/Cargo.toml
- chord2mml-wasm/src/lib.rs
- chord2mml-web/README.md
- chord2mml-web/index.html
- chord2mml-web/package.json
- chord2mml-web/src/main.ts
- chord2mml-web/tsconfig.json
- chord2mml-web/vite.config.ts
- generated-docs/project-overview-generated-prompt.md
- issue-notes/11.md
- issue-notes/13.md
- issue-notes/15.md
- issue-notes/17.md
- issue-notes/19.md
- issue-notes/2.md
- issue-notes/20.md
- issue-notes/21.md
- issue-notes/22.md
- issue-notes/5.md
- issue-notes/7.md
- issue-notes/9.md
- tree-sitter-chord/Cargo.toml
- tree-sitter-chord/binding.gyp
- tree-sitter-chord/bindings/node/binding.cc
- tree-sitter-chord/bindings/node/index.js
- tree-sitter-chord/bindings/rust/build.rs
- tree-sitter-chord/bindings/rust/lib.rs
- tree-sitter-chord/grammar.js
- tree-sitter-chord/package.json
- tree-sitter-chord/src/grammar.json
- tree-sitter-chord/src/node-types.json
- tree-sitter-chord/src/parser.c
- tree-sitter-chord/src/tree_sitter/parser.h
- tree-sitter-chord/tree-sitter-chord

## 現在のオープンIssues
## [Issue #22](../issue-notes/22.md): 「README.ja.mdの計画に書いてあるが、chord2mmlリポジトリで扱っていない要素」は、LLMが勝手にハルシネーションしたものなので、READMEから削除する
[issue-notes/22.md](https://github.com/cat2151/chord2mml-rust/blob/main/issue-notes/22.md)

...
ラベル: 
--- issue-notes/22.md の内容 ---

```markdown
# issue 「README.ja.mdの計画に書いてあるが、chord2mmlリポジトリで扱っていない要素」は、LLMが勝手にハルシネーションしたものなので、削除する #22
[issues #22](https://github.com/cat2151/chord2mml-rust/issues/22)



```

## [Issue #21](../issue-notes/21.md): chord2mmlリポジトリで扱っているchordを一通り実装するためのロードマップをREADME.ja.mdにlistする。ただしハイフンは区切り文字だけに使うのが違いである
[issue-notes/21.md](https://github.com/cat2151/chord2mml-rust/blob/main/issue-notes/21.md)

...
ラベル: 
--- issue-notes/21.md の内容 ---

```markdown
# issue chord2mmlリポジトリで扱っているchordを一通り実装するためのロードマップをREADME.ja.mdにlistする。ただしハイフンは区切り文字だけに使うのが違いである #21
[issues #21](https://github.com/cat2151/chord2mml-rust/issues/21)



```

## ドキュメントで言及されているファイルの内容
### .github/actions-tmp/README.ja.md
```md
{% raw %}
# GitHub Actions 共通ワークフロー集

このリポジトリは、**複数プロジェクトで使い回せるGitHub Actions共通ワークフロー集**です

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

# 3行で説明
- 🚀 プロジェクトごとのGitHub Actions管理をもっと楽に
- 🔗 共通化されたワークフローで、どのプロジェクトからも呼ぶだけでOK
- ✅ メンテは一括、プロジェクト開発に集中できます

## Quick Links
| 項目 | リンク |
|------|--------|
| 📖 プロジェクト概要 | [generated-docs/project-overview.md](generated-docs/project-overview.md) |
| 📖 コールグラフ | [generated-docs/callgraph.html](https://cat2151.github.io/github-actions/generated-docs/callgraph.html) |
| 📊 開発状況 | [generated-docs/development-status.md](generated-docs/development-status.md) |

# notes
- まだ共通化の作業中です
- まだワークフロー内容を改善中です

※README.md は README.ja.md を元にGeminiの翻訳でGitHub Actionsで自動生成しています

{% endraw %}
```

### README.ja.md
```md
{% raw %}
# chord2mml-rust

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
出力MML (例: "'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'")
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
'c;e;g'

# コード進行
$ chord2mml "C-F-G-C"
'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'

# マイナーコード
$ chord2mml "Dm"
'd;f;a'

# 混合進行
$ chord2mml "C-Dm-G-C"
'c;e;g' 'd;f;a' 'g;b;d' 'c;e;g'
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
    println!("MML: {}", mml); // "'c;e;g'"
    
    // コード進行
    let progression = "C-F-G-C";
    let mml = convert(progression).unwrap();
    println!("MML: {}", mml); // "'c;e;g' 'f;a;c' 'g;b;d' 'c;e;g'"
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

{% endraw %}
```

### .github/actions-tmp/issue-notes/2.md
```md
{% raw %}
# issue GitHub Actions「関数コールグラフhtmlビジュアライズ生成」を共通ワークフロー化する #2
[issues #2](https://github.com/cat2151/github-actions/issues/2)


# prompt
```
あなたはGitHub Actionsと共通ワークフローのスペシャリストです。
このymlファイルを、以下の2つのファイルに分割してください。
1. 共通ワークフロー       cat2151/github-actions/.github/workflows/callgraph_enhanced.yml
2. 呼び出し元ワークフロー cat2151/github-actions/.github/workflows/call-callgraph_enhanced.yml
まずplanしてください
```

# 結果
- indent
    - linter？がindentのエラーを出しているがyml内容は見た感じOK
    - テキストエディタとagentの相性問題と判断する
    - 別のテキストエディタでsaveしなおし、テキストエディタをreload
    - indentのエラーは解消した
- LLMレビュー
    - agent以外の複数のLLMにレビューさせる
    - prompt
```
あなたはGitHub Actionsと共通ワークフローのスペシャリストです。
以下の2つのファイルをレビューしてください。最優先で、エラーが発生するかどうかだけレビューしてください。エラー以外の改善事項のチェックをするかわりに、エラー発生有無チェックに最大限注力してください。

--- 共通ワークフロー

# GitHub Actions Reusable Workflow for Call Graph Generation
name: Generate Call Graph

# TODO Windowsネイティブでのtestをしていた名残が残っているので、今後整理していく。今はWSL act でtestしており、Windowsネイティブ環境依存問題が解決した
#  ChatGPTにレビューさせるとそこそこ有用そうな提案が得られたので、今後それをやる予定
#  agentに自己チェックさせる手も、セカンドオピニオンとして選択肢に入れておく

on:
  workflow_call:

jobs:
  check-commits:
    runs-on: ubuntu-latest
    outputs:
      should-run: ${{ steps.check.outputs.should-run }}
    steps:
      - name: Checkout repository
        uses: actions/checkout@v4
        with:
          fetch-depth: 50 # 過去のコミットを取得

      - name: Check for user commits in last 24 hours
        id: check
        run: |
          node .github/scripts/callgraph_enhanced/check-commits.cjs

  generate-callgraph:
    needs: check-commits
    if: needs.check-commits.outputs.should-run == 'true'
    runs-on: ubuntu-latest
    permissions:
      contents: write
      security-events: write
      actions: read

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Set Git identity
        run: |
          git config user.name "github-actions[bot]"
          git config user.email "41898282+github-actions[bot]@users.noreply.github.com"

      - name: Remove old CodeQL packages cache
        run: rm -rf ~/.codeql/packages

      - name: Check Node.js version
        run: |
          node .github/scripts/callgraph_enhanced/check-node-version.cjs

      - name: Install CodeQL CLI
        run: |
          wget https://github.com/github/codeql-cli-binaries/releases/download/v2.22.1/codeql-linux64.zip
          unzip codeql-linux64.zip
          sudo mv codeql /opt/codeql
          echo "/opt/codeql" >> $GITHUB_PATH

      - name: Install CodeQL query packs
        run: |
          /opt/codeql/codeql pack install .github/codeql-queries

      - name: Check CodeQL exists
        run: |
          node .github/scripts/callgraph_enhanced/check-codeql-exists.cjs

      - name: Verify CodeQL Configuration
        run: |
          node .github/scripts/callgraph_enhanced/analyze-codeql.cjs verify-config

      - name: Remove existing CodeQL DB (if any)
        run: |
          rm -rf codeql-db

      - name: Perform CodeQL Analysis
        run: |
          node .github/scripts/callgraph_enhanced/analyze-codeql.cjs analyze

      - name: Check CodeQL Analysis Results
        run: |
          node .github/scripts/callgraph_enhanced/analyze-codeql.cjs check-results

      - name: Debug CodeQL execution
        run: |
          node .github/scripts/callgraph_enhanced/analyze-codeql.cjs debug

      - name: Wait for CodeQL results
        run: |
          node -e "setTimeout(()=>{}, 10000)"

      - name: Find and process CodeQL results
        run: |
          node .github/scripts/callgraph_enhanced/find-process-results.cjs

      - name: Generate HTML graph
        run: |
          node .github/scripts/callgraph_enhanced/generate-html-graph.cjs

      - name: Copy files to generated-docs and commit results
        run: |
          node .github/scripts/callgraph_enhanced/copy-commit-results.cjs

--- 呼び出し元
# 呼び出し元ワークフロー: call-callgraph_enhanced.yml
name: Call Call Graph Enhanced

on:
  schedule:
    # 毎日午前5時(JST) = UTC 20:00前日
    - cron: '0 20 * * *'
  workflow_dispatch:

jobs:
  call-callgraph-enhanced:
    # uses: cat2151/github-actions/.github/workflows/callgraph_enhanced.yml
    uses: ./.github/workflows/callgraph_enhanced.yml # ローカルでのテスト用
```

# レビュー結果OKと判断する
- レビュー結果を人力でレビューした形になった

# test
- #4 同様にローカル WSL + act でtestする
- エラー。userのtest設計ミス。
  - scriptの挙動 : src/ がある前提
  - 今回の共通ワークフローのリポジトリ : src/ がない
  - 今回testで実現したいこと
    - 仮のソースでよいので、関数コールグラフを生成させる
  - 対策
    - src/ にダミーを配置する
- test green
  - ただしcommit pushはしてないので、html内容が0件NG、といったケースの検知はできない
  - もしそうなったら別issueとしよう

# test green

# commit用に、yml 呼び出し元 uses をlocal用から本番用に書き換える

# closeとする
- もしhtml内容が0件NG、などになったら、別issueとするつもり

{% endraw %}
```

### issue-notes/2.md
```md
{% raw %}
# issue TreeSitterと各種ライブラリを利用した最低限の構成に完全に作り直す #2
[issues #2](https://github.com/cat2151/chord2mml-rust/issues/2)



{% endraw %}
```

### .github/actions-tmp/issue-notes/21.md
```md
{% raw %}
# issue project-summary の development-status 生成時、project-overviewが生成済みのproject-overview.mdもpromptに添付、を試す #21
[issues #21](https://github.com/cat2151/github-actions/issues/21)

# 何が困るの？
- project-overview.mdがpromptに添付されていたほうが、Geminiの生成品質が改善できる可能性がある。
    - メリットは、ファイル一覧、関数一覧、をGeminiにわたせること

# 検討事項
- 課題、その一覧に付記されている「ファイルや関数の要約」は、Geminiが「ファイル名や関数名を元に生成しただけ」で、「ファイル内容や関数内容を参照せずに生成した」可能性が高い
    - 対策、project-overview.mdに依存しない。
        - 方法、新規関数をagentに実装させる
            - 新規関数で、ファイル一覧と関数一覧を生成する
        - 根拠、そのほうが、シンプルに目的を達成できる可能性が高そう。
        - 根拠、project-overview.mdだと、不具合として.github 配下のymlがlistに含まれておらず、ymlに関するissue、に関する生成、をするとき不具合の可能性がありそう。そういった、別機能の不具合に影響されがち。
- 課題、早期に実施したほうが毎日好影響が出る可能性がある
    - 対策、上記検討事項の対処は後回しにして、先に実装してみる
    - agentに投げる
- 課題、ProjectSummaryCoordinator をみたところ、並列処理されている
    - なので、project-overview.mdを参照したいときに、まだ生成されていない、という可能性が高い
    - 対策、前述の、新規関数で、ファイル一覧と関数一覧を生成させる

# agentに投げるための整理
- 編集対象ファイル
    - prompt
        - .github_automation/project_summary/prompts/development-status-prompt.md
        - 編集内容
            - projectのファイル一覧を埋め込む用の、プレースホルダーを追加する
    - source
        - .github_automation/project_summary/scripts/development/DevelopmentStatusGenerator.cjs
        - 編集内容
            - projectのファイル一覧を生成する関数、を実装し、
            - それを前述のプレースホルダーに埋め込む

# agentに投げて実装させた

# test結果
- 以下が不要
    - .git/
    - node_modules/

# どうする？
- agentに上記を変更させた
- testする

# 結果
- test greenとなった

# まとめ
- issueのtitleからは仕様変更した。
    - projectのfile一覧をpromptに含める、とした。
    - そのほうがpromptとして、よい生成結果が期待できる、と判断した。
- test greenとなった

# closeとする

{% endraw %}
```

### issue-notes/21.md
```md
{% raw %}
# issue chord2mmlリポジトリで扱っているchordを一通り実装するためのロードマップをREADME.ja.mdにlistする。ただしハイフンは区切り文字だけに使うのが違いである #21
[issues #21](https://github.com/cat2151/chord2mml-rust/issues/21)



{% endraw %}
```

### .github/actions-tmp/issue-notes/22.md
```md
{% raw %}
# issue project-summary の development-status 生成時、Geminiに与えたprompt、もcommit push、を試す #22
[issues #22](https://github.com/cat2151/github-actions/issues/22)

# 何が困るの？
- 生成された development-status.md の妥当性がわかりづらいし、バグった場合の原因調査がしづらい

# 対策案
- Geminiに与えたpromptをfileにしてcommit pushしておくと、デバッグに役立つ可能性がある。

# 方法案
- Geminiに与えるprompt を生成時、それをfileにsaveし、commit push対象にする。
- ひとまずgenerated-docs/ に保存する。落ち着いたら移動先を検討する。
    - generated-docs/ 配下のまま、も有力な候補である。
        - なぜなら、cjsによってgenerateされたdocなので。

# 日次バッチでpromptを生成させ、agentに投げた
- レビューした
- 修正させた

# 結果
- エラー。pathのミス。呼び出し元側に保存したいのに、共通ワークフロー側に保存となってしまった。
- 対策、ymlで引数を指定するようにした。
- testする。

# 結果
- test green。呼び出し元側にcommitされていることを確認した。
- 20Kbytesである
    - Geminiにわたすサイズとしても許容範囲内と判断する
        - token数から概算して100Kbytes～1Mbytes程度を想定

# closeとする

{% endraw %}
```

### issue-notes/22.md
```md
{% raw %}
# issue 「README.ja.mdの計画に書いてあるが、chord2mmlリポジトリで扱っていない要素」は、LLMが勝手にハルシネーションしたものなので、削除する #22
[issues #22](https://github.com/cat2151/chord2mml-rust/issues/22)



{% endraw %}
```

## 最近の変更（過去7日間）
### コミット履歴:
93a6db9 Auto-play MML on textarea input (#24)
2b154d9 Auto-translate README.ja.md to README.md [auto]
7e4aa01 Wrap chord output in single quotes for mmlabc syntax compliance (#23)
3a99698 Update project summaries (overview & development status) [auto]
dba6ca1 Remove manual parser and implement Tree-sitter (#18)
1d4a926 Update project summaries (overview & development status) [auto]
7aba882 Add issue note for #22 [auto]
4edef66 Add issue note for #21 [auto]
3f3fdbd Add issue note for #20 [auto]
e59ece1 Add issue note for #19 [auto]

### 変更されたファイル:
EXAMPLES.md
IMPLEMENTATION.md
README.ja.md
README.md
chord2mml-cli/README.md
chord2mml-core/Cargo.toml
chord2mml-core/src/lib.rs
chord2mml-core/src/mml.rs
chord2mml-core/src/parser.rs
chord2mml-web/index.html
chord2mml-web/src/main.ts
generated-docs/development-status-generated-prompt.md
generated-docs/development-status.md
generated-docs/project-overview-generated-prompt.md
generated-docs/project-overview.md
issue-notes/22.md
tree-sitter-chord/grammar.js
tree-sitter-chord/src/grammar.json
tree-sitter-chord/src/node-types.json
tree-sitter-chord/src/parser.c


---
Generated at: 2026-01-15 07:01:41 JST
