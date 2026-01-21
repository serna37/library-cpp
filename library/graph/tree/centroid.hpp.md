---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/tree_isomorphism.hpp
    title: "\u6728\u306E\u540C\u578B\u6027\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.tree_isomorphism.test.cpp
    title: "\u6728 - \u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n  private:\n\
    \    int N;\n    vector<vector<Edge>> G;\n    int es;\n\n  public:\n    Graph(int\
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
    };\n#line 3 \"library/graph/tree/centroid.hpp\"\nvector<int> centroid(const Graph\
    \ &G) {\n    const int N = (int)G.size();\n    stack<pair<int, int>> st;\n   \
    \ st.emplace(0ll, -1ll);\n    vector<int> sz(N), par(N);\n    while (!st.empty())\
    \ {\n        auto p = st.top();\n        if (sz[p.first] == 0ll) {\n         \
    \   sz[p.first] = 1;\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) st.emplace(to, p.first);\n          \
    \  }\n        } else {\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) sz[p.first] += sz[to];\n            }\n\
    \            par[p.first] = p.second;\n            st.pop();\n        }\n    }\n\
    \    vector<int> ret;\n    int size = N;\n    for (int i = 0; i < N; ++i) {\n\
    \        int val = N - sz[i];\n        for (auto &&[from, to, cost, idx] : G[i])\
    \ {\n            if (to != par[i]) val = max(val, sz[to]);\n        }\n      \
    \  if (val < size) size = val, ret.clear();\n        if (val == size) ret.emplace_back(i);\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\nvector<int> centroid(const\
    \ Graph &G) {\n    const int N = (int)G.size();\n    stack<pair<int, int>> st;\n\
    \    st.emplace(0ll, -1ll);\n    vector<int> sz(N), par(N);\n    while (!st.empty())\
    \ {\n        auto p = st.top();\n        if (sz[p.first] == 0ll) {\n         \
    \   sz[p.first] = 1;\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) st.emplace(to, p.first);\n          \
    \  }\n        } else {\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) sz[p.first] += sz[to];\n            }\n\
    \            par[p.first] = p.second;\n            st.pop();\n        }\n    }\n\
    \    vector<int> ret;\n    int size = N;\n    for (int i = 0; i < N; ++i) {\n\
    \        int val = N - sz[i];\n        for (auto &&[from, to, cost, idx] : G[i])\
    \ {\n            if (to != par[i]) val = max(val, sz[to]);\n        }\n      \
    \  if (val < size) size = val, ret.clear();\n        if (val == size) ret.emplace_back(i);\n\
    \    }\n    return ret;\n}\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/tree/centroid.hpp
  requiredBy:
  - library/graph/tree/tree_isomorphism.hpp
  timestamp: '2026-01-21 10:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.tree_isomorphism.test.cpp
documentation_of: library/graph/tree/centroid.hpp
layout: document
title: "\u6728\u306E\u91CD\u5FC3"
---

# 木の重心

## できること
- 木の重心を求める
- 重心 $\cdots$ その頂点を取り除いたときにできる部分木たちの頂点数が、全て半分以下になる
- 重心はは1個か2個存在する

## 計算量
$O(V)$

## 使い方
```cpp
int N;
Graph G(N);
vector<int> C = centroid(G);
```

