---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/geometry.util.test.cpp
    title: "\u5E7E\u4F55Util\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/util.hpp\"\ndouble deg_to_rad(double d)\
    \ { // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\u6CD5\n    return d * PI / 180;\n\
    }\ndouble rad_to_deg(double r) { // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\
    \n    return r * 180 / PI;\n}\ndouble arc_tan(double x, double y) { // \u504F\u89D2\
    \u3092\u30E9\u30B8\u30A2\u30F3\u3067\u8FD4\u3059\n    return atan2(y, x);\n}\n"
  code: "#pragma once\ndouble deg_to_rad(double d) { // \u5EA6\u6570\u6CD5 \u2192\
    \ \u5F27\u5EA6\u6CD5\n    return d * PI / 180;\n}\ndouble rad_to_deg(double r)\
    \ { // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\n    return r * 180 / PI;\n\
    }\ndouble arc_tan(double x, double y) { // \u504F\u89D2\u3092\u30E9\u30B8\u30A2\
    \u30F3\u3067\u8FD4\u3059\n    return atan2(y, x);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/util.hpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/geometry.util.test.cpp
documentation_of: library/geometry/util.hpp
layout: document
title: "\u5E7E\u4F55Util"
---

# 幾何Util

## できること
- 度数法と弧度法の変換
- 偏角を求める

## 計算量
いろいろ

## 使い方
そのままなので省略
