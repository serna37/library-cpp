---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/various/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/dual_segment_tree.hpp\"\n#include <functional>\n\
    #line 2 \"library/various/monoid.hpp\"\n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\
    \n */\nstruct Monoid {\n    // \u6700\u5C0F\u5024\n    struct Min {\n        static\
    \ constexpr int e = INT_MAX;\n        static int op(int x, int y) {\n        \
    \    return min(x, y);\n        }\n    };\n    // \u6700\u5927\u5024\n    struct\
    \ Max {\n        static constexpr int e = -INT_MAX;\n        static int op(int\
    \ x, int y) {\n            return max(x, y);\n        }\n    };\n    // \u52A0\
    \u7B97\n    struct Add {\n        static constexpr int e = 0;\n        static\
    \ int op(int x, int y) {\n            return x + y;\n        }\n    };\n    //\
    \ \u4E57\u7B97\n    struct Mul {\n        static constexpr int e = 1;\n      \
    \  static int op(int x, int y) {\n            return x * y;\n        }\n    };\n\
    \    // \u4EE3\u5165\n    struct Set {\n        static constexpr int e = INT_MAX;\n\
    \        static int op(int x, int y) {\n            return y == INT_MAX ? x :\
    \ y;\n        }\n    };\n    // \u6700\u5927\u516C\u7D04\u6570\n    struct Gcd\
    \ {\n        static constexpr int e = 0;\n        static int op(int x, int y)\
    \ {\n            return gcd(x, y);\n        }\n    };\n    // \u6700\u5C0F\u516C\
    \u500D\u6570\n    struct Lcm {\n        static constexpr int e = 1;\n        static\
    \ int op(int x, int y) {\n            return lcm(x, y);\n        }\n    };\n \
    \   // \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n    struct Xor {\n        static\
    \ constexpr int e = 0;\n        static int op(int x, int y) {\n            return\
    \ x ^ y;\n        }\n    };\n};\n#line 4 \"library/segtree/dual_segment_tree.hpp\"\
    \ntemplate <typename T> struct DualSegmentTree {\n    using F = function<T(T,\
    \ T)>;\n\n  private:\n    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T>\
    \ node;\n    void init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
    \ = 1ll << log) << 1, e);\n    }\n    void apply_at(int k, T a) {\n        node[k]\
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
  code: "#pragma once\n#include <functional>\n#include \"library/various/monoid.hpp\"\
    \ntemplate <typename T> struct DualSegmentTree {\n    using F = function<T(T,\
    \ T)>;\n\n  private:\n    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T>\
    \ node;\n    void init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
    \ = 1ll << log) << 1, e);\n    }\n    void apply_at(int k, T a) {\n        node[k]\
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
  dependsOn:
  - library/various/monoid.hpp
  isVerificationFile: false
  path: library/segtree/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/dual_segment_tree.test.cpp
documentation_of: library/segtree/dual_segment_tree.hpp
layout: document
title: Dual Segment Tree
---

# Dual Segment Tree

## できること
- モノイドについて処理
- 区間[l, r)の値を更新
- 1点の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$

## 使い方
```cpp
DualSegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```
