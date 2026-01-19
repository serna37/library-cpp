---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/subset_zeta_moebius_transform.hpp
    title: "\u4E0B\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\
      \u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_or.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FOR\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft/subset_zeta_moebius_transform.hpp\"\
    \ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>& f) {\n    const\
    \ int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (int j = 0; j < n; j += i << 1) {\n         \
    \   for (int k = 0; k < i; k++) {\n                f[j + k + i] += f[j + k];\n\
    \            }\n        }\n    }\n}\ntemplate <typename T>\nvoid subset_moebius_transform(vector<T>&\
    \ f) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n  \
    \  for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j += i <<\
    \ 1) {\n            for (int k = 0; k < i; k++) {\n                f[j + k + i]\
    \ -= f[j + k];\n            }\n        }\n    }\n}\n#line 3 \"library/polynomial/fft/convolution_bitwise_or.hpp\"\
    \ntemplate <typename T>\nvector<T> convolution_bitwise_or(vector<T> f, vector<T>\
    \ g) {\n    const int n = (int)f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    subset_moebius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n#include \"library/polynomial/fft/subset_zeta_moebius_transform.hpp\"\
    \ntemplate <typename T>\nvector<T> convolution_bitwise_or(vector<T> f, vector<T>\
    \ g) {\n    const int n = (int)f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    subset_moebius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn:
  - library/polynomial/fft/subset_zeta_moebius_transform.hpp
  isVerificationFile: false
  path: library/polynomial/fft/convolution_bitwise_or.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.fft.convolution_bitwise_or.test.cpp
documentation_of: library/polynomial/fft/convolution_bitwise_or.hpp
layout: document
title: "Bitwise\u7573\u307F\u8FBC\u307FOR"
---

# Bitwise畳み込みOR

## できること
$h_k = \sum_{i OR j=k}　f_i \cdot g_j$
- Bitwise畳み込み OR を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_or(a, b);
```

