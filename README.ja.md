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

**出力はJS版と互換**（例: `C` → `v11'c1eg'`）で、JS版の約100テストを仕様として段階的に移植しています（移植済みのケースは `chord2mml-core/tests/corpus/` のゴールデンコーパス参照）。

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

JS版の約100テストを仕様とし、以下の順で移植を進めます（各ウェーブでネイティブ+WASM両経路のテストを維持）。

- [x] **Phase 0**: WASM安全アーキテクチャ + CI + Pagesデプロイ復活
- [x] **Phase 1**: JS版互換の出力形式（`v11'c1eg'`）とパイプライン4段化、基本コード
  - メジャー/マイナー/maj7/min7/7/dim/aug/sus2/sus4、全角・半角の#♭、分数コード（ベース音）、コード進行
- [x] **Wave A**: テンション（6, 9, 11, 13）、7sus系、クォータル（4.N）、maj9系（`maj7,add9`）
- [x] **Wave B**: 修飾（add, omit, ♭5, #5）、`-`表記のマイナー（`C-`, `C-7`）
- [ ] **Wave C**: オンコード（EonC）、ポリコード（US）、転回形（^N, 1st inv 等）
- [ ] **Wave D**: ボイシング（drop2等）、ベースモード、オクターブ指定
- [ ] **Wave E**: 小節と音長（`|`, `/ `）、度数記法、キー/スケール
- [ ] **Wave F**: インラインMML/ABC、MIDIプログラムチェンジ、テンポ
- [ ] **Wave G**: 方言プリプロセス（LLM生成コード進行対応）

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

## 貢献

Issue や Pull Request を歓迎します。

## 作者

cat2151

## 参考リンク

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) - 構文解析ライブラリ
- [EXAMPLES.md](EXAMPLES.md) - より詳しい使用例とアーキテクチャ説明
