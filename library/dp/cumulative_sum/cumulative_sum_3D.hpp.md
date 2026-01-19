---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp
    title: "3\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/dp/cumulative_sum/cumulative_sum_3D.hpp\"\ntemplate\
    \ <typename T>\nvector<vector<vector<long long>>>\ncumulative_sum_3D(const vector<vector<vector<T>>>\
    \ &A) {\n    vector<vector<vector<long long>>> S;\n    int szx = A.size(), szy\
    \ = A[0].size(), szz = A[0][0].size();\n    S.resize(szx + 1,\n             vector<vector<long\
    \ long>>(szy + 1, vector<long long>(szz + 1, 0)));\n    for (int x = 1; x <= szx;\
    \ ++x) {\n        for (int y = 1; y <= szy; ++y) {\n            for (int z = 1;\
    \ z <= szz; ++z) {\n                S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x\
    \ - 1][y][z] +\n                             S[x][y - 1][z] + S[x][y][z - 1] -\n\
    \                             S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -\n    \
    \                         S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];\n     \
    \       }\n        }\n    }\n    return S;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<vector<vector<long long>>>\n\
    cumulative_sum_3D(const vector<vector<vector<T>>> &A) {\n    vector<vector<vector<long\
    \ long>>> S;\n    int szx = A.size(), szy = A[0].size(), szz = A[0][0].size();\n\
    \    S.resize(szx + 1,\n             vector<vector<long long>>(szy + 1, vector<long\
    \ long>(szz + 1, 0)));\n    for (int x = 1; x <= szx; ++x) {\n        for (int\
    \ y = 1; y <= szy; ++y) {\n            for (int z = 1; z <= szz; ++z) {\n    \
    \            S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +\n        \
    \                     S[x][y - 1][z] + S[x][y][z - 1] -\n                    \
    \         S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -\n                        \
    \     S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];\n            }\n        }\n\
    \    }\n    return S;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dp/cumulative_sum/cumulative_sum_3D.hpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp
documentation_of: library/dp/cumulative_sum/cumulative_sum_3D.hpp
layout: document
title: "3\u6B21\u5143\u7D2F\u7A4D\u548C"
---

# 3次元累積和

## できること
- 3次元での累積和を返す

## 計算量
$O(N^3)$

## 使い方
```cpp
vector<vector<vector<long long>>> S = cumulative_sum_3D(A);
```

包除として
```cpp
// Lx Ly Lzは0-indexed Rx Ry Rzは1-indexed
// S[Rxyz] - S[Lxyz]
long long ans = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] - S[Rx][Ly][Rz] -
        S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz] +
        S[Rx][Ly][Lz] - S[Lx][Ly][Lz];
```
