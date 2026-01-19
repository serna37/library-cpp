---
title: 第一種スターリング数
documentation_of: //library/polynomial/fps/stirling_first_number.hpp
---

# 第一種スターリング数

## できること
- 入力Nに対し、 $k (0 \le k \le N)$についての第一種スターリング数 $\lbrack {}^n_k \rbrack$ を求める
- 戻り値のFPSの各次数がkに対応する
- 組み合わせ的に、`N人`を`K個の円卓`に座らせる方法の数
- 第二種の逆で $\lbrack {}^n_k \rbrack$ は 下降階乗を $x^n$ に展開する際の係数として現れる
  - $x(x-1) \cdots (x-k+1) = \displaystyle\sum_{k=0}^{n} (-1)^{n-k} \lbrack {}^n_k \rbrack x^k $

## 計算量
$O(NlogN)$

## 使い方
```cpp
using mint = modint998244353;
cout << stirling_first_number<FPS, mint>(N);
```

