---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/struct/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728"
    links: []
  bundledCode: "#line 2 \"library/struct/edge.hpp\"\n/**\n * @brief \u8FBA\n */\n\
    struct Edge {\n    int from, to;\n    long long cost;\n    Edge(int from, int\
    \ to, long long cost = 1)\n        : from(from), to(to), cost(cost) {\n    }\n\
    };\n#line 3 \"library/struct/min_span_tree.hpp\"\n/**\n * @brief \u6700\u5C0F\u5168\
    \u57DF\u6728\n */\nstruct MinSpanTree {\n    long long cost;\n    vector<Edge>\
    \ edges;\n};\n// TODO \u30AF\u30E9\u30B9\u30AB\u30EB\n"
  code: "#pragma once\n#include \"library/struct/edge.hpp\"\n/**\n * @brief \u6700\
    \u5C0F\u5168\u57DF\u6728\n */\nstruct MinSpanTree {\n    long long cost;\n   \
    \ vector<Edge> edges;\n};\n// TODO \u30AF\u30E9\u30B9\u30AB\u30EB\n"
  dependsOn:
  - library/struct/edge.hpp
  isVerificationFile: false
  path: library/struct/min_span_tree.hpp
  requiredBy: []
  timestamp: '2026-01-03 22:41:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/struct/min_span_tree.hpp
layout: document
redirect_from:
- /library/library/struct/min_span_tree.hpp
- /library/library/struct/min_span_tree.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728"
---
