---
title: 二分探索 配列中 未満の最大値
documentation_of: //library/search/bi_lt_val.hpp
---

# 二分探索 配列中 未満の最大値

## できること
- 配列中の「x未満の最大値」を返す

## 計算量
- $O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int v = bi_lt_val(A, x);
int v = bi_lt_val(st, x);
if (v == -INF) {
    // 値が存在しなかった
}
```
