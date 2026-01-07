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
  bundledCode: "#line 2 \"library/sequence/cumulative_sum.hpp\"\nvector<long long>\
    \ cumulative_sum(const vector<long long> &A) {\n    int N = A.size();\n    vector<long\
    \ long> S(N + 1);\n    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];\n \
    \   return S;\n}\n"
  code: "#pragma once\nvector<long long> cumulative_sum(const vector<long long> &A)\
    \ {\n    int N = A.size();\n    vector<long long> S(N + 1);\n    for (int i =\
    \ 0; i < N; ++i) S[i + 1] = S[i] + A[i];\n    return S;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2026-01-07 17:15:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/cumulative_sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C"
---

# 累積和

## できること
- 累積和の数列を返す。 $S_i = \sum A[0, i)$
```
A:    1   4   2   8   2   9
S: 0  1   5   7  15  17  26
```

半開区間 $[l, r)$ の和は、次のように求められる。

$\sum_{j=l}^{r-1} A_j = S_r - S_l$

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> S = cumulative_sum(A);
```
