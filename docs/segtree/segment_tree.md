---
title: Segment Tree
documentation_of: //library/segtree/segment_tree.hpp
---

# Segment Tree
[詳しい説明](https://note.alhinc.jp/n/n20b6c51a4760)

## できること
- モノイドについて処理
- 1点の値を更新
- 区間[l, r)の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間取得`prod`: $O(logN)$

## 使い方
```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```
