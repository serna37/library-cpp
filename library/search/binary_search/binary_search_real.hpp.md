---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search.binary_search.binary_search_real.test.cpp
    title: "\u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/binary_search/binary_search_real.hpp\"\n\
    #include <functional>\nconst long double EPS = 1e-14;\npair<double, double> binary_search_real(function<bool(double)>\
    \ f) {\n    double L = 0, R = 1, MID = 0;\n    while (!f(R)) R *= 2;\n    auto\
    \ ABS = [&]() { return abs(R - L) > EPS; };\n    auto REL = [&]() { return abs(R\
    \ - L) / max(R, L) > EPS; };\n    while (ABS() and REL()) {\n        MID = L +\
    \ (R - L) / 2;\n        (f(MID) ? R : L) = MID;\n    }\n    return {L, R};\n}\n"
  code: "#pragma once\n#include <functional>\nconst long double EPS = 1e-14;\npair<double,\
    \ double> binary_search_real(function<bool(double)> f) {\n    double L = 0, R\
    \ = 1, MID = 0;\n    while (!f(R)) R *= 2;\n    auto ABS = [&]() { return abs(R\
    \ - L) > EPS; };\n    auto REL = [&]() { return abs(R - L) / max(R, L) > EPS;\
    \ };\n    while (ABS() and REL()) {\n        MID = L + (R - L) / 2;\n        (f(MID)\
    \ ? R : L) = MID;\n    }\n    return {L, R};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/binary_search/binary_search_real.hpp
  requiredBy: []
  timestamp: '2026-01-15 10:11:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/search.binary_search.binary_search_real.test.cpp
documentation_of: library/search/binary_search/binary_search_real.hpp
layout: document
title: "\u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22"
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
