<!-- AtCoder -->
<div>
  <a href="https://atcoder.jp/users/serna37">
    <img src="https://badgen.org/img/atcoder/serna37/rating/algorithm?style=flat&label=serna37" />
  </a>
</div>

# C++ ライブラリ
C++での競技プログラミング向けに構築した、アルゴリズムとデータ構造のライブラリです

# 関連
- 私の[dotfiles](https://github.com/serna37/dotfiles/blob/master/cpp.zsh)中に、関連コマンドが作成されています
- VerifyとPagesは[online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper/blob/master/README.ja.md)を使用

# 開発ルール
- 必要な場合のみ、関数に説明コメントをつける
  - 1行で済む場合は`// xxx`のスタイルで記載
  - 複数行の場合、`Doxygen`で記載
  - `[coc.nvim](https://github.com/neoclide/coc.nvim)`での予測変換で表示されることを意識する
- 用意する関数は、種別ごとにファイル分けする
- 依存は最小限にする
- `template`使用はラムダ式のほうが記述量が少ないことが多いため、ラムダ優先で記述
- できるだけテストする
