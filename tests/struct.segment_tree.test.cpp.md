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
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: library/struct/segment_tree.hpp
    title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: template/includes.hpp
    title: "\u57FA\u672Cinclude\u7528"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    document_title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include \"template/template.hpp\"\n#include \"library/struct/monoid.hpp\"\n\
    #include \"library/struct/segment_tree.hpp\"\n/**\n * @brief \u30BB\u30B0\u6728\
    \u306E\u30C6\u30B9\u30C8:RMQ\n */\nvoid solve() {\n    int N, Q;\n    cin >> N\
    \ >> Q;\n    SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);\n    while\
    \ (Q--) {\n        int com, x, y;\n        cin >> com >> x >> y;\n        if (com\
    \ == 0) {\n            seg.set(x, y);\n        }\n        if (com == 1) {\n  \
    \          print(seg.prod(x, y + 1));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/includes.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  - library/struct/monoid.hpp
  - library/struct/segment_tree.hpp
  isVerificationFile: true
  path: tests/struct.segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-03 21:39:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/struct.segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/struct.segment_tree.test.cpp
- /verify/tests/struct.segment_tree.test.cpp.html
title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
---
