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
    path: tests/graph/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5 - Dijkstra\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
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
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/dijkstra.hpp\"\ntemplate\
    \ <typename T> using rev_pq = priority_queue<T, vector<T>, greater<T>>;\npair<vector<long\
    \ long>, vector<int>> dijkstra(const Graph &G,\n                             \
    \                 const vector<int> &starts = {0}) {\n    int N = G.size();\n\
    \    rev_pq<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\u3044\u9806\
    ), \u9802\u70B9\n    vector<long long> weight(N, INF);\n    vector<int> route(N,\
    \ -1);\n    for (auto &&v : starts) q.emplace(0, v), weight[v] = 0;\n    while\
    \ (!q.empty()) {\n        auto [w, v] = q.top();\n        q.pop();\n        if\
    \ (weight[v] < w) continue;\n        for (auto &&[from, to, cost, idx] : G[v])\
    \ {\n            long long next_w = w + cost;\n            if (weight[to] <= next_w)\
    \ continue;\n            weight[to] = next_w;\n            q.emplace(weight[to],\
    \ to);\n            route[to] = v;\n        }\n    }\n    return {weight, route};\n\
    }\n"
  code: "#pragma once\n#include \"library/graph/graph.hpp\"\ntemplate <typename T>\
    \ using rev_pq = priority_queue<T, vector<T>, greater<T>>;\npair<vector<long long>,\
    \ vector<int>> dijkstra(const Graph &G,\n                                    \
    \          const vector<int> &starts = {0}) {\n    int N = G.size();\n    rev_pq<pair<long\
    \ long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\u3044\u9806), \u9802\u70B9\
    \n    vector<long long> weight(N, INF);\n    vector<int> route(N, -1);\n    for\
    \ (auto &&v : starts) q.emplace(0, v), weight[v] = 0;\n    while (!q.empty())\
    \ {\n        auto [w, v] = q.top();\n        q.pop();\n        if (weight[v] <\
    \ w) continue;\n        for (auto &&[from, to, cost, idx] : G[v]) {\n        \
    \    long long next_w = w + cost;\n            if (weight[to] <= next_w) continue;\n\
    \            weight[to] = next_w;\n            q.emplace(weight[to], to);\n  \
    \          route[to] = v;\n        }\n    }\n    return {weight, route};\n}\n"
  dependsOn:
  - library/graph/graph.hpp
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2026-01-08 22:37:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
  - tests/graph/route_restore.test.cpp
documentation_of: library/graph/dijkstra.hpp
layout: document
title: Dijkstra
---

# Dijkstra

## できること
- 最小コストを求める
- 複数始点
  - `starts`: 始点の配列（デフォルト0）
  - `weight`: dis[v] := 頂点vまでの最小コスト
  - `route`: 経路復元用の配列

## 計算量
$O(ElogV)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [weight, route] = dijkstra(G, {r});
```
