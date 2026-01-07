---
title: Starry Sky Tree
documentation_of: //library/segtree/starry_sky_tree.hpp
---

# Starry Sky Tree

## できること
- 累積和の要領で実現してる
  - 参考: https://rsk0315.hatenablog.com/entry/2019/06/21/174953
- 区間[l, r)にの値を加算
- 区間[l, r)のmaxを取得

## 計算量
- 構築: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`get`: $O(logN)$

## 使い方
```cpp
StarrySkyTree sst(N);
```
