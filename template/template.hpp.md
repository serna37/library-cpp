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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "\U0001F36A\U0001F9F8\U0001F43E"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u0E05^>\u03C9<^\u0E05"
    links:
    - https://serna37.github.io/library-cpp/
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 7: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "/**\n * @brief \u0E05^>\u03C9<^\u0E05\n * @author serna37\n * @note https://serna37.github.io/library-cpp/\n\
    \ */\n#ifdef LOCAL\n#include \"template/debug.hpp\"\n#else\n#define debug(...)\n\
    #endif\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"library/def/common.hpp\"\
    \n#include \"library/def/io.hpp\"\n#include \"library/def/type.hpp\"\n#include\
    \ \"library/def/const.hpp\"\n#include \"library/util/number.hpp\"\n#include \"\
    library/util/string.hpp\"\n#include \"library/util/sequence.hpp\"\n#include \"\
    library/util/search.hpp\"\n#include \"library/util/grid.hpp\"\n#include \"library/util/geometry.hpp\"\
    \n#include \"library/struct/graph.hpp\"\n#include \"library/struct/union_find.hpp\"\
    \n#include \"library/struct/fenwick_tree.hpp\"\n#include \"library/struct/segment_tree.hpp\"\
    \n#include \"library/struct/monoid.hpp\"\nnamespace lib {\nNumber num;\nString\
    \ str;\nSequence seq;\nSearch search;\nGrid grid;\nGeometry geo;\n}; // namespace\
    \ lib\nvoid solve();\nsigned main() {\n    solve();\n}\n// -----------------------------------------\n\
    // #include \"template/template.hpp\" is done.\n// -----------------------------------------\n"
  dependsOn:
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
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - main.cpp
  timestamp: '2026-01-01 11:08:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: "\u0E05^>\u03C9<^\u0E05"
---
