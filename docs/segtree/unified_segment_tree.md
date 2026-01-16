---
title: 統合セグ木
documentation_of: //library/segtree/unified_segment_tree.hpp
---

# 統合セグ木

## できること
- 更新モノイド、演算モノイド、作用素モノイド、更新区間、演算区間を指定することで適切な木の構造体を構築
  - 星空木、Fenwick木、セグ木、双対セグ木、遅延セグ木を自動選択
  - 1点でも区間でも、更新は`update`
  - 1点でも区間でも、取得は`query`

## 計算量
- 構築: $O(N)$
- 更新`update`: $O(logN)$
- 取得`query`: $O(logN)$

## 使い方
```cpp
// 更新:Add, 演算:Min, 範囲-範囲
UnifiedSegmentTree<Monoid::Min, Monoid::Add> seg(N, RangeType::Range, RangeType::Range);
seg.update(l, r, v);
int res = seg.query(l, r);

// 更新:Add, 演算:Add, 一点-範囲
UnifiedSegmentTree<Monoid::Add, Monoid::Add> seg(N, RangeType::Single, RangeType::Range);
seg.update(i, i+1, v);
int res = seg.query(l, r);

// 第3引数に作用素 Act を指定
UnifiedSegmentTree<Monoid::Add, Monoid::Set, MonoidAct::AddSet> seg(N, RangeType::Range, RangeType::Range);
seg.update(l, r, v);
int res = seg.query(l, r);

// 配列でも初期化できる
vector<int> A = {1, 2, 3, 4, 5};

// 例：一点更新・範囲最小値（SegmentTreeが自動選択される）
UnifiedSegmentTree<Monoid::Min> seg(A, RangeType::Single, RangeType::Range);

// 例：範囲加算・範囲最大値（StarrySkyTreeが自動選択される）
UnifiedSegmentTree<Monoid::Max, Monoid::Add> sst(A, RangeType::Range, RangeType::Range);
```
