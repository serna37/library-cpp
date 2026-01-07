---
title: モノイド
documentation_of: //library/struct/monoid.hpp
---

# モノイド

## できること
- 二項演算を定義してるだけ

## 計算量
$O(1)$

## 使い方
```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```
