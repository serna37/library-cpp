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
  bundledCode: '#line 2 "library/util/common.hpp"

    #define int long long

    #define all(x) begin(x), end(x)

    #define rall(x) rbegin(x), rend(x)

    auto chmin = []<class T>(T &i, T &j) { return i > j && (i = j, true); };

    auto chmax = []<class T>(T &i, T &j) { return i < j && (i = j, true); };

    '
  code: '#pragma once

    #define int long long

    #define all(x) begin(x), end(x)

    #define rall(x) rbegin(x), rend(x)

    auto chmin = []<class T>(T &i, T &j) { return i > j && (i = j, true); };

    auto chmax = []<class T>(T &i, T &j) { return i < j && (i = j, true); };

    '
  dependsOn: []
  isVerificationFile: false
  path: library/util/common.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/common.hpp
layout: document
title: "\u5171\u901A"
---

# 共通

`int`は`long long`として扱います。

管理内容
- マクロなど、全体を通して利用するもの
- その他 的なカテゴリのもの
