---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
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
  requiredBy: []
  timestamp: '2026-01-06 20:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
documentation_of: library/util/geometry.hpp
layout: document
redirect_from:
- /library/library/util/geometry.hpp
- /library/library/util/geometry.hpp.html
title: "\u5E7E\u4F55"
---
