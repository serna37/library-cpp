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
  timestamp: '2026-01-11 17:31:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
