---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/base_convert.hpp\"\nstring base_convert(const\
    \ string &S, int from, int to) {\n    long long base_10_number = 0ll;\n    for\
    \ (auto &&v : S) base_10_number = base_10_number * from + (int)(v - '0');\n  \
    \  if (base_10_number == 0) return \"0\";\n    string res = \"\";\n    while (base_10_number)\
    \ {\n        res = (char)(base_10_number % to + '0') + res;\n        base_10_number\
    \ /= to;\n    }\n    return res;\n}\n"
  code: "#pragma once\nstring base_convert(const string &S, int from, int to) {\n\
    \    long long base_10_number = 0ll;\n    for (auto &&v : S) base_10_number =\
    \ base_10_number * from + (int)(v - '0');\n    if (base_10_number == 0) return\
    \ \"0\";\n    string res = \"\";\n    while (base_10_number) {\n        res =\
    \ (char)(base_10_number % to + '0') + res;\n        base_10_number /= to;\n  \
    \  }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number/base_convert.hpp
  requiredBy: []
  timestamp: '2026-01-07 16:12:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number/base_convert.hpp
layout: document
title: "\u9032\u6570\u5909\u63DB"
---

# 進数変換

## できること
- 進数を変換する
- fromとtoは10を超えないこと

## 計算量
$O(|S|)$

## 使い方
```cpp
// 10進数から2進数に変換
string T = base_convert(S, 10, 2);
```
