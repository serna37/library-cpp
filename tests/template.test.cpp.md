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
    path: library/struct/fenwick_tree.hpp
    title: "FenwicTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97 \u548C\u306E\u307F"
  - icon: ':heavy_check_mark:'
    path: library/struct/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: library/struct/segment_tree.hpp
    title: "SegmentTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: library/struct/union_find.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: library/util/geometry.hpp
    title: "\u5E7E\u4F55"
  - icon: ':heavy_check_mark:'
    path: library/util/grid.hpp
    title: "\u30B0\u30EA\u30C3\u30C9"
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
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
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
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"template/template.hpp\"\n/*\ntemplate.hpp\u304B\u3089\u547C\u3093\
    \u3067\u3044\u308B\nlibrary/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\
    \u30C8\n\u51FA\u529B\u3059\u308B\u3068\u554F\u984C\u306B\u6B63\u89E3\u3067\u304D\
    \u306A\u3044\u306E\u3067assert\u306E\u307F\n*/\n// ===== library/util/number.hpp\
    \ =====\nvoid test_number() {\n    // TODO test\n}\n// ===== library/util/string.hpp\
    \ =====\nvoid test_string() {\n    // TODO test\n}\n// ===== library/util/sequence.hpp\
    \ =====\nvoid test_sequence() {\n    // TODO test\n}\n// ===== library/util/search.hpp\
    \ =====\nvoid test_search() {\n    // TODO test\n}\n// ===== library/util/grid.hpp\
    \ =====\nvoid test_grid() {\n    // TODO test\n}\n// ===== library/util/gepmetry.hpp\
    \ =====\nvoid test_geometry() {\n    // TODO test\n}\nvoid solve() {\n    // URL\u306E\
    \u554F\u984C\u306E\u7B54\u3048\u306F\u3053\u308C\u3060\u3051\n    cout << \"Hello\
    \ World\" << endl;\n    test_number();\n    test_string();\n    test_sequence();\n\
    \    test_search();\n    test_grid();\n    test_geometry();\n}\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  - library/util/number.hpp
  - library/util/string.hpp
  - library/util/sequence.hpp
  - library/util/search.hpp
  - library/util/grid.hpp
  - library/util/geometry.hpp
  - library/struct/graph.hpp
  - library/struct/union_find.hpp
  - library/struct/fenwick_tree.hpp
  - library/struct/segment_tree.hpp
  - library/struct/monoid.hpp
  isVerificationFile: true
  path: tests/template.test.cpp
  requiredBy: []
  timestamp: '2026-01-01 11:08:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/template.test.cpp
layout: document
redirect_from:
- /verify/tests/template.test.cpp
- /verify/tests/template.test.cpp.html
title: tests/template.test.cpp
---
