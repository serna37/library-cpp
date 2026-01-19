---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/polynomial/fft/superset_zeta_moebius_transform.hpp
    title: "\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\
      \u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ f[j + k + i];\n            }\n        }\n    }\n}\n#line 3 \"library/polynomial/fft/convolution_bitwise_and.hpp\"\
    \ntemplate <typename T>\nvector<T> convolution_bitwise_and(vector<T> f, vector<T>\
    \ g) {\n    const int n = (int)f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    superset_moebius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n#include \"library/polynomial/fft/superset_zeta_moebius_transform.hpp\"\
    \ntemplate <typename T>\nvector<T> convolution_bitwise_and(vector<T> f, vector<T>\
    \ g) {\n    const int n = (int)f.size();\n    assert(f.size() == g.size());\n\
    \    assert((n & (n - 1)) == 0);\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for (int i = 0; i < n; i++) f[i] *= g[i];\n    superset_moebius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn:
  - library/polynomial/fft/superset_zeta_moebius_transform.hpp
  isVerificationFile: false
  path: library/polynomial/fft/convolution_bitwise_and.hpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/fft/convolution_bitwise_and.hpp
layout: document
title: "Bitwise\u7573\u307F\u8FBC\u307FAND"
---

# Bitwise畳み込みAND

## できること
$h_k = \sum_{i AND j=k}　f_i \cdot g_j$
- Bitwise畳み込み AND を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
auto c = convolution_bitwise_and(a, b);
```

