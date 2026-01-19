---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_pow.hpp
    title: "MOD \u4E8C\u5206\u7D2F\u4E57"
  _extendedRequiredBy: []
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
    \ ret;\n}\n#line 2 \"library/number/mod/mod_pow.hpp\"\nlong long mod_pow(long\
    \ long a, long long n, long long m) {\n    long long res = 1ll;\n    while (n\
    \ > 0) {\n        if (n & 1) res = res * a % m;\n        a = a * a % m;\n    \
    \    n >>= 1ll;\n    }\n    return res;\n}\n#line 4 \"library/number/mod/mod_tetration.hpp\"\
    \ntemplate <typename T>\nT mod_tetration(const T &a, const T &b, const T &m) {\n\
    \    if (m == 1) return 0;\n    if (a == 0) return !(b & 1);\n    if (b == 0)\
    \ return 1;\n    if (b == 1) return a % m;\n    if (b == 2) return mod_pow(a,\
    \ a, m);\n    auto phi = euler_phi(m);\n    auto tmp = mod_tetration(a, b - 1,\
    \ phi);\n    if (tmp == 0) tmp += phi;\n    return mod_pow(a, tmp, m);\n}\n"
  code: "#pragma once\n#include \"library/number/euler_phi.hpp\"\n#include \"library/number/mod/mod_pow.hpp\"\
    \ntemplate <typename T>\nT mod_tetration(const T &a, const T &b, const T &m) {\n\
    \    if (m == 1) return 0;\n    if (a == 0) return !(b & 1);\n    if (b == 0)\
    \ return 1;\n    if (b == 1) return a % m;\n    if (b == 2) return mod_pow(a,\
    \ a, m);\n    auto phi = euler_phi(m);\n    auto tmp = mod_tetration(a, b - 1,\
    \ phi);\n    if (tmp == 0) tmp += phi;\n    return mod_pow(a, tmp, m);\n}\n"
  dependsOn:
  - library/number/euler_phi.hpp
  - library/number/mod/mod_pow.hpp
  isVerificationFile: false
  path: library/number/mod/mod_tetration.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.mod.mod_tetration.test.cpp
documentation_of: library/number/mod/mod_tetration.hpp
layout: document
title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
---

# テトレーション

## できること
- ${a \uparrow \uparrow b} \bmod m$ を求める
  - $\uparrow \uparrow$ はテトレーション演算で、 $a^{a^{a^{a^{\ldots}}}}$ ( $a$ が $b$ 個続く) を指す

## 計算量
$O(\sqrt{m})$

## 使い方
```cpp
long long ans = mod_tetration(a, b, MOD);
```
