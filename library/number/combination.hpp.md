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
  bundledCode: "#line 2 \"library/number/combination.hpp\"\nlong long combination(int\
    \ n, int k) {\n    if (k < 0 || n < k) return 0ll;\n    long long res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n        res *= n--;\n        res /= i;\n \
    \   }\n    return res;\n}\n"
  code: "#pragma once\nlong long combination(int n, int k) {\n    if (k < 0 || n <\
    \ k) return 0ll;\n    long long res = 1;\n    for (int i = 1; i <= k; ++i) {\n\
    \        res *= n--;\n        res /= i;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number/combination.hpp
  requiredBy: []
  timestamp: '2026-01-07 16:12:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number/combination.hpp
layout: document
title: "\u7D44\u307F\u5408\u308F\u305B nCk"
---

# 組み合わせ nCk

## できること
- $nCk$ を求める

## 計算量
$O(k)$

## 使い方
```cpp
long long comb = combination(n, k);
```
