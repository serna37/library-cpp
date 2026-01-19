---
title: Bitwise畳み込みOR
documentation_of: //library/polynomial/fft/convolution_bitwise_or.hpp
---

# Bitwise畳み込みOR

## できること
$h_k = \sum_{i OR j=k}　f_i \cdot g_j$
- Bitwise畳み込み OR を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_or(a, b);
```

