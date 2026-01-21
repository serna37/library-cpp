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
    path: tests/graph.tree.convert_rooted_tree.test.cpp
    title: "\u6728 - \u6839\u4ED8\u304D\u6728\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n    int N;\n\
    \    vector<vector<Edge>> G;\n    int es;\n    Graph() = default;\n    Graph(int\
    \ N) : N(N), G(N), es(0) {}\n    const vector<Edge> &operator[](int v) const {\
    \ return G[v]; }\n    int size() const { return N; }\n    void add(int from, int\
    \ to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost, es++));\n\
    \    }\n    void add_both(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es));\n        G[to].push_back(Edge(to, from, cost, es++));\n    }\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int u, v;\n            cin >> u >> v;\n            u += padding, v += padding;\n\
    \            long long cost = 1ll;\n            if (weighted) cin >> cost;\n \
    \           if (directed) {\n                add(u, v, cost);\n            } else\
    \ {\n                add_both(u, v, cost);\n            }\n        }\n    }\n\
    };\n#line 3 \"library/graph/tree/convert_rooted_tree.hpp\"\nGraph convert_rooted_tree(const\
    \ Graph &G, int r = 0) {\n    int N = (int)G.size();\n    Graph rg(N);\n    vector<int>\
    \ v(N);\n    v[r] = 1;\n    queue<int> que;\n    que.emplace(r);\n    while (!que.empty())\
    \ {\n        auto p = que.front();\n        que.pop();\n        for (auto &&edge\
    \ : G[p]) {\n            if (v[edge.to] == 0ll) {\n                v[edge.to]\
    \ = 1;\n                que.emplace(edge.to);\n                rg.G[p].emplace_back(edge);\n\
    \            }\n        }\n    }\n    return rg;\n}\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\nGraph convert_rooted_tree(const\
    \ Graph &G, int r = 0) {\n    int N = (int)G.size();\n    Graph rg(N);\n    vector<int>\
    \ v(N);\n    v[r] = 1;\n    queue<int> que;\n    que.emplace(r);\n    while (!que.empty())\
    \ {\n        auto p = que.front();\n        que.pop();\n        for (auto &&edge\
    \ : G[p]) {\n            if (v[edge.to] == 0ll) {\n                v[edge.to]\
    \ = 1;\n                que.emplace(edge.to);\n                rg.G[p].emplace_back(edge);\n\
    \            }\n        }\n    }\n    return rg;\n}\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/tree/convert_rooted_tree.hpp
  requiredBy: []
  timestamp: '2026-01-21 14:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.convert_rooted_tree.test.cpp
documentation_of: library/graph/tree/convert_rooted_tree.hpp
layout: document
title: "\u6839\u4ED8\u304D\u6728\u5909\u63DB"
---

# 根付き木変換

## できること
- 無向グラフな木を、「親から子への方向」をもつ、有向グラフな木に変換する
- BFSを用いて、指定した頂点から遠ざかる方向にのみ辺を張り直している

## 計算量
$O(N + M)$ Nは頂点数、Mは辺の数

## 使い方
```cpp
Graph rG = convert_rooted_tree(G, 0);
```

