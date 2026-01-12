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
  bundledCode: "#line 2 \"library/search/binary_search.hpp\"\npair<long long, long\
    \ long> binary_search(function<bool(long long)> f) {\n    long long L = 0, R =\
    \ 1, MID = 0;\n    while (!f(R)) R <<= 1;\n    while (abs(R - L) > 1) {\n    \
    \    MID = L + (R - L) / 2;\n        (f(MID) ? R : L) = MID;\n    }\n    return\
    \ {L, R};\n}\n"
  code: "#pragma once\npair<long long, long long> binary_search(function<bool(long\
    \ long)> f) {\n    long long L = 0, R = 1, MID = 0;\n    while (!f(R)) R <<= 1;\n\
    \    while (abs(R - L) > 1) {\n        MID = L + (R - L) / 2;\n        (f(MID)\
    \ ? R : L) = MID;\n    }\n    return {L, R};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/binary_search.hpp
  requiredBy: []
  timestamp: '2026-01-12 21:09:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/binary_search.hpp
layout: document
title: "\u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22"
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
