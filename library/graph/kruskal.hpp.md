---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/min_span_tree.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728"
  - icon: ':heavy_check_mark:'
    path: library/struct/union_find.hpp
    title: "UnionFind \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/mst_kruskal.test.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 - \u30AF\u30E9\u30B9\u30AB\u30EB\u306E\u30C6\
      \u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {\n    }\n};\n#line 3 \"library/graph/base/min_span_tree.hpp\"\nstruct MinSpanTree\
    \ {\n    long long cost;\n    vector<Edge> edges;\n};\n#line 2 \"library/struct/union_find.hpp\"\
    \nstruct UnionFind {\n  private:\n    vector<int> parent, size;\n\n  public:\n\
    \    UnionFind(int N) {\n        parent.assign(N, -1);\n        size.assign(N,\
    \ 1);\n    }\n    int operator[](int p) {\n        return size[find(p)];\n   \
    \ }\n    int find(int p) {\n        return !~parent[p] ? p : (parent[p] = find(parent[p]));\n\
    \    }\n    bool unite(int a, int b) {\n        int x = find(a), y = find(b);\n\
    \        if (x == y) return false;\n        if (size[x] > size[y]) swap(x, y);\n\
    \        parent[x] = y, size[y] += size[x];\n        return true;\n    }\n};\n\
    #line 4 \"library/graph/kruskal.hpp\"\nMinSpanTree kruskal(vector<Edge> edges,\
    \ int v_cnt) {\n    sort(edges.begin(), edges.end(),\n         [](const Edge &a,\
    \ const Edge &b) { return a.cost < b.cost; });\n    UnionFind uf(v_cnt);\n   \
    \ long long total = 0ll;\n    vector<Edge> es;\n    for (auto &&e : edges) {\n\
    \        if (uf.unite(e.from, e.to)) {\n            es.emplace_back(e);\n    \
    \        total += e.cost;\n        }\n    }\n    // \u5168\u57DF\u306B\u9054\u3057\
    \u306A\u3044\u5834\u5408\n    if (uf[0] < v_cnt) {\n        total = INF;\n   \
    \ }\n    return {total, es};\n}\n"
  code: "#pragma once\n#include \"library/graph/base/min_span_tree.hpp\"\n#include\
    \ \"library/struct/union_find.hpp\"\nMinSpanTree kruskal(vector<Edge> edges, int\
    \ v_cnt) {\n    sort(edges.begin(), edges.end(),\n         [](const Edge &a, const\
    \ Edge &b) { return a.cost < b.cost; });\n    UnionFind uf(v_cnt);\n    long long\
    \ total = 0ll;\n    vector<Edge> es;\n    for (auto &&e : edges) {\n        if\
    \ (uf.unite(e.from, e.to)) {\n            es.emplace_back(e);\n            total\
    \ += e.cost;\n        }\n    }\n    // \u5168\u57DF\u306B\u9054\u3057\u306A\u3044\
    \u5834\u5408\n    if (uf[0] < v_cnt) {\n        total = INF;\n    }\n    return\
    \ {total, es};\n}\n"
  dependsOn:
  - library/graph/base/min_span_tree.hpp
  - library/graph/base/edge.hpp
  - library/struct/union_find.hpp
  isVerificationFile: false
  path: library/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2026-01-13 19:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/mst_kruskal.test.cpp
documentation_of: library/graph/kruskal.hpp
layout: document
title: Kruskal
---

# Kruskal

## できること
- 最小全域木を求める
- edgesは中でソートしてる

## 計算量
$O(ElogV)$
- V: 頂点数
- E: 辺の数

## 使い方
```cpp
vector<Edge> edges;
MinSpanTree mst = kruskal(edges, V);
```
