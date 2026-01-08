---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/sequence/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
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
    \    return (int)cvt.size();\n}\n"
  code: "#pragma once\ntemplate <typename T> int zip_coordinate(vector<T> &A) {\n\
    \    vector<T> cvt = A;\n    sort(cvt.begin(), cvt.end());\n    cvt.erase(unique(cvt.begin(),\
    \ cvt.end()), cvt.end());\n    for (auto &v : A) v = lower_bound(cvt.begin(),\
    \ cvt.end(), v) - cvt.begin();\n    return (int)cvt.size();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/zip_coordinate.hpp
  requiredBy:
  - library/sequence/inversion_number.hpp
  timestamp: '2026-01-08 22:08:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence/inversion_number.test.cpp
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
