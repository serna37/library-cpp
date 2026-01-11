---
title: Dijkstra
documentation_of: //library/graph/shortest_path/dijkstra.hpp
---

# Dijkstra

## できること
- 最小コストを求める
- 複数始点
  - `starts`: 始点の配列（デフォルト0）
  - `weight`: dis[v] := 頂点vまでの最小コスト
  - `route`: 経路復元用の配列

## 計算量
$O(ElogV)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [weight, route] = dijkstra(G, {r});
```
