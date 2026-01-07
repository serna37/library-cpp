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
  bundledCode: "#line 2 \"library/search/bi_le_cnt.hpp\"\ntemplate <typename T> int\
    \ bi_le_cnt(vector<T> &v, const T &x) {\n    sort(v.begin(), v.end());\n    return\
    \ upper_bound(v.begin(), v.end(), x) - v.begin();\n}\n"
  code: "#pragma once\ntemplate <typename T> int bi_le_cnt(vector<T> &v, const T &x)\
    \ {\n    sort(v.begin(), v.end());\n    return upper_bound(v.begin(), v.end(),\
    \ x) - v.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bi_le_cnt.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:37:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/bi_le_cnt.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0B\u306E\u8981\u7D20\
  \u6570"
---

# 二分探索 配列中 以下の要素数

## できること
- 配列中の「x以下の要素数」を返す
- 中でソートする

## 計算量
$O(NlogN)$

## 使い方
```cpp
int cnt = bi_le_cnt(A, x);
```
