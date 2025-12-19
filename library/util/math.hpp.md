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
  bundledCode: "#line 2 \"library/util/math.hpp\"\n// \u5272\u308A\u4E0B\u3052\uFF08\
    \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\nauto divCeil\
    \ = []<class T>(T a, T b) {\n    return a / b + (((a ^ b) > 0 and a % b != 0)\
    \ ? 1 : 0);\n};\n// \u5272\u308A\u4E0A\u3052\uFF08\u8CA0\u306E\u5834\u54080\u5074\
    \u3078\u4E38\u3081\u306A\u3044\uFF09\nauto divFloor = []<class T>(T a, T b) {\n\
    \    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);\n};\n// TODO \u6570\
    \u5024\u7CFB mod\u3068\u304B\u968E\u4E57\u3001\u7D20\u6570\u3001\u7D04\u6570\u3068\
    \u304B\n"
  code: "#pragma once\n// \u5272\u308A\u4E0B\u3052\uFF08\u8CA0\u306E\u5834\u54080\u5074\
    \u3078\u4E38\u3081\u306A\u3044\uFF09\nauto divCeil = []<class T>(T a, T b) {\n\
    \    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);\n};\n// \u5272\u308A\
    \u4E0A\u3052\uFF08\u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\
    \uFF09\nauto divFloor = []<class T>(T a, T b) {\n    return a / b - (((a ^ b)\
    \ < 0 and a % b != 0) ? 1 : 0);\n};\n// TODO \u6570\u5024\u7CFB mod\u3068\u304B\
    \u968E\u4E57\u3001\u7D20\u6570\u3001\u7D04\u6570\u3068\u304B\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/math.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/math.hpp
layout: document
title: "\u6570\u5B66\u7CFB"
---

数値計算や数の性質などをまとめる
