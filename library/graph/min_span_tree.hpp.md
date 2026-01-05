---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/struct/union_find.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728"
    links: []
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\n/**\n * @brief \u8FBA\n */\nstruct\
    \ Edge {\n    int from, to;\n    long long cost;\n    Edge(int from, int to, long\
    \ long cost = 1)\n        : from(from), to(to), cost(cost) {\n    }\n};\n#line\
    \ 2 \"library/struct/union_find.hpp\"\n/**\n * @brief UnionFind\n */\nstruct UnionFind\
    \ {\n  private:\n    vector<int> parent, size;\n\n  public:\n    UnionFind(int\
    \ N) {\n        parent.assign(N, -1);\n        size.assign(N, 1);\n    }\n   \
    \ // \u81EA\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\n    int\
    \ operator[](int p) {\n        return size[find(p)];\n    }\n    // p\u306E\u89AA\
    \u3092\u898B\u3064\u3051\u308B\n    int find(int p) {\n        return !~parent[p]\
    \ ? p : (parent[p] = find(parent[p]));\n    }\n    // a\u3068b\u3092\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B \u64CD\u4F5C\u3057\u305F\u3089true\n\
    \    bool unite(int a, int b) {\n        int x = find(a), y = find(b);\n     \
    \   if (x == y) return false;\n        if (size[x] > size[y]) swap(x, y);\n  \
    \      parent[x] = y, size[y] += size[x];\n        return true;\n    }\n};\n#line\
    \ 4 \"library/graph/min_span_tree.hpp\"\n/**\n * @brief \u6700\u5C0F\u5168\u57DF\
    \u6728\n */\nstruct MinSpanTree {\n    long long cost;\n    vector<Edge> edges;\n\
    };\n/**\n * \u30AF\u30E9\u30B9\u30AB\u30EB O(ElogV)\n * @return \u6700\u5C0F\u5168\
    \u57DF\u6728\n */\nMinSpanTree kruskal(vector<Edge> edges, int v_cnt) {\n    sort(edges.begin(),\
    \ edges.end(),\n         [](const Edge &a, const Edge &b) { return a.cost < b.cost;\
    \ });\n    UnionFind uf(v_cnt);\n    long long total = 0ll;\n    vector<Edge>\
    \ es;\n    for (auto &&e : edges) {\n        if (uf.unite(e.from, e.to)) {\n \
    \           es.emplace_back(e);\n            total += e.cost;\n        }\n   \
    \ }\n    // \u5168\u57DF\u306B\u9054\u3057\u306A\u3044\u5834\u5408\n    if (uf[0]\
    \ < v_cnt) {\n        total = INF;\n    }\n    return {total, es};\n}\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\n#include \"library/struct/union_find.hpp\"\
    \n/**\n * @brief \u6700\u5C0F\u5168\u57DF\u6728\n */\nstruct MinSpanTree {\n \
    \   long long cost;\n    vector<Edge> edges;\n};\n/**\n * \u30AF\u30E9\u30B9\u30AB\
    \u30EB O(ElogV)\n * @return \u6700\u5C0F\u5168\u57DF\u6728\n */\nMinSpanTree kruskal(vector<Edge>\
    \ edges, int v_cnt) {\n    sort(edges.begin(), edges.end(),\n         [](const\
    \ Edge &a, const Edge &b) { return a.cost < b.cost; });\n    UnionFind uf(v_cnt);\n\
    \    long long total = 0ll;\n    vector<Edge> es;\n    for (auto &&e : edges)\
    \ {\n        if (uf.unite(e.from, e.to)) {\n            es.emplace_back(e);\n\
    \            total += e.cost;\n        }\n    }\n    // \u5168\u57DF\u306B\u9054\
    \u3057\u306A\u3044\u5834\u5408\n    if (uf[0] < v_cnt) {\n        total = INF;\n\
    \    }\n    return {total, es};\n}\n"
  dependsOn:
  - library/graph/edge.hpp
  - library/struct/union_find.hpp
  isVerificationFile: false
  path: library/graph/min_span_tree.hpp
  requiredBy: []
  timestamp: '2026-01-05 21:30:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/min_span_tree.hpp
layout: document
redirect_from:
- /library/library/graph/min_span_tree.hpp
- /library/library/graph/min_span_tree.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728"
---
