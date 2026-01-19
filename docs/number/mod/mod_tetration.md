---
title: テトレーション
documentation_of: //library/number/mod/mod_tetration.hpp
---

# テトレーション

## できること
- ${a \uparrow \uparrow b} \bmod m$ を求める
  - $\uparrow \uparrow$ はテトレーション演算で、 $a^{a^{a^{a^{\ldots}}}}$ ( $a$ が $b$ 個続く) を指す

## 計算量
$O(\sqrt{m})$

## 使い方
```cpp
long long ans = mod_tetration(a, b, MOD);
```
