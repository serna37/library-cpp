---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence/cumulative_sum_rev_diff.test.cpp
    title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\
      \u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/cumulative_sum_rev_diff.hpp\"\ntemplate\
    \ <typename T>\nvector<long long> cumulative_sum_rev_diff(const vector<T> &A)\
    \ {\n    int N = A.size();\n    vector<long long> R(N + 1);\n    for (int i =\
    \ N - 1; i >= 0; --i) {\n        R[i] = R[i + 1];\n        if (i & 1) R[i] +=\
    \ abs((i + 1 < N ? A[i + 1] : 0) - A[i]);\n    }\n    return R;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<long long> cumulative_sum_rev_diff(const\
    \ vector<T> &A) {\n    int N = A.size();\n    vector<long long> R(N + 1);\n  \
    \  for (int i = N - 1; i >= 0; --i) {\n        R[i] = R[i + 1];\n        if (i\
    \ & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) - A[i]);\n    }\n    return R;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/cumulative_sum_rev_diff.hpp
  requiredBy: []
  timestamp: '2026-01-13 09:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence/cumulative_sum_rev_diff.test.cpp
documentation_of: library/sequence/cumulative_sum_rev_diff.hpp
layout: document
title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C \u53CD\u8EE2"
---

# 二項差での累積和 反転

## できること
- 2項ごとでの、逆向きの累積和の数列を返す。
```
A:    1   4   2   8   2   9
増分　 <--  2  <--  6  <--  9  <--
R:   17  17  15  15   9   9  0
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> R = cumulative_sum_rev_diff(A);
```
