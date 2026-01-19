---
title: モジュロ演算
documentation_of: //library/number/mod/montgomery_mod_int.hpp
---

# モジュロ演算

## できること
- モンゴメリ乗算を用いた高速なモジュロ演算をおこなう


## 計算量
$O(1)$

## 使い方
```cpp
// 1. 宣言と初期化 任意のMODを指定する。2つはよく使うのであらかじめ定義済み
modint998244353 a = 10;
modint1000000007 b = 20;
using mint = modint<MOD>;
using mint = modint<3456>;

// 2. 標準入出力に対応。自動的に mod されるし、自動的にval()が呼ばれる
modint998244353 c;
cin >> c;
cout << c << endl;

// 3. 四則演算
modint998244353 res_add = a + b;
modint998244353 res_mul = a * b;
modint998244353 res_div = a / b; // 内部で逆元(inv)を掛けています

// 4. 累乗 (pow) は内部で、二分累乗を行う
modint998244353 res_pow = a.pow(100); // a の 100 乗
```
