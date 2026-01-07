---
title: 実数上の二分探索
documentation_of: //library/search/binary_search_real.hpp
---

# 実数上の二分探索

## できること
- 実数全体で二分探索し、L Rを返す
- 上界を指数探索で求めてる
- `3.5<=x`なら`L=3.5`, `R=3.5`(LRの誤差がEPS内)
```
     L R
 x x x o o o o
       ↑ここを求める
```

## 計算量
$O(logN)$

## 使い方
```cpp
auto [L, R] = binary_search_real([&](double x){
    return 3.5 <= x;
});
```
