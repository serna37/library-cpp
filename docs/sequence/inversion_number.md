---
title: 転倒数
documentation_of: //library/sequence/inversion_number.hpp
---

# 転倒数

## できること
- 右に倒れる$A_i > A_j (i < j)$の回数を求める
- 中で座標圧縮してるので配列は破壊
- Fenwick Treeで求めている

## 計算量
$O(NlogN)$

## 使い方
```cpp
long long inv = inversion_number(A);
```
