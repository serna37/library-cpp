---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.connected_components.connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\u30B9\
      \u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {\n    }\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n  private:\n\
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
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/connected_components/connected_components.hpp\"\
    \npair<vector<vector<int>>, vector<int>> connected_components(const Graph &G)\
    \ {\n    int N = G.size(), cnt = 0;\n    vector<vector<int>> groups;\n    vector<int>\
    \ ids(N, -1);\n    vector<int> com;\n    auto dfs = [&](auto &f, int v) -> void\
    \ {\n        ids[v] = cnt;\n        com.push_back(v);\n        for (auto &&[from,\
    \ to, cost, idx] : G[v]) {\n            if (ids[to] != -1) continue;\n       \
    \     f(f, to);\n        }\n    };\n    for (int i = 0; i < N; ++i) {\n      \
    \  if (ids[i] != -1) continue;\n        com.clear();\n        dfs(dfs, i);\n \
    \       groups.push_back(com);\n        ++cnt;\n    }\n    return {groups, ids};\n\
    }\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\npair<vector<vector<int>>,\
    \ vector<int>> connected_components(const Graph &G) {\n    int N = G.size(), cnt\
    \ = 0;\n    vector<vector<int>> groups;\n    vector<int> ids(N, -1);\n    vector<int>\
    \ com;\n    auto dfs = [&](auto &f, int v) -> void {\n        ids[v] = cnt;\n\
    \        com.push_back(v);\n        for (auto &&[from, to, cost, idx] : G[v])\
    \ {\n            if (ids[to] != -1) continue;\n            f(f, to);\n       \
    \ }\n    };\n    for (int i = 0; i < N; ++i) {\n        if (ids[i] != -1) continue;\n\
    \        com.clear();\n        dfs(dfs, i);\n        groups.push_back(com);\n\
    \        ++cnt;\n    }\n    return {groups, ids};\n}\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/connected_components/connected_components.hpp
  requiredBy: []
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.connected_components.connected_components.test.cpp
documentation_of: library/graph/connected_components/connected_components.hpp
layout: document
title: "\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

# 連結成分分解

## できること
- 連結な頂点群に分解する
  - `groups`: 連結な頂点群の集合
  - `ids` : ids[v] := 頂点vが属するgroupsのインデックス

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
auto [groups, ids] = connected_components(G);
```
