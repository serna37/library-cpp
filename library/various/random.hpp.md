---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/rolling_hash.test.cpp
    title: "\u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/various/random.test.cpp
    title: "\u4E71\u6570\u751F\u6210\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/random.hpp\"\n#include <chrono>\n#include\
    \ <random>\ninline long long random(long long a, long long b) {\n    if (a >=\
    \ b) return a;\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<long long> dist(a, b - 1);\n    return dist(mt);\n\
    }\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\ninline long long random(long\
    \ long a, long long b) {\n    if (a >= b) return a;\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<long long> dist(a, b - 1);\n    return dist(mt);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/various/random.hpp
  requiredBy:
  - library/string/rolling_hash.hpp
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/rolling_hash.test.cpp
  - tests/various/random.test.cpp
documentation_of: library/various/random.hpp
layout: document
title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
---

# 擬似乱数生成

## できること
- [a, b)で乱数生成
- メルセンヌツイスタ

## 計算量
$O(1)$

## 使い方
```cpp
long long randome_number = random(1ll, 1e3ll + 1ll);
```

