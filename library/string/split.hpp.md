---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.split.test.cpp
    title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/split.hpp\"\nvector<string> split(const string\
    \ &S, const char &sep) {\n    vector<string> res = {\"\"};\n    for (auto &&v\
    \ : S) {\n        if (v == sep) {\n            res.emplace_back(\"\");\n     \
    \   } else {\n            res.back() += v;\n        }\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\nvector<string> split(const string &S, const char &sep) {\n\
    \    vector<string> res = {\"\"};\n    for (auto &&v : S) {\n        if (v ==\
    \ sep) {\n            res.emplace_back(\"\");\n        } else {\n            res.back()\
    \ += v;\n        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/split.hpp
  requiredBy: []
  timestamp: '2026-01-16 14:13:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.split.test.cpp
documentation_of: library/string/split.hpp
layout: document
title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B"
---

# 文字列を区切る

## できること
- 区切り文字(1文字)で区切る

## 計算量
$O(\vert S \vert)$

## 使い方
```cpp
vector<string> list = split(S, ",");
```
