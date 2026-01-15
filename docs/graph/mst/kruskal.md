---
title: Kruskal
documentation_of: //library/graph/mst/kruskal.hpp
---

# Kruskal

## できること
- 最小全域木（グラフ全頂点を満たす最小コスト木）を求める
- edgesは中でソートしてる
- 最小全域木の構造体
  - `cost`: 全域の総コスト。全域に達しない場合、INF
  - `edges`: 全域に達するための`vector<Edge>`

## 計算量
$O(ElogV)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<Edge> edges;
MinSpanTree mst = kruskal(edges, V);
mst.cost;
mst.edges;
```
