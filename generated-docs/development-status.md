Last updated: 2026-01-13

# Development Status

## 現在のIssues
- コアパーサーをTree-sitterベースに移行し、手動パーサーを削除する作業([Issue #17](../issue-notes/17.md), [Issue #18](../issue-notes/18.md))が進行中です。
- MML出力の文法準拠のため、各コードをシングルクォートで囲む変更([Issue #19](../issue-notes/19.md))が必要です。
- README.ja.mdに、現在扱っているコードのロードマップを整理し、LLMによるハルシネーション([Issue #21](../issue-notes/21.md), [Issue #22](../issue-notes/22.md))を削除します。

## 次の一手候補
1. [Issue #17](../issue-notes/17.md) 手動パーサーを削除し、Tree-sitterベースの実装へ移行する
   - 最初の小さな一歩: `chord2mml-core/src/parser.rs` から、手動パーサーのコードブロックを完全に削除する。
   - Agent実行プロンプ:
     ```
     対象ファイル: chord2mml-core/src/parser.rs, chord2mml-core/Cargo.toml

     実行内容:
     `chord2mml-core/src/parser.rs` から、`#[cfg(not(feature = "tree-sitter"))]` で囲まれた `parse_to_ast_manual` 関数および、`parse_chord_manual`, `validate_bass_note`, `parse_quality_manual` 関数とその関連コード（手動パーサー部分）を完全に削除してください。
     また、`parse_to_ast` 関数から手動パーサーへの条件分岐を削除し、Tree-sitterパーサーのみを使用するように修正してください。
     `chord2mml-core/Cargo.toml` から `default = []` フィーチャーを削除し、`tree-sitter` フィーチャーをデフォルトで有効にするか、`tree-sitter` フィーチャーなしではコンパイルできないように修正してください。

     確認事項:
     手動パーサー関連コードの削除によって、`chord2mml-core` クレートがTree-sitterフィーチャーなしではコンパイルされないことを確認してください。
     `chord2mml-wasm` クレートのビルドに失敗しないことを確認してください。（WASMは`tree-sitter`フィーチャーを有効にできないため、`chord2mml-core`が`default`フィーチャーに依存しないように変更する必要があります。）
     `chord2mml-wasm/Cargo.toml` が `chord2mml-core` の `tree-sitter` フィーチャーを有効にしていないことを確認してください。

     期待する出力:
     修正された `chord2mml-core/src/parser.rs` と `chord2mml-core/Cargo.toml` の内容。
     ```

2. [Issue #19](../issue-notes/19.md) 出力されたchordそれぞれをシングルクォートで囲むようにする
   - 最初の小さな一歩: `chord2mml-core/src/mml.rs` の `chord_to_mml` 関数内で、MML文字列の各コードの生成時にシングルクォートを追加する。
   - Agent実行プロンプト:
     ```
     対象ファイル: chord2mml-core/src/mml.rs

     実行内容:
     `chord2mml-core/src/mml.rs` 内の `chord_to_mml` 関数を修正し、各コードがMML文字列として出力される際に、そのコード全体をシングルクォート `'` で囲むように変更してください。
     例えば、`c;e;g` だったものが `'c;e;g'` となるように修正してください。
     `generate_mml_from_ast` 関数も、この変更に合わせて適切にMML文字列を結合するように調整してください。

     確認事項:
     既存のテストがパスすることを確認してください。
     CLIツール (`chord2mml-cli`) で変換した際に、MML出力がシングルクォートで囲まれていることを確認してください。

     期待する出力:
     修正された `chord2mml-core/src/mml.rs` の内容。
     ```

3. [Issue #21](../issue-notes/21.md) chord2mmlリポジトリで扱っているchordを一通り実装するためのロードマップをREADME.ja.mdにlistする
   - 最初の小さな一歩: `README.ja.md` の「ロードマップ」セクションで、各コードタイプの実装状況（MML変換の有無）を正確に反映したチェックボックスリストに更新する。
   - Agent実行プロンプト:
     ```
     対象ファイル: README.ja.md

     実行内容:
     `README.ja.md` ファイルの「ロードマップ」セクションにある「Phase 2: 元のchord2mmlテストの移植」の内容を更新してください。
     特に「現在の実装状況」を、`chord2mml-core/src/parser.rs` と `chord2mml-core/src/mml.rs` の現在の実装を反映した、より正確な記述に修正してください。
     また、各コードタイプのリスト（メジャー系、マイナー系、セブンス系など）について、現時点でMML変換が実装されているものと未実装のものを明確に区別し、未実装のものは`[ ]`チェックボックスで示すように変更してください。
     「ハイフンは区切り文字だけに使うのが違いである」という点については、必要に応じて追記を検討してください。ただし、この点は主にパーサーの挙動に関わるため、MML変換のロードマップ部分では簡潔に触れる程度で十分です。

     確認事項:
     既存のMML変換が実装されているコードタイプ（例: C, Cm）が「[x]」とマークされていること。
     Tree-sitterパーサーが認識するがMML変換が未実装のコードタイプ（例: CM7, Cdim, Csus4, C/E）が「[ ]」とマークされていること。
     [Issue #22](../issue-notes/22.md)で言及されているLLMのハルシネーション（「README.ja.mdの計画に書いてあるが、chord2mmlリポジトリで扱っていない要素」）に該当する部分がないか確認し、削除または修正してください。
     更新されたロードマップが、プロジェクトの現状と今後の方向性を正確に反映していることを確認してください。

     期待する出力:
     更新された `README.ja.md` の内容。

---
Generated at: 2026-01-13 07:02:03 JST
