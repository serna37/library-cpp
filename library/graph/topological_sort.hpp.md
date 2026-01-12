---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/cycle_detect.hpp
    title: "\u9589\u8DEF\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/cycle_detect.hpp\"\n\
    vector<Edge> cycle_detect(const Graph &G, bool directed = true) {\n    int N =\
    \ G.size();\n    vector<bool> seen(N), finished(N);\n    vector<Edge> history;\n\
    \    auto dfs = [&](auto &f, int v, const Edge &e) -> int {\n        seen[v] =\
    \ true;\n        history.push_back(e);\n        for (const auto &ne : G[v]) {\n\
    \            auto [from, to, cost, idx] = ne;\n            if (!directed and to\
    \ == e.from) continue;\n            if (finished[to]) continue;\n            if\
    \ (seen[to] and !finished[to]) {\n                history.push_back(ne);\n   \
    \             return to;\n            }\n            int pos = f(f, to, ne);\n\
    \            if (pos != -1) return pos;\n        }\n        finished[v] = true;\n\
    \        history.pop_back();\n        return -1;\n    };\n    auto restruct =\
    \ [&](int pos) -> vector<Edge> {\n        vector<Edge> cycle;\n        while (!history.empty())\
    \ {\n            const Edge e = history.back();\n            cycle.push_back(e);\n\
    \            history.pop_back();\n            if (e.from == pos) break;\n    \
    \    }\n        reverse(cycle.begin(), cycle.end());\n        return cycle;\n\
    \    };\n    int pos = -1;\n    for (int v = 0; v < N and pos == -1; ++v) {\n\
    \        if (seen[v]) continue;\n        history.clear();\n        pos = dfs(dfs,\
    \ v, Edge({-1, -1, -1, -1}));\n        if (pos != -1) return restruct(pos);\n\
    \    }\n    return vector<Edge>();\n}\n#line 3 \"library/graph/topological_sort.hpp\"\
    \nvector<int> topological_sort(const Graph &G) {\n    if (cycle_detect(G).size()\
    \ != 0) return vector<int>();\n    int N = G.size();\n    vector<int> seen(N,\
    \ 0), sorted;\n    auto dfs = [&](auto &f, int v) -> void {\n        seen[v] =\
    \ 1;\n        for (auto &&[from, to, cost, idx] : G[v]) {\n            if (!seen[to])\
    \ f(f, to);\n        }\n        sorted.push_back(v);\n    };\n    for (int i =\
    \ 0; i < N; ++i) {\n        if (!seen[i]) dfs(dfs, i);\n    }\n    reverse(sorted.begin(),\
    \ sorted.end());\n    return sorted;\n}\n"
  code: "#pragma once\n#include \"library/graph/cycle_detect.hpp\"\nvector<int> topological_sort(const\
    \ Graph &G) {\n    if (cycle_detect(G).size() != 0) return vector<int>();\n  \
    \  int N = G.size();\n    vector<int> seen(N, 0), sorted;\n    auto dfs = [&](auto\
    \ &f, int v) -> void {\n        seen[v] = 1;\n        for (auto &&[from, to, cost,\
    \ idx] : G[v]) {\n            if (!seen[to]) f(f, to);\n        }\n        sorted.push_back(v);\n\
    \    };\n    for (int i = 0; i < N; ++i) {\n        if (!seen[i]) dfs(dfs, i);\n\
    \    }\n    reverse(sorted.begin(), sorted.end());\n    return sorted;\n}\n"
  dependsOn:
  - library/graph/cycle_detect.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2026-01-12 21:43:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/topological_sort.test.cpp
documentation_of: library/graph/topological_sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---

# トポロジカルソート

## できること
- DAGをトポロジカルソートする
- 閉路がある場合は空配列を返却

## 計算量
$O(V+E)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<int> sorted = topological_sort(G);
```
