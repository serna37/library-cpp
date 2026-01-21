---
title: 根付き木変換
documentation_of: //library/graph/tree/convert_rooted_tree.hpp
---

# 根付き木変換

## できること
- 無向グラフな木を、「親から子への方向」をもつ、有向グラフな木に変換する
- BFSを用いて、指定した頂点から遠ざかる方向にのみ辺を張り直している

## 計算量
$O(N + M)$ Nは頂点数、Mは辺の数

## 使い方
```cpp
Graph rG = convert_rooted_tree(G, 0);
```

