---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_pow.hpp
    title: "MOD \u4E8C\u5206\u7D2F\u4E57"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_combination.hpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.mod.mod_combination.test.cpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/mod/mod_pow.hpp\"\nlong long mod_pow(long\
    \ long a, long long n, long long m) {\n    long long res = 1ll;\n    while (n\
    \ > 0) {\n        if (n & 1) res = res * a % m;\n        a = a * a % m;\n    \
    \    n >>= 1ll;\n    }\n    return res;\n}\n#line 3 \"library/number/mod/mod_inverse.hpp\"\
    \nlong long mod_inverse(long long a, long long m) {\n    return mod_pow(a, m -\
    \ 2, m);\n}\n"
  code: "#pragma once\n#include \"library/number/mod/mod_pow.hpp\"\nlong long mod_inverse(long\
    \ long a, long long m) {\n    return mod_pow(a, m - 2, m);\n}\n"
  dependsOn:
  - library/number/mod/mod_pow.hpp
  isVerificationFile: false
  path: library/number/mod/mod_inverse.hpp
  requiredBy:
  - library/number/mod/mod_combination.hpp
  timestamp: '2026-01-16 11:55:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.mod.mod_combination.test.cpp
documentation_of: library/number/mod/mod_inverse.hpp
layout: document
title: "MOD Fermat\u306E\u5C0F\u5B9A\u7406"
---

# MOD Fermatの小定理

## できること
- MOD下で、逆元を求める

## 計算量
$O(logM)$

## 使い方
```cpp
long long inv = mod_inverse(a, MOD);
```
