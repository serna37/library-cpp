---
title: 整数上の二分探索
documentation_of: //library/search/binary_search.hpp
---

# 整数上の二分探索

## できること
- 整数全体で二分探索し、L Rを返す
- 上界を指数探索で求めてる
- `5<=x`なら`L=4`, `R=5`(LRの誤差がEPS内)
```
     L R
 x x x o o o o
       ↑ここを求める
```

## 計算量
$O(logN)$

## 使い方
```cpp
auto [L, R] = binary_search([&](long long x){
    return 5 <= x;
});
```
