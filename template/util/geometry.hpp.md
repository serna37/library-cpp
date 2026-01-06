---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/bellman_ford.test.cpp
    title: "\u30B0\u30E9\u30D5 - BellmanFord\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\u30B9\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/cycle_detect.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9589\u8DEF\u691C\u51FA\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5 - Dijkstra\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/mst_kruskal.test.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 - \u30AF\u30E9\u30B9\u30AB\u30EB\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      \u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/warshall_froyd.test.cpp
    title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct/union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: "template/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E7E\u4F55"
    links: []
  bundledCode: "#line 2 \"template/util/geometry.hpp\"\n/**\n * @brief \u5E7E\u4F55\
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
  path: template/util/geometry.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-06 20:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/lazy_segment_tree.test.cpp
  - tests/segtree/fenwick_tree.test.cpp
  - tests/segtree/segment_tree.test.cpp
  - tests/segtree/dual_segment_tree.test.cpp
  - tests/graph/bfs.test.cpp
  - tests/graph/topological_sort.test.cpp
  - tests/graph/bellman_ford.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/cycle_detect.test.cpp
  - tests/graph/mst_kruskal.test.cpp
  - tests/graph/route_restore.test.cpp
  - tests/graph/strongly_connected_components.test.cpp
  - tests/graph/warshall_froyd.test.cpp
  - tests/graph/connected_components.test.cpp
  - tests/struct/union_find.test.cpp
  - tests/util.test.cpp
documentation_of: template/util/geometry.hpp
layout: document
redirect_from:
- /library/template/util/geometry.hpp
- /library/template/util/geometry.hpp.html
title: "\u5E7E\u4F55"
---
