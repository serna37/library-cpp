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
  bundledCode: "#line 2 \"library/grid/bfs8.hpp\"\nconst vector<int> dx8 = {0, 1,\
    \ 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n\
    template <typename T, typename F> void bfs8(vector<vector<T>> &G, F f) {\n   \
    \ int H = G.size(), W = G[0].size();\n    for (int i = 0; i < H; ++i) {\n    \
    \    for (int j = 0; j < W; ++j) {\n            for (int k = 0; k < 8; ++k) {\n\
    \                int y = i + dy8[k], x = j + dx8[k];\n                if (y <\
    \ 0 or x < 0 or H <= y or W <= x) continue;\n                f(y, x);\n      \
    \      }\n        }\n    }\n}\n"
  code: "#pragma once\nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst\
    \ vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\ntemplate <typename T, typename\
    \ F> void bfs8(vector<vector<T>> &G, F f) {\n    int H = G.size(), W = G[0].size();\n\
    \    for (int i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n  \
    \          for (int k = 0; k < 8; ++k) {\n                int y = i + dy8[k],\
    \ x = j + dx8[k];\n                if (y < 0 or x < 0 or H <= y or W <= x) continue;\n\
    \                f(y, x);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/grid/bfs8.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:05:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/grid/bfs8.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C98\u65B9\u5411\u3078\u306EBFS"
---

# グリッド8方向へのBFS

## できること
- xxx

## 計算量
$O(HW)$

## 使い方
```cpp
// TODO
```
