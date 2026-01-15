---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/join.test.cpp
    title: "\u6587\u5B57\u5217\u7D50\u5408\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/join.hpp\"\nstring join(const vector<string>\
    \ &v, const string &sep) {\n    string res;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        if (0 < i) res += sep;\n        res += v[i];\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\nstring join(const vector<string> &v, const string &sep) {\n\
    \    string res;\n    for (int i = 0; i < (int)v.size(); ++i) {\n        if (0\
    \ < i) res += sep;\n        res += v[i];\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/join.hpp
  requiredBy: []
  timestamp: '2026-01-15 14:36:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/join.test.cpp
documentation_of: library/string/join.hpp
layout: document
title: "\u6587\u5B57\u5217\u7D50\u5408"
---

# 文字列結合

## できること
- 文字列を結合する

## 計算量
$O(\vert S \vert)$ (合計長)

## 使い方
```cpp
vector<string> v;
string S = join(v, ",");
```
