---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence.collection_util.test.cpp
    title: "\u914D\u5217\u7CFBUtil\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/collection_util.hpp\"\nclass CollectionUtil\
    \ {\n  public:\n    template <typename T> T min(const vector<T> &v) {\n      \
    \  return *min_element(all(v));\n    }\n    template <typename T> T max(const\
    \ vector<T> &v) {\n        return *max_element(all(v));\n    }\n    template <typename\
    \ T> long long sum(const vector<T> &v) {\n        return accumulate(all(v), 0ll);\n\
    \    }\n    template <typename T, typename F> bool all_match(const vector<T> &v,\
    \ F f) {\n        bool b = true;\n        for (int i = 0; i < (int)v.size(); ++i)\
    \ b &= f(v[i], i);\n        return b;\n    }\n    template <typename T, typename\
    \ F> bool none_match(const vector<T> &v, F f) {\n        return !any_match(v,\
    \ f);\n    }\n    template <typename T, typename F> bool any_match(const vector<T>\
    \ &v, F f) {\n        bool b = false;\n        for (int i = 0; i < (int)v.size();\
    \ ++i) b |= f(v[i], i);\n        return b;\n    }\n    template <typename T> void\
    \ distinct(vector<T> &v) {\n        sort(all(v));\n        v.erase(unique(all(v)),\
    \ v.end());\n    }\n    template <typename T> void asc(vector<T> &v) {\n     \
    \   sort(all(v));\n    }\n    template <typename T> void desc(vector<T> &v) {\n\
    \        sort(rall(v));\n    }\n    template <typename T> void reverse(vector<T>\
    \ &v) {\n        std::reverse(all(v));\n    }\n    template <typename T> void\
    \ sequence(vector<T> &v, T start = 0) {\n        iota(all(v), start);\n    }\n\
    \    template <typename T> void erase(set<T> &st, const T &v) {\n        st.erase(st.find(v));\n\
    \    }\n    template <typename T> void erase(multiset<T> &st, const T &v) {\n\
    \        st.erase(st.find(v));\n    }\n} collection;\n"
  code: "#pragma once\nclass CollectionUtil {\n  public:\n    template <typename T>\
    \ T min(const vector<T> &v) {\n        return *min_element(all(v));\n    }\n \
    \   template <typename T> T max(const vector<T> &v) {\n        return *max_element(all(v));\n\
    \    }\n    template <typename T> long long sum(const vector<T> &v) {\n      \
    \  return accumulate(all(v), 0ll);\n    }\n    template <typename T, typename\
    \ F> bool all_match(const vector<T> &v, F f) {\n        bool b = true;\n     \
    \   for (int i = 0; i < (int)v.size(); ++i) b &= f(v[i], i);\n        return b;\n\
    \    }\n    template <typename T, typename F> bool none_match(const vector<T>\
    \ &v, F f) {\n        return !any_match(v, f);\n    }\n    template <typename\
    \ T, typename F> bool any_match(const vector<T> &v, F f) {\n        bool b = false;\n\
    \        for (int i = 0; i < (int)v.size(); ++i) b |= f(v[i], i);\n        return\
    \ b;\n    }\n    template <typename T> void distinct(vector<T> &v) {\n       \
    \ sort(all(v));\n        v.erase(unique(all(v)), v.end());\n    }\n    template\
    \ <typename T> void asc(vector<T> &v) {\n        sort(all(v));\n    }\n    template\
    \ <typename T> void desc(vector<T> &v) {\n        sort(rall(v));\n    }\n    template\
    \ <typename T> void reverse(vector<T> &v) {\n        std::reverse(all(v));\n \
    \   }\n    template <typename T> void sequence(vector<T> &v, T start = 0) {\n\
    \        iota(all(v), start);\n    }\n    template <typename T> void erase(set<T>\
    \ &st, const T &v) {\n        st.erase(st.find(v));\n    }\n    template <typename\
    \ T> void erase(multiset<T> &st, const T &v) {\n        st.erase(st.find(v));\n\
    \    }\n} collection;\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/collection_util.hpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.collection_util.test.cpp
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
