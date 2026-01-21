---
title: Lazy Segment Tree
documentation_of: //library/segtree/lazy_segment_tree.hpp
---

# Lazy Segment Tree

## できること
- モノイドについて処理
- 区間[l, r)の値を更新
- 区間[l, r)の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 全要素の取得`getall`: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`prod`: $O(logN)$
- 全区間取得`top`: $O(1)$
- 木上の二分探索`max_right`: $O(logN)$
- 木上の二分探索`min_left`: $O(logN)$

## 使い方
```cpp
// 演算op e 更新op e 作用op
LazySegmentTree<int, int> seg(Monoid::Min::op, Monoid::Min::e, Monoid::Add::op, Monoid::Add::e, MonoidAct::MinAdd::op, N);

// 独自定義の例
vector<Node> A(N); // 初期配列
auto prod_op = [](const Node &x, const Node &y) -> Node { return x + y; };
auto prod_e = Node();
auto apply_op = [](int f, int g) { return g; };
auto apply_e = INF;
auto act_op = [](const Node &x, int a, int sz) -> Node {
    (void)sz;
    return {a, x.length};
};
LazySegmentTree<Node, int> seg(prod_op, prod_e, apply_op, apply_e, act_op,
                                A);
```
