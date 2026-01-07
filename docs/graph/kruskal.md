---
title: Kruskal
documentation_of: //library/graph/kruskal.hpp
---

# Kruskal

## できること
- 最小全域木を求める
- edgesは中でソートしてる

## 計算量
$O(ElogV)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<Edge> edges;
MinSpanTree mst = kruskal(edges, V);
```
