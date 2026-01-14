---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/range.test.cpp
    title: "\u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/range.hpp\"\nstring range(const string &S,\
    \ int A, int B) {\n    if (A > B or A >= (int)S.size()) return \"\";\n    return\
    \ S.substr(A, B - A + 1);\n}\n"
  code: "#pragma once\nstring range(const string &S, int A, int B) {\n    if (A >\
    \ B or A >= (int)S.size()) return \"\";\n    return S.substr(A, B - A + 1);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/range.hpp
  requiredBy: []
  timestamp: '2026-01-14 20:12:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/range.test.cpp
documentation_of: library/string/range.hpp
layout: document
title: "\u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97"
---

# 文字列の区間取得

## できること
- 文字列の区間[A, B]を取得

## 計算量
$O(|T|)$ (区間長)

## 使い方
```cpp
string T = range(S, A, B);
```
