---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/util/util.hpp
    title: library/util/util.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_or.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FOR\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.collection_util.test.cpp
    title: "\u914D\u5217\u7CFBUtil\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/collection_util.hpp\"\nclass CollectionUtil\
    \ {\npublic:\n  template <typename T> T min(const vector<T> &v) {\n    return\
    \ *min_element(v.begin(), v.end());\n  }\n  template <typename T> T max(const\
    \ vector<T> &v) {\n    return *max_element(v.begin(), v.end());\n  }\n  template\
    \ <typename T> long long sum(const vector<T> &v) {\n    return accumulate(v.begin(),\
    \ v.end(), 0ll);\n  }\n  template <typename T, typename F> bool all_match(const\
    \ vector<T> &v, F f) {\n    bool b = true;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) b &= f(v[i], i);\n    return b;\n  }\n  template <typename T, typename\
    \ F> bool none_match(const vector<T> &v, F f) {\n    return !any_match(v, f);\n\
    \  }\n  template <typename T, typename F> bool any_match(const vector<T> &v, F\
    \ f) {\n    bool b = false;\n    for (int i = 0; i < (int)v.size(); ++i) b |=\
    \ f(v[i], i);\n    return b;\n  }\n  template <typename T> void distinct(vector<T>\
    \ &v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n  }\n  template <typename T> void asc(vector<T> &v) { sort(v.begin(),\
    \ v.end()); }\n  template <typename T> void desc(vector<T> &v) { sort(v.rbegin(),\
    \ v.rend()); }\n  template <typename T> void reverse(vector<T> &v) { std::reverse(v.begin(),\
    \ v.end()); }\n  template <typename T> void sequence(vector<T> &v, T start = 0)\
    \ {\n    iota(v.begin(), v.end(), start);\n  }\n  template <typename T> void erase(set<T>\
    \ &st, const T &v) {\n    st.erase(st.find(v));\n  }\n  template <typename T>\
    \ void erase(multiset<T> &st, const T &v) {\n    st.erase(st.find(v));\n  }\n\
    } collection;\n"
  code: "#pragma once\nclass CollectionUtil {\npublic:\n  template <typename T> T\
    \ min(const vector<T> &v) {\n    return *min_element(v.begin(), v.end());\n  }\n\
    \  template <typename T> T max(const vector<T> &v) {\n    return *max_element(v.begin(),\
    \ v.end());\n  }\n  template <typename T> long long sum(const vector<T> &v) {\n\
    \    return accumulate(v.begin(), v.end(), 0ll);\n  }\n  template <typename T,\
    \ typename F> bool all_match(const vector<T> &v, F f) {\n    bool b = true;\n\
    \    for (int i = 0; i < (int)v.size(); ++i) b &= f(v[i], i);\n    return b;\n\
    \  }\n  template <typename T, typename F> bool none_match(const vector<T> &v,\
    \ F f) {\n    return !any_match(v, f);\n  }\n  template <typename T, typename\
    \ F> bool any_match(const vector<T> &v, F f) {\n    bool b = false;\n    for (int\
    \ i = 0; i < (int)v.size(); ++i) b |= f(v[i], i);\n    return b;\n  }\n  template\
    \ <typename T> void distinct(vector<T> &v) {\n    sort(v.begin(), v.end());\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n  }\n  template <typename\
    \ T> void asc(vector<T> &v) { sort(v.begin(), v.end()); }\n  template <typename\
    \ T> void desc(vector<T> &v) { sort(v.rbegin(), v.rend()); }\n  template <typename\
    \ T> void reverse(vector<T> &v) { std::reverse(v.begin(), v.end()); }\n  template\
    \ <typename T> void sequence(vector<T> &v, T start = 0) {\n    iota(v.begin(),\
    \ v.end(), start);\n  }\n  template <typename T> void erase(set<T> &st, const\
    \ T &v) {\n    st.erase(st.find(v));\n  }\n  template <typename T> void erase(multiset<T>\
    \ &st, const T &v) {\n    st.erase(st.find(v));\n  }\n} collection;\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/collection_util.hpp
  requiredBy:
  - library/util/util.hpp
  timestamp: '2026-08-07 23:39:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.collection_util.test.cpp
  - tests/polynomial.fft.convolution_bitwise_or.test.cpp
documentation_of: library/sequence/collection_util.hpp
layout: document
title: "\u914D\u5217\u7CFBUtil"
---

# 配列系Util

## できること
- 配列に関するよくある操作のユーティリティ

## 計算量
だいたい $O(N)$

## 使い方
そのままなので省略
