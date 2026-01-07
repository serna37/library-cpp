---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/number/mod_combination.hpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk"
  - icon: ':warning:'
    path: library/number/mod_inverse.hpp
    title: "MOD Fermat\u306E\u5C0F\u5B9A\u7406"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/mod_pow.hpp\"\nlong long mod_pow(long long\
    \ a, long long n, long long m) {\n    long long res = 1ll;\n    while (n > 0)\
    \ {\n        if (n & 1) res = res * a % m;\n        a = a * a % m;\n        n\
    \ >>= 1ll;\n    }\n    return res;\n}\n"
  code: "#pragma once\nlong long mod_pow(long long a, long long n, long long m) {\n\
    \    long long res = 1ll;\n    while (n > 0) {\n        if (n & 1) res = res *\
    \ a % m;\n        a = a * a % m;\n        n >>= 1ll;\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/mod_pow.hpp
  requiredBy:
  - library/number/mod_inverse.hpp
  - library/number/mod_combination.hpp
  timestamp: '2026-01-07 21:37:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number/mod_pow.hpp
layout: document
title: "MOD \u4E8C\u5206\u7D2F\u4E57"
---

# MOD 二分累乗

## できること
- MOD下で、 $a^n$ を求める

## 計算量
$O(logN)$

## 使い方
```cpp
long long ans = mod_pow(a, n, MOD);
```
