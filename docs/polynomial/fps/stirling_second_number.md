---
title: 第二種スターリング数
documentation_of: //library/polunomial/fps/stirling_second_number.hpp
---

# 第二種スターリング数

## できること
- 入力Nに対し、 $k (0 \le k \le N)$についての第二種スターリング数 $\lbrace {}^n_k \rbrace$ を求める
- 戻り値のFPSの各次数がkに対応する
- 組み合わせ的に、`区別できるN個のボール`を`区別できないK個の箱`に、空箱が無いように分ける方法の数
  - ${}_n C_k$ ではないことに注意
- $\lbrace {}^n_k \rbrace$ は $x^n$ を下降階乗になおす際の係数として現れる
  - $x^n = \displaystyle\sum_{k=0}^{n} \lbrace {}^n_k \rbrace x(x-1) \cdots (x-k+1)$
- よって、ファウルハーバーの公式の別バージョンとしてベルヌーイ数でなく、第二種スターリング数を用いたべき乗和の公式が存在する

## 計算量
$O(NlogN)$

## 使い方
```cpp
using mint = modint998244353;
cout << stirling_second_number<FPS, mint>(N);
```

