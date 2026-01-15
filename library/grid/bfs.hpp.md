---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/grid/bfs.test.cpp
    title: "\u30B0\u30EA\u30C3\u30C9BFS\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/grid/bfs.hpp\"\nconst vector<int> dx = {0, 1, 0,\
    \ -1};\nconst vector<int> dy = {1, 0, -1, 0};\nconst vector<int> dx8 = {0, 1,\
    \ 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n\
    template <typename T>\nvector<vector<int>> bfs(vector<vector<T>> &G, T start,\
    \ int d = 4,\n                        const string &wall = \"#\") {\n    int H\
    \ = G.size(), W = G[0].size();\n    vector<vector<int>> min_cost(H, vector<int>(W,\
    \ -1));\n    queue<pair<int, int>> q;\n    for (int i = 0; i < H; ++i) {\n   \
    \     for (int j = 0; j < W; ++j) {\n            if (G[i][j] == start) {\n   \
    \             q.emplace(i, j);\n                min_cost[i][j] = 0;\n        \
    \    }\n        }\n    }\n    while (!q.empty()) {\n        auto [Y, X] = q.front();\n\
    \        q.pop();\n        for (int i = 0; i < d; ++i) {\n            int y =\
    \ Y + (d == 4 ? dy[i] : dy8[i]),\n                x = X + (d == 4 ? dx[i] : dx8[i]);\n\
    \            if (y < 0 or x < 0 or H <= y or W <= x) continue;\n            if\
    \ (~min_cost[y][x]) continue;\n            if (wall.find(G[y][x]) != string::npos)\
    \ continue;\n            min_cost[y][x] = min_cost[Y][X] + 1;\n            q.emplace(y,\
    \ x);\n        }\n    }\n    return min_cost;\n}\n"
  code: "#pragma once\nconst vector<int> dx = {0, 1, 0, -1};\nconst vector<int> dy\
    \ = {1, 0, -1, 0};\nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst\
    \ vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\ntemplate <typename T>\nvector<vector<int>>\
    \ bfs(vector<vector<T>> &G, T start, int d = 4,\n                        const\
    \ string &wall = \"#\") {\n    int H = G.size(), W = G[0].size();\n    vector<vector<int>>\
    \ min_cost(H, vector<int>(W, -1));\n    queue<pair<int, int>> q;\n    for (int\
    \ i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n            if\
    \ (G[i][j] == start) {\n                q.emplace(i, j);\n                min_cost[i][j]\
    \ = 0;\n            }\n        }\n    }\n    while (!q.empty()) {\n        auto\
    \ [Y, X] = q.front();\n        q.pop();\n        for (int i = 0; i < d; ++i) {\n\
    \            int y = Y + (d == 4 ? dy[i] : dy8[i]),\n                x = X + (d\
    \ == 4 ? dx[i] : dx8[i]);\n            if (y < 0 or x < 0 or H <= y or W <= x)\
    \ continue;\n            if (~min_cost[y][x]) continue;\n            if (wall.find(G[y][x])\
    \ != string::npos) continue;\n            min_cost[y][x] = min_cost[Y][X] + 1;\n\
    \            q.emplace(y, x);\n        }\n    }\n    return min_cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/grid/bfs.hpp
  requiredBy: []
  timestamp: '2026-01-15 11:05:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/grid/bfs.test.cpp
documentation_of: library/grid/bfs.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C9BFS"
---

# グリッドBFS

## できること
- グリッド上で始点を決め、各点への最短距離を求める

## 計算量
$O(HW)$

## 使い方
```cpp
string wall = "#";
vector<vector<int>> dis = bfs(G, 'S', 4ll, wall);
int ans = dis[gy][gx];
```
