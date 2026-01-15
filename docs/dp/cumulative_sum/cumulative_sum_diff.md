---
title: 二項差での累積和
documentation_of: //library/dp/cumulative_sum/cumulative_sum_diff.hpp
---

# 二項差での累積和

## できること
- 2項ごとでの、累積和の数列を返す。
```
A:     1   4   2   8   2   9
増分 --> 3  -->  6  -->  7  -->
S:  0  0   3   3   9   9  16
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> S = cumulative_sum_diff(A);
```
