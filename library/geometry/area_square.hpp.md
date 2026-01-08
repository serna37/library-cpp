---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/area_square.hpp\"\ntemplate <typename T>\n\
    double area_square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {\n    return\
    \ hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;\n}\n"
  code: "#pragma once\ntemplate <typename T>\ndouble area_square(T x1, T y1, T x2,\
    \ T y2, T x3, T y3, T x4, T y4) {\n    return hypot(x1 - x3, y1 - y3) * hypot(x2\
    \ - x4, y2 - y4) / 2.0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/area_square.hpp
  requiredBy: []
  timestamp: '2026-01-08 23:00:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/area_square.hpp
layout: document
title: "\u56DB\u89D2\u5F62\u306E\u9762\u7A4D"
---

# 四角形の面積

## できること
- 4点の座標から、四角形の面積を求める

> doubleは桁数表現11bitを除き、52bit程度の精度  
18桁使うなら2で割らずlong longで返すこと

## 計算量
$O(1)$

## 使い方
```cpp
double S = area_square(x1, y1, x2, y2, x3, y3, x4, y4);
```
