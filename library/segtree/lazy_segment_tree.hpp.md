---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid_act.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
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
    \            return x ^ y;\n        }\n    };\n};\n#line 3 \"library/struct/monoid_act.hpp\"\
    \n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20\n */\nstruct MonoidAct\
    \ {\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ AddAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            return node +\
    \ a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0\
    : \u4EE3\u5165\n    struct AddSet {\n        static constexpr int op(const int\
    \ &node, const int &a,\n                                const int &size) {\n \
    \           return a == Monoid::Set::e ? node : a * size;\n        }\n    };\n\
    \    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct\
    \ AddMin {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return min(node, a);\n        }\n    };\n    // \u6F14\u7B97\
    : \u52A0\u7B97  \u66F4\u65B0: \u6700\u5927\u5024\n    struct AddMax {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\
    \u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n        static constexpr\
    \ int op(const int &node, const int &a,\n                                const\
    \ int &size) {\n            (void)size; // unused\n            return node ==\
    \ Monoid::Min::e ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct MinSet {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ a == Monoid::Set::e ? node : a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct MinMin {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ min(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\
    \u65B0: \u6700\u5927\u5024\n    struct MinMax {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return max(node, a);\n\
    \        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u52A0\
    \u7B97\n    struct MaxAdd {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return node == Monoid::Max::e ? node :\
    \ node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\
    \u65B0: \u4EE3\u5165\n    struct MaxSet {\n        static constexpr int op(const\
    \ int &node, const int &a,\n                                const int &size) {\n\
    \            (void)size; // unused\n            return a == Monoid::Set::e ? node\
    \ : a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0\
    : \u6700\u5C0F\u5024\n    struct MaxMin {\n        static constexpr int op(const\
    \ int &node, const int &a,\n                                const int &size) {\n\
    \            (void)size; // unused\n            return min(node, a);\n       \
    \ }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u6700\u5927\
    \u5024\n    struct MaxMax {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return max(node, a);\n        }\n    };\n\
    };\n#line 4 \"library/segtree/lazy_segment_tree.hpp\"\ntemplate <typename T, typename\
    \ U> struct LazySegmentTree {\n    using ProdOp = function<T(T, T)>;\n    using\
    \ UpdOp = function<U(U, U)>;\n    using ActOp = function<T(T, U, int)>;\n\n  private:\n\
    \    ProdOp prod_op;\n    T prod_e;\n    UpdOp upd_op;\n    U upd_e;\n    ActOp\
    \ act_op;\n    int N, size, log = 1;\n    vector<T> node;\n    vector<U> lazy;\n\
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
    \       return node[p];\n    }\n    vector<T> getall() {\n        for (int i =\
    \ 1; i < size; ++i) propagate(i);\n        return {node.begin() + size, node.begin()\
    \ + size + N};\n    }\n    void set(int p, const T &x) {\n        p += size;\n\
    \        for (int i = log; i >= 1; --i) propagate(p >> i);\n        node[p] =\
    \ x;\n        for (int i = 1; i <= log; ++i) update(p >> i);\n    }\n    T prod(int\
    \ l, int r) {\n        if (l == r) return prod_e;\n        l += size, r += size;\n\
    \        for (int i = log; i >= 1; --i) {\n            if (((l >> i) << i) !=\
    \ l) propagate(l >> i);\n            if (((r >> i) << i) != r) propagate((r -\
    \ 1) >> i);\n        }\n        T L = prod_e, R = prod_e;\n        for (; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) L = prod_op(L, node[l++]);\n\
    \            if (r & 1) R = prod_op(node[--r], R);\n        }\n        return\
    \ prod_op(L, R);\n    }\n    T top() {\n        return node[1];\n    }\n    void\
    \ apply(int l, int r, U a) {\n        if (l == r) return;\n        l += size,\
    \ r += size;\n        for (int i = log; i >= 1; --i) {\n            if (((l >>\
    \ i) << i) != l) propagate(l >> i);\n            if (((r >> i) << i) != r) propagate((r\
    \ - 1) >> i);\n        }\n        int l2 = l, r2 = r;\n        for (; l < r; l\
    \ >>= 1, r >>= 1) {\n            if (l & 1) apply_at(l++, a);\n            if\
    \ (r & 1) apply_at(--r, a);\n        }\n        l = l2, r = r2;\n        for (int\
    \ i = 1; i <= log; ++i) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    template <typename F> int max_right(const F &test, int L) {\n        if (L\
    \ == N) return N;\n        L += size;\n        for (int i = log; i >= 1; --i)\
    \ propagate(L >> i);\n        T sm = prod_e;\n        do {\n            while\
    \ (L % 2 == 0) L >>= 1;\n            if (!test(prod_op(sm, node[L]))) {\n    \
    \            while (L < size) {\n                    propagate(L);\n         \
    \           L = 2 * L;\n                    if (test(prod_op(sm, node[L]))) sm\
    \ = prod_op(sm, node[L++]);\n                }\n                return L - size;\n\
    \            }\n            sm = prod_op(sm, node[L++]);\n        } while ((L\
    \ & -L) != L);\n        return N;\n    }\n    template <typename F> int min_left(const\
    \ F test, int R) {\n        if (R == 0) return 0;\n        R += size;\n      \
    \  for (int i = log; i >= 1; i--) propagate((R - 1) >> i);\n        T sm = prod_e;\n\
    \        do {\n            R--;\n            while (R > 1 && (R % 2)) R >>= 1;\n\
    \            if (!test(prod_op(node[R], sm))) {\n                while (R < size)\
    \ {\n                    propagate(R);\n                    R = 2 * R + 1;\n \
    \                   if (test(prod_op(node[R], sm))) sm = prod_op(node[R--], sm);\n\
    \                }\n                return R + 1 - size;\n            }\n    \
    \        sm = prod_op(node[R], sm);\n        } while ((R & -R) != R);\n      \
    \  return 0;\n    }\n};\n"
  code: "#pragma once\n#include \"library/struct/monoid.hpp\"\n#include \"library/struct/monoid_act.hpp\"\
    \ntemplate <typename T, typename U> struct LazySegmentTree {\n    using ProdOp\
    \ = function<T(T, T)>;\n    using UpdOp = function<U(U, U)>;\n    using ActOp\
    \ = function<T(T, U, int)>;\n\n  private:\n    ProdOp prod_op;\n    T prod_e;\n\
    \    UpdOp upd_op;\n    U upd_e;\n    ActOp act_op;\n    int N, size, log = 1;\n\
    \    vector<T> node;\n    vector<U> lazy;\n    void init() {\n        while ((1ll\
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
    \ }\n    vector<T> getall() {\n        for (int i = 1; i < size; ++i) propagate(i);\n\
    \        return {node.begin() + size, node.begin() + size + N};\n    }\n    void\
    \ set(int p, const T &x) {\n        p += size;\n        for (int i = log; i >=\
    \ 1; --i) propagate(p >> i);\n        node[p] = x;\n        for (int i = 1; i\
    \ <= log; ++i) update(p >> i);\n    }\n    T prod(int l, int r) {\n        if\
    \ (l == r) return prod_e;\n        l += size, r += size;\n        for (int i =\
    \ log; i >= 1; --i) {\n            if (((l >> i) << i) != l) propagate(l >> i);\n\
    \            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n        }\n \
    \       T L = prod_e, R = prod_e;\n        for (; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) L = prod_op(L, node[l++]);\n            if (r & 1) R =\
    \ prod_op(node[--r], R);\n        }\n        return prod_op(L, R);\n    }\n  \
    \  T top() {\n        return node[1];\n    }\n    void apply(int l, int r, U a)\
    \ {\n        if (l == r) return;\n        l += size, r += size;\n        for (int\
    \ i = log; i >= 1; --i) {\n            if (((l >> i) << i) != l) propagate(l >>\
    \ i);\n            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n      \
    \  }\n        int l2 = l, r2 = r;\n        for (; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) apply_at(l++, a);\n            if (r & 1) apply_at(--r,\
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
  dependsOn:
  - library/struct/monoid.hpp
  - library/struct/monoid_act.hpp
  isVerificationFile: false
  path: library/segtree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-08 21:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/lazy_segment_tree.test.cpp
documentation_of: library/segtree/lazy_segment_tree.hpp
layout: document
title: Lazy Segment Tree
---

# Lazy Segment Tree

## できること
- モノイドについて処理
- 区間[l, r)の値を更新
- 区間[l, r)の演算結果を取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 全要素の取得`getall`: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`prod`: $O(logN)$
- 全区間取得`top`: $O(1)$
- 木上の二分探索`max_right`: $O(logN)$
- 木上の二分探索`min_left`: $O(logN)$

## 使い方
```cpp
// 演算op e 更新op e 作用op
LazySegmentTree<int, int> seg(Monoid::Min::op, Monoid::Min::e, Monoid::Add::op, Monoid::Add::e, MonoidAct::MinAdd::op N);
```
