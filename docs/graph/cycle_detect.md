---
title: 閉路検出
documentation_of: //library/graph/cycle_detect.hpp
---

# 閉路検出

## できること
- 閉路を見つける
- サイクルな辺の集合を返却
  - `directed`: 有向なら `true`（デフォルト `true`）

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<Edge> cyc = cycle_detect(G, true);
```
