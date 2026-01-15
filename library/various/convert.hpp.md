---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.shortest_path.warshall_froyd.test.cpp
    title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/various.convert.test.cpp
    title: "\u578B\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/convert.hpp\"\nchar int_to_char(int x) {\n\
    \    return (char)(x + '0');\n}\nchar int_to_alph(int x) {\n    return (char)(x\
    \ + 'a');\n}\nint char_to_int(char c) {\n    return (int)(c - '0');\n}\nstring\
    \ int_to_string(long long x) {\n    return to_string(x);\n}\nlong long string_to_int(const\
    \ string &s) {\n    return stoll(s);\n}\n"
  code: "#pragma once\nchar int_to_char(int x) {\n    return (char)(x + '0');\n}\n\
    char int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char\
    \ c) {\n    return (int)(c - '0');\n}\nstring int_to_string(long long x) {\n \
    \   return to_string(x);\n}\nlong long string_to_int(const string &s) {\n    return\
    \ stoll(s);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/various/convert.hpp
  requiredBy: []
  timestamp: '2026-01-15 17:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/various.convert.test.cpp
  - tests/graph.shortest_path.warshall_froyd.test.cpp
documentation_of: library/various/convert.hpp
layout: document
title: "\u578B\u5909\u63DB"
---

# 型変換

## できること
- C++の型変換まとめ

## 計算量
$O(1)$

## 使い方
そのままなので省略
