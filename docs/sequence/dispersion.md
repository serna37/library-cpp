---
title: 数直線上での個数分布
documentation_of: //library/sequence/dispersion.hpp
---

# 数直線上での個数分布

## できること
- 配列要素が数直線上の各点に何個ずつあるか、を返す
```
A: 1 2 3 3 5 9
```
を変換すると
```
arr:   1 1 2   1       1          ...
idx: 0 1 2 3 4 5 6 7 8 9 10 11 12 ...
```
を得る

## 計算量
$O(N)$

## 使い方
```cpp
vector<int> disp = dispersion(A);
```
