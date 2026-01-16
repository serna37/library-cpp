---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/convolution_fft.hpp
    title: "\u7573\u307F\u8FBC\u307F FFT"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.convolution_fft.test.cpp
    title: "\u7573\u307F\u8FBC\u307FFFT\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft.hpp\"\nnamespace FFT {\nusing real\
    \ = double;\nstruct C {\n    real x, y;\n    C() : x(0), y(0) {};\n    C(real\
    \ x, real y) : x(x), y(y) {};\n    inline C operator+(const C &c) const {\n  \
    \      return C(x + c.x, y + c.y);\n    }\n    inline C operator-(const C &c)\
    \ const {\n        return C(x - c.x, y - c.y);\n    }\n    inline C operator*(const\
    \ C &c) const {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n   \
    \ }\n    inline C conj() const {\n        return C(x, -y);\n    }\n};\nconst real\
    \ PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int>\
    \ rev = {0, 1};\nvoid ensure_base(int nbase) {\n    if (nbase <= base) return;\n\
    \    rev.resize(1 << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0;\
    \ i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n    }\n    while (base < nbase) {\n        real angle = PI *\
    \ 2.0 / (1 << (base + 1));\n        for (int i = 1 << (base - 1); i < (1 << base);\
    \ i++) {\n            rts[i << 1] = rts[i];\n            real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n        }\n        ++base;\n    }\n}\nvoid fft(vector<C> &a,\
    \ int n) {\n    assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);\n\
    \    }\n    for (int k = 1; k < n; k <<= 1) {\n        for (int i = 0; i < n;\
    \ i += 2 * k) {\n            for (int j = 0; j < k; j++) {\n                C\
    \ z = a[i + j + k] * rts[j + k];\n                a[i + j + k] = a[i + j] - z;\n\
    \                a[i + j] = a[i + j] + z;\n            }\n        }\n    }\n}\n\
    } // namespace FFT\n"
  code: "#pragma once\nnamespace FFT {\nusing real = double;\nstruct C {\n    real\
    \ x, y;\n    C() : x(0), y(0) {};\n    C(real x, real y) : x(x), y(y) {};\n  \
    \  inline C operator+(const C &c) const {\n        return C(x + c.x, y + c.y);\n\
    \    }\n    inline C operator-(const C &c) const {\n        return C(x - c.x,\
    \ y - c.y);\n    }\n    inline C operator*(const C &c) const {\n        return\
    \ C(x * c.x - y * c.y, x * c.y + y * c.x);\n    }\n    inline C conj() const {\n\
    \        return C(x, -y);\n    }\n};\nconst real PI = acosl(-1);\nint base = 1;\n\
    vector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\nvoid ensure_base(int\
    \ nbase) {\n    if (nbase <= base) return;\n    rev.resize(1 << nbase);\n    rts.resize(1\
    \ << nbase);\n    for (int i = 0; i < (1 << nbase); i++) {\n        rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n    }\n    while (base < nbase) {\n\
    \        real angle = PI * 2.0 / (1 << (base + 1));\n        for (int i = 1 <<\
    \ (base - 1); i < (1 << base); i++) {\n            rts[i << 1] = rts[i];\n   \
    \         real angle_i = angle * (2 * i + 1 - (1 << base));\n            rts[(i\
    \ << 1) + 1] = C(cos(angle_i), sin(angle_i));\n        }\n        ++base;\n  \
    \  }\n}\nvoid fft(vector<C> &a, int n) {\n    assert((n & (n - 1)) == 0);\n  \
    \  int zeros = __builtin_ctz(n);\n    ensure_base(zeros);\n    int shift = base\
    \ - zeros;\n    for (int i = 0; i < n; i++) {\n        if (i < (rev[i] >> shift))\
    \ swap(a[i], a[rev[i] >> shift]);\n    }\n    for (int k = 1; k < n; k <<= 1)\
    \ {\n        for (int i = 0; i < n; i += 2 * k) {\n            for (int j = 0;\
    \ j < k; j++) {\n                C z = a[i + j + k] * rts[j + k];\n          \
    \      a[i + j + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n\
    \            }\n        }\n    }\n}\n} // namespace FFT\n"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/fft.hpp
  requiredBy:
  - library/polynomial/convolution_fft.hpp
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.convolution_fft.test.cpp
documentation_of: library/polynomial/fft.hpp
layout: document
title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
---

# 高速フーリエ変換
[詳しい説明](https://www.slideshare.net/slideshow/fft-49066791/49066791)

## できること
$F(k) = \sum_{n=0}^{N-1} f(n) \exp(\frac{-2 \pi i}{N} n k)$
- 離散フーリエ変換をバタフライ演算とかで高速に行う
- 多項式の乗算を高速に行うことができる

## 計算量
$O(NlogN)$

## 使い方
```cpp
int nbase = 1;
FFT::ensure_base(nbase);
int sz = 1 << nbase;
vector<C> fa(sz);
FFT::fft(fa, sz);
```

