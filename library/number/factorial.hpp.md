---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.factorial.test.cpp
    title: "\u968E\u4E57\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/factorial.hpp\"\nlong long factorial(int\
    \ N) {\n    long long res = 1;\n    while (N > 0) res *= N--;\n    return res;\n\
    }\n"
  code: "#pragma once\nlong long factorial(int N) {\n    long long res = 1;\n    while\
    \ (N > 0) res *= N--;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/factorial.hpp
  requiredBy: []
  timestamp: '2026-01-16 16:23:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.factorial.test.cpp
documentation_of: library/number/factorial.hpp
layout: document
title: "\u968E\u4E57"
---

# 階乗

## できること
- $N!$ を求める

## 計算量
$O(N)$

## 使い方
```cpp
long long fac = factorial(N);
```
