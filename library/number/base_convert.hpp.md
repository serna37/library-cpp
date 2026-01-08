---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number/base_convert.test.cpp
    title: "\u9032\u6570\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/base_convert.hpp\"\nvector<int> base_convert(long\
    \ long x, int to) {\n    vector<int> ret;\n    long long t = 1, k = abs(to);\n\
    \    while (x) {\n        ret.emplace_back((x * t) % k);\n        if (ret.back()\
    \ < 0) ret.back() += k;\n        x -= ret.back() * t;\n        x /= k;\n     \
    \   t *= to / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n    reverse(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\nvector<int> base_convert(long long x, int to) {\n    vector<int>\
    \ ret;\n    long long t = 1, k = abs(to);\n    while (x) {\n        ret.emplace_back((x\
    \ * t) % k);\n        if (ret.back() < 0) ret.back() += k;\n        x -= ret.back()\
    \ * t;\n        x /= k;\n        t *= to / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n\
    \    reverse(ret.begin(), ret.end());\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/base_convert.hpp
  requiredBy: []
  timestamp: '2026-01-08 21:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number/base_convert.test.cpp
documentation_of: library/number/base_convert.hpp
layout: document
title: "\u9032\u6570\u5909\u63DB"
---

# 進数変換

## できること
- to進数に変換する
- 結果が`42`の場合、`4, 2`と配列で返す

## 計算量
$O(log_{|to|} x)$

## 使い方
```cpp
vector<int> cvt = base_convert(x, 10);
```
