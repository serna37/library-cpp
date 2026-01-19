---
title: 畳み込み FFT
documentation_of: //library/polynomial/fft/convolution_fft.hpp
---

# 畳み込み FFT

## できること
- 畳み込みは、  $(1 + 2x + 3x^2) \times (4 + 5x + 6x^2)$の係数を求める
- 畳み込みをFFTで高速に行う
- 演算結果はllroundで四捨五入している
- 誤差なしのためには数論変換NTTが必要

## 計算量
$O(NlogN)$

## 使い方
```cpp
vector<long long> res = convolution_fft(a, b);
```
