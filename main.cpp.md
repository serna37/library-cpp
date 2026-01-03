---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
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
  - icon: ':heavy_check_mark:'
    path: library/util/geometry.hpp
    title: "\u5E7E\u4F55"
  - icon: ':heavy_check_mark:'
    path: library/util/grid.hpp
    title: "\u30AF\u3099\u30EA\u30C3\u30C8\u3099"
  - icon: ':heavy_check_mark:'
    path: library/util/number.hpp
    title: "\u6570\u306E\u6027\u8CEA"
  - icon: ':heavy_check_mark:'
    path: library/util/search.hpp
    title: "\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: library/util/sequence.hpp
    title: "\u914D\u5217\u30FB\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: library/util/string.hpp
    title: "\u6587\u5B57\u5217"
  - icon: ':heavy_check_mark:'
    path: template/includes.hpp
    title: "\u57FA\u672Cinclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\U0001F36A\U0001F9F8\U0001F43E"
    links:
    - https://serna37.github.io/library-cpp/
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
  code: "#include \"template/template.hpp\"\n/**\n * @brief \U0001F36A\U0001F9F8\U0001F43E\
    \n * @note https://serna37.github.io/library-cpp/\n */\nvoid solve() {\n}\n"
  dependsOn:
  - template/template.hpp
  - template/includes.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  - template/lib.hpp
  - library/util/number.hpp
  - library/util/string.hpp
  - library/util/sequence.hpp
  - library/util/search.hpp
  - library/util/grid.hpp
  - library/util/geometry.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2026-01-03 23:10:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
title: "main\u30D5\u30A1\u30A4\u30EB"
---

プログラムを書くファイル。 解き終わったらバンドルする。
ライブラリで用意したものは`lib:xxx.`とすることで予測変換で見やすい。

