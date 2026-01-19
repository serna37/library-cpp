---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.mod.mod_tetration.test.cpp
    title: "MOD \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/euler_phi.hpp\"\ntemplate <typename T> T\
    \ euler_phi(T n) {\n    T ret = n;\n    for (T i = 2; i * i <= n; ++i) {\n   \
    \     if (n % i == 0) {\n            ret -= ret / i;\n            while (n % i\
    \ == 0) n /= i;\n        }\n    }\n    if (n > 1) ret -= ret / n;\n    return\
    \ ret;\n}\n"
  code: "#pragma once\ntemplate <typename T> T euler_phi(T n) {\n    T ret = n;\n\
    \    for (T i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n           \
    \ ret -= ret / i;\n            while (n % i == 0) n /= i;\n        }\n    }\n\
    \    if (n > 1) ret -= ret / n;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/euler_phi.hpp
  requiredBy:
  - library/number/mod/mod_tetration.hpp
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.mod.mod_tetration.test.cpp
documentation_of: library/number/euler_phi.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
---

# オイラーのφ関数

## できること
- 正の整数Nが与えられたとき、1~Nまでの自然数のうちNと`互いに素`な個数 $\phi (N)$ を求める
- $\phi (n) = n \displaystyle\prod_{i=1}^{k} (1 - \frac{1}{p_i})$

## 計算量
$O(\sqrt{N})$

## 使い方
```cpp
long long ans = euler_phi(N);
```

