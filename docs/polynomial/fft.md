---
title: 高速フーリエ変換
documentation_of: //library/polynomial/fft.hpp
---

# 高速フーリエ変換

## できること
$F(k) = \sum_{n=0}^{N-1} f(n) \exp(\frac{-2 \pi i}{N} n k)$
- 離散フーリエ変換をバタフライ演算とかで高速に行う
- 多項式の乗算を高速に行うことができる

<details markdown="1"><summary>詳しい説明</summary>

<iframe src="https://www.slideshare.net/slideshow/embed_code/key/fc5RcW8Wkqciu" width="510" height="420"frameborder="0" marginwidth="0" marginheight="0" scrolling="no"style="border: var(--border-1) solid #CCC; border-width:1px; margin-bottom:5px; max-width:100%;"allowfullscreen></iframe><div style="margin-bottom:5px"><strong><a href="https://www.slideshare.net/slideshow/fft-49066791/49066791" title="fft-49066791" target="_blank">fft-49066791</a></strong>from <strong><a href="https://www.slideshare.net/chokudai" target="_blank">AtCoder Inc.</a></strong></div>

</details>

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

