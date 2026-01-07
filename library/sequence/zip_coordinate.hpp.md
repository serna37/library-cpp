---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/sequence/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/zip_coordinate.hpp\"\ntemplate <typename\
    \ T> int zip_coordinate(vector<T> &A) {\n    vector<T> cvt = A;\n    sort(A.begin(),\
    \ A.end());\n    v.erase(unique(A.begin(), A.end()), v.end());\n    for (auto\
    \ &v : A) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();\n    return\
    \ (int)cvt.size();\n}\n"
  code: "#pragma once\ntemplate <typename T> int zip_coordinate(vector<T> &A) {\n\
    \    vector<T> cvt = A;\n    sort(A.begin(), A.end());\n    v.erase(unique(A.begin(),\
    \ A.end()), v.end());\n    for (auto &v : A) v = lower_bound(cvt.begin(), cvt.end(),\
    \ v) - cvt.begin();\n    return (int)cvt.size();\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/zip_coordinate.hpp
  requiredBy:
  - library/sequence/inversion_number.hpp
  timestamp: '2026-01-07 15:59:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/zip_coordinate.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

# 座標圧縮

## できること
- 大きさの序列のみを保持した配列に圧縮する
- 圧縮後の種類数を返却
- 中でdistinctする
```
1 4 9 9 15 42
```
を座標圧縮すると
```
0 1 2 2 3 4
```
を得る。この時の種類数は5個。要素数ではない。

## 計算量
$O(NlogN)$

## 使い方
```cpp
int sz = zip_coordinate(A);
```
