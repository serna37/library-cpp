---
title: 二分探索 配列中 以上の要素数
documentation_of: //library/search/binary_search/bi_ge_cnt.hpp
---

# 二分探索 配列中 以上の要素数

## できること
- 配列中の「x以上の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_ge_cnt(A, x);
```
