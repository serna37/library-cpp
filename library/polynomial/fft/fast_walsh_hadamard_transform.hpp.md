---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/polynomial/fft/convolution_bitwise_xor.hpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FXOR"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft/fast_walsh_hadamard_transform.hpp\"\
    \ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(vector<T> &f, bool\
    \ inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j\
    \ += i << 1) {\n            for (int k = 0; k < i; k++) {\n                T s\
    \ = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n         \
    \       f[j + k + i] = s - t;\n            }\n        }\n    }\n    if (inv) {\n\
    \        T inv_n = T(1) / n;\n        for (auto &x : f) x *= inv_n;\n    }\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvoid fast_walsh_hadamard_transform(vector<T>\
    \ &f, bool inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n\
    \ - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j += i << 1) {\n            for (int k = 0; k < i; k++) {\n         \
    \       T s = f[j + k], t = f[j + k + i];\n                f[j + k] = s + t;\n\
    \                f[j + k + i] = s - t;\n            }\n        }\n    }\n    if\
    \ (inv) {\n        T inv_n = T(1) / n;\n        for (auto &x : f) x *= inv_n;\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/fft/fast_walsh_hadamard_transform.hpp
  requiredBy:
  - library/polynomial/fft/convolution_bitwise_xor.hpp
  timestamp: '2026-01-19 13:52:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/fft/fast_walsh_hadamard_transform.hpp
layout: document
title: "\u9AD8\u901FWalshHadamard\u5909\u63DB"
---

# 高速WalshHadamard変換
[詳しい説明](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)

## できること
- 行列とベクトルの積を高速に計算するための変換

<img width="350" height="327" alt="Image" src="https://github.com/user-attachments/assets/26e220ba-fb48-4020-8368-0af5cb5a6ad0" />

## 計算量
$O(NlogN)$

## 使い方
```cpp
fast_walsh_hadamard_transform(f, false);
```

