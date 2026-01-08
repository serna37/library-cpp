---
title: 二分探索 配列中 以下の要素数
documentation_of: //library/search/bi_le_cnt.hpp
---

# 二分探索 配列中 以下の要素数

## できること
- 配列中の「x以下の要素数」を返す

## 計算量
$O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int cnt = bi_le_cnt(A, x);
```
