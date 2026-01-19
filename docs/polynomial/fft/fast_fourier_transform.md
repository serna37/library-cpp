---
title: 高速フーリエ変換
documentation_of: //library/polynomial/fft/fast_fourier_transform.hpp
---

# 高速フーリエ変換
[詳しい説明](https://www.slideshare.net/slideshow/fft-49066791/49066791)

## できること
$F(k) = \sum_{n=0}^{N-1} f(n) \exp(\frac{-2 \pi i}{N} n k)$
- 離散フーリエ変換をバタフライ演算とかで高速に行う
- 多項式の乗算を高速に行うことができる

## 計算量
$O(NlogN)$

## 使い方
```cpp
int nbase = 1;
FFT::ensure_base(nbase);
int sz = 1 << nbase;
vector<C> fa(sz);
FFT::fft(fa, sz);
```

