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
  bundledCode: "#line 2 \"library/sequence/merge.hpp\"\ntemplate <typename T> void\
    \ merge(vector<T> &A, vector<T> &B) {\n    if (A.size() > B.size()) swap(A, B);\n\
    \    for (auto &&v : A) B.push_back(v);\n    A.clear();\n}\ntemplate <typename\
    \ T> void merge(set<T> &A, set<T> &B) {\n    if (A.size() > B.size()) swap(A,\
    \ B);\n    for (auto &&v : A) B.insert(v);\n    A.clear();\n}\ntemplate <typename\
    \ T, typename F> void merge(T &A, T &B, F f) {\n    if (A.size() > B.size()) swap(A,\
    \ B);\n    for (auto &&v : A) {\n        f(B, v);\n    }\n    A.clear();\n}\n"
  code: "#pragma once\ntemplate <typename T> void merge(vector<T> &A, vector<T> &B)\
    \ {\n    if (A.size() > B.size()) swap(A, B);\n    for (auto &&v : A) B.push_back(v);\n\
    \    A.clear();\n}\ntemplate <typename T> void merge(set<T> &A, set<T> &B) {\n\
    \    if (A.size() > B.size()) swap(A, B);\n    for (auto &&v : A) B.insert(v);\n\
    \    A.clear();\n}\ntemplate <typename T, typename F> void merge(T &A, T &B, F\
    \ f) {\n    if (A.size() > B.size()) swap(A, B);\n    for (auto &&v : A) {\n \
    \       f(B, v);\n    }\n    A.clear();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/merge.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:37:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/merge.hpp
layout: document
title: "\u30DE\u30FC\u30B8\u30C6\u30AF"
---

# マージテク

## できること
- AをBにマージする
- Aは空にする

## 計算量
- vector: $O(NlogN)$
- set: $O(Nlog^2N)$

## 使い方
```cpp
merge(A, B);
merge(stA, stB);
merge(mpA, mpB, [&](map<int, int> &B, pair<int, int> a){
    auto [k, v] = a;
    B[k] += v;
});
```
