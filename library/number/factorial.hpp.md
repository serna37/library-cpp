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
  bundledCode: "#line 2 \"library/number/factorial.hpp\"\nlong long factorial(int\
    \ N) {\n    long long res = 1;\n    while (N > 0) res *= N--;\n    return res;\n\
    }\n"
  code: "#pragma once\nlong long factorial(int N) {\n    long long res = 1;\n    while\
    \ (N > 0) res *= N--;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/factorial.hpp
  requiredBy: []
  timestamp: '2026-01-08 20:39:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
