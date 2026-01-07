---
title: 累積和
documentation_of: //library/sequence/cumulative_sum.hpp
---

# 累積和

## できること
- 累積和の数列を返す。 $S_i = \sum A[0, i)$
```
A:    1   4   2   8   2   9
S: 0  1   5   7  15  17  26
```

半開区間 $[l, r)$ の和は、次のように求められる。

$\sum_{j=l}^{r-1} A_j = S_r - S_l$

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> S = cumulative_sum(A);
```
