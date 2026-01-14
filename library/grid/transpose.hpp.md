---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/grid/transpose.test.cpp
    title: "\u8EE2\u7F6E\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/grid/transpose.hpp\"\ntemplate <typename T> vector<vector<T>>\
    \ transpose(const vector<vector<T>> &G) {\n    int H = G.size(), W = G[0].size();\n\
    \    vector<vector<T>> _G(W, vector<T>(H));\n    for (int i = 0; i < H; ++i) {\n\
    \        for (int j = 0; j < W; ++j) {\n            _G[j][i] = G[i][j];\n    \
    \    }\n    }\n    return _G;\n}\n"
  code: "#pragma once\ntemplate <typename T> vector<vector<T>> transpose(const vector<vector<T>>\
    \ &G) {\n    int H = G.size(), W = G[0].size();\n    vector<vector<T>> _G(W, vector<T>(H));\n\
    \    for (int i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n  \
    \          _G[j][i] = G[i][j];\n        }\n    }\n    return _G;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/grid/transpose.hpp
  requiredBy: []
  timestamp: '2026-01-14 14:43:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/grid/transpose.test.cpp
documentation_of: library/grid/transpose.hpp
layout: document
title: "\u8EE2\u7F6E"
---

# 転置

## できること
- 縦横を転置した行列をつくる

## 計算量
$O(HW)$

## 使い方
```cpp
vector<vector<int>> T = transpose(G);
```
