---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/number.ext_gcd.test.cpp
    title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/ext_gcd.hpp\"\ntemplate <typename T> T ext_gcd(T\
    \ a, T b, T &x, T &y) {\n    T d = a;\n    if (b != 0ll) {\n        d = ext_gcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1ll;\n \
    \       y = 0ll;\n    }\n    return d;\n}\n"
  code: "#pragma once\ntemplate <typename T> T ext_gcd(T a, T b, T &x, T &y) {\n \
    \   T d = a;\n    if (b != 0ll) {\n        d = ext_gcd(b, a % b, y, x);\n    \
    \    y -= (a / b) * x;\n    } else {\n        x = 1ll;\n        y = 0ll;\n   \
    \ }\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/ext_gcd.hpp
  requiredBy: []
  timestamp: '2026-01-20 19:53:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/number.ext_gcd.test.cpp
documentation_of: library/number/ext_gcd.hpp
layout: document
title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5"
---

# 拡張Euclidの互除法

## できること
- 最大公約数 $d = gcd(a, b)$ を求める
- 通常のユークリッドの互除法の過程で、 $(ax+by=d)$ を満たす整数 $(x, y)$ （ベズーの等式）を同時に求める
- 整数解は複数考えられるが、 $\vert x \vert + \vert y \vert$ が最小のものが格納される
- $1 \le a, b$ であること

## 計算量
$O(\log \min(a, b))$

## 使い方
```cpp
int a, b, x, y;
cin >> a >> b;
ext_gcd(a, b, x, y);
```

