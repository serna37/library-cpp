---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3"
  - icon: ':x:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3\u306E\u30C6\u30B9\u30C8"
  - icon: ':x:'
    path: tests/string.rolling_hash.test.cpp
    title: "\u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8"
  - icon: ':x:'
    path: tests/various.random.test.cpp
    title: "\u4E71\u6570\u751F\u6210\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - library/string/finds.hpp
  - library/string/rolling_hash.hpp
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/string.rolling_hash.test.cpp
  - tests/string.finds.test.cpp
  - tests/various.random.test.cpp
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

