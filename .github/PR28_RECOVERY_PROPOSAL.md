# PR #28 復旧提案: tree-sitter WASM 問題への適切な対処

## エグゼクティブサマリ

PR #28 は、CI エラーに対して `.github/workflows/deploy-pages.yml` を削除するという不適切な対処を行いました。
このドキュメントでは、適切な解決策を提案します。

## 問題の再定義

### 技術的な問題
- **現象**: `wasm-pack build` 時に tree-sitter クレートがコンパイルエラー
- **根本原因**: tree-sitter は C ライブラリに依存し、`wasm32-unknown-unknown` ターゲットをサポートしない
- **制約**: stdio.h, stdlib.h などの C 標準ライブラリが wasm32-unknown-unknown 環境で利用不可

### ビジネス的な影響
- **失われた機能**: GitHub Pages による Web デモ
- **ユーザーへの影響**: ブラウザで試すことができない（導入障壁が上がる）
- **プロジェクトの価値低下**: "Rust + WASM" を謳っているのに WASM 版が動作しない

## 解決策の比較分析

### 案1: wasm32-wasi ターゲットの使用 ⭐ 推奨

#### 概要
`wasm32-unknown-unknown` の代わりに `wasm32-wasi` ターゲットを使用。
WASI (WebAssembly System Interface) は C 標準ライブラリのサポートを含む。

#### 実装方法
```yaml
# .github/workflows/deploy-pages.yml
- name: Setup Rust
  with:
    toolchain: stable
    target: wasm32-wasi  # ← unknown-unknown から変更

- name: Build WASM
  run: |
    cd chord2mml-wasm
    wasm-pack build --target web --out-dir ../chord2mml-web/public/wasm -- --target wasm32-wasi
```

```javascript
// chord2mml-web での読み込み
import { WASI } from '@wasmer/wasi';

const wasi = new WASI({});
const imports = {
  wasi_snapshot_preview1: wasi.wasiImport,
};

const wasmModule = await WebAssembly.instantiateStreaming(
  fetch('/wasm/chord2mml_wasm_bg.wasm'),
  imports
);
```

#### メリット
- ✅ tree-sitter がそのまま使える（コード変更なし）
- ✅ 長期的なメンテナンスコストが低い
- ✅ tree-sitter の全機能が利用可能

#### デメリット
- ⚠️ WASI polyfill が必要（@wasmer/wasi, ~50KB）
- ⚠️ ブラウザ対応に追加の設定が必要
- ⚠️ パフォーマンスが若干低下する可能性

#### 工数見積
- ワークフロー修正: 30分
- Web フロントエンド修正: 1-2時間
- テスト: 1時間
- **合計: 2.5-3.5時間**

---

### 案2: 条件付きコンパイル（Native: tree-sitter, WASM: 手動パーサー）

#### 概要
ネイティブビルドは tree-sitter を使用、WASM ビルドは純 Rust の手動パーサーを使用。

#### 実装方法
```rust
// chord2mml-core/src/parser.rs
#[cfg(not(target_arch = "wasm32"))]
pub fn parse(input: &str) -> Result<Vec<ASTChord>, Error> {
    // tree-sitter 実装
    use tree_sitter::Parser;
    // ...
}

#[cfg(target_arch = "wasm32")]
pub fn parse(input: &str) -> Result<Vec<ASTChord>, Error> {
    // 手動パーサー実装
    parse_manual(input)
}

fn parse_manual(input: &str) -> Result<Vec<ASTChord>, Error> {
    // 純 Rust パーサーの実装
    // ...
}
```

#### メリット
- ✅ 各環境で最適な実装
- ✅ wasm32-unknown-unknown で動作（polyfill 不要）
- ✅ WASM バイナリサイズが小さい

#### デメリット
- ❌ パーサーの二重実装・メンテナンス
- ❌ 機能差異が発生するリスク
- ❌ テストが複雑化（両方のパーサーをテスト）
- ❌ 実装コストが高い

#### 工数見積
- 手動パーサー実装: 4-6時間
- テスト追加: 2-3時間
- CI 設定: 1時間
- **合計: 7-10時間**

---

### 案3: WASM 版は tree-sitter を諦め、別アプローチ

#### 概要
WASM 版は別のパーサーライブラリ（pest, nom など）を使用。

#### 実装方法
```toml
# chord2mml-core/Cargo.toml
[dependencies]
tree-sitter = { version = "0.26", optional = true }
pest = { version = "2.7", optional = true }

[features]
default = ["tree-sitter"]
wasm = ["pest"]
```

#### メリット
- ✅ WASM で確実に動作
- ✅ 成熟したライブラリを使用

#### デメリット
- ❌ tree-sitter 文法を pest/nom に書き直す必要
- ❌ 文法の二重メンテナンス
- ❌ tree-sitter の強みを活かせない
- ❌ 学習コスト（pest/nom の習得）

#### 工数見積
- pest/nom 文法定義: 4-6時間
- パーサー実装: 3-4時間
- テスト: 2-3時間
- **合計: 9-13時間**

---

### 案4: WASM サポートを一時的に無効化（現状維持）

#### 概要
deploy-pages ワークフローは残すが、WASM ビルドステップをコメントアウト。

#### 実装方法
```yaml
# .github/workflows/deploy-pages.yml
# TODO: Fix tree-sitter WASM compilation issue
# See: https://github.com/cat2151/chord2mml-rust/issues/27
# Temporarily disabled until wasm32-wasi support is added
#
# - name: Build WASM
#   run: |
#     cd chord2mml-wasm
#     wasm-pack build --target web
```

#### メリット
- ✅ 最小限の変更
- ✅ 将来の修正が容易（ファイルは残る）
- ✅ ワークフロー構造は維持

#### デメリット
- ❌ WASM 版が使えない（現状と同じ）
- ❌ 問題を先送りするだけ

#### 工数見積
- ワークフロー修正: 15分
- ドキュメント更新: 30分
- **合計: 45分**

---

## 推奨案

### 第一推奨: 案1 (wasm32-wasi ターゲット)

**理由:**
1. **実装コストが妥当** (2.5-3.5時間)
2. **tree-sitter をそのまま使える** (メンテナンスコスト低)
3. **機能の完全性** (パーサーの差異なし)
4. **実績がある** (他のプロジェクトでも使用されている)

**推奨する実装順序:**
1. 別ブランチで wasm32-wasi 実装を試す
2. ローカルで動作確認
3. CI/CD を更新
4. GitHub Pages にデプロイしてテスト
5. 問題なければマージ

### 第二推奨: 案4 (一時的無効化) + 将来的に案1

短期的に案4で対処し、リソースができたタイミングで案1を実装。

**理由:**
- すぐに CI エラーを解消できる
- deploy-pages ワークフローは削除しない（PR #28 の問題を回避）
- 将来の改善の道を残す

## 実装プラン（案1を採用する場合）

### Phase 1: 検証 (1-2時間)
```bash
# ローカルで wasm32-wasi ビルドを試す
rustup target add wasm32-wasi
cd chord2mml-wasm
cargo build --target wasm32-wasi --release

# WASI polyfill を試す
cd ../chord2mml-web
npm install @wasmer/wasi
# 実装を修正してテスト
```

### Phase 2: 実装 (1-2時間)
1. `Cargo.toml` の target 設定を確認
2. wasm-pack ビルドコマンドを更新
3. Web フロントエンドで WASI サポートを追加
4. エラーハンドリングを追加

### Phase 3: CI/CD 更新 (30分)
1. `.github/workflows/deploy-pages.yml` を更新
2. WASI 関連の依存を追加
3. ビルドスクリプトを調整

### Phase 4: テスト (1時間)
1. ローカルでの動作確認
2. CI でのビルド確認
3. GitHub Pages へのデプロイテスト
4. 各種ブラウザでの動作確認

### Phase 5: ドキュメント更新 (30分)
1. README に WASI 使用を明記
2. ビルド手順を更新
3. Known Issues に追記（あれば）

## リスク分析

### 案1のリスク
| リスク | 影響度 | 発生確率 | 対策 |
|--------|---------|----------|------|
| WASI polyfill のサイズ | 中 | 高 | gzip 圧縮、CDN 利用 |
| ブラウザ互換性問題 | 高 | 低 | polyfill が広くサポート |
| パフォーマンス低下 | 低 | 中 | ベンチマーク測定、必要なら最適化 |

### 案2のリスク
| リスク | 影響度 | 発生確率 | 対策 |
|--------|---------|----------|------|
| パーサーの挙動差異 | 高 | 中 | 包括的なテスト |
| メンテナンスコスト増 | 高 | 高 | ドキュメント整備 |
| バグの増加 | 中 | 高 | CI でのクロステスト |

## 次のアクション

### すぐに実施すべきこと
1. **ユーザーへの確認**: どの案を採用するか判断を仰ぐ
2. **PR #28 のレビュー**: 削除されたワークフローを確認
3. **issue #27 の更新**: このドキュメントの内容を反映

### 中期的な改善（この issue の範囲外）
1. **CI の自動チェック**: アーキテクチャ変更を検出する仕組み
2. **テスト強化**: WASM ビルドの自動テスト
3. **ドキュメント**: WASM 対応の詳細ガイド

## 参考資料

- [wasm32-wasi support in rust](https://doc.rust-lang.org/rustc/platform-support/wasm32-wasi.html)
- [@wasmer/wasi documentation](https://github.com/wasmerio/wasmer-js/tree/main/packages/wasi)
- [tree-sitter WASM limitations](https://github.com/tree-sitter/tree-sitter/issues/1143)
- [wasm-pack targets](https://rustwasm.github.io/docs/wasm-pack/commands/build.html#target)

---

**このドキュメントを issue #29 の添付資料として提供し、ユーザー様の判断を仰ぎます。**
