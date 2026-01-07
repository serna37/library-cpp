---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/kruskal.hpp
    title: "\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\nstruct Edge {\n    int from, to;\n\
    \    long long cost;\n    int idx;\n    Edge(int from, int to, long long cost\
    \ = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {\n \
    \   }\n};\n#line 3 \"library/graph/min_span_tree.hpp\"\nstruct MinSpanTree {\n\
    \    long long cost;\n    vector<Edge> edges;\n};\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\nstruct MinSpanTree {\n\
    \    long long cost;\n    vector<Edge> edges;\n};"
  dependsOn:
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/min_span_tree.hpp
  requiredBy:
  - library/graph/kruskal.hpp
  timestamp: '2026-01-07 15:59:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/mst_kruskal.test.cpp
documentation_of: library/graph/min_span_tree.hpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6728"
---

# 最小全域木

## できること
- 最小全域木の構造体
  - `cost`: 全域の総コスト。全域に達しない場合、INF
  - `edges`: 全域に達するための`vector<Edge>`

## 計算量
なし

## 使い方
```cpp
vector<Edge> edges;
MinSpanTree mst = kruskal(edges, V);
mst.cost;
mst.edges;
```
