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
  bundledCode: "#line 2 \"library/search/permutation.hpp\"\ntemplate <typename T,\
    \ typename F> bool permutation(vector<T> &A, F f) {\n    sort(begin(A), end(A));\n\
    \    do {\n        if (f()) return true;\n    } while (next_permutation(begin(A),\
    \ end(A)));\n    return false;\n}\n"
  code: "#pragma once\ntemplate <typename T, typename F> bool permutation(vector<T>\
    \ &A, F f) {\n    sort(begin(A), end(A));\n    do {\n        if (f()) return true;\n\
    \    } while (next_permutation(begin(A), end(A)));\n    return false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/permutation.hpp
  requiredBy: []
  timestamp: '2026-01-12 16:39:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/permutation.hpp
layout: document
title: "\u9806\u5217\u5168\u63A2\u7D22"
---

# 順列全探索

## できること
- 順列の全パターンを探索する

## 計算量
$O(N!)$ Nは10〜12程度まで

## 使い方
```cpp
// 関数でbreakしてたらtrue
bool is_loop_break = permutation(A, [&](){
    print(A);
    return true; // trueで探索をbreak
});
```
