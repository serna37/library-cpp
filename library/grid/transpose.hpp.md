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
  bundledCode: "#line 2 \"library/grid/transpose.hpp\"\ntemplate <typename T> vector<vector<T>>\
    \ transpose(const vector<vector<T>> &G) {\n    int H = G.size(), W = G[0].size();\n\
    \    vector<vector<T>> _G(W, vector<T>(H));\n    for (int i = 0; i < H; ++i) {\n\
    \        for (int j = 0; j < W; ++j) {\n            _G[j][i] = G[i][j];\n    \
    \    }\n    }\n    return _G;\n}\n"
  code: "#pragma once\ntemplate <typename T> vector<vector<T>> transpose(const vector<vector<T>>\
    \ &G) {\n    int H = G.size(), W = G[0].size();\n    vector<vector<T>> _G(W, vector<T>(H));\n\
    \    for (int i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n  \
    \          _G[j][i] = G[i][j];\n        }\n    }\n    return _G;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/grid/transpose.hpp
  requiredBy: []
  timestamp: '2026-01-07 16:29:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
