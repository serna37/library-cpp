---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
    links: []
  bundledCode: "#line 2 \"library/struct/segment_tree.hpp\"\n/**\n * @brief Segment\
    \ Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97\n */\ntemplate <typename T>\
    \ struct SegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n    F\
    \ op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void init()\
    \ {\n        while ((1ll << log) < N) ++log;\n        node.assign((size = 1ll\
    \ << log) << 1, e);\n    }\n\n  public:\n    SegmentTree(F op, T e, int N) : op(op),\
    \ e(e), N(N) {\n        init();\n    }\n    SegmentTree(F op, T e, const vector<T>\
    \ &A) : op(op), e(e), N(A.size()) {\n        init();\n        for (int i = 0;\
    \ i < N; ++i) node[i + size] = A[i];\n        for (int i = size - 1; i >= 1; --i)\n\
    \            node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    //\
    \ \u8981\u7D20i\u306E\u5024\u3092x\u306B\u3059\u308B\n    void set(int i, const\
    \ T &x) {\n        node[i += size] = x;\n        while (i >>= 1) node[i] = op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u6F14\u7B97[l,r)\n    T prod(int\
    \ l, int r) {\n        T L = e, R = e;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L, node[l++]);\n     \
    \       if (r & 1) R = op(node[--r], R);\n        }\n        return op(L, R);\n\
    \    }\n};\n"
  code: "#pragma once\n/**\n * @brief Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\
    \u53D6\u5F97\n */\ntemplate <typename T> struct SegmentTree {\n    using F = function<T(T,\
    \ T)>;\n\n  private:\n    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T>\
    \ node;\n    void init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
    \ = 1ll << log) << 1, e);\n    }\n\n  public:\n    SegmentTree(F op, T e, int\
    \ N) : op(op), e(e), N(N) {\n        init();\n    }\n    SegmentTree(F op, T e,\
    \ const vector<T> &A) : op(op), e(e), N(A.size()) {\n        init();\n       \
    \ for (int i = 0; i < N; ++i) node[i + size] = A[i];\n        for (int i = size\
    \ - 1; i >= 1; --i)\n            node[i] = op(node[i << 1 | 0], node[i << 1 |\
    \ 1]);\n    }\n    // \u8981\u7D20i\u306E\u5024\u3092x\u306B\u3059\u308B\n   \
    \ void set(int i, const T &x) {\n        node[i += size] = x;\n        while (i\
    \ >>= 1) node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u6F14\
    \u7B97[l,r)\n    T prod(int l, int r) {\n        T L = e, R = e;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L\
    \ = op(L, node[l++]);\n            if (r & 1) R = op(node[--r], R);\n        }\n\
    \        return op(L, R);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-03 21:52:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.segment_tree.test.cpp
documentation_of: library/struct/segment_tree.hpp
layout: document
redirect_from:
- /library/library/struct/segment_tree.hpp
- /library/library/struct/segment_tree.hpp.html
title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
---
