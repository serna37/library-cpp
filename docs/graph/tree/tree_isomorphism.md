---
title: 木の同型性判定
documentation_of: //library/graph/tree/tree_isomorphism.hpp
---

# 木の同型性判定

## できること
- 見た目の描き方は違っても、グラフとしての構造（つながり方）が本質的に同じかどうかを判定
- 定義: 2つの木 $T_1$ と $T_2$ の頂点の番号をうまく付け替えることで $T_1$ と $T_2$ を全く同じ形にできるとき、同型である
- 部分木の検索や木の圧縮、重複排除などに活用できる

## 計算量
$O(N \log N)$

## 使い方
```cpp
bool is_same = tree_isomorphism(t, g);
```

