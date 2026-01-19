---
title: 累積和 反転
documentation_of: //library/dp/cumulative_sum/cumulative_sum_rev.hpp
---

# 累積和 反転

## できること
- 逆向きの累積和の数列を返す。$R_i =$「$A_i$から右全部の和」
```
A:  1   4   2   8   2   9
R: 26  25  21  19  11   9  0
```

累積和 $S$ と合わせて、全区間の和は次のように求められる。

$\displaystyle\sum_{j=0}^{i-1} + \displaystyle\sum_{j=i}^{last} = S_i + R_i$

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> R = cumulative_sum_rev(A);
```
