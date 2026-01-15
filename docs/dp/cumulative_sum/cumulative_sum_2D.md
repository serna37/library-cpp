---
title: 2次元累積和
documentation_of: //library/dp/cumulative_sum/cumulative_sum_2D.hpp
---

# 2次元累積和

## できること
- 2次元平面での累積和を返す

## 計算量
$O(HW)$

## 使い方
```cpp
vector<vector<long long>> S = cumulative_sum_2D(G);
```
$\sum$ (s,t)~(x,y) は以下の包除で求める
```cpp
long long ans = S[y][x] - S[y][s] - S[t][x] + S[t][s];
```
