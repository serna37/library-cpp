---
title: 形式的冪級数
documentation_of: //library/polynomial/fps/formal_power_series.hpp
---

# 形式的冪級数

## できること
- 無限項の項式を、配列として扱う
- 多項式同士の計算を行う
  - 算術演算 `+` `-` `*` `/` `%`
    - `*` 任意MOD畳み込み(FFTを利用)
  - 微分 `diff` $(a_{n}x^{n})^{\prime} = n \cdot a_{n}x^{n-1}$
  - 積分 `integral` $\int a_{n}x^{n}dx = \frac{a_{n}}{n+1}x^{n+1}$
  - 逆元 `inv` $1/A(x)$ : ニュートン法を利用
  - 対数 `log` $\ln(A(x))$ : $\int \frac{A^{\prime}(x)}{A(x)}dx$ として計算
  - 指数 `exp` $e^{A(x)}$ : ニュートン法を利用
  - 累乗 `pow` $(A(x))^k$ : $exp(k \ln A(x))$ として計算
  - 平方根 `sqrt` $\sqrt{A(x)} $
  - テイラーシフト `taylor_shift(c)` : 畳み込みを利用
    - $f(x) = \sum_{i=0}^{\infin}a_{i}x^{i}$ に対し
    - $f(x+c) = \sum_{n=0}^{\infin}\frac{f^{(n)}(c)}{n!}x^n$
  - 多項式 $g$ を法とした二分累乗 $x^k$ `mod_pow(k, g)`
  - 多項式に値 $x$ を代入 `operator()(T x)`

## 計算量
- 加減算: $O(N)$
- 除算・剰余, 乗算: $O(NlogN)$
- 微積分: $O(N)$
- 逆元: $O(NlogN)$
- 対数: $O(NlogN)$
- 指数: $O(NlogN)$
- 累乗: $O(NlogN)$
- 平方根: $O(NlogN)$
- テイラーシフト: $O(NlogN)$
- 多項式を法とした二分累乗: $O(M \log M \cdot \log k)$
  - $M$ は法となる多項式 $g$ の次数、 $k$ は指数

## 使い方
```cpp
using mint = modint1000000007; // 10^9+7 を使用
using P = FPS<mint>;

// 1. 多項式の定義: A(x) = 1 + 2x + 3x^2
P a = {1, 2, 3};
// B(x) = 4 + 5x
P b = {4, 5};

// 2. 乗算: C(x) = A(x) * B(x)
P c = a * b; // {4, 13, 22, 15} -> 4 + 13x + 22x^2 + 15x^3

cout << "A * B = ";
for(auto v : c) cout << v << " ";
cout << endl;

// 3. 逆元の計算: D(x) = 1 / (1 - x) mod x^5
// 1 / (1 - x) = 1 + x + x^2 + x^3 + x^4 + ...
P d_base = {1, -1};
P d_inv = d_base.inv(5); 

cout << "1 / (1-x) mod x^5 = ";
for(auto v : d_inv) cout << v << " ";
cout << endl;

// 4. 累乗: (1 + x)^10 mod x^4
P e = {1, 1};
P e_pow = e.pow(10, 4); // 二項定理より 1 + 10x + 45x^2 + 120x^3

cout << "(1+x)^10 mod x^4 = ";
for(auto v : e_pow) cout << v << " ";
cout << endl;
```

