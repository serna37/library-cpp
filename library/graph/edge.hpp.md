---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/min_span_tree.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (kruskal)"
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8FBA"
    links: []
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\n/**\n * @brief \u8FBA\n */\nstruct\
    \ Edge {\n    int from, to;\n    long long cost;\n    int idx;\n    Edge(int from,\
    \ int to, long long cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief \u8FBA\n */\nstruct Edge {\n    int from, to;\n\
    \    long long cost;\n    int idx;\n    Edge(int from, int to, long long cost\
    \ = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/edge.hpp
  requiredBy:
  - library/graph/min_span_tree.hpp
  - library/graph/graph.hpp
  timestamp: '2026-01-06 20:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
documentation_of: library/graph/edge.hpp
layout: document
redirect_from:
- /library/library/graph/edge.hpp
- /library/library/graph/edge.hpp.html
title: "\u8FBA"
---
