---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/struct/monoid.hpp\"\n/**\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\n */\nstruct Monoid {\n    // \u6700\u5C0F\u5024\n    struct Min\
    \ {\n        static constexpr int e = INT_MAX;\n        static int op(int x, int\
    \ y) {\n            return min(x, y);\n        }\n    };\n    // \u6700\u5927\u5024\
    \n    struct Max {\n        static constexpr int e = -INT_MAX;\n        static\
    \ int op(int x, int y) {\n            return max(x, y);\n        }\n    };\n \
    \   // \u52A0\u7B97\n    struct Add {\n        static constexpr int e = 0;\n \
    \       static int op(int x, int y) {\n            return x + y;\n        }\n\
    \    };\n    // \u4E57\u7B97\n    struct Mul {\n        static constexpr int e\
    \ = 1;\n        static int op(int x, int y) {\n            return x * y;\n   \
    \     }\n    };\n    // \u4EE3\u5165\n    struct Set {\n        static constexpr\
    \ int e = INT_MAX;\n        static int op(int x, int y) {\n            return\
    \ y == INT_MAX ? x : y;\n        }\n    };\n    // \u6700\u5927\u516C\u7D04\u6570\
    \n    struct Gcd {\n        static constexpr int e = 0;\n        static int op(int\
    \ x, int y) {\n            return gcd(x, y);\n        }\n    };\n    // \u6700\
    \u5C0F\u516C\u500D\u6570\n    struct Lcm {\n        static constexpr int e = 1;\n\
    \        static int op(int x, int y) {\n            return lcm(x, y);\n      \
    \  }\n    };\n    // \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n    struct Xor {\n\
    \        static constexpr int e = 0;\n        static int op(int x, int y) {\n\
    \            return x ^ y;\n        }\n    };\n};\n#line 3 \"library/segtree/segment_tree.hpp\"\
    \ntemplate <typename T> struct SegmentTree {\n    using F = function<T(T, T)>;\n\
    \n  private:\n    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n\
    \    void init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
    \ = 1ll << log) << 1, e);\n    }\n\n  public:\n    SegmentTree(F op, T e, int\
    \ N) : op(op), e(e), N(N) {\n        init();\n    }\n    SegmentTree(F op, T e,\
    \ const vector<T> &A) : op(op), e(e), N(A.size()) {\n        init();\n       \
    \ for (int i = 0; i < N; ++i) node[i + size] = A[i];\n        for (int i = size\
    \ - 1; i >= 1; --i)\n            node[i] = op(node[i << 1 | 0], node[i << 1 |\
    \ 1]);\n    }\n    void set(int i, const T &x) {\n        node[i += size] = x;\n\
    \        while (i >>= 1) node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n \
    \   }\n    T prod(int l, int r) {\n        T L = e, R = e;\n        for (l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L,\
    \ node[l++]);\n            if (r & 1) R = op(node[--r], R);\n        }\n     \
    \   return op(L, R);\n    }\n};\n"
  code: "#pragma once\n#include \"library/struct/monoid.hpp\"\ntemplate <typename\
    \ T> struct SegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n  \
    \  F op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void init()\
    \ {\n        while ((1ll << log) < N) ++log;\n        node.assign((size = 1ll\
    \ << log) << 1, e);\n    }\n\n  public:\n    SegmentTree(F op, T e, int N) : op(op),\
    \ e(e), N(N) {\n        init();\n    }\n    SegmentTree(F op, T e, const vector<T>\
    \ &A) : op(op), e(e), N(A.size()) {\n        init();\n        for (int i = 0;\
    \ i < N; ++i) node[i + size] = A[i];\n        for (int i = size - 1; i >= 1; --i)\n\
    \            node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    void\
    \ set(int i, const T &x) {\n        node[i += size] = x;\n        while (i >>=\
    \ 1) node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    T prod(int\
    \ l, int r) {\n        T L = e, R = e;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L, node[l++]);\n     \
    \       if (r & 1) R = op(node[--r], R);\n        }\n        return op(L, R);\n\
    \    }\n};\n"
  dependsOn:
  - library/struct/monoid.hpp
  isVerificationFile: false
  path: library/segtree/segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-08 23:00:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/segment_tree.test.cpp
documentation_of: library/segtree/segment_tree.hpp
layout: document
title: Segment Tree
---

# Segment Tree

## できること
- モノイドについて処理
- 1点の値を更新
- 区間[l, r)の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間取得`prod`: $O(logN)$

## 使い方
```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```
