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
  bundledCode: "#line 2 \"library/search/bi_gt_val.hpp\"\ntemplate <typename T> T\
    \ bi_gt_val(vector<T> &v, const T &x) {\n    sort(v.begin(), v.end());\n    auto\
    \ it = upper_bound(v.begin(), v.end(), x);\n    return (it == v.end() ? INF :\
    \ *it);\n}\ntemplate <typename T> T bi_gt_val(const set<T> &st, const T &x) {\n\
    \    auto it = st.upper_bound(x);\n    return (it == st.end() ? INF : *it);\n\
    }\n"
  code: "#pragma once\ntemplate <typename T> T bi_gt_val(vector<T> &v, const T &x)\
    \ {\n    sort(v.begin(), v.end());\n    auto it = upper_bound(v.begin(), v.end(),\
    \ x);\n    return (it == v.end() ? INF : *it);\n}\ntemplate <typename T> T bi_gt_val(const\
    \ set<T> &st, const T &x) {\n    auto it = st.upper_bound(x);\n    return (it\
    \ == st.end() ? INF : *it);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bi_gt_val.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:37:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/bi_gt_val.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u3088\u308A\u4E0A\u306E\u6700\
  \u5C0F\u5024"
---

# 二分探索 配列中 より上の最小値

## できること
- 配列中の「xより上の最小値」を返す
- 中でソートする

## 計算量
- $O(NlogN)$
- setの場合は二分探索のみなので $O(logN)$

## 使い方
```cpp
int v = bi_gt_val(A, x);
int v = bi_gt_val(st, x);
if (v == INF) {
    // 値が存在しなかった
}
```
