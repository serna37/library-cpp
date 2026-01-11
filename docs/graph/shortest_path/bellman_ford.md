---
title: Bellman Ford
documentation_of: //library/graph/shortest_path/bellman_ford.hpp
---

# Bellman Ford

## できること
- 最小コストを求める
- 負の重みOK
  - `s`: 始点（デフォルト0）
  - `dis`: dis[v] := 頂点vまでの最小コスト
  - `negativeCycle`: 負の閉路がある場合true
  - `route`: 経路復元用の配列

## 計算量
$O(VE)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [dis, negativeCycle, route] = bellman_ford(G, s);
```
