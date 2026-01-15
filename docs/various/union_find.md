---
title: UnionFind 素集合データ構造
documentation_of: //library/various/union_find.hpp
---

# UnionFind 素集合データ構造

## できること
- 集合をつなげたり。切れはしない

## 計算量
- 構築: $O(N)$
- 自分のグループサイズ`uf[p]`: $O(α(N))$
- 自分の親を見つける`find`: $O(α(N))$
- 同じグループにする`unite`: $O(α(N))$

## 使い方
```cpp
UnionFind uf(N);
int sz = uf[p];
if (uf.unite(a, b)) {
    // つなげた場合
}
if (uf.find(a) == uf.find(b)) {
    // 同じグループである
}
```
