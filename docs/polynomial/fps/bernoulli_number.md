---
title: ベルヌーイ数
documentation_of: //library/polynomial/fps/bernoulli_number.hpp
---

# ベルヌーイ数

## できること
- ベルヌーイ数を求める
- 指数型母関数: $\frac{x}{e^x - 1} = \displaystyle\sum_{n=0}^{\infty} B_n \frac{x^n}{n!}$
- 等差数列の累乗和（ファウルハーバーの公式）などに現れる数

## 計算量
$O(NlogN)$

## 使い方
```cpp
using mint = modint998244353;
cout << bernoulli_number<FPS, mint>(N);
```

