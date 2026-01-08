---
title: 二分探索 配列中 未満の要素数
documentation_of: //library/search/bi_lt_cnt.hpp
---

# 二分探索 配列中 未満の要素数

## できること
- 配列中の「x未満の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_lt_cnt(A, x);
```
