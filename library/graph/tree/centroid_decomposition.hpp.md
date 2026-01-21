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
    path: tests/graph.tree.centroid_decomposition.test.cpp
    title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.centroid_decomposition2.test.cpp
    title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C82"
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
    };\n#line 3 \"library/graph/tree/centroid_decomposition.hpp\"\nstruct CentroidDecomposition\
    \ : Graph {\n  public:\n    using Graph::Graph;\n    using Graph::G;\n    Graph\
    \ tree;\n    int build() {\n        sub.assign(G.size(), 0ll);\n        v.assign(G.size(),\
    \ 0ll);\n        tree = Graph(G.size());\n        return build_dfs(0ll);\n   \
    \ }\n    explicit CentroidDecomposition(const Graph &G) : Graph(G) {}\n\n  private:\n\
    \    vector<int> sub;\n    vector<int> v;\n    inline int build_dfs(int idx, int\
    \ par) {\n        sub[idx] = 1;\n        for (auto &&edge : G[idx]) {\n      \
    \      if (edge.to == par or v[edge.to]) continue;\n            sub[idx] += build_dfs(edge.to,\
    \ idx);\n        }\n        return sub[idx];\n    }\n    inline int search_centroid(int\
    \ idx, int par, const int mid) {\n        for (auto &&edge : G[idx]) {\n     \
    \       if (edge.to == par or v[edge.to]) continue;\n            if (sub[edge.to]\
    \ > mid) return search_centroid(edge.to, idx, mid);\n        }\n        return\
    \ idx;\n    }\n    inline int build_dfs(int idx) {\n        int centroid = search_centroid(idx,\
    \ -1, build_dfs(idx, -1) / 2ll);\n        v[centroid] = true;\n        for (auto\
    \ &&edge : G[centroid]) {\n            if (!v[edge.to]) tree.add(centroid, build_dfs(edge.to));\n\
    \        }\n        v[centroid] = false;\n        return centroid;\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\nstruct CentroidDecomposition\
    \ : Graph {\n  public:\n    using Graph::Graph;\n    using Graph::G;\n    Graph\
    \ tree;\n    int build() {\n        sub.assign(G.size(), 0ll);\n        v.assign(G.size(),\
    \ 0ll);\n        tree = Graph(G.size());\n        return build_dfs(0ll);\n   \
    \ }\n    explicit CentroidDecomposition(const Graph &G) : Graph(G) {}\n\n  private:\n\
    \    vector<int> sub;\n    vector<int> v;\n    inline int build_dfs(int idx, int\
    \ par) {\n        sub[idx] = 1;\n        for (auto &&edge : G[idx]) {\n      \
    \      if (edge.to == par or v[edge.to]) continue;\n            sub[idx] += build_dfs(edge.to,\
    \ idx);\n        }\n        return sub[idx];\n    }\n    inline int search_centroid(int\
    \ idx, int par, const int mid) {\n        for (auto &&edge : G[idx]) {\n     \
    \       if (edge.to == par or v[edge.to]) continue;\n            if (sub[edge.to]\
    \ > mid) return search_centroid(edge.to, idx, mid);\n        }\n        return\
    \ idx;\n    }\n    inline int build_dfs(int idx) {\n        int centroid = search_centroid(idx,\
    \ -1, build_dfs(idx, -1) / 2ll);\n        v[centroid] = true;\n        for (auto\
    \ &&edge : G[centroid]) {\n            if (!v[edge.to]) tree.add(centroid, build_dfs(edge.to));\n\
    \        }\n        v[centroid] = false;\n        return centroid;\n    }\n};\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2026-01-21 11:49:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.centroid_decomposition.test.cpp
  - tests/graph.tree.centroid_decomposition2.test.cpp
documentation_of: library/graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3"
---

# 重心分解

## できること
- 重心分解とは、以下を再帰的に行い、木を階層構造に作り替える
  1. 現在の木から重心を見つける
  1. 重心でポッキリする。（重心を「分解後の木の根」とし、重心を木から取り除く）
  1. 分割した各々の木に対して、1から繰り返す
- 重心で分けるたび部分木のサイズが半分以下になるため、再帰の深さは必ず対数オーダーに収まる
- これにより、「重心分解ツリー」が作られる
  - 元の木における任意の2頂点間のパスは、重心分解ツリーにおける「ある頂点の共通の先祖」を経由するものとして分類できる
  - 木の分割統治ができるため「木上のパスのうち条件 $X$ を満たすものはいくつか？」等が高速で求まる

## 計算量
- 構築: $O(V \log V)$

## 使い方
```cpp
int N, M;
CentroidDecomposition cd(N);
cd.read(M); // グラフ構造体と同様に作成

// 重心分解を実行。戻り値は重心分解ツリー全体の根
int root = cd.build();

// cd.tree に重心分解後の親子関係が格納される
// ex) cd.tree.g[u] には、重心分解ツリーにおける u の子リストが入る
```

