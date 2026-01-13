Last updated: 2026-01-14

# Development Status

## 現在のIssues
- [Issue #22](../issue-notes/22.md) はREADME.ja.md内のLLMハルシネーションを削除し、[Issue #21](../issue-notes/21.md) はロードマップを正確に整備することを目指しています。
- [Issue #19](../issue-notes/19.md) はMML出力にシングルクォートを追加し、[Issue #20](../issue-notes/20.md) はWeb UIでの即時演奏開始を計画しています。
- これらのIssueは、プロジェクトのドキュメントの正確性を高め、MML出力の品質とWebアプリケーションのUXを向上させることに注力しています。

## 次の一手候補
1. [Issue #22](../issue-notes/22.md): README.ja.mdからLLMがハルシネーションした不要な要素を削除
   - 最初の小さな一歩: `README.ja.md` をレビューし、現在のプロジェクトで扱われていないLLMが生成したとみられる記述（特にロードマップやサポート範囲に関する記述）を特定し、削除する。
   - Agent実行プロンプ:
     ```
     対象ファイル: `README.ja.md`

     実行内容: `README.ja.md` を精査し、「ロードマップ」セクションやその他の説明文において、現在の`chord2mml-rust`プロジェクトでサポートされていない機能や概念（LLMによるハルシネーションが疑われるもの）を特定し、それらを削除または修正してください。具体的には、Tree-sitterパーサーや`chord2mml-core`の実装内容と照合し、現状と異なる記述を修正します。

     確認事項: プロジェクトのファイル一覧、特に`chord2mml-core`クレートのソースコード（例: `chord2mml-core/src/lib.rs`, `chord2mml-core/src/mml.rs`）と`tree-sitter-chord`グラマー定義（例: `tree-sitter-chord/grammar.js`）の内容を横断的に確認し、README.ja.mdの記載内容がプロジェクトの現状と一致しているか検証してください。

     期待する出力: 修正された `README.ja.md` のファイル内容。
     ```

2. [Issue #21](../issue-notes/21.md): chord2mmlで扱っているchordのロードマップをREADME.ja.mdに正確にリストする
   - 最初の小さな一歩: `README.ja.md` の「ロードマップ」セクションを、現在の`chord2mml-core`のコードと`tree-sitter-chord`のグラマー定義に基づいて、実装状況を正確に反映させるように更新する。「ハイフンは区切り文字としてのみ使用する」というルールも追記する。
   - Agent実行プロンプ:
     ```
     対象ファイル: `README.ja.md`

     実行内容: `README.ja.md` の「ロードマップ」セクションを更新してください。現在の`chord2mml-core/src/mml.rs`と`tree-sitter-chord/grammar.js`の実装状況に基づき、メジャー系、マイナー系、セブンス系などの各コードタイプが実際にMML変換可能か、パーサーで認識されているかを正確に反映させてください。また、「ハイフンは区切り文字としてのみ使用する」という制約を明記してください。

     確認事項: `chord2mml-core/src/mml.rs`と`tree-sitter-chord/grammar.js`の内容を確認し、どのコードタイプがMML変換まで実装されているか（`generate_mml`関数や関連ロジック）、どのコードタイプがTree-sitterグラマーで認識されているかを確認してください。既存のロードマップ記述との整合性を保ち、矛盾がないことを確認してください。

     期待する出力: 更新された `README.ja.md` のファイル内容。
     ```

3. [Issue #19](../issue-notes/19.md): MML出力の各コードをシングルクォートで囲むよう修正し、mmlabc文法に準拠させる
   - 最初の小さな一歩: `chord2mml-core/src/mml.rs` 内のMML文字列を生成する関数を特定し、出力される各コード（例: `c;e;g`）が `'c;e;g'` のようにシングルクォートで囲まれるようにロジックを変更する。
   - Agent実行プロンプ:
     ```
     対象ファイル: `chord2mml-core/src/mml.rs`

     実行内容: `chord2mml-core/src/mml.rs` ファイル内の、ASTからMML文字列を構築している`generate_mml`関数、またはそれに相当するMML生成ロジックを特定してください。そして、出力されるMML内の各コードブロック（例: `c;e;g`）が、mmlabcの文法に準拠するようにシングルクォートで囲まれる形式（例: `'c;e;g'`）に変更してください。

     確認事項: MML生成ロジックの変更が、コードブロックの区切りや音符の生成に予期せぬ影響を与えないか確認してください。特に、複数のコードが連続する場合や、異なる音符が混在する場合でも正しくシングルクォートが適用されることを保証してください。可能であれば、関連するテストケースを更新または追加して動作を確認してください。

     期待する出力: 修正された `chord2mml-core/src/mml.rs` のファイル内容。
     ```

---
Generated at: 2026-01-14 07:02:11 JST
