---
title: 最小全域木
documentation_of: //library/graph/base/min_span_tree.hpp
---

# 最小全域木

## できること
- 最小全域木の構造体
  - `cost`: 全域の総コスト。全域に達しない場合、INF
  - `edges`: 全域に達するための`vector<Edge>`

## 計算量
なし

## 使い方
```cpp
vector<Edge> edges;
MinSpanTree mst = kruskal(edges, V);
mst.cost;
mst.edges;
```
