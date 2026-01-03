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
    path: library/struct/lazy_segment_tree.hpp
    title: "Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
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
    path: template/includes.hpp
    title: "\u57FA\u672Cinclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    document_title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n#include \"template/template.hpp\"\n#include \"library/struct/monoid.hpp\"\n\
    #include \"library/struct/lazy_segment_tree.hpp\"\n/**\n * @brief \u9045\u5EF6\
    \u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ\n */\nvoid solve() {\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> A(N, INT_MAX);\n    LazySegmentTree<int,\
    \ int> seg(Monoid::Min::op, Monoid::Min::e,\n                                \
    \  Monoid::Set::op, Monoid::Set::e,\n                                  MonoidAct::MinSet::op,\
    \ N);\n    while (Q--) {\n        int com;\n        cin >> com;\n        if (com\
    \ == 0) {\n            int s, t, x;\n            cin >> s >> t >> x;\n       \
    \     seg.apply(s, t + 1, x);\n        }\n        if (com == 1) {\n          \
    \  int s, t;\n            cin >> s >> t;\n            print(seg.prod(s, t + 1));\n\
    \        }\n    }\n}\n"
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
  - library/struct/monoid.hpp
  - library/struct/lazy_segment_tree.hpp
  isVerificationFile: true
  path: tests/struct.lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-03 22:01:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/struct.lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/struct.lazy_segment_tree.test.cpp
- /verify/tests/struct.lazy_segment_tree.test.cpp.html
title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
---
