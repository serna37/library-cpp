---
title: マージテク
documentation_of: //library/sequence/merge.hpp
---

# マージテク

## できること
- AをBにマージする
- Aは空にする

## 計算量
- vector: $O(NlogN)$
- set: $O(Nlog^2N)$

## 使い方
```cpp
merge(A, B);
merge(stA, stB);
merge(mpA, mpB, [&](map<int, int> &B, pair<int, int> a){
    auto [k, v] = a;
    B[k] += v;
});
```
