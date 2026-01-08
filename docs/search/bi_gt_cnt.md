---
title: 二分探索 配列中 より上の要素数
documentation_of: //library/search/bi_gt_cnt.hpp
---

# 二分探索 配列中 より上の要素数

## できること
- 配列中の「xより上の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_gt_cnt(A, x);
```
