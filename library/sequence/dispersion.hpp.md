---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence/dispersion.test.cpp
    title: "\u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u5206\u5E03\u306E\u30C6\
      \u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/dispersion.hpp\"\nvector<int> dispersion(const\
    \ vector<int> &A) {\n    vector<int> res(2e6);\n    for (auto &&v : A) ++res[v];\n\
    \    return res;\n}\n"
  code: "#pragma once\nvector<int> dispersion(const vector<int> &A) {\n    vector<int>\
    \ res(2e6);\n    for (auto &&v : A) ++res[v];\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/dispersion.hpp
  requiredBy: []
  timestamp: '2026-01-13 11:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence/dispersion.test.cpp
documentation_of: library/sequence/dispersion.hpp
layout: document
title: "\u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u5206\u5E03"
---

# 数直線上での個数分布

## できること
- 配列要素が数直線上の各点に何個ずつあるか、を返す
```
A: 1 2 3 3 5 9
```
を変換すると
```
arr:   1 1 2   1       1          ...
idx: 0 1 2 3 4 5 6 7 8 9 10 11 12 ...
```
を得る

## 計算量
$O(N)$

## 使い方
```cpp
vector<int> disp = dispersion(A);
```
