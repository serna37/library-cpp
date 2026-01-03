---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/includes.h
    title: "\u5FC5\u8981\u306Ainclude\u3092\u7528\u610F"
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
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
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
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
    #endif\n#include \"bits/includes.h\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#include \"library/def/common.hpp\"\n#include \"library/def/io.hpp\"\n\
    #include \"library/def/type.hpp\"\n#include \"library/def/const.hpp\"\nvoid solve();\n\
    signed main() {\n    solve();\n}\n// -----------------------------------------\n\
    // #include \"template/template.hpp\" is done.\n// -----------------------------------------\n"
  dependsOn:
  - bits/includes.h
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - main.cpp
  timestamp: '2026-01-03 21:26:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: "\u0E05^>\u03C9<^\u0E05"
---
