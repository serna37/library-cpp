---
title: Bitwise畳み込みAND
documentation_of: //library/polynomial/fft/convolution_bitwise_and.hpp
---

# Bitwise畳み込みAND

## できること
$h_k = \sum_{i AND j=k}　f_i \cdot g_j$
- Bitwise畳み込み AND を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_and(a, b);
```

