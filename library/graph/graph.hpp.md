---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':heavy_check_mark:'
    path: library/graph/bfs.hpp
    title: BFS
  - icon: ':heavy_check_mark:'
    path: library/graph/connected_components.hpp
    title: "\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: library/graph/cycle_detect.hpp
    title: "\u9589\u8DEF\u691C\u51FA"
  - icon: ':heavy_check_mark:'
    path: library/graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: library/graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Tarjan)"
  - icon: ':heavy_check_mark:'
    path: library/graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/graph/warshall_froyd.hpp
    title: Warshall Froyd
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
    links: []
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\nstruct Edge {\n    int from, to;\n\
    \    long long cost;\n    int idx;\n    Edge(int from, int to, long long cost\
    \ = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {\n \
    \   }\n};\n#line 3 \"library/graph/graph.hpp\"\nstruct Graph {\n  private:\n \
    \   int N;\n    vector<vector<Edge>> G;\n    int es;\n\n  public:\n    Graph(int\
    \ N) : N(N), G(N), es(0) {\n    }\n    const vector<Edge> &operator[](int v) const\
    \ {\n        return G[v];\n    }\n    int size() const {\n        return N;\n\
    \    }\n    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es++));\n    }\n    void add_both(int from, int to, long long cost\
    \ = 1) {\n        G[from].push_back(Edge(from, to, cost, es));\n        G[to].push_back(Edge(to,\
    \ from, cost, es++));\n    }\n    void read(int M, int padding = -1, bool weighted\
    \ = false,\n              bool directed = false) {\n        for (int i = 0; i\
    \ < M; i++) {\n            int u, v;\n            cin >> u >> v;\n           \
    \ u += padding, v += padding;\n            long long cost = 1ll;\n           \
    \ if (weighted) cin >> cost;\n            if (directed) {\n                add(u,\
    \ v, cost);\n            } else {\n                add_both(u, v, cost);\n   \
    \         }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\nstruct Graph {\n  private:\n\
    \    int N;\n    vector<vector<Edge>> G;\n    int es;\n\n  public:\n    Graph(int\
    \ N) : N(N), G(N), es(0) {\n    }\n    const vector<Edge> &operator[](int v) const\
    \ {\n        return G[v];\n    }\n    int size() const {\n        return N;\n\
    \    }\n    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es++));\n    }\n    void add_both(int from, int to, long long cost\
    \ = 1) {\n        G[from].push_back(Edge(from, to, cost, es));\n        G[to].push_back(Edge(to,\
    \ from, cost, es++));\n    }\n    void read(int M, int padding = -1, bool weighted\
    \ = false,\n              bool directed = false) {\n        for (int i = 0; i\
    \ < M; i++) {\n            int u, v;\n            cin >> u >> v;\n           \
    \ u += padding, v += padding;\n            long long cost = 1ll;\n           \
    \ if (weighted) cin >> cost;\n            if (directed) {\n                add(u,\
    \ v, cost);\n            } else {\n                add_both(u, v, cost);\n   \
    \         }\n        }\n    }\n};\n"
  dependsOn:
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy:
  - library/graph/warshall_froyd.hpp
  - library/graph/bellman_ford.hpp
  - library/graph/topological_sort.hpp
  - library/graph/connected_components.hpp
  - library/graph/bfs.hpp
  - library/graph/cycle_detect.hpp
  - library/graph/strongly_connected_components.hpp
  - library/graph/dijkstra.hpp
  timestamp: '2026-01-08 22:37:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/bfs.test.cpp
  - tests/graph/topological_sort.test.cpp
  - tests/graph/bellman_ford.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/cycle_detect.test.cpp
  - tests/graph/route_restore.test.cpp
  - tests/graph/strongly_connected_components.test.cpp
  - tests/graph/warshall_froyd.test.cpp
  - tests/graph/connected_components.test.cpp
documentation_of: library/graph/graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5"
---

# グラフ

## できること
- グラフの構造体
  - `N`: 頂点数
  - `G`: グラフ本体
  - `es`: カウンタ

辺を貼るたび、`Edge#idx`を自動で採番。

## 計算量
なし

## 使い方
```cpp
Graph G(N);
// 有向グラフ 一方向にのみ辺を張る
G.add(from, to, cost);
// 無向グラフ 双方向に辺を張る
G.add_both(from, to, cost);
```

標準入力にも対応
```cpp
Graph G(N);
// 辺の数、1-indexなら-1する
//             重みtrue  有向true
G.read(M, -1, true, true);
```
