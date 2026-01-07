---
title: トポロジカルソート
documentation_of: //library/graph/topological_sort.hpp
---

# トポロジカルソート

## できること
- DAGをトポロジカルソートする
- 閉路がある場合は空配列を返却

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<int> sorted = topological_sort(G);
```
