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
    path: library/various/mo.hpp
    title: Mo's algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    document_title: "Mo's algorithm\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"template/template.hpp\"\n#include \"library/sequence/compressor.hpp\"\
    \n#include \"library/segtree/fenwick_tree.hpp\"\n#include \"library/various/mo.hpp\"\
    \n/**\n * @brief Mo's algorithm\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    cin >> A;\n   \
    \ Mo mo(N, Q);\n    for (int i = 0; i < Q; ++i) {\n        int l, r;\n       \
    \ cin >> l >> r;\n        mo.add_query(l, r);\n    }\n    Compressor zip(A);\n\
    \    A = zip.get_all();\n    FenwickTree fwk(zip.size());\n    int64_t inv = 0,\
    \ all = 0;\n    vector<int64_t> ans(Q);\n    auto add_left = [&](int idx) {\n\
    \        inv += fwk.sum(A[idx] - 1);\n        fwk.add(A[idx], 1);\n        all++;\n\
    \    };\n    auto add_right = [&](int idx) {\n        inv += all - fwk.sum(A[idx]);\n\
    \        fwk.add(A[idx], 1);\n        ++all;\n    };\n    auto erase_left = [&](int\
    \ idx) {\n        fwk.add(A[idx], -1);\n        --all;\n        inv -= fwk.sum(A[idx]\
    \ - 1);\n    };\n    auto erase_right = [&](int idx) {\n        fwk.add(A[idx],\
    \ -1);\n        --all;\n        inv -= all - fwk.sum(A[idx]);\n    };\n    auto\
    \ query = [&](int idx) { ans[idx] = inv; };\n    mo.calclate_queries(add_left,\
    \ add_right, erase_left, erase_right, query);\n    for (auto &p : ans) print(p);\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/compressor.hpp
  - library/segtree/fenwick_tree.hpp
  - library/various/mo.hpp
  isVerificationFile: true
  path: tests/various.mo.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 20:11:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/various.mo.test.cpp
layout: document
redirect_from:
- /verify/tests/various.mo.test.cpp
- /verify/tests/various.mo.test.cpp.html
title: "Mo's algorithm\u306E\u30C6\u30B9\u30C8"
---
