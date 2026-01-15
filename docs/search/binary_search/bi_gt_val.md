---
title: 二分探索 配列中 より上の最小値
documentation_of: //library/search/binary_search/bi_gt_val.hpp
---

# 二分探索 配列中 より上の最小値

## できること
- 配列中の「xより上の最小値」を返す

## 計算量
- $O(logN)$

## 使い方
```cpp
sort(A.begin(), A.end());
int v = bi_gt_val(A, x);
int v = bi_gt_val(st, x);
if (v == INF) {
    // 値が存在しなかった
}
```
