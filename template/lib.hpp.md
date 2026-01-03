---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/util/number.hpp: line 5: #pragma once found in a non-first line\n"
  code: '#include "library/util/number.hpp"

    #include "library/util/string.hpp"

    #include "library/util/sequence.hpp"

    #include "library/util/search.hpp"

    #include "library/util/grid.hpp"

    #include "library/util/geometry.hpp"

    namespace lib {

    Number num;

    String str;

    Sequence seq;

    Search search;

    Grid grid;

    Geometry geo;

    }; // namespace lib

    // -----------------------------------------

    // #include "template/lib.hpp" is done.

    // -----------------------------------------

    '
  dependsOn:
  - library/util/number.hpp
  - library/util/string.hpp
  - library/util/sequence.hpp
  - library/util/search.hpp
  - library/util/grid.hpp
  - library/util/geometry.hpp
  isVerificationFile: false
  path: template/lib.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 21:52:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: template/lib.hpp
layout: document
title: "library/util/*.hpp\u306Einclude\u7528"
---

namespaceを用意しているので`lib:xxx.`とすることで予測変換で見やすい。


