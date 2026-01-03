---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
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
  - icon: ':question:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\U0001F36A\U0001F9F8\U0001F43E"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 7: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#include \"template/template.hpp\"\n// #include \"template/lib.hpp\"\n//\
    \ #include \"library/struct/graph.hpp\"\n// #include \"library/struct/union_find.hpp\"\
    \n// #include \"library/struct/fenwick_tree.hpp\"\n// #include \"library/struct/monoid.hpp\"\
    \n// #include \"library/struct/segment_tree.hpp\"\n// #include \"library/struct/dual_segment_tree.hpp\"\
    \n// #include \"library/struct/lazy_segment_tree.hpp\"\n/**\n * @brief \U0001F36A\
    \U0001F9F8\U0001F43E\n */\nvoid solve() {\n}\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2026-01-03 21:07:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
title: "main\u30D5\u30A1\u30A4\u30EB"
---

プログラムを書くファイル。 解き終わったらバンドルする。
ライブラリで用意したものは`lib:xxx.`とすることで予測変換で見やすい。

