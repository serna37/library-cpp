---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/min_span_tree.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728"
  - icon: ':heavy_check_mark:'
    path: library/graph/connected_components.hpp
    title: "\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: library/graph/cycle_detect.hpp
    title: "\u9589\u8DEF\u691C\u51FA"
  - icon: ':heavy_check_mark:'
    path: library/graph/kruskal.hpp
    title: Kruskal
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/bfs.hpp
    title: BFS
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/warshall_froyd.hpp
    title: Warshall Froyd
  - icon: ':heavy_check_mark:'
    path: library/graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Tarjan)"
  - icon: ':heavy_check_mark:'
    path: library/graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\u30B9\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/cycle_detect.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9589\u8DEF\u691C\u51FA\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/mst_kruskal.test.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 - \u30AF\u30E9\u30B9\u30AB\u30EB\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/shortest_path/bellman_ford.test.cpp
    title: "\u30B0\u30E9\u30D5 - BellmanFord\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/shortest_path/bfs.test.cpp
    title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/shortest_path/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5 - Dijkstra\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/shortest_path/warshall_froyd.test.cpp
    title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      \u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {\n    }\n};\n"
  code: "#pragma once\nstruct Edge {\n    int from, to;\n    long long cost;\n   \
    \ int idx;\n    Edge(int from, int to, long long cost = 1, int idx = -1)\n   \
    \     : from(from), to(to), cost(cost), idx(idx) {\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/base/edge.hpp
  requiredBy:
  - library/graph/shortest_path/warshall_froyd.hpp
  - library/graph/shortest_path/bellman_ford.hpp
  - library/graph/shortest_path/bfs.hpp
  - library/graph/shortest_path/dijkstra.hpp
  - library/graph/kruskal.hpp
  - library/graph/topological_sort.hpp
  - library/graph/base/min_span_tree.hpp
  - library/graph/base/graph.hpp
  - library/graph/connected_components.hpp
  - library/graph/cycle_detect.hpp
  - library/graph/strongly_connected_components.hpp
  timestamp: '2026-01-12 22:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/topological_sort.test.cpp
  - tests/graph/shortest_path/bfs.test.cpp
  - tests/graph/shortest_path/bellman_ford.test.cpp
  - tests/graph/shortest_path/dijkstra.test.cpp
  - tests/graph/shortest_path/warshall_froyd.test.cpp
  - tests/graph/cycle_detect.test.cpp
  - tests/graph/mst_kruskal.test.cpp
  - tests/graph/route_restore.test.cpp
  - tests/graph/strongly_connected_components.test.cpp
  - tests/graph/connected_components.test.cpp
documentation_of: library/graph/base/edge.hpp
layout: document
title: "\u8FBA"
---

# 辺

## できること
- 辺の構造体
  - `from`: 辺の元の頂点
  - `to`: 辺の先の頂点
  - `cost`: 重み
  - `idx`: 辺のid

## 計算量
なし

## 使い方
```cpp
vector<Edge> edges;
```
