---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_factorial.hpp
    title: "MOD \u968E\u4E57"
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_inverse.hpp
    title: "MOD Fermat\u306E\u5C0F\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_pow.hpp
    title: "MOD \u4E8C\u5206\u7D2F\u4E57"
  _extendedRequiredBy: []
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
    \ 2, m);\n}\n#line 2 \"library/number/mod/mod_factorial.hpp\"\nvector<long long>\
    \ _mf_memo;\nlong long mod_factorial(int x, long long m) {\n    if ((int)_mf_memo.size()\
    \ > x) return _mf_memo[x];\n    if (_mf_memo.empty()) _mf_memo.push_back(1);\n\
    \    for (int i = _mf_memo.size(); i <= x; ++i)\n        _mf_memo.push_back(_mf_memo.back()\
    \ * i % m);\n    return _mf_memo[x];\n}\n#line 4 \"library/number/mod/mod_combination.hpp\"\
    \nlong long mod_combination(int n, int k, long long m) {\n    if (k < 0 or n <\
    \ k) return 0ll;\n    return mod_factorial(n, m) * mod_inverse(mod_factorial(k,\
    \ m), m) % m *\n           mod_inverse(mod_factorial(n - k, m), m) % m;\n}\n"
  code: "#pragma once\n#include \"library/number/mod/mod_inverse.hpp\"\n#include \"\
    library/number/mod/mod_factorial.hpp\"\nlong long mod_combination(int n, int k,\
    \ long long m) {\n    if (k < 0 or n < k) return 0ll;\n    return mod_factorial(n,\
    \ m) * mod_inverse(mod_factorial(k, m), m) % m *\n           mod_inverse(mod_factorial(n\
    \ - k, m), m) % m;\n}\n"
  dependsOn:
  - library/number/mod/mod_inverse.hpp
  - library/number/mod/mod_pow.hpp
  - library/number/mod/mod_factorial.hpp
  isVerificationFile: false
  path: library/number/mod/mod_combination.hpp
  requiredBy: []
  timestamp: '2026-01-16 11:55:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.mod.mod_combination.test.cpp
documentation_of: library/number/mod/mod_combination.hpp
layout: document
title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk"
---

# MOD 組み合わせ nCk

## できること
- MOD下で、 $nCk$ を求める

## 計算量
$O(logM)$

## 使い方
```cpp
long long comb = mod_combination(n, k, MOD);
```
