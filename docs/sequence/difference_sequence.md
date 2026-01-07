---
title: 階差数列
documentation_of: //library/sequence/difference_sequence.hpp
---

# 階差数列

## できること
- 各項の差の数列を返す
```
A: 1   4   2   8   2   9
D:   3  -2   6  -6   7
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> diff = difference_sequence(A);
```
