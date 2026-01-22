---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.prime.eratosthenes.test.cpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u30C6\u30B9\
      \u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/prime/eratosthenes.hpp\"\nstruct Eratosthenes\
    \ {\n  private:\n    int N;         // \u4E0A\u9650\n    vector<int> D; // \u6700\
    \u5C0F\u7D20\u56E0\u6570 (least prime factor)\n  public:\n    Eratosthenes(int\
    \ N) : N(N) {\n        D.resize(N + 1);\n        iota(D.begin(), D.end(), 0ll);\n\
    \        vector<int> known_prime = {2ll, 3ll, 5ll};\n        for (int p : known_prime)\
    \ {\n            for (int i = p * p; i <= N; i += p) {\n                if (D[i]\
    \ == i) D[i] = p;\n            }\n        }\n        vector<int> inc = {4, 2,\
    \ 4, 2, 4, 6, 2, 6};\n        int p = 7, idx = 0;\n        int root = floor(sqrt(N)\
    \ + 0.5);\n        while (p <= root) {\n            if (D[p] == p) {\n       \
    \         for (int i = p * p; i <= N; i += p) {\n                    if (D[i]\
    \ == i) D[i] = p;\n                }\n            }\n            p += inc[idx++];\n\
    \            if (idx == 8) idx = 0;\n        }\n    }\n    bool is_prime(int x)\
    \ const {\n        assert(1 <= x and x <= N);\n        return x == 1ll ? false\
    \ : D[x] == x;\n    }\n    vector<pair<int, int>> factorize(int x) const {\n \
    \       assert(1 <= x and x <= N);\n        vector<pair<int, int>> F;\n      \
    \  while (x != 1) {\n            int p = D[x], e = 0;\n            while (x %\
    \ p == 0ll) x /= p, e++;\n            F.emplace_back(p, e);\n        }\n     \
    \   return F;\n    }\n    vector<int> calc_divisors(int x) const {\n        assert(1\
    \ <= x and x <= N);\n        int n = 1; // \u7D04\u6570\u306E\u500B\u6570\n  \
    \      vector<pair<int, int>> F;\n        while (x != 1ll) {\n            int\
    \ p = D[x], e = 0;\n            while (x % p == 0ll) x /= p, e++;\n          \
    \  F.emplace_back(p, e);\n            n *= (1 + e);\n        }\n        vector<int>\
    \ divisors(n, 1);\n        int sz = 1; // \u73FE\u5728\u306E\u7D04\u6570\u306E\
    \u500B\u6570\n        for (const auto &[p, e] : F) {\n            for (int i =\
    \ 0; i < sz * e; i++) {\n                divisors[sz + i] = divisors[i] * p;\n\
    \            }\n            sz *= (1 + e);\n        }\n        return divisors;\n\
    \    }\n    // \u6700\u5C0F\u7D20\u56E0\u6570 (least prime factor)\n    int lpf(int\
    \ x) const {\n        assert(1 <= x and x <= N);\n        return D[x];\n    }\n\
    \    int euler_phi(int x) const {\n        assert(1 <= x and x <= N);\n      \
    \  int res = x;\n        while (x != 1ll) {\n            int p = D[x];\n     \
    \       res -= res / p;\n            while (x % p == 0ll) x /= p;\n        }\n\
    \        return res;\n    }\n    // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\
    \u30C6\u30FC\u30D6\u30EB\u3092\u8A08\u7B97\u3059\u308B\n    vector<int> calc_moebius()\
    \ const {\n        vector<int> moebius(N + 1, 0);\n        moebius[1] = 1;\n \
    \       for (int x = 2; x <= N; x++) {\n            int y = x / D[x];\n      \
    \      if (D[x] != D[y]) moebius[x] = -moebius[y];\n        }\n        return\
    \ moebius;\n    }\n};\n"
  code: "#pragma once\nstruct Eratosthenes {\n  private:\n    int N;         // \u4E0A\
    \u9650\n    vector<int> D; // \u6700\u5C0F\u7D20\u56E0\u6570 (least prime factor)\n\
    \  public:\n    Eratosthenes(int N) : N(N) {\n        D.resize(N + 1);\n     \
    \   iota(D.begin(), D.end(), 0ll);\n        vector<int> known_prime = {2ll, 3ll,\
    \ 5ll};\n        for (int p : known_prime) {\n            for (int i = p * p;\
    \ i <= N; i += p) {\n                if (D[i] == i) D[i] = p;\n            }\n\
    \        }\n        vector<int> inc = {4, 2, 4, 2, 4, 6, 2, 6};\n        int p\
    \ = 7, idx = 0;\n        int root = floor(sqrt(N) + 0.5);\n        while (p <=\
    \ root) {\n            if (D[p] == p) {\n                for (int i = p * p; i\
    \ <= N; i += p) {\n                    if (D[i] == i) D[i] = p;\n            \
    \    }\n            }\n            p += inc[idx++];\n            if (idx == 8)\
    \ idx = 0;\n        }\n    }\n    bool is_prime(int x) const {\n        assert(1\
    \ <= x and x <= N);\n        return x == 1ll ? false : D[x] == x;\n    }\n   \
    \ vector<pair<int, int>> factorize(int x) const {\n        assert(1 <= x and x\
    \ <= N);\n        vector<pair<int, int>> F;\n        while (x != 1) {\n      \
    \      int p = D[x], e = 0;\n            while (x % p == 0ll) x /= p, e++;\n \
    \           F.emplace_back(p, e);\n        }\n        return F;\n    }\n    vector<int>\
    \ calc_divisors(int x) const {\n        assert(1 <= x and x <= N);\n        int\
    \ n = 1; // \u7D04\u6570\u306E\u500B\u6570\n        vector<pair<int, int>> F;\n\
    \        while (x != 1ll) {\n            int p = D[x], e = 0;\n            while\
    \ (x % p == 0ll) x /= p, e++;\n            F.emplace_back(p, e);\n           \
    \ n *= (1 + e);\n        }\n        vector<int> divisors(n, 1);\n        int sz\
    \ = 1; // \u73FE\u5728\u306E\u7D04\u6570\u306E\u500B\u6570\n        for (const\
    \ auto &[p, e] : F) {\n            for (int i = 0; i < sz * e; i++) {\n      \
    \          divisors[sz + i] = divisors[i] * p;\n            }\n            sz\
    \ *= (1 + e);\n        }\n        return divisors;\n    }\n    // \u6700\u5C0F\
    \u7D20\u56E0\u6570 (least prime factor)\n    int lpf(int x) const {\n        assert(1\
    \ <= x and x <= N);\n        return D[x];\n    }\n    int euler_phi(int x) const\
    \ {\n        assert(1 <= x and x <= N);\n        int res = x;\n        while (x\
    \ != 1ll) {\n            int p = D[x];\n            res -= res / p;\n        \
    \    while (x % p == 0ll) x /= p;\n        }\n        return res;\n    }\n   \
    \ // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u30C6\u30FC\u30D6\u30EB\u3092\u8A08\
    \u7B97\u3059\u308B\n    vector<int> calc_moebius() const {\n        vector<int>\
    \ moebius(N + 1, 0);\n        moebius[1] = 1;\n        for (int x = 2; x <= N;\
    \ x++) {\n            int y = x / D[x];\n            if (D[x] != D[y]) moebius[x]\
    \ = -moebius[y];\n        }\n        return moebius;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/prime/eratosthenes.hpp
  requiredBy: []
  timestamp: '2026-01-22 14:26:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.prime.eratosthenes.test.cpp
documentation_of: library/number/prime/eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
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
