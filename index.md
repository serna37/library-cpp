---
data:
  libraryCategories:
  - name: bits
    pages:
    - icon: ':question:'
      path: bits/stdc++.h
      title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - name: .
    pages:
    - icon: ':warning:'
      path: bundle.cpp
      title: "\u30D0\u30F3\u30C9\u30EB\u5F8C\u306E\u30B5\u30F3\u30D7\u30EB"
    - icon: ':warning:'
      path: main.cpp
      title: "main\u30D5\u30A1\u30A4\u30EB"
  - name: bundler
    pages:
    - icon: ':warning:'
      path: bundler/main.cpp
      title: "C++\u30E9\u30A4\u30D6\u30E9\u30EA\u30D0\u30F3\u30C9\u30E9"
  - name: library/def
    pages:
    - icon: ':question:'
      path: library/def/common.hpp
      title: "\u5171\u901A"
    - icon: ':question:'
      path: library/def/const.hpp
      title: "\u5B9A\u6570"
    - icon: ':question:'
      path: library/def/io.hpp
      title: "IO\u95A2\u9023"
    - icon: ':question:'
      path: library/def/type.hpp
      title: "\u578B"
  - name: library/struct
    pages:
    - icon: ':heavy_check_mark:'
      path: library/struct/dual_segment_tree.hpp
      title: "Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97"
    - icon: ':heavy_check_mark:'
      path: library/struct/fenwick_tree.hpp
      title: "FenwicTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97 \u548C\u306E\
        \u307F"
    - icon: ':warning:'
      path: library/struct/graph.hpp
      title: "\u30B0\u30E9\u30D5"
    - icon: ':heavy_check_mark:'
      path: library/struct/lazy_segment_tree.hpp
      title: "Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
    - icon: ':heavy_check_mark:'
      path: library/struct/monoid.hpp
      title: "\u30E2\u30CE\u30A4\u30C9"
    - icon: ':heavy_check_mark:'
      path: library/struct/segment_tree.hpp
      title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
    - icon: ':heavy_check_mark:'
      path: library/struct/union_find.hpp
      title: UnionFind
  - name: library/util
    pages:
    - icon: ':question:'
      path: library/util/geometry.hpp
      title: "\u5E7E\u4F55"
    - icon: ':question:'
      path: library/util/grid.hpp
      title: "\u30B0\u30EA\u30C3\u30C9"
    - icon: ':question:'
      path: library/util/number.hpp
      title: "\u6570\u306E\u6027\u8CEA"
    - icon: ':question:'
      path: library/util/search.hpp
      title: "\u63A2\u7D22"
    - icon: ':question:'
      path: library/util/sequence.hpp
      title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
    - icon: ':question:'
      path: library/util/string.hpp
      title: "\u6587\u5B57\u5217"
  - name: template
    pages:
    - icon: ':warning:'
      path: template/debug.hpp
      title: "\u3081\u3063\u3061\u3083\u898B\u3084\u3059\u3044debug\u51FA\u529B"
    - icon: ':question:'
      path: template/includes.hpp
      title: "\u57FA\u672Cinclude\u7528"
    - icon: ':question:'
      path: template/lib.hpp
      title: "library/util/*.hpp\u306Einclude\u7528"
    - icon: ':question:'
      path: template/template.hpp
      title: "\u0E05^>\u03C9<^\u0E05"
  verificationCategories:
  - name: tests
    pages:
    - icon: ':heavy_check_mark:'
      path: tests/struct.dual_segment_tree.test.cpp
      title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
    - icon: ':heavy_check_mark:'
      path: tests/struct.fenwick_tree.test.cpp
      title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
    - icon: ':heavy_check_mark:'
      path: tests/struct.lazy_segment_tree.test.cpp
      title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
    - icon: ':heavy_check_mark:'
      path: tests/struct.segment_tree.test.cpp
      title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
    - icon: ':heavy_check_mark:'
      path: tests/struct.union_find.test.cpp
      title: "Union Find\u306E\u30C6\u30B9\u30C8"
    - icon: ':x:'
      path: tests/template.test.cpp
      title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
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
- できるだけテストする
