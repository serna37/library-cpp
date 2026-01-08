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
  bundledCode: "#line 2 \"library/sequence/difference_sequence.hpp\"\ntemplate <typename\
    \ T>\nvector<long long> difference_sequence(const vector<T> &A) {\n    int N =\
    \ A.size();\n    vector<long long> D(N - 1);\n    for (int i = 0; i < N; ++i)\
    \ D[i] = A[i + 1] - A[i];\n    return D;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<long long> difference_sequence(const\
    \ vector<T> &A) {\n    int N = A.size();\n    vector<long long> D(N - 1);\n  \
    \  for (int i = 0; i < N; ++i) D[i] = A[i + 1] - A[i];\n    return D;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/difference_sequence.hpp
  requiredBy: []
  timestamp: '2026-01-08 21:27:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/difference_sequence.hpp
layout: document
title: "\u968E\u5DEE\u6570\u5217"
---

# 階差数列

## できること
- 各項の差の数列を返す
```
A: 1   4   2   8   2   9
D:   3  -2   6  -6   7
```

## 計算量
$O(N)$

## 使い方
```cpp
vector<long long> diff = difference_sequence(A);
```
