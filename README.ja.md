# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

コード進行をMML（Music Macro Language）に変換するライブラリ・アプリケーション。Rustで書かれています。

## 注意
- 破壊的変更を頻繁に行います。
- 以降の文章はAI生成を含みます。誤りやuserの意図と違うものを含む可能性があります。

## 概要

このプロジェクトは、[chord2mml](https://github.com/cat2151/chord2mml)で Peggy.js + JavaScript で作っていたものを、**Rust + Tree-sitter** として新たに作り直したものです。

**出力はJS版と互換**（例: `C` → `v11'c1eg'`）で、JS版の約100テストを仕様として段階的に移植をしました。移植したケースは `chord2mml-core/tests/corpus/` のゴールデンコーパスを参照ください。

### これまでの課題と、このプロジェクトが目指すこと
- [chord2mml](https://github.com/cat2151/chord2mml)は、localでRustでコード進行を鳴らしたいときには、利用が困難でした。
- そのため、このプロジェクトで、Rust + Tree-sitter で作り直すことにしました。
- 結果、  https://github.com/cat2151/clap-mml-render-tui/blob/main/README.ja.md で役立っています（コマンドライン引数にコード進行文字列を与えるだけでコード進行を即座に鳴らせる）

### 主な特徴

- **Tree-sitterパーサー**: 堅牢で正確な構文解析
- **JS版互換の出力**: obsidian-plugin-mmlabc 等でそのまま利用できるMML形式
- **ネイティブ + ブラウザ両対応**: CLI/ライブラリに加え、WASM + web-tree-sitter によるブラウザデモ
- **ゴールデンコーパス**: JS版の実行結果を期待値とするテストを、ネイティブ・WASM両経路で共有

## アーキテクチャ

```
chord2mml-rust/
├── tree-sitter-chord/   # Tree-sitterグラマー定義 + 文法WASM
├── chord2mml-core/      # Rustによる変換コアライブラリ
├── chord2mml-cli/       # コマンドラインインターフェース
├── chord2mml-wasm/      # WASMバインディング（C依存なし）
└── chord2mml-web/       # ブラウザデモ（web-tree-sitter + Vite）
```

### データフロー

[tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) で実証済みのパターンを踏襲しています。パイプラインはJS版の4段構成を移植したものです。

```
[ネイティブ] 入力 → tree-sitter Rustクレート → CST
[ブラウザ]   入力 → web-tree-sitter(JS) + tree-sitter-chord.wasm → CST(JSON)
共通:       CST → cst_to_ast → イベント配列AST → ast2ast → ast2notes → notes2mml → MML
```

ポイント: tree-sitter の C 依存を Rust の WASM ビルドに含めないため、`chord2mml-core` はデフォルトで tree-sitter 非依存（`tree-sitter` feature をCLIが有効化）です。

## デモ

### ブラウザ

GitHub Pages: https://cat2151.github.io/chord2mml-rust/

### CLIツール

```bash
# 単一のコード
$ chord2mml "C"
v11'c1eg'

# コード進行（空白・" - "・→・・ で区切り。ハイフン区切りも当面利用可能）
$ chord2mml "Dm G7 C"
v11'd1fa''g1b<df''c1eg'

$ chord2mml "C-F-G-C"
v11'c1eg''f1a<c''g1b<d''c1eg'
```

## 使い方

### CLIツール

```bash
# ビルド
cargo build --release -p chord2mml-cli

# 実行（引数から）
chord2mml "Dm G7 C"

# 実行（標準入力から）
echo "Dm G7 C" | chord2mml
```

### Rustライブラリとして

```rust
use chord2mml_core::convert;

fn main() {
    // 単一のコード
    let mml = convert("C").unwrap();
    println!("MML: {}", mml); // "v11'c1eg'"

    // コード進行
    let mml = convert("Dm G7 C").unwrap();
    println!("MML: {}", mml); // "v11'd1fa''g1b<df''c1eg'"
}
```

### ビルド・テスト

```bash
# ワークスペース全体（ネイティブ）
cargo test --workspace --all-features

# WASM（C依存なしでビルドできることの確認）
cargo build -p chord2mml-wasm --target wasm32-unknown-unknown --release

# ブラウザ経路のテスト（web-tree-sitter + Rust WASM をNodeで実行）
cd chord2mml-web && npm install && npm run build:wasm && npm test

# ブラウザ実動作テスト（headless Chromium）
cd chord2mml-web && npm run build:web && npm run test:browser
```

## ロードマップ

JS版の約100テストを仕様とし、以下の順で移植しました（各ウェーブでネイティブ+WASM両経路のテストを維持）。

- [x] **Phase 0**: WASM安全アーキテクチャ + CI + Pagesデプロイ復活
- [x] **Phase 1**: JS版互換の出力形式（`v11'c1eg'`）とパイプライン4段化、基本コード
  - メジャー/マイナー/maj7/min7/7/dim/aug/sus2/sus4、全角・半角の#♭、分数コード（ベース音）、コード進行
- [x] **Wave A**: テンション（6, 9, 11, 13）、7sus系、クォータル（4.N）、maj9系（`maj7,add9`）
- [x] **Wave B**: 修飾（add, omit, ♭5, #5）、`-`表記のマイナー（`C-`, `C-7`）
- [x] **Wave C**: オンコード（EonC）、ポリコード（US）、転回形（^N, 1st inv 等）
- [x] **Wave D**: ボイシング（drop2/drop4/drop2and4/close/open triad）、ベースモード（bass is root）、オクターブ指定（octave up/down、`'`/`,`）
- [x] **Wave E**: 小節と音長（`|`, `/ `）、度数記法（ローマ数字/アラビア数字）、キー/スケール（教会旋法・シャープ/フラット綴り）
- [x] **Wave F**: インラインMML/ABC、MIDIプログラムチェンジ（GM音色名 PC000-127）、テンポ（BPM/Tempo）
- [x] **Wave G**: 方言プリプロセス（LLM生成コード進行対応。ハイフン方言・小文字ローマ数字・変換組合せ総当たり）

**全ウェーブ完了**: JS版のテストスイートに基づくゴールデンコーパス324ケース（うちJS検証済み319 + Rust拡張5）が、ネイティブ・WASM両経路で全通過しています。JS版との突き合わせは `scripts/verify-corpus-vs-js.mjs` で再検証できます。

## 開発方針

### 元のchord2mmlとの違い

| 項目 | chord2mml (旧) | chord2mml-rust (新) |
|------|---------------|-------------------|
| パーサー | Peggy.js | Tree-sitter |
| 言語 | JavaScript/TypeScript | Rust |
| 実行環境 | ブラウザ | ネイティブ（CLI）+ ブラウザ（WASM） |
| 出力 | `v11'c1eg'` 形式 | 同じ（互換） |

### 設計思想

1. **JS版テストが仕様**: 機能はJS版のテストに根拠を求める（ハルシネーション防止）
2. **両経路の一致**: ネイティブとWASMで同一の意味論コード（cst_to_ast）を通す
3. **テスト駆動**: ゴールデンコーパスによる網羅的検証

## ビルド要件

- Rust 1.70以降（ネイティブビルドにはCコンパイラも必要）
- Node.js 20以降（ブラウザデモ・WASM経路テスト用）
- 文法WASMの再生成時のみ: tree-sitter-cli + docker または emscripten

## ライセンス

MIT License

## 関連プロジェクト

- [chord2mml](https://github.com/cat2151/chord2mml) - オリジナルのJavaScript版（仕様の源泉）
- [tonejs-mml-to-json](https://github.com/cat2151/tonejs-mml-to-json) - tree-sitter + WASM アーキテクチャの参照実装
- [tonejs-json-sequencer](https://github.com/cat2151/tonejs-json-sequencer) - 音声再生ライブラリ

## 参考リンク

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - 構文解析ライブラリ
- [EXAMPLES.md](EXAMPLES.md) - より詳しい使用例とアーキテクチャ説明
