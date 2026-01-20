---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/segtree/unified_segment_tree.hpp
    title: "\u7D71\u5408\u30BB\u30B0\u6728"
  - icon: ':heavy_check_mark:'
    path: library/sequence/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: library/sequence/static_range_count_distinct.hpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.unified_segment_tree.test.cpp
    title: "\u7D71\u5408\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.inversion_number.test.cpp
    title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u30FBFenwickTree\u306E\
      \u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.static_range_count_distinct.test.cpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\u30C8"
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
  requiredBy:
  - library/segtree/unified_segment_tree.hpp
  - library/sequence/static_range_count_distinct.hpp
  - library/sequence/inversion_number.hpp
  timestamp: '2026-01-07 14:42:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.static_range_count_distinct.test.cpp
  - tests/segtree.fenwick_tree.test.cpp
  - tests/sequence.inversion_number.test.cpp
  - tests/segtree.unified_segment_tree.test.cpp
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
