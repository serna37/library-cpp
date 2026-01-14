---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/run_length.test.cpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/run_length.hpp\"\nvector<pair<char, int>>\
    \ run_length(const string &S) {\n    vector<pair<char, int>> res;\n    for (auto\
    \ &&x : S) {\n        if (res.empty() or res.back().first != x) res.emplace_back(x,\
    \ 0);\n        ++res.back().second;\n    }\n    return res;\n}\n"
  code: "#pragma once\nvector<pair<char, int>> run_length(const string &S) {\n   \
    \ vector<pair<char, int>> res;\n    for (auto &&x : S) {\n        if (res.empty()\
    \ or res.back().first != x) res.emplace_back(x, 0);\n        ++res.back().second;\n\
    \    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/run_length.hpp
  requiredBy: []
  timestamp: '2026-01-14 15:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/run_length.test.cpp
documentation_of: library/string/run_length.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---

# ランレングス圧縮

## できること
- 文字の連続数で圧縮する
```
AAAABBBCDDDD
↓
{ [A, 4], [B, 3], [C, 1], [D, 4] }
```

## 計算量
$O(|S|)$

## 使い方
```cpp
vector<pair<char, int>> R = run_length(S);
```
