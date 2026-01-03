---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "FenwicTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97 \u548C\
      \u306E\u307F"
    links: []
  bundledCode: "#line 2 \"library/struct/fenwick_tree.hpp\"\n/**\n * @brief FenwicTree\
    \ 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97 \u548C\u306E\u307F\n */\nstruct\
    \ FenwickTree {\n  private:\n    int N;\n    vector<int> fwk;\n\n  public:\n \
    \   FenwickTree(int N) : N(N) {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const\
    \ vector<int> &A) : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for\
    \ (int i = 1; i <= N; ++i) {\n            fwk[i] += A[i - 1];\n            if\
    \ (i + (i & -i) <= N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    // \u5024\
    \u3092\u52A0\u3048\u308B\n    void add(int i, const int &x) {\n        for (++i;\
    \ i <= N; i += i & -i) fwk[i] += x;\n    }\n    // \u03A3[0, i]\n    int sum(int\
    \ i) {\n        int ans = 0;\n        for (++i; i; i -= i & -i) ans += fwk[i];\n\
    \        return ans;\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief FenwicTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\
    \u5F97 \u548C\u306E\u307F\n */\nstruct FenwickTree {\n  private:\n    int N;\n\
    \    vector<int> fwk;\n\n  public:\n    FenwickTree(int N) : N(N) {\n        fwk.assign(N\
    \ + 1, 0);\n    }\n    FenwickTree(const vector<int> &A) : N(A.size()) {\n   \
    \     fwk.assign(N + 1, 0);\n        for (int i = 1; i <= N; ++i) {\n        \
    \    fwk[i] += A[i - 1];\n            if (i + (i & -i) <= N) fwk[i + (i & -i)]\
    \ += fwk[i];\n        }\n    }\n    // \u5024\u3092\u52A0\u3048\u308B\n    void\
    \ add(int i, const int &x) {\n        for (++i; i <= N; i += i & -i) fwk[i] +=\
    \ x;\n    }\n    // \u03A3[0, i]\n    int sum(int i) {\n        int ans = 0;\n\
    \        for (++i; i; i -= i & -i) ans += fwk[i];\n        return ans;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-01-03 22:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.fenwick_tree.test.cpp
documentation_of: library/struct/fenwick_tree.hpp
layout: document
redirect_from:
- /library/library/struct/fenwick_tree.hpp
- /library/library/struct/fenwick_tree.hpp.html
title: "FenwicTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97 \u548C\u306E\u307F"
---
