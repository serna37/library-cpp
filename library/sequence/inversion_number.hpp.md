---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/zip_coordinate.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence/inversion_number.test.cpp
    title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/zip_coordinate.hpp\"\ntemplate <typename\
    \ T> int zip_coordinate(vector<T> &A) {\n    vector<T> cvt = A;\n    sort(cvt.begin(),\
    \ cvt.end());\n    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());\n   \
    \ for (auto &v : A) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();\n\
    \    return (int)cvt.size();\n}\n#line 3 \"library/sequence/inversion_number.hpp\"\
    \ntemplate <typename T> long long inversion_number(vector<T> &A) {\n    int sz\
    \ = zip_coordinate(A);\n    vector<int> fwk(sz + 1);\n    long long inv = 0, N\
    \ = A.size();\n    for (int i = 0; i < N; ++i) {\n        for (int f = sz; f;\
    \ f -= f & -f) inv += fwk[f];\n        for (int f = A[i] + 1; f; f -= f & -f)\
    \ inv -= fwk[f];\n        for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n\
    \    }\n    return inv;\n}\n"
  code: "#pragma once\n#include \"library/sequence/zip_coordinate.hpp\"\ntemplate\
    \ <typename T> long long inversion_number(vector<T> &A) {\n    int sz = zip_coordinate(A);\n\
    \    vector<int> fwk(sz + 1);\n    long long inv = 0, N = A.size();\n    for (int\
    \ i = 0; i < N; ++i) {\n        for (int f = sz; f; f -= f & -f) inv += fwk[f];\n\
    \        for (int f = A[i] + 1; f; f -= f & -f) inv -= fwk[f];\n        for (int\
    \ f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n    }\n    return inv;\n}\n"
  dependsOn:
  - library/sequence/zip_coordinate.hpp
  isVerificationFile: false
  path: library/sequence/inversion_number.hpp
  requiredBy: []
  timestamp: '2026-01-14 18:38:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence/inversion_number.test.cpp
documentation_of: library/sequence/inversion_number.hpp
layout: document
title: "\u8EE2\u5012\u6570"
---

# 転倒数

## できること
- 右に倒れる$A_i > A_j (i < j)$の回数を求める
- 中で座標圧縮してるので配列は破壊
- Fenwick Treeで求めている

## 計算量
$O(NlogN)$

## 使い方
```cpp
long long inv = inversion_number(A);
```
