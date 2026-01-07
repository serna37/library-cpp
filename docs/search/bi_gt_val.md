---
title: 二分探索 配列中 より上の最小値
documentation_of: //library/search/bi_gt_val.hpp
---

# 二分探索 配列中 より上の最小値

## できること
- 配列中の「xより上の最小値」を返す
- 中でソートする

## 計算量
- $O(NlogN)$
- setの場合は二分探索のみなので $O(logN)$

## 使い方
```cpp
int v = bi_gt_val(A, x);
int v = bi_gt_val(st, x);
if (v == INF) {
    // 値が存在しなかった
}
```
