---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/struct/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':warning:'
    path: library/struct/min_span_tree.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u8FBA"
    links: []
  bundledCode: "#line 2 \"library/struct/edge.hpp\"\n/**\n * @brief \u8FBA\n */\n\
    struct Edge {\n    int from, to;\n    long long cost;\n    Edge(int from, int\
    \ to, long long cost = 1)\n        : from(from), to(to), cost(cost) {\n    }\n\
    };\n"
  code: "#pragma once\n/**\n * @brief \u8FBA\n */\nstruct Edge {\n    int from, to;\n\
    \    long long cost;\n    Edge(int from, int to, long long cost = 1)\n       \
    \ : from(from), to(to), cost(cost) {\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/edge.hpp
  requiredBy:
  - library/struct/min_span_tree.hpp
  - library/struct/graph.hpp
  timestamp: '2026-01-03 22:41:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/struct/edge.hpp
layout: document
redirect_from:
- /library/library/struct/edge.hpp
- /library/library/struct/edge.hpp.html
title: "\u8FBA"
---
