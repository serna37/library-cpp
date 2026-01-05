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
    };\n// TODO \u30AF\u30E9\u30B9\u30AB\u30EB\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\n#include \"library/struct/union_find.hpp\"\
    \n/**\n * @brief \u6700\u5C0F\u5168\u57DF\u6728\n */\nstruct MinSpanTree {\n \
    \   long long cost;\n    vector<Edge> edges;\n};\n// TODO \u30AF\u30E9\u30B9\u30AB\
    \u30EB\n"
  dependsOn:
  - library/graph/edge.hpp
  - library/struct/union_find.hpp
  isVerificationFile: false
  path: library/graph/min_span_tree.hpp
  requiredBy: []
  timestamp: '2026-01-05 20:31:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/min_span_tree.hpp
layout: document
redirect_from:
- /library/library/graph/min_span_tree.hpp
- /library/library/graph/min_span_tree.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728"
---
