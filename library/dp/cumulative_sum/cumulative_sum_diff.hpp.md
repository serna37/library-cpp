---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp
    title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/dp/cumulative_sum/cumulative_sum_diff.hpp\"\ntemplate\
    \ <typename T>\nvector<long long> cumulative_sum_diff(const vector<T> &A) {\n\
    \    int N = A.size();\n    vector<long long> S(N + 1);\n    for (int i = 0; i\
    \ < N; ++i) {\n        S[i + 1] = S[i];\n        if (i & 1) S[i + 1] += abs(A[i]\
    \ - A[i - 1]);\n    }\n    return S;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<long long> cumulative_sum_diff(const\
    \ vector<T> &A) {\n    int N = A.size();\n    vector<long long> S(N + 1);\n  \
    \  for (int i = 0; i < N; ++i) {\n        S[i + 1] = S[i];\n        if (i & 1)\
    \ S[i + 1] += abs(A[i] - A[i - 1]);\n    }\n    return S;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dp/cumulative_sum/cumulative_sum_diff.hpp
  requiredBy: []
  timestamp: '2026-01-16 15:08:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp
documentation_of: library/dp/cumulative_sum/cumulative_sum_diff.hpp
layout: document
title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C"
---

# 二項差での累積和

## できること
- 2項ごとでの、累積和の数列を返す。
```
A:     1   4   2   8   2   9
増分 --> 3  -->  6  -->  7  -->
S:  0  0   3   3   9   9  16
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> S = cumulative_sum_diff(A);
```
