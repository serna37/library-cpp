---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.div.test.cpp
    title: "\u5272\u308A\u7B97\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/div.hpp\"\nlong long div_ceil(long long a,\
    \ long long b) { // \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\
    \n    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);\n}\nlong long div_floor(long\
    \ long a, long long b) { // \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\
    \u3044\n    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);\n}\n"
  code: "#pragma once\nlong long div_ceil(long long a, long long b) { // \u8CA0\u306E\
    \u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\n    return a / b + (((a ^ b)\
    \ > 0 and a % b != 0) ? 1 : 0);\n}\nlong long div_floor(long long a, long long\
    \ b) { // \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\n    return\
    \ a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/div.hpp
  requiredBy: []
  timestamp: '2026-01-15 17:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.div.test.cpp
documentation_of: library/number/div.hpp
layout: document
title: "\u5272\u308A\u7B97"
---

# 割り算

## できること
- 割り算の、切り上げ・切り下げ
- 負の場合0側へ丸めない

## 計算量
$O(1)$

## 使い方
そのままなので省略
