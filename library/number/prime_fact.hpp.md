---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number/prime_fact.test.cpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/prime_fact.hpp\"\nmap<int, int> prime_fact(int\
    \ N) {\n    map<int, int> P;\n    for (int i = 2; i * i <= N; ++i) {\n       \
    \ while (N % i == 0) {\n            ++P[i];\n            N /= i;\n        }\n\
    \    }\n    if (N > 1) ++P[N];\n    return P;\n}\n"
  code: "#pragma once\nmap<int, int> prime_fact(int N) {\n    map<int, int> P;\n \
    \   for (int i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n       \
    \     ++P[i];\n            N /= i;\n        }\n    }\n    if (N > 1) ++P[N];\n\
    \    return P;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/prime_fact.hpp
  requiredBy: []
  timestamp: '2026-01-12 21:43:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number/prime_fact.test.cpp
documentation_of: library/number/prime_fact.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---

# 素因数分解

## できること
- 整数Nの`<素因数, 個数>`のmapを作る

## 計算量
$O(\sqrt N)$

## 使い方
```cpp
map<int, int> pf = prime_fact(N);
```
