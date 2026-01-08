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
  bundledCode: "#line 2 \"library/string/finds.hpp\"\nvector<int> finds(const string\
    \ &T, const string &S) {\n    vector<int> pos;\n    auto p = T.find(S);\n    while\
    \ (p != string::npos) {\n        pos.emplace_back(p);\n        p = T.find(S, p\
    \ + 1);\n    }\n    return pos;\n}\n"
  code: "#pragma once\nvector<int> finds(const string &T, const string &S) {\n   \
    \ vector<int> pos;\n    auto p = T.find(S);\n    while (p != string::npos) {\n\
    \        pos.emplace_back(p);\n        p = T.find(S, p + 1);\n    }\n    return\
    \ pos;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/finds.hpp
  requiredBy: []
  timestamp: '2026-01-08 20:39:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/finds.hpp
layout: document
title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570"
---

# 文字列検索 複数

## できること
- 文字列Tの中にあるSの一致場所を全て取得
- マッチした頭のインデックスを返す

## 計算量
$O(|T| * |S|)$

## 使い方
```cpp
vector<int> pos = finds(T, S);
```
