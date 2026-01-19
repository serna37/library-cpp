---
title: オイラーのφ関数
documentation_of: //library/number/euler_phi.hpp
---

# オイラーのφ関数

## できること
- 正の整数Nが与えられたとき、1~Nまでの自然数のうちNと`互いに素`な個数 $\phi (N)$ を求める
- $\phi (n) = n \displaystyle\prod_{i=1}^{k} (1 - \frac{1}{p_i})$

## 計算量
$O(\sqrt{N})$

## 使い方
```cpp
long long ans = euler_phi(N);
```

