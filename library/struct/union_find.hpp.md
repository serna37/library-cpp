---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/mst_kruskal.test.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 - \u30AF\u30E9\u30B9\u30AB\u30EB\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/struct/union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/struct/union_find.hpp\"\nstruct UnionFind {\n  private:\n\
    \    vector<int> parent, size;\n\n  public:\n    UnionFind(int N) {\n        parent.assign(N,\
    \ -1);\n        size.assign(N, 1);\n    }\n    int operator[](int p) {\n     \
    \   return size[find(p)];\n    }\n    int find(int p) {\n        return !~parent[p]\
    \ ? p : (parent[p] = find(parent[p]));\n    }\n    bool unite(int a, int b) {\n\
    \        int x = find(a), y = find(b);\n        if (x == y) return false;\n  \
    \      if (size[x] > size[y]) swap(x, y);\n        parent[x] = y, size[y] += size[x];\n\
    \        return true;\n    }\n};\n"
  code: "#pragma once\nstruct UnionFind {\n  private:\n    vector<int> parent, size;\n\
    \n  public:\n    UnionFind(int N) {\n        parent.assign(N, -1);\n        size.assign(N,\
    \ 1);\n    }\n    int operator[](int p) {\n        return size[find(p)];\n   \
    \ }\n    int find(int p) {\n        return !~parent[p] ? p : (parent[p] = find(parent[p]));\n\
    \    }\n    bool unite(int a, int b) {\n        int x = find(a), y = find(b);\n\
    \        if (x == y) return false;\n        if (size[x] > size[y]) swap(x, y);\n\
    \        parent[x] = y, size[y] += size[x];\n        return true;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/union_find.hpp
  requiredBy:
  - library/graph/kruskal.hpp
  timestamp: '2026-01-08 22:08:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/mst_kruskal.test.cpp
  - tests/struct/union_find.test.cpp
documentation_of: library/struct/union_find.hpp
layout: document
title: "UnionFind \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
---

# UnionFind 素集合データ構造

## できること
- 集合をつなげたり。切れはしない

## 計算量
- 構築: $O(N)$
- 自分のグループサイズ`uf[p]`: $O(α(N))$
- 自分の親を見つける`find`: $O(α(N))$
- 同じグループにする`unite`: $O(α(N))$

## 使い方
```cpp
UnionFind uf(N);
int sz = uf[p];
if (uf.unite(a, b)) {
    // つなげた場合
}
if (uf.find(a) == uf.find(b)) {
    // 同じグループである
}
```
