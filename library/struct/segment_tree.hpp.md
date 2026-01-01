---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "SegmentTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
    links: []
  bundledCode: "#line 2 \"library/struct/segment_tree.hpp\"\n/**\n * @brief SegmentTree\
    \ 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97\n */\ntemplate <class Monoid> struct\
    \ SegmentTree {\n    using T = typename Monoid::T;\n\n  private:\n    Monoid M;\n\
    \    int N, size, log = 1;\n    vector<T> node;\n    void init() {\n        while\
    \ ((1 << log) < N) ++log;\n        node.assign((size = 1 << log) << 1, M.e());\n\
    \    }\n\n  public:\n    SegmentTree(Monoid M, int N) : M(M), N(N) {\n       \
    \ init();\n    }\n    SegmentTree(Monoid M, const vector<T> &A) : M(M), N(A.size())\
    \ {\n        init();\n        for (int i = 0; i < N; ++i) node[i + size] = A[i];\n\
    \        for (int i = size - 1; i >= 1; --i)\n            node[i] = M.op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u8981\u7D20i\u306E\u5024\u3092\
    x\u306B\u3059\u308B\n    void set(int i, const T &x) {\n        node[i += size]\
    \ = x;\n        while (i >>= 1) node[i] = M.op(node[i << 1 | 0], node[i << 1 |\
    \ 1]);\n    }\n    // \u6F14\u7B97[l,r)\n    T prod(int l, int r) {\n        T\
    \ L = M.e(), R = M.e();\n        for (l += size, r += size; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) L = M.op(L, node[l++]);\n            if (r\
    \ & 1) R = M.op(node[--r], R);\n        }\n        return M.op(L, R);\n    }\n\
    };\n"
  code: "#pragma once\n/**\n * @brief SegmentTree 1\u70B9\u66F4\u65B0 \u533A\u9593\
    \u53D6\u5F97\n */\ntemplate <class Monoid> struct SegmentTree {\n    using T =\
    \ typename Monoid::T;\n\n  private:\n    Monoid M;\n    int N, size, log = 1;\n\
    \    vector<T> node;\n    void init() {\n        while ((1 << log) < N) ++log;\n\
    \        node.assign((size = 1 << log) << 1, M.e());\n    }\n\n  public:\n   \
    \ SegmentTree(Monoid M, int N) : M(M), N(N) {\n        init();\n    }\n    SegmentTree(Monoid\
    \ M, const vector<T> &A) : M(M), N(A.size()) {\n        init();\n        for (int\
    \ i = 0; i < N; ++i) node[i + size] = A[i];\n        for (int i = size - 1; i\
    \ >= 1; --i)\n            node[i] = M.op(node[i << 1 | 0], node[i << 1 | 1]);\n\
    \    }\n    // \u8981\u7D20i\u306E\u5024\u3092x\u306B\u3059\u308B\n    void set(int\
    \ i, const T &x) {\n        node[i += size] = x;\n        while (i >>= 1) node[i]\
    \ = M.op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u6F14\u7B97[l,r)\n\
    \    T prod(int l, int r) {\n        T L = M.e(), R = M.e();\n        for (l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = M.op(L,\
    \ node[l++]);\n            if (r & 1) R = M.op(node[--r], R);\n        }\n   \
    \     return M.op(L, R);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/segment_tree.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-01 11:13:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/struct/segment_tree.hpp
layout: document
redirect_from:
- /library/library/struct/segment_tree.hpp
- /library/library/struct/segment_tree.hpp.html
title: "SegmentTree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
---
