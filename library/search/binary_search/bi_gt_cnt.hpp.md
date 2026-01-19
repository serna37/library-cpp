---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search.binary_search.bi_search_cnt.test.cpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u8981\u7D20\u6570\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/binary_search/bi_gt_cnt.hpp\"\ntemplate <typename\
    \ T> int bi_gt_cnt(vector<T> &v, const T &x) {\n    return v.end() - upper_bound(v.begin(),\
    \ v.end(), x);\n}\n"
  code: "#pragma once\ntemplate <typename T> int bi_gt_cnt(vector<T> &v, const T &x)\
    \ {\n    return v.end() - upper_bound(v.begin(), v.end(), x);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/binary_search/bi_gt_cnt.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/search.binary_search.bi_search_cnt.test.cpp
documentation_of: library/search/binary_search/bi_gt_cnt.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u3088\u308A\u4E0A\u306E\u8981\
  \u7D20\u6570"
---

# 二分探索 配列中 より上の要素数

## できること
- 配列中の「xより上の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_gt_cnt(A, x);
```
