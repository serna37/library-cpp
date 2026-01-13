---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/various/random.test.cpp
    title: "\u4E71\u6570\u751F\u6210\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/random.hpp\"\ninline int random(int a, int\
    \ b) {\n    if (a >= b) return a;\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<int> dist(a, b - 1);\n    return dist(mt);\n}\n"
  code: "#pragma once\ninline int random(int a, int b) {\n    if (a >= b) return a;\n\
    \    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<int> dist(a, b - 1);\n    return dist(mt);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/various/random.hpp
  requiredBy: []
  timestamp: '2026-01-13 20:35:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
int randome_number = random(1, 1e3 + 1);
```

