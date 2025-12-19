---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/util/search.hpp\"\n/**\n * \u9806\u5217\u5168\u63A2\
    \u7D22 O(N!) N\u306F10\u301C12\u7A0B\u5EA6\n * \u9806\u5217\u306E\u5168\u30D1\u30BF\
    \u30FC\u30F3\u4E2D\u3067\u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\u308C\
    \u308B\n * \u4F8B) search_permu(A, [&](){cout << A;} );\n */\nauto search_permu\
    \ = []<class T, class F>(vector<T> &A, F f) {\n    sort(A.begin(), A.end());\n\
    \    do {\n        f();\n    } while (next_permutation(all(A)));\n};\n/**\n *\
    \ bit\u5168\u63A2\u7D22 O(2^N) N\u306F20\u524D\u5F8C\n * \u96C6\u5408A\u306E\u5168\
    \u30D1\u30BF\u30FC\u30F3\u306E\u90E8\u5206\u96C6\u5408\u3092\u8FD4\u3059\n * {1,2,3}\
    \ -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }\n */\nauto search_bit = []<class\
    \ T>(vector<T> &A) {\n    int N = A.size();\n    vector<vector<T>> res;\n    for\
    \ (long long bit = 0; bit < (1ll << N); ++bit) {\n        vector<T> tmp;\n   \
    \     for (int k = 0; k < N; ++k) {\n            if (bit & (1ll << k)) {\n   \
    \             tmp.push_back(A[k]);\n            }\n        }\n        res.push_back(tmp);\n\
    \    }\n    return res;\n};\n// TODO \u306B\u3076\u305F\u3093\u7CFB\n"
  code: "#pragma once\n/**\n * \u9806\u5217\u5168\u63A2\u7D22 O(N!) N\u306F10\u301C\
    12\u7A0B\u5EA6\n * \u9806\u5217\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u4E2D\u3067\
    \u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\u308C\u308B\n * \u4F8B) search_permu(A,\
    \ [&](){cout << A;} );\n */\nauto search_permu = []<class T, class F>(vector<T>\
    \ &A, F f) {\n    sort(A.begin(), A.end());\n    do {\n        f();\n    } while\
    \ (next_permutation(all(A)));\n};\n/**\n * bit\u5168\u63A2\u7D22 O(2^N) N\u306F\
    20\u524D\u5F8C\n * \u96C6\u5408A\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u306E\u90E8\
    \u5206\u96C6\u5408\u3092\u8FD4\u3059\n * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}\
    \ }\n */\nauto search_bit = []<class T>(vector<T> &A) {\n    int N = A.size();\n\
    \    vector<vector<T>> res;\n    for (long long bit = 0; bit < (1ll << N); ++bit)\
    \ {\n        vector<T> tmp;\n        for (int k = 0; k < N; ++k) {\n         \
    \   if (bit & (1ll << k)) {\n                tmp.push_back(A[k]);\n          \
    \  }\n        }\n        res.push_back(tmp);\n    }\n    return res;\n};\n// TODO\
    \ \u306B\u3076\u305F\u3093\u7CFB\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/search.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/search.hpp
layout: document
title: "\u63A2\u7D22"
---

全探索などをまとめる
- 順列全探索
- bit全探索
- 二分探索
