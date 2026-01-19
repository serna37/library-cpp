---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/segtree/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':question:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':question:'
    path: library/segtree/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: library/segtree/segment_tree.hpp
    title: Segment Tree
  - icon: ':x:'
    path: library/segtree/starry_sky_tree.hpp
    title: Starry Sky Tree
  - icon: ':question:'
    path: library/various/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':question:'
    path: library/various/monoid_act.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/segtree.unified_segment_tree.test.cpp
    title: "\u7D71\u5408\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/unified_segment_tree.hpp\"\n#include <variant>\n\
    #include <type_traits>\n#include <functional>\n\n#line 2 \"library/various/monoid.hpp\"\
    \n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\n */\nstruct Monoid {\n    // \u6700\
    \u5C0F\u5024\n    struct Min {\n        static constexpr int e = INT_MAX;\n  \
    \      static int op(int x, int y) {\n            return min(x, y);\n        }\n\
    \    };\n    // \u6700\u5927\u5024\n    struct Max {\n        static constexpr\
    \ int e = -INT_MAX;\n        static int op(int x, int y) {\n            return\
    \ max(x, y);\n        }\n    };\n    // \u52A0\u7B97\n    struct Add {\n     \
    \   static constexpr int e = 0;\n        static int op(int x, int y) {\n     \
    \       return x + y;\n        }\n    };\n    // \u4E57\u7B97\n    struct Mul\
    \ {\n        static constexpr int e = 1;\n        static int op(int x, int y)\
    \ {\n            return x * y;\n        }\n    };\n    // \u4EE3\u5165\n    struct\
    \ Set {\n        static constexpr int e = INT_MAX;\n        static int op(int\
    \ x, int y) {\n            return y == INT_MAX ? x : y;\n        }\n    };\n \
    \   // \u6700\u5927\u516C\u7D04\u6570\n    struct Gcd {\n        static constexpr\
    \ int e = 0;\n        static int op(int x, int y) {\n            return gcd(x,\
    \ y);\n        }\n    };\n    // \u6700\u5C0F\u516C\u500D\u6570\n    struct Lcm\
    \ {\n        static constexpr int e = 1;\n        static int op(int x, int y)\
    \ {\n            return lcm(x, y);\n        }\n    };\n    // \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n    struct Xor {\n        static constexpr int e = 0;\n  \
    \      static int op(int x, int y) {\n            return x ^ y;\n        }\n \
    \   };\n};\n#line 4 \"library/segtree/dual_segment_tree.hpp\"\ntemplate <typename\
    \ T> struct DualSegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n\
    \    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void\
    \ init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
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
    \            l >>= 1, r >>= 1;\n        }\n    }\n};\n#line 2 \"library/segtree/fenwick_tree.hpp\"\
    \nstruct FenwickTree {\n  private:\n    int N;\n    vector<int> fwk;\n\n  public:\n\
    \    FenwickTree(int N) : N(N) {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const\
    \ vector<int> &A) : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for\
    \ (int i = 1; i <= N; ++i) {\n            fwk[i] += A[i - 1];\n            if\
    \ (i + (i & -i) <= N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    void\
    \ add(int i, const int &x) {\n        for (++i; i <= N; i += i & -i) fwk[i] +=\
    \ x;\n    }\n    int sum(int i) {\n        int ans = 0;\n        for (++i; i;\
    \ i -= i & -i) ans += fwk[i];\n        return ans;\n    }\n};\n#line 3 \"library/various/monoid_act.hpp\"\
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
    };\n#line 5 \"library/segtree/lazy_segment_tree.hpp\"\ntemplate <typename T, typename\
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
    \  return 0;\n    }\n};\n#line 4 \"library/segtree/segment_tree.hpp\"\ntemplate\
    \ <typename T> struct SegmentTree {\n    using F = function<T(T, T)>;\n\n  private:\n\
    \    F op;\n    T e;\n    int N, size, log = 1;\n    vector<T> node;\n    void\
    \ init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((size\
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
    \   return op(L, R);\n    }\n};\n#line 2 \"library/segtree/starry_sky_tree.hpp\"\
    \ntemplate <bool is_min_mode = true> struct StarrySkyTree {\n  private:\n    int\
    \ N, sz, log = 1;\n    const int INF = 1e9;\n    vector<int> node;\n    int compare(int\
    \ a, int b) {\n        if constexpr (is_min_mode) {\n            return min(a,\
    \ b);\n        } else {\n            return max(a, b);\n        }\n    }\n   \
    \ int unit_element() {\n        return is_min_mode ? INF : -INF;\n    }\n    void\
    \ init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((sz =\
    \ 1ll << log) << 1, 0);\n    }\n    int _star(int i) {\n        int val = compare(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n        node[i << 1 | 0] -= val;\n        node[i\
    \ << 1 | 1] -= val;\n        return val;\n    }\n    void star(int i) {\n    \
    \    node[i] += _star(i);\n    }\n    int sum(int i) {\n        int ans = node[i];\n\
    \        while (i >>= 1) ans += node[i];\n        return ans;\n    }\n\n  public:\n\
    \    StarrySkyTree(int n) : N(n) {\n        init();\n    }\n    StarrySkyTree(const\
    \ vector<int> &a) : N(a.size()) {\n        init();\n        for (int i = 0; i\
    \ < N; ++i) node[i + sz] = a[i];\n        for (int i = sz - 1; i >= 1; --i) node[i]\
    \ = _star(i);\n    }\n    int operator[](int i) {\n        return sum(i + sz);\n\
    \    }\n    void apply(int l, int r, const int &v) {\n        if (l >= r) return;\n\
    \        int l_bak = l + sz, r_bak = r + sz - 1;\n        for (l += sz, r += sz;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) node[l++] += v;\n       \
    \     if (r & 1) node[--r] += v;\n        }\n        for (int i = l_bak >> 1;\
    \ i >= 1; i >>= 1) star(i);\n        for (int i = r_bak >> 1; i >= 1; i >>= 1)\
    \ star(i);\n    }\n    void set(int p, const int &x) {\n        apply(p, p + 1,\
    \ x - sum(p + sz));\n    }\n    int prod(int l, int r) {\n        if (l >= r)\
    \ return unit_element();\n        int ans = unit_element();\n        for (l +=\
    \ sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) ans = compare(ans,\
    \ sum(l++));\n            if (r & 1) ans = compare(ans, sum(--r));\n        }\n\
    \        return ans;\n    }\n};\n#line 13 \"library/segtree/unified_segment_tree.hpp\"\
    \n\nenum class RangeType { Single, Range };\n\ntemplate <typename ProdMonoid,\
    \ typename UpdMonoid = ProdMonoid, typename Act = void>\nstruct UnifiedSegmentTree\
    \ {\n    // std::decay_t \u3092\u4F7F\u3063\u3066 const \u3084\u53C2\u7167\u3092\
    \u9664\u53BB\u3057\u305F\u7D14\u7C8B\u306A\u578B\u3092\u53D6\u5F97\u3059\u308B\
    \n    using T = std::decay_t<decltype(ProdMonoid::e)>;\n    using U = std::decay_t<decltype(UpdMonoid::e)>;\n\
    \n    using VariantType = std::variant<\n        std::monostate,\n        SegmentTree<T>,\n\
    \        DualSegmentTree<U>,\n        LazySegmentTree<T, U>,\n        FenwickTree,\n\
    \        StarrySkyTree<true>,\n        StarrySkyTree<false>\n    >;\n\n  private:\n\
    \    VariantType tree;\n    int N;\n\n    // \u5206\u5C90\u30ED\u30B8\u30C3\u30AF\
    \uFF1Aupd_t, prod_t \u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u5224\u5B9A\
    \u3067\u304D\u306A\u3044\u305F\u3081\u3001\n    // if constexpr \u3067\u306F\u306A\
    \u304F\u901A\u5E38\u306E if \u3067\u5206\u5C90\u3055\u305B\u308B\u304B\u3001\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306B\u79FB\u52D5\u3055\u305B\u308B\
    \u5FC5\u8981\u304C\u3042\u308A\u307E\u3059\u3002\n    // \u4ECA\u56DE\u306F\u4F7F\
    \u3044\u52DD\u624B\u3092\u512A\u5148\u3057\u3001\u5B9F\u884C\u6642\u306E if \u5206\
    \u5C90\u3067 variant \u306B\u4EE3\u5165\u3057\u307E\u3059\u3002\n    template\
    \ <typename InitData>\n    void construct(int n, const InitData& data, RangeType\
    \ upd_t, RangeType prod_t) {\n        N = n;\n        constexpr bool is_vec =\
    \ !std::is_integral_v<InitData>;\n\n        // 1. \u661F\u7A7A\u6728 (\u578B\u5224\
    \u5B9A\u306E\u307F\u306A\u306E\u3067 if constexpr \u304C\u4F7F\u3048\u308B)\n\
    \        if constexpr (std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid,\
    \ Monoid::Min>) {\n            if constexpr (is_vec) tree.template emplace<StarrySkyTree<true>>(data);\n\
    \            else tree.template emplace<StarrySkyTree<true>>(N);\n        }\n\
    \        else if constexpr (std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid,\
    \ Monoid::Max>) {\n            if constexpr (is_vec) tree.template emplace<StarrySkyTree<false>>(data);\n\
    \            else tree.template emplace<StarrySkyTree<false>>(N);\n        }\n\
    \        // 2. Fenwick Tree (upd_t \u306F\u5B9F\u884C\u6642\u5909\u6570\u306A\u306E\
    \u3067\u901A\u5E38\u306E if)\n        else if (upd_t == RangeType::Single && prod_t\
    \ == RangeType::Range &&\n                 std::is_same_v<UpdMonoid, Monoid::Add>\
    \ && std::is_same_v<ProdMonoid, Monoid::Add> && std::is_same_v<T, long long>)\
    \ {\n             // \u30E6\u30FC\u30B6\u30FC\u74B0\u5883\u306B\u5408\u308F\u305B\
    \u3066 int/long long \u306F\u8ABF\u6574\u304C\u5FC5\u8981\u3067\u3059\u304C\u3001\
    \u3053\u3053\u3067\u306F A \u306E\u578B\u306B\u5408\u308F\u305B\u307E\u3059\n\
    \             if constexpr (is_vec) tree.template emplace<FenwickTree>(data);\n\
    \             else tree.template emplace<FenwickTree>(N);\n        }\n       \
    \ // 3. Segment Tree (Point Update / Range Product)\n        else if (upd_t ==\
    \ RangeType::Single && prod_t == RangeType::Range) {\n            if constexpr\
    \ (is_vec) tree.template emplace<SegmentTree<T>>(ProdMonoid::op, ProdMonoid::e,\
    \ data);\n            else tree.template emplace<SegmentTree<T>>(ProdMonoid::op,\
    \ ProdMonoid::e, N);\n        }\n        // 4. Dual Segment Tree (Range Update\
    \ / Point Get)\n        else if (upd_t == RangeType::Range && prod_t == RangeType::Single)\
    \ {\n            if constexpr (is_vec) tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op,\
    \ UpdMonoid::e, data);\n            else tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op,\
    \ UpdMonoid::e, N);\n        }\n        // 5. Lazy Segment Tree\n        else\
    \ {\n            static_assert(!std::is_void_v<Act>, \"LazySegmentTree requires\
    \ an Act operator.\");\n            if constexpr (is_vec) tree.template emplace<LazySegmentTree<T,\
    \ U>>(ProdMonoid::op, ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, data);\n\
    \            else tree.template emplace<LazySegmentTree<T, U>>(ProdMonoid::op,\
    \ ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, N);\n        }\n    }\n\
    \n  public:\n    UnifiedSegmentTree(int n, RangeType upd_t, RangeType prod_t)\
    \ {\n        construct(n, n, upd_t, prod_t);\n    }\n\n    UnifiedSegmentTree(const\
    \ std::vector<T>& a, RangeType upd_t, RangeType prod_t) {\n        construct(a.size(),\
    \ a, upd_t, prod_t);\n    }\n\n    void update(int l, int r, U x) {\n        std::visit([&](auto&&\
    \ t) {\n            using VT = std::decay_t<decltype(t)>;\n            if constexpr\
    \ (std::is_same_v<VT, StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>>\
    \ ||\n                          std::is_same_v<VT, DualSegmentTree<U>> || std::is_same_v<VT,\
    \ LazySegmentTree<T, U>>) {\n                t.apply(l, r, x);\n            }\
    \ else if constexpr (std::is_same_v<VT, SegmentTree<T>>) {\n                t.set(l,\
    \ x);\n            } else if constexpr (std::is_same_v<VT, FenwickTree>) {\n \
    \               t.add(l, x);\n            }\n        }, tree);\n    }\n\n    T\
    \ query(int l, int r) {\n        return std::visit([&](auto&& t) -> T {\n    \
    \        using VT = std::decay_t<decltype(t)>;\n            if constexpr (std::is_same_v<VT,\
    \ StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>> ||\n      \
    \                    std::is_same_v<VT, SegmentTree<T>> || std::is_same_v<VT,\
    \ LazySegmentTree<T, U>>) {\n                return t.prod(l, r);\n          \
    \  } else if constexpr (std::is_same_v<VT, DualSegmentTree<U>>) {\n          \
    \      return t[l];\n            } else if constexpr (std::is_same_v<VT, FenwickTree>)\
    \ {\n                return t.sum(r - 1) - t.sum(l - 1);\n            }\n    \
    \        return (T)ProdMonoid::e;\n        }, tree);\n    }\n};\n"
  code: "#pragma once\n#include <variant>\n#include <type_traits>\n#include <functional>\n\
    \n#include \"library/segtree/dual_segment_tree.hpp\"\n#include \"library/segtree/fenwick_tree.hpp\"\
    \n#include \"library/segtree/lazy_segment_tree.hpp\"\n#include \"library/segtree/segment_tree.hpp\"\
    \n#include \"library/segtree/starry_sky_tree.hpp\"\n#include \"library/various/monoid.hpp\"\
    \n#include \"library/various/monoid_act.hpp\"\n\nenum class RangeType { Single,\
    \ Range };\n\ntemplate <typename ProdMonoid, typename UpdMonoid = ProdMonoid,\
    \ typename Act = void>\nstruct UnifiedSegmentTree {\n    // std::decay_t \u3092\
    \u4F7F\u3063\u3066 const \u3084\u53C2\u7167\u3092\u9664\u53BB\u3057\u305F\u7D14\
    \u7C8B\u306A\u578B\u3092\u53D6\u5F97\u3059\u308B\n    using T = std::decay_t<decltype(ProdMonoid::e)>;\n\
    \    using U = std::decay_t<decltype(UpdMonoid::e)>;\n\n    using VariantType\
    \ = std::variant<\n        std::monostate,\n        SegmentTree<T>,\n        DualSegmentTree<U>,\n\
    \        LazySegmentTree<T, U>,\n        FenwickTree,\n        StarrySkyTree<true>,\n\
    \        StarrySkyTree<false>\n    >;\n\n  private:\n    VariantType tree;\n \
    \   int N;\n\n    // \u5206\u5C90\u30ED\u30B8\u30C3\u30AF\uFF1Aupd_t, prod_t \u306F\
    \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u5224\u5B9A\u3067\u304D\u306A\u3044\
    \u305F\u3081\u3001\n    // if constexpr \u3067\u306F\u306A\u304F\u901A\u5E38\u306E\
    \ if \u3067\u5206\u5C90\u3055\u305B\u308B\u304B\u3001\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\u5F15\u6570\u306B\u79FB\u52D5\u3055\u305B\u308B\u5FC5\u8981\u304C\u3042\
    \u308A\u307E\u3059\u3002\n    // \u4ECA\u56DE\u306F\u4F7F\u3044\u52DD\u624B\u3092\
    \u512A\u5148\u3057\u3001\u5B9F\u884C\u6642\u306E if \u5206\u5C90\u3067 variant\
    \ \u306B\u4EE3\u5165\u3057\u307E\u3059\u3002\n    template <typename InitData>\n\
    \    void construct(int n, const InitData& data, RangeType upd_t, RangeType prod_t)\
    \ {\n        N = n;\n        constexpr bool is_vec = !std::is_integral_v<InitData>;\n\
    \n        // 1. \u661F\u7A7A\u6728 (\u578B\u5224\u5B9A\u306E\u307F\u306A\u306E\
    \u3067 if constexpr \u304C\u4F7F\u3048\u308B)\n        if constexpr (std::is_same_v<UpdMonoid,\
    \ Monoid::Add> && std::is_same_v<ProdMonoid, Monoid::Min>) {\n            if constexpr\
    \ (is_vec) tree.template emplace<StarrySkyTree<true>>(data);\n            else\
    \ tree.template emplace<StarrySkyTree<true>>(N);\n        }\n        else if constexpr\
    \ (std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid, Monoid::Max>)\
    \ {\n            if constexpr (is_vec) tree.template emplace<StarrySkyTree<false>>(data);\n\
    \            else tree.template emplace<StarrySkyTree<false>>(N);\n        }\n\
    \        // 2. Fenwick Tree (upd_t \u306F\u5B9F\u884C\u6642\u5909\u6570\u306A\u306E\
    \u3067\u901A\u5E38\u306E if)\n        else if (upd_t == RangeType::Single && prod_t\
    \ == RangeType::Range &&\n                 std::is_same_v<UpdMonoid, Monoid::Add>\
    \ && std::is_same_v<ProdMonoid, Monoid::Add> && std::is_same_v<T, long long>)\
    \ {\n             // \u30E6\u30FC\u30B6\u30FC\u74B0\u5883\u306B\u5408\u308F\u305B\
    \u3066 int/long long \u306F\u8ABF\u6574\u304C\u5FC5\u8981\u3067\u3059\u304C\u3001\
    \u3053\u3053\u3067\u306F A \u306E\u578B\u306B\u5408\u308F\u305B\u307E\u3059\n\
    \             if constexpr (is_vec) tree.template emplace<FenwickTree>(data);\n\
    \             else tree.template emplace<FenwickTree>(N);\n        }\n       \
    \ // 3. Segment Tree (Point Update / Range Product)\n        else if (upd_t ==\
    \ RangeType::Single && prod_t == RangeType::Range) {\n            if constexpr\
    \ (is_vec) tree.template emplace<SegmentTree<T>>(ProdMonoid::op, ProdMonoid::e,\
    \ data);\n            else tree.template emplace<SegmentTree<T>>(ProdMonoid::op,\
    \ ProdMonoid::e, N);\n        }\n        // 4. Dual Segment Tree (Range Update\
    \ / Point Get)\n        else if (upd_t == RangeType::Range && prod_t == RangeType::Single)\
    \ {\n            if constexpr (is_vec) tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op,\
    \ UpdMonoid::e, data);\n            else tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op,\
    \ UpdMonoid::e, N);\n        }\n        // 5. Lazy Segment Tree\n        else\
    \ {\n            static_assert(!std::is_void_v<Act>, \"LazySegmentTree requires\
    \ an Act operator.\");\n            if constexpr (is_vec) tree.template emplace<LazySegmentTree<T,\
    \ U>>(ProdMonoid::op, ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, data);\n\
    \            else tree.template emplace<LazySegmentTree<T, U>>(ProdMonoid::op,\
    \ ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, N);\n        }\n    }\n\
    \n  public:\n    UnifiedSegmentTree(int n, RangeType upd_t, RangeType prod_t)\
    \ {\n        construct(n, n, upd_t, prod_t);\n    }\n\n    UnifiedSegmentTree(const\
    \ std::vector<T>& a, RangeType upd_t, RangeType prod_t) {\n        construct(a.size(),\
    \ a, upd_t, prod_t);\n    }\n\n    void update(int l, int r, U x) {\n        std::visit([&](auto&&\
    \ t) {\n            using VT = std::decay_t<decltype(t)>;\n            if constexpr\
    \ (std::is_same_v<VT, StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>>\
    \ ||\n                          std::is_same_v<VT, DualSegmentTree<U>> || std::is_same_v<VT,\
    \ LazySegmentTree<T, U>>) {\n                t.apply(l, r, x);\n            }\
    \ else if constexpr (std::is_same_v<VT, SegmentTree<T>>) {\n                t.set(l,\
    \ x);\n            } else if constexpr (std::is_same_v<VT, FenwickTree>) {\n \
    \               t.add(l, x);\n            }\n        }, tree);\n    }\n\n    T\
    \ query(int l, int r) {\n        return std::visit([&](auto&& t) -> T {\n    \
    \        using VT = std::decay_t<decltype(t)>;\n            if constexpr (std::is_same_v<VT,\
    \ StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>> ||\n      \
    \                    std::is_same_v<VT, SegmentTree<T>> || std::is_same_v<VT,\
    \ LazySegmentTree<T, U>>) {\n                return t.prod(l, r);\n          \
    \  } else if constexpr (std::is_same_v<VT, DualSegmentTree<U>>) {\n          \
    \      return t[l];\n            } else if constexpr (std::is_same_v<VT, FenwickTree>)\
    \ {\n                return t.sum(r - 1) - t.sum(l - 1);\n            }\n    \
    \        return (T)ProdMonoid::e;\n        }, tree);\n    }\n};\n"
  dependsOn:
  - library/segtree/dual_segment_tree.hpp
  - library/various/monoid.hpp
  - library/segtree/fenwick_tree.hpp
  - library/segtree/lazy_segment_tree.hpp
  - library/various/monoid_act.hpp
  - library/segtree/segment_tree.hpp
  - library/segtree/starry_sky_tree.hpp
  isVerificationFile: false
  path: library/segtree/unified_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/segtree.unified_segment_tree.test.cpp
documentation_of: library/segtree/unified_segment_tree.hpp
layout: document
title: "\u7D71\u5408\u30BB\u30B0\u6728"
---

# 統合セグ木

## できること
- 更新モノイド、演算モノイド、作用素モノイド、更新区間、演算区間を指定することで適切な木の構造体を構築
  - 星空木、Fenwick木、セグ木、双対セグ木、遅延セグ木を自動選択
  - 1点でも区間でも、更新は`update`
  - 1点でも区間でも、取得は`query`

## 計算量
- 構築: $O(N)$
- 更新`update`: $O(logN)$
- 取得`query`: $O(logN)$

## 使い方
```cpp
// 更新:Add, 演算:Min, 範囲-範囲
UnifiedSegmentTree<Monoid::Min, Monoid::Add> seg(N, RangeType::Range, RangeType::Range);
seg.update(l, r, v);
int res = seg.query(l, r);

// 更新:Add, 演算:Add, 一点-範囲
UnifiedSegmentTree<Monoid::Add, Monoid::Add> seg(N, RangeType::Single, RangeType::Range);
seg.update(i, i+1, v);
int res = seg.query(l, r);

// 第3引数に作用素 Act を指定
UnifiedSegmentTree<Monoid::Add, Monoid::Set, MonoidAct::AddSet> seg(N, RangeType::Range, RangeType::Range);
seg.update(l, r, v);
int res = seg.query(l, r);

// 配列でも初期化できる
vector<int> A = {1, 2, 3, 4, 5};

// 例：一点更新・範囲最小値（SegmentTreeが自動選択される）
UnifiedSegmentTree<Monoid::Min> seg(A, RangeType::Single, RangeType::Range);

// 例：範囲加算・範囲最大値（StarrySkyTreeが自動選択される）
UnifiedSegmentTree<Monoid::Max, Monoid::Add> sst(A, RangeType::Range, RangeType::Range);
```
