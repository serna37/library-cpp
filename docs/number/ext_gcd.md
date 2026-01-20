---
title: 拡張Euclidの互除法
documentation_of: //library/number/ext_gcd.hpp
---

# 拡張Euclidの互除法

## できること
- 最大公約数 $d = gcd(a, b)$ を求める
- 通常のユークリッドの互除法の過程で、$ (ax+by=d) $ を満たす整数 $(x, y)$ （ベズーの等式）を同時に求める
- 整数解は複数考えられるが、 $\vert x \vert + \vert y \vert$ が最小のものが格納される
- $1 \le a, b$ であること

## 計算量
$O(\log \min(a, b))$

## 使い方
```cpp
int a, b, x, y;
cin >> a >> b;
ext_gcd(a, b, x, y);
```

