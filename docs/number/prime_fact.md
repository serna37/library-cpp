---
title: 素因数分解
documentation_of: //library/number/prime_fact.hpp
---

# 素因数分解

## できること
- 整数Nの`<素因数, 個数>`のmapを作る

## 計算量
$O(\sqrt N)$

## 使い方
```cpp
map<int, int> pf = prime_fact(N);
```
