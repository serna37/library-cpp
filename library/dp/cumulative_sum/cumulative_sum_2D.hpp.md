---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/dp/cumulative_sum/cumulative_sum_2D.hpp\"\ntemplate\
    \ <typename T>\nvector<vector<long long>> cumulative_sum_2D(const vector<T> &G)\
    \ {\n    int H = G.size(), W = G[0].size();\n    vector<vector<long long>> S(H\
    \ + 1, vector<long long>(W + 1));\n    for (int i = 0; i < H; ++i) { // \u6A2A\
    \u5411\u304D\n        for (int j = 0; j < W; ++j) {\n            S[i + 1][j +\
    \ 1] = S[i + 1][j] + G[i][j];\n        }\n    }\n    for (int i = 0; i < H; ++i)\
    \ { // \u7E26\u5411\u304D\n        for (int j = 0; j < W; ++j) {\n           \
    \ S[i + 1][j + 1] += S[i][j + 1];\n        }\n    }\n    return S;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<vector<long long>> cumulative_sum_2D(const\
    \ vector<T> &G) {\n    int H = G.size(), W = G[0].size();\n    vector<vector<long\
    \ long>> S(H + 1, vector<long long>(W + 1));\n    for (int i = 0; i < H; ++i)\
    \ { // \u6A2A\u5411\u304D\n        for (int j = 0; j < W; ++j) {\n           \
    \ S[i + 1][j + 1] = S[i + 1][j] + G[i][j];\n        }\n    }\n    for (int i =\
    \ 0; i < H; ++i) { // \u7E26\u5411\u304D\n        for (int j = 0; j < W; ++j)\
    \ {\n            S[i + 1][j + 1] += S[i][j + 1];\n        }\n    }\n    return\
    \ S;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dp/cumulative_sum/cumulative_sum_2D.hpp
  requiredBy: []
  timestamp: '2026-01-16 13:01:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp
documentation_of: library/dp/cumulative_sum/cumulative_sum_2D.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---

# 2次元累積和

## できること
- 2次元平面での累積和を返す

## 計算量
$O(HW)$

## 使い方
```cpp
vector<vector<long long>> S = cumulative_sum_2D(G);
```
$\sum$ (s,t)~(x,y) は以下の包除で求める
```cpp
long long ans = S[y][x] - S[y][s] - S[t][x] + S[t][s];
```
