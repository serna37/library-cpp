---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/warshall_froyd.hpp\"\
    \npair<vector<vector<long long>>, bool> warshall_froyd(const Graph &G) {\n   \
    \ int N = G.size();\n    vector<vector<long long>> dis(N, vector<long long>(N,\
    \ INF));\n    for (int v = 0; v < N; ++v) {\n        dis[v][v] = 0;\n        for\
    \ (auto &&[from, to, cost, idx] : G[v]) {\n            dis[v][to] = min(dis[v][to],\
    \ cost);\n        }\n    }\n    for (int k = 0; k < N; ++k) {\n        for (int\
    \ i = 0; i < N; ++i) {\n            if (dis[i][k] == INF) continue;\n        \
    \    for (int j = 0; j < N; ++j) {\n                if (dis[k][j] == INF) continue;\n\
    \                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);\n        \
    \    }\n        }\n    }\n    bool negativeCycle = false;\n    for (int i = 0;\
    \ i < N; ++i) {\n        if (dis[i][i] < 0) {\n            negativeCycle = true;\n\
    \            break;\n        }\n    }\n    return {dis, negativeCycle};\n}\n"
  code: "#pragma once\n#include \"library/graph/graph.hpp\"\npair<vector<vector<long\
    \ long>>, bool> warshall_froyd(const Graph &G) {\n    int N = G.size();\n    vector<vector<long\
    \ long>> dis(N, vector<long long>(N, INF));\n    for (int v = 0; v < N; ++v) {\n\
    \        dis[v][v] = 0;\n        for (auto &&[from, to, cost, idx] : G[v]) {\n\
    \            dis[v][to] = min(dis[v][to], cost);\n        }\n    }\n    for (int\
    \ k = 0; k < N; ++k) {\n        for (int i = 0; i < N; ++i) {\n            if\
    \ (dis[i][k] == INF) continue;\n            for (int j = 0; j < N; ++j) {\n  \
    \              if (dis[k][j] == INF) continue;\n                dis[i][j] = min(dis[i][j],\
    \ dis[i][k] + dis[k][j]);\n            }\n        }\n    }\n    bool negativeCycle\
    \ = false;\n    for (int i = 0; i < N; ++i) {\n        if (dis[i][i] < 0) {\n\
    \            negativeCycle = true;\n            break;\n        }\n    }\n   \
    \ return {dis, negativeCycle};\n}\n"
  dependsOn:
  - library/graph/graph.hpp
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/warshall_froyd.hpp
  requiredBy: []
  timestamp: '2026-01-08 20:49:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/warshall_froyd.test.cpp
documentation_of: library/graph/warshall_froyd.hpp
layout: document
title: Warshall Froyd
---

# Warshall Froyd

## できること
- 全頂点対の最小コストを求める
- 複数始点
  - `dis`: dis[i][j] := 頂点までの最小コスト
  - `negativeCycle`: 負の閉路がある場合true

## 計算量
$O(N^3)$

## 使い方
```cpp
auto [dis, negativeCycle] = warshall_froyd(G);
```
