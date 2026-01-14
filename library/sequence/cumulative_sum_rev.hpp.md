---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence/cumulative_sum_rev.test.cpp
    title: "\u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/cumulative_sum_rev.hpp\"\ntemplate <typename\
    \ T> vector<long long> cumulative_sum_rev(const vector<T> &A) {\n    int N = A.size();\n\
    \    vector<long long> R(N + 1);\n    for (int i = N - 1; i >= 0; --i) R[i] =\
    \ R[i + 1] + A[i];\n    return R;\n}\n"
  code: "#pragma once\ntemplate <typename T> vector<long long> cumulative_sum_rev(const\
    \ vector<T> &A) {\n    int N = A.size();\n    vector<long long> R(N + 1);\n  \
    \  for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] + A[i];\n    return R;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/cumulative_sum_rev.hpp
  requiredBy: []
  timestamp: '2026-01-14 14:43:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence/cumulative_sum_rev.test.cpp
documentation_of: library/sequence/cumulative_sum_rev.hpp
layout: document
title: "\u7D2F\u7A4D\u548C \u53CD\u8EE2"
---

# 累積和 反転

## できること
- 逆向きの累積和の数列を返す。$R_i =$「$A_i$から右全部の和」
```
A:  1   4   2   8   2   9
R: 26  25  21  19  11   9  0
```

累積和 $S$ と合わせて、全区間の和は次のように求められる。

$\sum_{j=0}^{i-1} + \sum_{j=i}^{last} = S_i + R_i$

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> R = cumulative_sum_rev(A);
```
