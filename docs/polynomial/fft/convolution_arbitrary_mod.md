---
title: 畳み込み 任意MOD
documentation_of: //library/polynomial/fft/convolution_arbitrary_mod.hpp
---

# 畳み込み 任意MOD

## できること
- 任意の法において、2つの多項式の積を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
// 法を設定: ライブラリ「montgomery_mod_int.hpp」を使用している
using mint = modint<MOD>;
//using mint = modint998244353; // 用意済みのものでもOK

// 1. 多項式の係数を用意
ConvolutionArbitraryMod<mint> fft;
vector<mint> a = {1, 2, 3}; // 1 + 2x + 3x^2
vector<mint> b = {4, 5};    // 4 + 5x

// 2. 畳み込み実行
// (1+2x+3x^2)(4+5x) = 4 + 13x + 22x^2 + 15x^3
vector<mint> result = fft.multiply(a, b);
// 結果: 4 13 22 15
```

