---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.util.test.cpp
    title: "\u6587\u5B57\u5217Util\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/util.hpp\"\nstring string_to_lower(string\
    \ s) {\n    std::transform(all(s), s.begin(), ::tolower);\n    return s;\n}\n\
    string string_to_upper(string s) {\n    std::transform(all(s), s.begin(), ::toupper);\n\
    \    return s;\n}\nbool char_is_lower(char c) { // bool\u3067\u8FD4\u3059\n  \
    \  return islower(c) != 0;\n}\nbool char_is_upper(char c) { // bool\u3067\u8FD4\
    \u3059\n    return isupper(c) != 0;\n}\n"
  code: "#pragma once\nstring string_to_lower(string s) {\n    std::transform(all(s),\
    \ s.begin(), ::tolower);\n    return s;\n}\nstring string_to_upper(string s) {\n\
    \    std::transform(all(s), s.begin(), ::toupper);\n    return s;\n}\nbool char_is_lower(char\
    \ c) { // bool\u3067\u8FD4\u3059\n    return islower(c) != 0;\n}\nbool char_is_upper(char\
    \ c) { // bool\u3067\u8FD4\u3059\n    return isupper(c) != 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/util.hpp
  requiredBy: []
  timestamp: '2026-01-15 17:22:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.util.test.cpp
documentation_of: library/string/util.hpp
layout: document
title: "\u6587\u5B57\u5217Util"
---

# 文字列Util

## できること
- 大文字小文字変換
- charが大文字かどうかを判別（C++のstlはboolで返さないのでラップ）

## 計算量
だいたい $O(\vert S \vert)$

## 使い方
そのままなので省略
