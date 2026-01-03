---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\
      \u5F97"
    links: []
  bundledCode: "#line 2 \"library/struct/lazy_segment_tree.hpp\"\n/**\n * @brief Lazy\
    \ Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\u5F97\n * @note \u6F14\
    \u7B97op e \u66F4\u65B0op e \u4F5C\u7528op\n */\ntemplate <typename T, typename\
    \ U> struct LazySegmentTree {\n    using ProdOp = function<T(T, T)>;\n    using\
    \ UpdOp = function<U(U, U)>;\n    using ActOp = function<T(T, U, int)>;\n\n  private:\n\
    \    ProdOp prod_op;\n    UpdOp upd_op;\n    ActOp act_op;\n    T prod_e;\n  \
    \  U upd_e;\n    int N, size, log = 1;\n    vector<T> node;\n    vector<U> lazy;\n\
    \    void init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
    \ = 1ll << log) << 1, prod_e);\n        lazy.assign(size, upd_e);\n    }\n   \
    \ void update(int i) {\n        node[i] = prod_op(node[i << 1 | 0], node[i <<\
    \ 1 | 1]);\n    }\n    void apply_at(int k, U a) {\n        int topbit = k ==\
    \ 0 ? -1 : 31 - __builtin_clzll(k);\n        long long sz = 1 << (log - topbit);\n\
    \        node[k] = act_op(node[k], a, sz);\n        if (k < size) lazy[k] = upd_op(lazy[k],\
    \ a);\n    }\n    void propagate(int k) {\n        if (lazy[k] == upd_e) return;\n\
    \        apply_at((k << 1 | 0), lazy[k]);\n        apply_at((k << 1 | 1), lazy[k]);\n\
    \        lazy[k] = upd_e;\n    }\n\n  public:\n    LazySegmentTree(ProdOp prod_op,\
    \ T prod_e, UpdOp upd_op, U upd_e,\n                    ActOp act_op, int n)\n\
    \        : prod_op(prod_op), prod_e(prod_e), upd_op(upd_op), upd_e(upd_e),\n \
    \         act_op(act_op), N(n) {\n        init();\n    }\n    LazySegmentTree(ProdOp\
    \ prod_op, T prod_e, UpdOp upd_op, U upd_e,\n                    ActOp act_op,\
    \ const vector<T> &a)\n        : prod_op(prod_op), prod_e(prod_e), upd_op(upd_op),\
    \ upd_e(upd_e),\n          act_op(act_op), N(a.size()) {\n        init();\n  \
    \      for (int i = 0; i < N; ++i) node[i + size] = a[i];\n        for (int i\
    \ = size - 1; i >= 1; --i) update(i);\n    }\n    T operator[](int p) {\n    \
    \    p += size;\n        for (int i = log; i >= 1; --i) propagate(p >> i);\n \
    \       return node[p];\n    }\n    // \u5168\u533A\u9593\u3092\u53D6\u5F97\n\
    \    vector<T> getall() {\n        for (int i = 1; i < size; ++i) propagate(i);\n\
    \        return {node.begin() + size, node.begin() + size + N};\n    }\n    //\
    \ \u8981\u7D20p\u306B\u5024x\u3092\u4EE3\u5165\u3059\u308B\n    void set(int p,\
    \ const T &x) {\n        p += size;\n        for (int i = log; i >= 1; --i) propagate(p\
    \ >> i);\n        node[p] = x;\n        for (int i = 1; i <= log; ++i) update(p\
    \ >> i);\n    }\n    // \u6F14\u7B97[l, r)\n    T prod(int l, int r) {\n     \
    \   if (l == r) return prod_e;\n        l += size, r += size;\n        for (int\
    \ i = log; i >= 1; --i) {\n            if (((l >> i) << i) != l) propagate(l >>\
    \ i);\n            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n      \
    \  }\n        T L = prod_e, R = prod_e;\n        for (; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) L = prod_op(L, node[l++]);\n            if (r &\
    \ 1) R = prod_op(node[--r], R);\n        }\n        return prod_op(L, R);\n  \
    \  }\n    // \u5168\u533A\u9593\u3067\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\
    \u5F97\n    T top() {\n        return node[1];\n    }\n    // \u533A\u9593[l,\
    \ r)\u306B\u5024a\u3092\u4F5C\u7528\u3055\u305B\u308B\n    void apply(int l, int\
    \ r, U a) {\n        if (l == r) return;\n        l += size, r += size;\n    \
    \    for (int i = log; i >= 1; --i) {\n            if (((l >> i) << i) != l) propagate(l\
    \ >> i);\n            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n   \
    \     }\n        int l2 = l, r2 = r;\n        for (; l < r; l >>= 1, r >>= 1)\
    \ {\n            if (l & 1) apply_at(l++, a);\n            if (r & 1) apply_at(--r,\
    \ a);\n        }\n        l = l2, r = r2;\n        for (int i = 1; i <= log; ++i)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    template <typename\
    \ F> int max_right(const F &test, int L) {\n        if (L == N) return N;\n  \
    \      L += size;\n        for (int i = log; i >= 1; --i) propagate(L >> i);\n\
    \        T sm = prod_e;\n        do {\n            while (L % 2 == 0) L >>= 1;\n\
    \            if (!test(prod_op(sm, node[L]))) {\n                while (L < size)\
    \ {\n                    propagate(L);\n                    L = 2 * L;\n     \
    \               if (test(prod_op(sm, node[L]))) sm = prod_op(sm, node[L++]);\n\
    \                }\n                return L - size;\n            }\n        \
    \    sm = prod_op(sm, node[L++]);\n        } while ((L & -L) != L);\n        return\
    \ N;\n    }\n    template <typename F> int min_left(const F test, int R) {\n \
    \       if (R == 0) return 0;\n        R += size;\n        for (int i = log; i\
    \ >= 1; i--) propagate((R - 1) >> i);\n        T sm = prod_e;\n        do {\n\
    \            R--;\n            while (R > 1 && (R % 2)) R >>= 1;\n           \
    \ if (!test(prod_op(node[R], sm))) {\n                while (R < size) {\n   \
    \                 propagate(R);\n                    R = 2 * R + 1;\n        \
    \            if (test(prod_op(node[R], sm))) sm = prod_op(node[R--], sm);\n  \
    \              }\n                return R + 1 - size;\n            }\n      \
    \      sm = prod_op(node[R], sm);\n        } while ((R & -R) != R);\n        return\
    \ 0;\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\
    \u9593\u53D6\u5F97\n * @note \u6F14\u7B97op e \u66F4\u65B0op e \u4F5C\u7528op\n\
    \ */\ntemplate <typename T, typename U> struct LazySegmentTree {\n    using ProdOp\
    \ = function<T(T, T)>;\n    using UpdOp = function<U(U, U)>;\n    using ActOp\
    \ = function<T(T, U, int)>;\n\n  private:\n    ProdOp prod_op;\n    UpdOp upd_op;\n\
    \    ActOp act_op;\n    T prod_e;\n    U upd_e;\n    int N, size, log = 1;\n \
    \   vector<T> node;\n    vector<U> lazy;\n    void init() {\n        while ((1ll\
    \ << log) < N) ++log;\n        node.assign((size = 1ll << log) << 1, prod_e);\n\
    \        lazy.assign(size, upd_e);\n    }\n    void update(int i) {\n        node[i]\
    \ = prod_op(node[i << 1 | 0], node[i << 1 | 1]);\n    }\n    void apply_at(int\
    \ k, U a) {\n        int topbit = k == 0 ? -1 : 31 - __builtin_clzll(k);\n   \
    \     long long sz = 1 << (log - topbit);\n        node[k] = act_op(node[k], a,\
    \ sz);\n        if (k < size) lazy[k] = upd_op(lazy[k], a);\n    }\n    void propagate(int\
    \ k) {\n        if (lazy[k] == upd_e) return;\n        apply_at((k << 1 | 0),\
    \ lazy[k]);\n        apply_at((k << 1 | 1), lazy[k]);\n        lazy[k] = upd_e;\n\
    \    }\n\n  public:\n    LazySegmentTree(ProdOp prod_op, T prod_e, UpdOp upd_op,\
    \ U upd_e,\n                    ActOp act_op, int n)\n        : prod_op(prod_op),\
    \ prod_e(prod_e), upd_op(upd_op), upd_e(upd_e),\n          act_op(act_op), N(n)\
    \ {\n        init();\n    }\n    LazySegmentTree(ProdOp prod_op, T prod_e, UpdOp\
    \ upd_op, U upd_e,\n                    ActOp act_op, const vector<T> &a)\n  \
    \      : prod_op(prod_op), prod_e(prod_e), upd_op(upd_op), upd_e(upd_e),\n   \
    \       act_op(act_op), N(a.size()) {\n        init();\n        for (int i = 0;\
    \ i < N; ++i) node[i + size] = a[i];\n        for (int i = size - 1; i >= 1; --i)\
    \ update(i);\n    }\n    T operator[](int p) {\n        p += size;\n        for\
    \ (int i = log; i >= 1; --i) propagate(p >> i);\n        return node[p];\n   \
    \ }\n    // \u5168\u533A\u9593\u3092\u53D6\u5F97\n    vector<T> getall() {\n \
    \       for (int i = 1; i < size; ++i) propagate(i);\n        return {node.begin()\
    \ + size, node.begin() + size + N};\n    }\n    // \u8981\u7D20p\u306B\u5024x\u3092\
    \u4EE3\u5165\u3059\u308B\n    void set(int p, const T &x) {\n        p += size;\n\
    \        for (int i = log; i >= 1; --i) propagate(p >> i);\n        node[p] =\
    \ x;\n        for (int i = 1; i <= log; ++i) update(p >> i);\n    }\n    // \u6F14\
    \u7B97[l, r)\n    T prod(int l, int r) {\n        if (l == r) return prod_e;\n\
    \        l += size, r += size;\n        for (int i = log; i >= 1; --i) {\n   \
    \         if (((l >> i) << i) != l) propagate(l >> i);\n            if (((r >>\
    \ i) << i) != r) propagate((r - 1) >> i);\n        }\n        T L = prod_e, R\
    \ = prod_e;\n        for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1)\
    \ L = prod_op(L, node[l++]);\n            if (r & 1) R = prod_op(node[--r], R);\n\
    \        }\n        return prod_op(L, R);\n    }\n    // \u5168\u533A\u9593\u3067\
    \u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97\n    T top() {\n        return\
    \ node[1];\n    }\n    // \u533A\u9593[l, r)\u306B\u5024a\u3092\u4F5C\u7528\u3055\
    \u305B\u308B\n    void apply(int l, int r, U a) {\n        if (l == r) return;\n\
    \        l += size, r += size;\n        for (int i = log; i >= 1; --i) {\n   \
    \         if (((l >> i) << i) != l) propagate(l >> i);\n            if (((r >>\
    \ i) << i) != r) propagate((r - 1) >> i);\n        }\n        int l2 = l, r2 =\
    \ r;\n        for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) apply_at(l++,\
    \ a);\n            if (r & 1) apply_at(--r, a);\n        }\n        l = l2, r\
    \ = r2;\n        for (int i = 1; i <= log; ++i) {\n            if (((l >> i) <<\
    \ i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n        }\n    }\n    template <typename F> int max_right(const F\
    \ &test, int L) {\n        if (L == N) return N;\n        L += size;\n       \
    \ for (int i = log; i >= 1; --i) propagate(L >> i);\n        T sm = prod_e;\n\
    \        do {\n            while (L % 2 == 0) L >>= 1;\n            if (!test(prod_op(sm,\
    \ node[L]))) {\n                while (L < size) {\n                    propagate(L);\n\
    \                    L = 2 * L;\n                    if (test(prod_op(sm, node[L])))\
    \ sm = prod_op(sm, node[L++]);\n                }\n                return L -\
    \ size;\n            }\n            sm = prod_op(sm, node[L++]);\n        } while\
    \ ((L & -L) != L);\n        return N;\n    }\n    template <typename F> int min_left(const\
    \ F test, int R) {\n        if (R == 0) return 0;\n        R += size;\n      \
    \  for (int i = log; i >= 1; i--) propagate((R - 1) >> i);\n        T sm = prod_e;\n\
    \        do {\n            R--;\n            while (R > 1 && (R % 2)) R >>= 1;\n\
    \            if (!test(prod_op(node[R], sm))) {\n                while (R < size)\
    \ {\n                    propagate(R);\n                    R = 2 * R + 1;\n \
    \                   if (test(prod_op(node[R], sm))) sm = prod_op(node[R--], sm);\n\
    \                }\n                return R + 1 - size;\n            }\n    \
    \        sm = prod_op(node[R], sm);\n        } while ((R & -R) != R);\n      \
    \  return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-03 21:26:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
documentation_of: library/struct/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/library/struct/lazy_segment_tree.hpp
- /library/library/struct/lazy_segment_tree.hpp.html
title: "Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
---
