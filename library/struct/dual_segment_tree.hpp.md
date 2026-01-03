---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/struct.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97"
    links: []
  bundledCode: "#line 2 \"library/struct/dual_segment_tree.hpp\"\n/**\n * @brief Dual\
    \ Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97\n */\ntemplate <typename\
    \ T> struct DualSegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n\
    \    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void\
    \ init() {\n        while ((1 << log) < N) ++log;\n        node.assign((size =\
    \ 1 << log) << 1, e);\n    }\n    void apply_at(int k, T a) {\n        node[k]\
    \ = op(node[k], a);\n    }\n    void propagate(int k) {\n        if (node[k] ==\
    \ e) return;\n        apply_at((k << 1 | 0), node[k]);\n        apply_at((k <<\
    \ 1 | 1), node[k]);\n        node[k] = e;\n    }\n\n  public:\n    DualSegmentTree(F\
    \ op, T e, int n) : op(op), e(e), N(n) {\n        init();\n    }\n    DualSegmentTree(F\
    \ op, T e, const vector<T> &a) : op(op), e(e), N(a.size()) {\n        init();\n\
    \        for (int i = 0; i < N; ++i) node[i + size] = a[i];\n    }\n    T operator[](int\
    \ p) {\n        p += size;\n        for (int i = log; i >= 1; --i) propagate(p\
    \ >> i);\n        return node[p];\n    }\n    void set(int p, const T &x) {\n\
    \        p += size;\n        apply_at(p, x);\n        node[p] = x;\n    }\n  \
    \  void apply(int l, int r, const T &a) {\n        if (l == r) return;\n     \
    \   l += size, r += size;\n        for (int i = log; i >= 1; --i) {\n        \
    \    if (((l >> i) << i) != l) propagate(l >> i);\n            if (((r >> i) <<\
    \ i) != r) propagate((r - 1) >> i);\n        }\n        while (l < r) {\n    \
    \        if (l & 1) apply_at(l++, a);\n            if (r & 1) apply_at(--r, a);\n\
    \            l >>= 1, r >>= 1;\n        }\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\
    \u53D6\u5F97\n */\ntemplate <typename T> struct DualSegmentTree {\n    using F\
    \ = function<T(T, T)>;\n\n  private:\n    F op;\n    T e;\n    int N, size, log\
    \ = 1;\n    vector<T> node;\n    void init() {\n        while ((1 << log) < N)\
    \ ++log;\n        node.assign((size = 1 << log) << 1, e);\n    }\n    void apply_at(int\
    \ k, T a) {\n        node[k] = op(node[k], a);\n    }\n    void propagate(int\
    \ k) {\n        if (node[k] == e) return;\n        apply_at((k << 1 | 0), node[k]);\n\
    \        apply_at((k << 1 | 1), node[k]);\n        node[k] = e;\n    }\n\n  public:\n\
    \    DualSegmentTree(F op, T e, int n) : op(op), e(e), N(n) {\n        init();\n\
    \    }\n    DualSegmentTree(F op, T e, const vector<T> &a) : op(op), e(e), N(a.size())\
    \ {\n        init();\n        for (int i = 0; i < N; ++i) node[i + size] = a[i];\n\
    \    }\n    T operator[](int p) {\n        p += size;\n        for (int i = log;\
    \ i >= 1; --i) propagate(p >> i);\n        return node[p];\n    }\n    void set(int\
    \ p, const T &x) {\n        p += size;\n        apply_at(p, x);\n        node[p]\
    \ = x;\n    }\n    void apply(int l, int r, const T &a) {\n        if (l == r)\
    \ return;\n        l += size, r += size;\n        for (int i = log; i >= 1; --i)\
    \ {\n            if (((l >> i) << i) != l) propagate(l >> i);\n            if\
    \ (((r >> i) << i) != r) propagate((r - 1) >> i);\n        }\n        while (l\
    \ < r) {\n            if (l & 1) apply_at(l++, a);\n            if (r & 1) apply_at(--r,\
    \ a);\n            l >>= 1, r >>= 1;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-03 21:07:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/struct.dual_segment_tree.test.cpp
documentation_of: library/struct/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/library/struct/dual_segment_tree.hpp
- /library/library/struct/dual_segment_tree.hpp.html
title: "Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97"
---
