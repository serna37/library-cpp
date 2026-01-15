---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.digit_sum.test.cpp
    title: "\u6841\u548C\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/digit_sum.hpp\"\nint digit_sum(int N, int\
    \ base_number = 10) {\n    int res = 0;\n    while (N != 0) {\n        res +=\
    \ N % base_number;\n        N /= base_number;\n    }\n    return res;\n}\n"
  code: "#pragma once\nint digit_sum(int N, int base_number = 10) {\n    int res =\
    \ 0;\n    while (N != 0) {\n        res += N % base_number;\n        N /= base_number;\n\
    \    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/digit_sum.hpp
  requiredBy: []
  timestamp: '2026-01-15 17:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.digit_sum.test.cpp
documentation_of: library/number/digit_sum.hpp
layout: document
title: "\u6841\u548C"
---

# 桁和

## できること
- 整数の、N進数での各桁の和を求める

## 計算量
$O(logN)$

## 使い方
```cpp
int sum = digit_sum(N, 10);
```
