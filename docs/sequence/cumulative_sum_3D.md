---
title: 3次元累積和
documentation_of: //library/sequence/cumulative_sum_3D.hpp
---

# 3次元累積和

## できること
- 3次元での累積和を返す

## 計算量
$O(N^3)$

## 使い方
```cpp
vector<vector<vector<long long>>> S = cumulative_sum_3D(A);
```

包除として
```cpp
// Lx Ly Lzは0-indexed Rx Ry Rzは1-indexed
// S[Rxyz] - S[Lxyz]
long long ans = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] - S[Rx][Ly][Rz] -
        S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz] +
        S[Rx][Ly][Lz] - S[Lx][Ly][Lz];
```
