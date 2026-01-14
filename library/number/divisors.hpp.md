---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number/divisors.test.cpp
    title: "\u7D04\u6570\u5217\u6319\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/divisors.hpp\"\nvector<int> divisors(int\
    \ N) {\n    vector<int> res;\n    for (int i = 1; i * i <= N; ++i) {\n       \
    \ if (N % i != 0) continue;\n        res.push_back(i);\n        if (N / i != i)\
    \ res.push_back(N / i);\n    }\n    return res;\n}\n"
  code: "#pragma once\nvector<int> divisors(int N) {\n    vector<int> res;\n    for\
    \ (int i = 1; i * i <= N; ++i) {\n        if (N % i != 0) continue;\n        res.push_back(i);\n\
    \        if (N / i != i) res.push_back(N / i);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/divisors.hpp
  requiredBy: []
  timestamp: '2026-01-14 15:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number/divisors.test.cpp
documentation_of: library/number/divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---

# 約数列挙

## できること
- 整数Nの約数一覧の配列を返す

## 計算量
$O(\sqrt N)$

## 使い方
```cpp
vector<int> divs = divisors(N);
```
