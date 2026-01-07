---
title: 経路復元
documentation_of: //library/graph/route_restore.hpp
---

# 経路復元

## できること
- 経路を復元する

## 計算量
$O(L)$
- L: パスの長さ

## 使い方
```cpp
auto [dis, route] = dijkstra(G, {s});
vector<int> pth = route_restore(route, goal);
```
