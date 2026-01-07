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
  bundledCode: "#line 2 \"library/grid/bfs.hpp\"\nconst vector<int> dx = {0, 1, 0,\
    \ -1};\nconst vector<int> dy = {1, 0, -1, 0};\ntemplate <typename T, typename\
    \ F> void bfs(vector<vector<T>> &G, F f) {\n    int H = G.size(), W = G[0].size();\n\
    \    // TODO queue\u306E\u51E6\u7406\u306A\u304F\u306D\uFF1F\n    for (int i =\
    \ 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n            for (int\
    \ k = 0; k < 4; ++k) {\n                int y = i + dy[k], x = j + dx[k];\n  \
    \              if (y < 0 or x < 0 or H <= y or W <= x) continue;\n           \
    \     f(y, x);\n            }\n        }\n    }\n}\n"
  code: "#pragma once\nconst vector<int> dx = {0, 1, 0, -1};\nconst vector<int> dy\
    \ = {1, 0, -1, 0};\ntemplate <typename T, typename F> void bfs(vector<vector<T>>\
    \ &G, F f) {\n    int H = G.size(), W = G[0].size();\n    // TODO queue\u306E\u51E6\
    \u7406\u306A\u304F\u306D\uFF1F\n    for (int i = 0; i < H; ++i) {\n        for\
    \ (int j = 0; j < W; ++j) {\n            for (int k = 0; k < 4; ++k) {\n     \
    \           int y = i + dy[k], x = j + dx[k];\n                if (y < 0 or x\
    \ < 0 or H <= y or W <= x) continue;\n                f(y, x);\n            }\n\
    \        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/grid/bfs.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:05:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/grid/bfs.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C94\u65B9\u5411\u3078\u306EBFS"
---

# グリッド4方向へのBFS

## できること
- xxx

## 計算量
$O(HW)$

## 使い方
```cpp
// TODO
```
