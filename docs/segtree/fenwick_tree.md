---
title: Fenwick Tree
documentation_of: //library/segtree/fenwick_tree.hpp
---

# Fenwick Tree

## できること
- 1点に加算する
- 区間[0, i]の和を取得

## 計算量
- 構築: $O(N)$
- 1点更新`add`: $O(logN)$
- 区間取得`sum`: $O(logN)$

## 使い方
```cpp
FenwickTree fwk(N);
```
