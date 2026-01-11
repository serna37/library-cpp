---
title: BFS
documentation_of: //library/graph/shortest_path/bfs.hpp
---

# BFS

## できること
- 最短経路を求める(幅優先探索)
- 複数始点
  - `starts`: 始点の配列（デフォルト0）
  - `dis`: dis[v] := 頂点vまでの最短距離
  - `route`: 経路復元用の配列

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [dis, route] = bfs(G, {0});
```
