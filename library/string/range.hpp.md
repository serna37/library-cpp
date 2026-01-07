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
  bundledCode: "#line 2 \"library/string/range.hpp\"\nstring range(const string &S,\
    \ int A, int B) {\n    if (A > B or A >= (int)S.size()) return \"\";\n    return\
    \ S.substr(A, B - A + 1);\n}\n"
  code: "#pragma once\nstring range(const string &S, int A, int B) {\n    if (A >\
    \ B or A >= (int)S.size()) return \"\";\n    return S.substr(A, B - A + 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/string/range.hpp
  requiredBy: []
  timestamp: '2026-01-07 16:29:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
