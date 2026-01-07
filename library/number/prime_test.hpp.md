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
  bundledCode: "#line 2 \"library/number/prime_test.hpp\"\nbool prime_test(int N)\
    \ {\n    if (N == 2) return true;\n    if (N == 1 or N % 2 == 0) return false;\n\
    \    for (int i = 3; i * i <= N; i += 2) {\n        if (N % i == 0) return false;\n\
    \    }\n    return true;\n}\n"
  code: "#pragma once\nbool prime_test(int N) {\n    if (N == 2) return true;\n  \
    \  if (N == 1 or N % 2 == 0) return false;\n    for (int i = 3; i * i <= N; i\
    \ += 2) {\n        if (N % i == 0) return false;\n    }\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number/prime_test.hpp
  requiredBy: []
  timestamp: '2026-01-07 16:29:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number/prime_test.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A"
---

# 素数判定

## できること
- 整数Nが素数であるかどうかを判定する

## 計算量
$O(\sqrt N)$

## 使い方
```cpp
bool is_prime = prime_test(N);
```
