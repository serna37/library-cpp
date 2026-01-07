---
title: Dual Segment Tree
documentation_of: //library/segtree/dual_segment_tree.hpp
---

# Dual Segment Tree

## できること
- モノイドについて処理
- 区間[l, r)の値を更新
- 1点の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$

## 使い方
```cpp
DualSegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```
