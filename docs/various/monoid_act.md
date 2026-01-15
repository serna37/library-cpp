---
title: モノイド作用素
documentation_of: //library/various/monoid_act.hpp
---

# モノイド作用素

## できること
- 二項演算を定義してるだけ

## 計算量
$O(1)$

## 使い方
```cpp
LazySegmentTree<int, int> seg(Monoid::Min::op, Monoid::Min::e, Monoid::Add::op, Monoid::Add::e, MonoidAct::MinAdd::op N);
```
