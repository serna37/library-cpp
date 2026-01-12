---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/number/mod_combination.hpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number/mod_combination.test.cpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/mod_factorial.hpp\"\nvector<long long> _mf_memo;\n\
    long long mod_factorial(int x, long long m) {\n    if ((int)_mf_memo.size() >\
    \ x) return _mf_memo[x];\n    if (_mf_memo.empty()) _mf_memo.push_back(1);\n \
    \   for (int i = _mf_memo.size(); i <= x; ++i)\n        _mf_memo.push_back(_mf_memo.back()\
    \ * i % m);\n    return _mf_memo[x];\n}\n"
  code: "#pragma once\nvector<long long> _mf_memo;\nlong long mod_factorial(int x,\
    \ long long m) {\n    if ((int)_mf_memo.size() > x) return _mf_memo[x];\n    if\
    \ (_mf_memo.empty()) _mf_memo.push_back(1);\n    for (int i = _mf_memo.size();\
    \ i <= x; ++i)\n        _mf_memo.push_back(_mf_memo.back() * i % m);\n    return\
    \ _mf_memo[x];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/mod_factorial.hpp
  requiredBy:
  - library/number/mod_combination.hpp
  timestamp: '2026-01-12 16:20:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number/mod_combination.test.cpp
documentation_of: library/number/mod_factorial.hpp
layout: document
title: "MOD \u968E\u4E57"
---

# MOD 階乗

## できること
- MOD下で、 $N!$ を求める
- メモ化してる

## 計算量
$O(N)$

## 使い方
```cpp
long long fac = mod_factorial(x, MOD);
```
