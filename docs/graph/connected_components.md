---
title: 連結成分分解
documentation_of: //library/graph/connected_components.hpp
---

# 連結成分分解

## できること
- 連結な頂点群に分解する
  - `groups`: 連結な頂点群の集合
  - `ids` : ids[v] := 頂点vが属するgroupsのインデックス

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [groups, ids] = connected_components(G);
```
