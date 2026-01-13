---
title: グリッドBFS
documentation_of: //library/grid/bfs.hpp
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
