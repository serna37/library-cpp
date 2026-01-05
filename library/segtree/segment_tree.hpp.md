---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
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
    \            return x ^ y;\n        }\n    };\n};\n/**\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\u4F5C\u7528\n */\nstruct MonoidAct {\n    // \u6F14\u7B97: \u52A0\
    \u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct AddAdd {\n        static constexpr\
    \ int op(const int &node, const int &a,\n                                const\
    \ int &size) {\n            return node + a * size;\n        }\n    };\n    //\
    \ \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u4EE3\u5165\n    struct AddSet {\n\
    \        static constexpr int op(const int &node, const int &a,\n            \
    \                    const int &size) {\n            return a == Monoid::Set::e\
    \ ? node : a * size;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024\
    \  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return node == Monoid::Min::e\
    \ ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024\
    \  \u66F4\u65B0: \u4EE3\u5165\n    struct MinSet {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return a == Monoid::Set::e\
    \ ? node : a;\n        }\n    };\n    // TODO \u3082\u3063\u3068\u5897\u3084\u3059\
    \n};\n#line 3 \"library/segtree/segment_tree.hpp\"\n/**\n * @brief Segment Tree\
    \ 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97\n */\ntemplate <typename T> struct\
    \ SegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n    F op;\n \
    \   T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void init() {\n\
    \        while ((1ll << log) < N) ++log;\n        node.assign((size = 1ll << log)\
    \ << 1, e);\n    }\n\n  public:\n    SegmentTree(F op, T e, int N) : op(op), e(e),\
    \ N(N) {\n        init();\n    }\n    SegmentTree(F op, T e, const vector<T> &A)\
    \ : op(op), e(e), N(A.size()) {\n        init();\n        for (int i = 0; i <\
    \ N; ++i) node[i + size] = A[i];\n        for (int i = size - 1; i >= 1; --i)\n\
    \            node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    //\
    \ \u8981\u7D20i\u306E\u5024\u3092x\u306B\u3059\u308B\n    void set(int i, const\
    \ T &x) {\n        node[i += size] = x;\n        while (i >>= 1) node[i] = op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u6F14\u7B97[l,r)\n    T prod(int\
    \ l, int r) {\n        T L = e, R = e;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L, node[l++]);\n     \
    \       if (r & 1) R = op(node[--r], R);\n        }\n        return op(L, R);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"library/struct/monoid.hpp\"\n/**\n * @brief Segment\
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
  dependsOn:
  - library/struct/monoid.hpp
  isVerificationFile: false
  path: library/segtree/segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-05 20:31:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.segment_tree.test.cpp
documentation_of: library/segtree/segment_tree.hpp
layout: document
redirect_from:
- /library/library/segtree/segment_tree.hpp
- /library/library/segtree/segment_tree.hpp.html
title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
---
