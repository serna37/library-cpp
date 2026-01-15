---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/geometry/area_triangle.test.cpp
    title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/area_triangle.hpp\"\ntemplate <typename\
    \ T> double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {\n    return abs((x2\
    \ - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;\n}\n"
  code: "#pragma once\ntemplate <typename T> double area_triangle(T x1, T y1, T x2,\
    \ T y2, T x3, T y3) {\n    return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2\
    \ - y1)) / 2.0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/area_triangle.hpp
  requiredBy: []
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/geometry/area_triangle.test.cpp
documentation_of: library/geometry/area_triangle.hpp
layout: document
title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D"
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
