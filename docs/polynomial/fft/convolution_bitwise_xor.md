---
title: Bitwise畳み込みXOR
documentation_of: //library/polynomial/fft/convolution_bitwise_xor.hpp
---

# Bitwise畳み込みXOR
[詳しい説明](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)

## できること
$h_k = \sum_{i \oplus j=k}　f_i \cdot g_j$
- Bitwise畳み込み XOR を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_xor(a, b);
```

