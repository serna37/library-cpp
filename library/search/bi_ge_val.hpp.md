---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search/bi_ge_val.test.cpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u6700\u5C0F\
      \u5024\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/bi_ge_val.hpp\"\ntemplate <typename T> T\
    \ bi_ge_val(vector<T> &v, const T &x) {\n    auto it = lower_bound(v.begin(),\
    \ v.end(), x);\n    return (it == v.end() ? INF : *it);\n}\ntemplate <typename\
    \ T> T bi_ge_val(const set<T> &st, const T &x) {\n    auto it = st.lower_bound(x);\n\
    \    return (it == st.end() ? INF : *it);\n}\n"
  code: "#pragma once\ntemplate <typename T> T bi_ge_val(vector<T> &v, const T &x)\
    \ {\n    auto it = lower_bound(v.begin(), v.end(), x);\n    return (it == v.end()\
    \ ? INF : *it);\n}\ntemplate <typename T> T bi_ge_val(const set<T> &st, const\
    \ T &x) {\n    auto it = st.lower_bound(x);\n    return (it == st.end() ? INF\
    \ : *it);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bi_ge_val.hpp
  requiredBy: []
  timestamp: '2026-01-13 14:30:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/search/bi_ge_val.test.cpp
documentation_of: library/search/bi_ge_val.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u6700\u5C0F\
  \u5024"
---

# 二分探索 配列中 以上の最小値

## できること
- 配列中の「x以上の最小値」を返す

## 計算量
- $O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int v = bi_ge_val(A, x);
int v = bi_ge_val(st, x);
if (v == INF) {
    // 値が存在しなかった
}
```
