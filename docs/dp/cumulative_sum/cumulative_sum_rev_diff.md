---
title: 二項差での累積和 反転
documentation_of: //library/dp/cumulative_sum/cumulative_sum_rev_diff.hpp
---

# 二項差での累積和 反転

## できること
- 2項ごとでの、逆向きの累積和の数列を返す。
```
A:    1   4   2   8   2   9
増分　 <--  2  <--  6  <--  9  <--
R:   17  17  15  15   9   9  0
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> R = cumulative_sum_rev_diff(A);
```
