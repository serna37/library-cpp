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
  bundledCode: "#line 2 \"library/search/bi_ge_cnt.hpp\"\ntemplate <typename T> int\
    \ bi_ge_cnt(vector<T> &v, const T &x) {\n    sort(v.begin(), v.end());\n    return\
    \ v.end() - lower_bound(v.begin(), v.end(), x);\n}\n"
  code: "#pragma once\ntemplate <typename T> int bi_ge_cnt(vector<T> &v, const T &x)\
    \ {\n    sort(v.begin(), v.end());\n    return v.end() - lower_bound(v.begin(),\
    \ v.end(), x);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bi_ge_cnt.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:05:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/bi_ge_cnt.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u8981\u7D20\
  \u6570"
---

# 二分探索 配列中 以上の要素数

## できること
- 配列中の「x以上の要素数」を返す
- 中でソートする

## 計算量
$O(NlogN)$

## 使い方
```cpp
int cnt = bi_ge_cnt(A, x);
```
