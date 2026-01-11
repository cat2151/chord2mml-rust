# chord2mml-rust

<p align="left">
  <a href="README.ja.md"><img src="https://img.shields.io/badge/🇯🇵-Japanese-red.svg" alt="Japanese"></a>
  <a href="README.md"><img src="https://img.shields.io/badge/🇺🇸-English-blue.svg" alt="English"></a>
</p>

コード進行をMML（Music Macro Language）に変換するライブラリ・アプリケーション。Rustで書かれています。

## 概要

このプロジェクトは、[chord2mml](https://github.com/cat2151/chord2mml)で Peggy.js + JavaScript で作っていたものを、Rust + Tree-sitter + WASM + TypeScript として新たに作り直したものです。

### 主な特徴

- **Rust + Tree-sitter**: 高速で堅牢なパーサーコア
- **ライブラリクレート**: Rustのネイティブアプリケーションから直接利用可能
- **WASM対応**: ブラウザ上でも動作
- **TypeScript統合**: Webアプリケーションとしての利用

## アーキテクチャ

```
chord2mml-rust/
├── chord2mml-core/     # Rust + Tree-sitterによる変換コアライブラリ
├── chord2mml-wasm/     # WASM バインディング
└── chord2mml-web/      # TypeScript + Webアプリケーション
```

### コンポーネント

1. **chord2mml-core**: コード進行をパースしてMMLに変換するRustライブラリ
   - Tree-sitterによる構文解析
   - ネイティブアプリケーションから利用可能

2. **chord2mml-wasm**: WASMバインディング
   - Rust CoreをWebAssemblyにコンパイル
   - JavaScriptからの呼び出しインターフェース

3. **chord2mml-web**: ブラウザアプリケーション
   - TypeScriptで実装
   - tonejs-mml-to-json と tonejs-json-sequencer を利用して音を再生
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
- [x] tonejs-mml-to-json と tonejs-json-sequencer の統合

### Phase 2: 元のchord2mmlテストの移植

元の[chord2mml](https://github.com/cat2151/chord2mml)リポジトリにあるテストを移植し、
以下の和音を網羅的にサポートします：

#### メジャー系コード
- [ ] C (ド・ミ・ソ)
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
- [ ] Tree-sitterグラマーの最適化
- [ ] パフォーマンス改善
- [ ] エラーハンドリングの強化
- [ ] ドキュメント整備

## 開発方針

### 元のchord2mmlとの違い

| 項目 | chord2mml (旧) | chord2mml-rust (新) |
|------|---------------|-------------------|
| パーサー | Peggy.js | Tree-sitter |
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
- **Tree-sitter**: 構文解析
- **wasm-pack**: WASMビルドツール
- **TypeScript**: Webアプリケーション
- **tonejs-mml-to-json**: MML解析
- **tonejs-json-sequencer**: 音声再生

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
