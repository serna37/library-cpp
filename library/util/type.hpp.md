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
  bundledCode: "#line 2 \"library/util/type.hpp\"\ntemplate <typename T>\nusing reverse_queue\
    \ = priority_queue<T, vector<T>, greater<T>>;\ntemplate <typename T> using vec2\
    \ = vector<vector<T>>;\ntemplate <typename T> vec2<T> make_vec2(int H, int W,\
    \ T &init) {\n    return vector<vector<T>>(H, vector<T>(W, init));\n}\ntemplate\
    \ <typename T> vec2<T> make_vec2(int H, int W) {\n    return vector<vector<T>>(H,\
    \ vector<T>(W));\n}\nchar int_to_char(int x) {\n    return (char)(x + '0');\n\
    }\nchar int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char\
    \ c) {\n    return (int)(c - '0');\n}\nstring toString(long long x) {\n    return\
    \ to_string(x);\n}\nlong long toInteger(string s) {\n    return stoll(s);\n}\n"
  code: "#pragma once\ntemplate <typename T>\nusing reverse_queue = priority_queue<T,\
    \ vector<T>, greater<T>>;\ntemplate <typename T> using vec2 = vector<vector<T>>;\n\
    template <typename T> vec2<T> make_vec2(int H, int W, T &init) {\n    return vector<vector<T>>(H,\
    \ vector<T>(W, init));\n}\ntemplate <typename T> vec2<T> make_vec2(int H, int\
    \ W) {\n    return vector<vector<T>>(H, vector<T>(W));\n}\nchar int_to_char(int\
    \ x) {\n    return (char)(x + '0');\n}\nchar int_to_alph(int x) {\n    return\
    \ (char)(x + 'a');\n}\nint char_to_int(char c) {\n    return (int)(c - '0');\n\
    }\nstring toString(long long x) {\n    return to_string(x);\n}\nlong long toInteger(string\
    \ s) {\n    return stoll(s);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/type.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/type.hpp
layout: document
title: "\u578B"
---

型のエイリアスや、型変換などをまとめる
