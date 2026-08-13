---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/search.binary_search.bi_search_cnt.test.cpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u8981\u7D20\u6570\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/binary_search/bi_lt_cnt.hpp\"\ntemplate <typename\
    \ T> int bi_lt_cnt(vector<T> &v, const T &x) {\n  return lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n}\n"
  code: "#pragma once\ntemplate <typename T> int bi_lt_cnt(vector<T> &v, const T &x)\
    \ {\n  return lower_bound(v.begin(), v.end(), x) - v.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/binary_search/bi_lt_cnt.hpp
  requiredBy: []
  timestamp: '2026-04-07 03:37:28+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/search.binary_search.bi_search_cnt.test.cpp
documentation_of: library/search/binary_search/bi_lt_cnt.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u672A\u6E80\u306E\u8981\u7D20\
  \u6570"
---

# 二分探索 配列中 未満の要素数

## できること
- 配列中の「x未満の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_lt_cnt(A, x);
```
