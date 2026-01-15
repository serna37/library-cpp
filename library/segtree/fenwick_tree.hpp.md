---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/fenwick_tree.hpp\"\nstruct FenwickTree {\n\
    \  private:\n    int N;\n    vector<int> fwk;\n\n  public:\n    FenwickTree(int\
    \ N) : N(N) {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const vector<int>\
    \ &A) : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for (int i = 1;\
    \ i <= N; ++i) {\n            fwk[i] += A[i - 1];\n            if (i + (i & -i)\
    \ <= N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    void add(int i, const\
    \ int &x) {\n        for (++i; i <= N; i += i & -i) fwk[i] += x;\n    }\n    int\
    \ sum(int i) {\n        int ans = 0;\n        for (++i; i; i -= i & -i) ans +=\
    \ fwk[i];\n        return ans;\n    }\n};\n"
  code: "#pragma once\nstruct FenwickTree {\n  private:\n    int N;\n    vector<int>\
    \ fwk;\n\n  public:\n    FenwickTree(int N) : N(N) {\n        fwk.assign(N + 1,\
    \ 0);\n    }\n    FenwickTree(const vector<int> &A) : N(A.size()) {\n        fwk.assign(N\
    \ + 1, 0);\n        for (int i = 1; i <= N; ++i) {\n            fwk[i] += A[i\
    \ - 1];\n            if (i + (i & -i) <= N) fwk[i + (i & -i)] += fwk[i];\n   \
    \     }\n    }\n    void add(int i, const int &x) {\n        for (++i; i <= N;\
    \ i += i & -i) fwk[i] += x;\n    }\n    int sum(int i) {\n        int ans = 0;\n\
    \        for (++i; i; i -= i & -i) ans += fwk[i];\n        return ans;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/segtree/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-01-15 11:05:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/fenwick_tree.test.cpp
documentation_of: library/segtree/fenwick_tree.hpp
layout: document
title: Fenwick Tree
---

# Fenwick Tree

## できること
- 1点に加算する
- 区間[0, i]の和を取得

## 計算量
- 構築: $O(N)$
- 1点更新`add`: $O(logN)$
- 区間取得`sum`: $O(logN)$

## 使い方
```cpp
FenwickTree fwk(N);
```
