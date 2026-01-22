---
title: エラトステネスの篩
documentation_of: //library/number/prime/eratosthenes.hpp
---

# エラトステネスの篩

## できること
- 前計算で最小素因数(Least Prime Factor)を求める
- 素数判定
- 素因数分解
- 約数列挙
- LPF取得
- オイラーのφ関数（互いに素な個数）
- メビウス関数テーブル

なお、それぞれ単品のライブラリもあるため、複数回の計算かどうかや  
前計算の計算量を加味して使い分ける

## 計算量
- 構築 `Eratosthenes(N)` : $O(N \log \log N)$
- 素数判定 `is_prime(x)` : $O(1)$
- 素因数分解 `factorize(x)` : $O(\log x)$
- 約数列挙 `calc_divisors(x)` : $O(d(x))$
- LPF取得 `lpf(x)` : $O(1)$
- オイラーのφ関数 `euler_phi(x)` : $O(\log x)$
- メビウス関数テーブル `calc_moebius` : $O(N)$

## 使い方
```cpp
// 構築
int limit = 1000000;
Eratosthenes er(limit);

int x = 999983;

// 素数判定
bool is_p = er.is_prime(x);

// 素因数分解 <素因数: 個数>
vector<pair<int, int>> factors = er.factorize(x);

// 約数列挙 (ソートされてないよ)
vector<int> divs = er.calc_divisors(x);

// 最小素因数
int lpf = er.lpf(x);

// φ(x)
int phi = er.euler_phi(x);

// メビウス
vector<int> moebius = er.calc_moebius();
```
