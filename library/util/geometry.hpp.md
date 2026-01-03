---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E7E\u4F55"
    links: []
  bundledCode: "#line 2 \"library/util/geometry.hpp\"\n/**\n * @brief \u5E7E\u4F55\
    \n */\nclass Geometry {\n  public:\n    // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\
    \u6CD5\n    double deg_to_rad(double d) {\n        return d * PI / 180;\n    }\n\
    \    // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\n    double rad_to_deg(double\
    \ r) {\n        return r * 180 / PI;\n    }\n    // \u504F\u89D2\u3092\u30E9\u30B8\
    \u30A2\u30F3\u3067\u8FD4\u3059\n    double arc_tan(double x, double y) {\n   \
    \     return atan2(y, x);\n    }\n    /**\n     * \u4E09\u89D2\u5F62\u306E\u9762\
    \u7A4D\n     * double\u306F\u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u3001\
    52bit\u7A0B\u5EA6\u306E\u7CBE\u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\
    \u5272\u3089\u305Along long\u3067\u8FD4\u3059\u3053\u3068\n     */\n    template\
    \ <typename T>\n    double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {\n\
    \        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;\n  \
    \  }\n    /**\n     * \u56DB\u89D2\u5F62\u306E\u9762\u7A4D\n     * double\u306F\
    \u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u300152bit\u7A0B\u5EA6\u306E\u7CBE\
    \u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\u5272\u3089\u305Along long\u3067\
    \u8FD4\u3059\u3053\u3068\n     */\n    template <typename T>\n    double area_square(T\
    \ x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {\n        return hypot(x1 - x3,\
    \ y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief \u5E7E\u4F55\n */\nclass Geometry {\n  public:\n\
    \    // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\u6CD5\n    double deg_to_rad(double\
    \ d) {\n        return d * PI / 180;\n    }\n    // \u5F27\u5EA6\u6CD5 \u2192\
    \ \u5EA6\u6570\u6CD5\n    double rad_to_deg(double r) {\n        return r * 180\
    \ / PI;\n    }\n    // \u504F\u89D2\u3092\u30E9\u30B8\u30A2\u30F3\u3067\u8FD4\u3059\
    \n    double arc_tan(double x, double y) {\n        return atan2(y, x);\n    }\n\
    \    /**\n     * \u4E09\u89D2\u5F62\u306E\u9762\u7A4D\n     * double\u306F\u6841\
    \u6570\u8868\u73FE11bit\u3092\u9664\u304D\u300152bit\u7A0B\u5EA6\u306E\u7CBE\u5EA6\
    \n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\u5272\u3089\u305Along long\u3067\
    \u8FD4\u3059\u3053\u3068\n     */\n    template <typename T>\n    double area_triangle(T\
    \ x1, T y1, T x2, T y2, T x3, T y3) {\n        return abs((x2 - x1) * (y3 - y1)\
    \ - (x3 - x1) * (y2 - y1)) / 2.0;\n    }\n    /**\n     * \u56DB\u89D2\u5F62\u306E\
    \u9762\u7A4D\n     * double\u306F\u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\
    \u300152bit\u7A0B\u5EA6\u306E\u7CBE\u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u3089\
    2\u3067\u5272\u3089\u305Along long\u3067\u8FD4\u3059\u3053\u3068\n     */\n  \
    \  template <typename T>\n    double area_square(T x1, T y1, T x2, T y2, T x3,\
    \ T y3, T x4, T y4) {\n        return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4,\
    \ y2 - y4) / 2.0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/geometry.hpp
  requiredBy:
  - template/lib.hpp
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 23:10:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.dual_segment_tree.test.cpp
  - tests/segtree.segment_tree.test.cpp
  - tests/template.test.cpp
  - tests/segtree.lazy_segment_tree.test.cpp
  - tests/segtree.fenwick_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/util/geometry.hpp
layout: document
redirect_from:
- /library/library/util/geometry.hpp
- /library/library/util/geometry.hpp.html
title: "\u5E7E\u4F55"
---
