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
    path: tests/graph/bellman_ford.test.cpp
    title: "\u30B0\u30E9\u30D5 - BellmanFord\u306E\u30C6\u30B9\u30C8"
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
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/bellman_ford.hpp\"\n\
    tuple<vector<long long>, bool, vector<int>> bellman_ford(const Graph &G,\n   \
    \                                                      int s = 0) {\n    int N\
    \ = G.size(), loop = 0;\n    vector<long long> dis(N, INF);\n    vector<int> route(N,\
    \ -1);\n    dis[s] = 0;\n    while (1) {\n        ++loop;\n        bool upd =\
    \ 0;\n        for (int v = 0; v < N; ++v) {\n            if (dis[v] == INF) continue;\n\
    \            for (auto &&[from, to, cost, idx] : G[v]) {\n                long\
    \ long asis = dis[to], tobe = dis[v] + cost;\n                if (dis[v] == -INF)\
    \ tobe = -INF;\n                tobe = max(tobe, -INF);\n                if (asis\
    \ <= tobe) continue;\n                if (loop >= N) tobe = -INF;\n          \
    \      dis[to] = tobe;\n                route[to] = v;\n                upd =\
    \ 1;\n            }\n        }\n        if (!upd) break;\n    }\n    bool negativeCycle\
    \ = false;\n    for (auto &&v : dis) {\n        if (v == -INF) {\n           \
    \ negativeCycle = true;\n            break;\n        }\n    }\n    return {dis,\
    \ negativeCycle, route};\n}\n"
  code: "#pragma once\n#include \"library/graph/graph.hpp\"\ntuple<vector<long long>,\
    \ bool, vector<int>> bellman_ford(const Graph &G,\n                          \
    \                               int s = 0) {\n    int N = G.size(), loop = 0;\n\
    \    vector<long long> dis(N, INF);\n    vector<int> route(N, -1);\n    dis[s]\
    \ = 0;\n    while (1) {\n        ++loop;\n        bool upd = 0;\n        for (int\
    \ v = 0; v < N; ++v) {\n            if (dis[v] == INF) continue;\n           \
    \ for (auto &&[from, to, cost, idx] : G[v]) {\n                long long asis\
    \ = dis[to], tobe = dis[v] + cost;\n                if (dis[v] == -INF) tobe =\
    \ -INF;\n                tobe = max(tobe, -INF);\n                if (asis <=\
    \ tobe) continue;\n                if (loop >= N) tobe = -INF;\n             \
    \   dis[to] = tobe;\n                route[to] = v;\n                upd = 1;\n\
    \            }\n        }\n        if (!upd) break;\n    }\n    bool negativeCycle\
    \ = false;\n    for (auto &&v : dis) {\n        if (v == -INF) {\n           \
    \ negativeCycle = true;\n            break;\n        }\n    }\n    return {dis,\
    \ negativeCycle, route};\n}\n"
  dependsOn:
  - library/graph/graph.hpp
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2026-01-07 21:37:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/bellman_ford.test.cpp
documentation_of: library/graph/bellman_ford.hpp
layout: document
title: Bellman Ford
---

# Bellman Ford

## できること
- 最小コストを求める
- 負の重みOK
  - `s`: 始点（デフォルト0）
  - `dis`: dis[v] := 頂点vまでの最小コスト
  - `negativeCycle`: 負の閉路がある場合true
  - `route`: 経路復元用の配列

## 計算量
$O(VE)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [dis, negativeCycle, route] = bellman_ford(G, s);
```
