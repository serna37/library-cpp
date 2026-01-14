---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search/bit_search.test.cpp
    title: "bit\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/search/bit_search.hpp\"\ntemplate <typename T> vector<vector<T>>\
    \ bit_search(const vector<T> &A) {\n    int N = A.size();\n    vector<vector<T>>\
    \ res;\n    for (long long bit = 0; bit < (1ll << N); ++bit) {\n        vector<T>\
    \ tmp;\n        for (int k = 0; k < N; ++k) {\n            if (bit & (1ll << k))\
    \ {\n                tmp.push_back(A[k]);\n            }\n        }\n        res.push_back(tmp);\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\ntemplate <typename T> vector<vector<T>> bit_search(const vector<T>\
    \ &A) {\n    int N = A.size();\n    vector<vector<T>> res;\n    for (long long\
    \ bit = 0; bit < (1ll << N); ++bit) {\n        vector<T> tmp;\n        for (int\
    \ k = 0; k < N; ++k) {\n            if (bit & (1ll << k)) {\n                tmp.push_back(A[k]);\n\
    \            }\n        }\n        res.push_back(tmp);\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/bit_search.hpp
  requiredBy: []
  timestamp: '2026-01-14 14:43:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/search/bit_search.test.cpp
documentation_of: library/search/bit_search.hpp
layout: document
title: "bit\u5168\u63A2\u7D22"
---

# bit全探索

## できること
- 集合Aの全パターンの部分集合を返す
```
{1,2,3}
↓
{ {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }
```


## 計算量
$O(2^N)$ Nは20前後まで

## 使い方
```cpp
vector<vector<int>> tmp = bit_search(A);
```
