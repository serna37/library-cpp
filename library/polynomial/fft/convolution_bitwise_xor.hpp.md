---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/fast_walsh_hadamard_transform.hpp
    title: "\u9AD8\u901FWalshHadamard\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_xor.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FXOR\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft/fast_walsh_hadamard_transform.hpp\"\
    \ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(vector<T> &f, bool\
    \ inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j\
    \ += i << 1) {\n            for (int k = 0; k < i; k++) {\n                T s\
    \ = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n         \
    \       f[j + k + i] = s - t;\n            }\n        }\n    }\n    if (inv) {\n\
    \        T inv_n = T(1) / n;\n        for (auto &x : f) x *= inv_n;\n    }\n}\n\
    #line 3 \"library/polynomial/fft/convolution_bitwise_xor.hpp\"\ntemplate <typename\
    \ T>\nvector<T> convolution_bitwise_xor(vector<T> f, vector<T> g) {\n    const\
    \ int n = (int)f.size();\n    assert(f.size() == g.size());\n    assert((n & (n\
    \ - 1)) == 0);\n    fast_walsh_hadamard_transform(f);\n    fast_walsh_hadamard_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    fast_walsh_hadamard_transform(f,\
    \ true);\n    return f;\n}\n"
  code: "#pragma once\n#include \"library/polynomial/fft/fast_walsh_hadamard_transform.hpp\"\
    \ntemplate <typename T>\nvector<T> convolution_bitwise_xor(vector<T> f, vector<T>\
    \ g) {\n    const int n = (int)f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    fast_walsh_hadamard_transform(f);\n    fast_walsh_hadamard_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    fast_walsh_hadamard_transform(f,\
    \ true);\n    return f;\n}\n"
  dependsOn:
  - library/polynomial/fft/fast_walsh_hadamard_transform.hpp
  isVerificationFile: false
  path: library/polynomial/fft/convolution_bitwise_xor.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.fft.convolution_bitwise_xor.test.cpp
documentation_of: library/polynomial/fft/convolution_bitwise_xor.hpp
layout: document
title: "Bitwise\u7573\u307F\u8FBC\u307FXOR"
---

# Bitwise畳み込みXOR
[詳しい説明](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)

## できること
$h_k = \sum_{i \oplus j=k}　f_i \cdot g_j$
- Bitwise畳み込み XOR を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_xor(a, b);
```

