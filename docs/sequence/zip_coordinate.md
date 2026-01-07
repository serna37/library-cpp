---
title: 座標圧縮
documentation_of: //library/sequence/zip_coordinate.hpp
---

# 座標圧縮

## できること
- 大きさの序列のみを保持した配列に圧縮する
- 圧縮後の種類数を返却
- 中でdistinctする
```
1 4 9 9 15 42
```
を座標圧縮すると
```
0 1 2 2 3 4
```
を得る。この時の種類数は5個。要素数ではない。

## 計算量
$O(NlogN)$

## 使い方
```cpp
int sz = zip_coordinate(A);
```
