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
// 1. 宣言と初期化
modint998244353 a = 10;
modint998244353 b = 20;

// 2. 標準入力 (operator>> が定義されているので直接読める)
// 入力が 1000000000000 のような大きな数でも、内部で自動的に mod されます
modint998244353 c;
cin >> c;

// 3. 四則演算
modint998244353 res_add = a + b;
modint998244353 res_mul = a * b;
modint998244353 res_div = a / b; // 内部で逆元(inv)を掛けています

// 4. 累乗 (pow)
modint998244353 res_pow = a.pow(100); // a の 100 乗

// 5. 標準出力 (operator<< が定義されているので直接出せる)
// 自動的に val() が呼ばれ、通常の剰余に戻して出力されます
cout << res_add << endl;
cout << res_mul << endl;
cout << res_pow << endl;
```
