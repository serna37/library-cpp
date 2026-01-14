---
title: LCA
documentation_of: //library/graph/tree/lca.hpp
---

# LCA

## できること
- LCA(木の最小共通祖先)を求める
- 木上の2頂点間の距離を求める
- BFSで1つ親を走査後、ダブリングテーブルを構築している

## 計算量
- 構築: $O(NlogN)$
- `get_lca`: $O(logN)$
- `get_dist`: $O(logN)$

## 使い方
```cpp
int N = 5;
Graph G(N);
// 0-1(10), 1-2(20), 1-3(30), 3-4(40)
G.add_both(0, 1, 10);
G.add_both(1, 2, 20);
G.add_both(1, 3, 30);
G.add_both(3, 4, 40);

LCA tree(G, 0); // 根が0

// 頂点2と頂点4の距離
// パス: 2 - (20) - 1 - (30) - 3 - (40) - 4  => 合計 90
long long dis = tree.get_dist(2, 4);
// LCAは1
int lca = tree.get_lca(2, 4);
```
