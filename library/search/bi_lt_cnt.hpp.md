---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/bi_lt_cnt.hpp\"\ntemplate <typename T> int\
    \ bi_lt_cnt(vector<T> &v, const T &x) {\n    sort(v.begin(), v.end());\n    return\
    \ lower_bound(v.begin(), v.end(), x) - v.begin();\n}\n"
  code: "#pragma once\ntemplate <typename T> int bi_lt_cnt(vector<T> &v, const T &x)\
    \ {\n    sort(v.begin(), v.end());\n    return lower_bound(v.begin(), v.end(),\
    \ x) - v.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bi_lt_cnt.hpp
  requiredBy: []
  timestamp: '2026-01-07 17:15:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/bi_lt_cnt.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u672A\u6E80\u306E\u8981\u7D20\
  \u6570"
---

# 二分探索 配列中 未満の要素数

## できること
- 配列中の「x未満の要素数」を返す
- 中でソートする

## 計算量
$O(NlogN)$

## 使い方
```cpp
int cnt = bi_lt_cnt(A, x);
```
