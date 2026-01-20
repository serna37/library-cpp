---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/sequence/compressor.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: library/sequence/static_range_count_distinct.hpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_count_distinct
    document_title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.yosupo.jp/problem/static_range_count_distinct
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n#include \"template/template.hpp\"\n#include \"library/sequence/static_range_count_distinct.hpp\"\
    \n/**\n * @brief \u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\
    \u30C8\n */\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    cin >> A;\n    StaticRangeCountDistinct srcd(A);\n    while (Q--)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        srcd.add_query(l, r);\n\
    \    }\n    auto ans = srcd.calclate_queries();\n    for (auto &&v : ans) print(v);\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/static_range_count_distinct.hpp
  - library/segtree/fenwick_tree.hpp
  - library/sequence/compressor.hpp
  isVerificationFile: true
  path: tests/sequence.static_range_count_distinct.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 20:11:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence.static_range_count_distinct.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence.static_range_count_distinct.test.cpp
- /verify/tests/sequence.static_range_count_distinct.test.cpp.html
title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\u30C8"
---
