---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/convolution_bitwise_and.hpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FAND"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_and.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FAND\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft/superset_zeta_moebius_transform.hpp\"\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f) {\n    const\
    \ int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (int j = 0; j < n; j += i << 1) {\n         \
    \   for (int k = 0; k < i; k++) {\n                f[j + k] += f[j + k + i];\n\
    \            }\n        }\n    }\n}\ntemplate <typename T>\nvoid superset_moebius_transform(vector<T>&\
    \ f) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n  \
    \  for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j += i <<\
    \ 1) {\n            for (int k = 0; k < i; k++) {\n                f[j + k] -=\
    \ f[j + k + i];\n            }\n        }\n    }\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
    \ f) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n  \
    \  for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j += i <<\
    \ 1) {\n            for (int k = 0; k < i; k++) {\n                f[j + k] +=\
    \ f[j + k + i];\n            }\n        }\n    }\n}\ntemplate <typename T>\nvoid\
    \ superset_moebius_transform(vector<T>& f) {\n    const int n = (int)f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n    \
    \    for (int j = 0; j < n; j += i << 1) {\n            for (int k = 0; k < i;\
    \ k++) {\n                f[j + k] -= f[j + k + i];\n            }\n        }\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/fft/superset_zeta_moebius_transform.hpp
  requiredBy:
  - library/polynomial/fft/convolution_bitwise_and.hpp
  timestamp: '2026-01-19 13:29:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.fft.convolution_bitwise_and.test.cpp
documentation_of: library/polynomial/fft/superset_zeta_moebius_transform.hpp
layout: document
title: "\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\
  \u5909\u63DB"
---

# 上位集合のゼータ・メビウス変換

## できること
- [詳しい説明](https://qiita.com/izu_nori/items/9e93c4263c11b3b98cd5)

<img width="641" height="257" alt="Image" src="https://github.com/user-attachments/assets/224b6bfa-bbd2-4053-a33b-1c1cc92ee686" />

## 計算量
$O(N \cdot 2^N)$

## 使い方
```cpp
superset_zeta_transform(f);
superset_moebius_transform(f);
```

