---
data:
  libraryCategories:
  - name: bits
    pages:
    - icon: ':heavy_check_mark:'
      path: bits/stdc++.h
      title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - name: bundler
    pages:
    - icon: ':warning:'
      path: bundler/main.cpp
      title: "C++\u30E9\u30A4\u30D6\u30E9\u30EA\u30D0\u30F3\u30C9\u30E9\u30FC"
  - name: library/datastruct
    pages:
    - icon: ':warning:'
      path: library/datastruct/segment_tree.hpp
      title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  - name: library/def
    pages:
    - icon: ':heavy_check_mark:'
      path: library/def/common.hpp
      title: "\u5171\u901A"
    - icon: ':heavy_check_mark:'
      path: library/def/const.hpp
      title: "\u5B9A\u6570"
    - icon: ':heavy_check_mark:'
      path: library/def/io.hpp
      title: "IO\u95A2\u9023"
    - icon: ':heavy_check_mark:'
      path: library/def/type.hpp
      title: "\u578B"
  - name: library
    pages:
    - icon: ':warning:'
      path: library/graph.hpp
      title: "\u30B0\u30E9\u30D5"
  - name: library/monoid
    pages:
    - icon: ':warning:'
      path: library/monoid/min.hpp
      title: library/monoid/min.hpp
  - name: library/util
    pages:
    - icon: ':heavy_check_mark:'
      path: library/util/geometry.hpp
      title: "\u5E7E\u4F55"
    - icon: ':heavy_check_mark:'
      path: library/util/number.hpp
      title: "\u6570\u306E\u6027\u8CEA"
    - icon: ':heavy_check_mark:'
      path: library/util/search.hpp
      title: "\u63A2\u7D22"
    - icon: ':heavy_check_mark:'
      path: library/util/sequence.hpp
      title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
    - icon: ':heavy_check_mark:'
      path: library/util/string.hpp
      title: "\u6587\u5B57\u5217"
  - name: .
    pages:
    - icon: ':warning:'
      path: main.cpp
      title: "\U0001F36A\U0001F9F8\U0001F43E"
  - name: template
    pages:
    - icon: ':warning:'
      path: template/debug.hpp
      title: "debug\u51FA\u529B"
    - icon: ':heavy_check_mark:'
      path: template/template.hpp
      title: "\u0E05^>\u03C9<^\u0E05"
  verificationCategories:
  - name: tests
    pages:
    - icon: ':heavy_check_mark:'
      path: tests/template.test.cpp
      title: tests/template.test.cpp
layout: toppage
---
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
  - [`coc.nvim`](https://github.com/neoclide/coc.nvim)での予測変換で表示されることを意識する
- 用意する関数は、種別ごとにファイル分けする
- 依存は最小限にする
- `template`使用はラムダ式のほうが記述量が少ないことが多いため、ラムダ優先で記述
- できるだけテストする
