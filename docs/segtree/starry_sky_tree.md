---
title: Starry Sky Tree
documentation_of: //library/segtree/starry_sky_tree.hpp
---

# Starry Sky Tree

## できること
- 累積和の要領で実現してる
  - 参考: https://rsk0315.hatenablog.com/entry/2019/06/21/174953
- 区間[l, r)の値を加算
- 区間[l, r)のmax/minを取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`prod`: $O(logN)$

## 使い方
```cpp
StarrySkyTree sst(N); // 区間min
StarrySkyTree<false> sst(N); // 区間max
```
