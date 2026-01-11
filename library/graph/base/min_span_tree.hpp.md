---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: library/graph/base/edge.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/kruskal.hpp
    title: Kruskal
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
    \ {\n    long long cost;\n    vector<Edge> edges;\n};\n"
  code: "#pragma once\n#include \"library/graph/base/edge.hpp\"\nstruct MinSpanTree\
    \ {\n    long long cost;\n    vector<Edge> edges;\n};\n"
  dependsOn:
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/base/min_span_tree.hpp
  requiredBy:
  - library/graph/kruskal.hpp
  timestamp: '2026-01-11 17:31:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/mst_kruskal.test.cpp
documentation_of: library/graph/base/min_span_tree.hpp
layout: document
redirect_from:
- /library/library/graph/base/min_span_tree.hpp
- /library/library/graph/base/min_span_tree.hpp.html
title: library/graph/base/min_span_tree.hpp
---
