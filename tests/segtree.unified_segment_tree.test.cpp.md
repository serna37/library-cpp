---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/segtree/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/segtree/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: library/segtree/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: library/segtree/starry_sky_tree.hpp
    title: Starry Sky Tree
  - icon: ':heavy_check_mark:'
    path: library/segtree/unified_segment_tree.hpp
    title: "\u7D71\u5408\u30BB\u30B0\u6728"
  - icon: ':heavy_check_mark:'
    path: library/various/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: library/various/monoid_act.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    document_title: "\u7D71\u5408\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#include \"template/template.hpp\"\n#include \"library/segtree/unified_segment_tree.hpp\"\
    \n/**\n * @brief \u7D71\u5408\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ\n\
    \ */\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N,\
    \ 0);\n    UnifiedSegmentTree<Monoid::Min, Monoid::Add, MonoidAct::MinAdd> seg(A,\
    \ RangeType::Range, RangeType::Range);\n    while (Q--) {\n        int com, s,\
    \ t;\n        cin >> com >> s >> t;\n        ++t;\n        if (com == 0) {\n \
    \           int x;\n            cin >> x;\n            seg.update(s, t, x);\n\
    \        }\n        if (com == 1) {\n            print(seg.query(s, t));\n   \
    \     }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/segtree/unified_segment_tree.hpp
  - library/segtree/dual_segment_tree.hpp
  - library/various/monoid.hpp
  - library/segtree/fenwick_tree.hpp
  - library/segtree/lazy_segment_tree.hpp
  - library/various/monoid_act.hpp
  - library/segtree/segment_tree.hpp
  - library/segtree/starry_sky_tree.hpp
  isVerificationFile: true
  path: tests/segtree.unified_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 15:19:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segtree.unified_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/segtree.unified_segment_tree.test.cpp
- /verify/tests/segtree.unified_segment_tree.test.cpp.html
title: "\u7D71\u5408\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
---
