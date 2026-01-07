---
title: 三角形の面積
documentation_of: //library/geometry/area_triangle.hpp
---

# 三角形の面積

## できること
- 3点の座標から、三角形の面積を求める

> doubleは桁数表現11bitを除き、52bit程度の精度  
18桁使うなら2で割らずlong longで返すこと

## 計算量
$O(1)$

## 使い方
```cpp
double S = area_triangle(x1, y1, x2, y2, x3, y3);
```
