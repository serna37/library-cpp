---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
    links: []
  bundledCode: "#line 2 \"library/datastruct/segment_tree.hpp\"\n\n/**\n * Segment\
    \ Tree\n * @brief 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97\n */\ntemplate\
    \ <typename Monoid> struct SegTree {\n    using M = Monoid;\n    using T = typename\
    \ M::value_type;\n\n  private:\n    int N, log, size;\n    vector<T> node;\n \
    \   void init() {\n        log = 1;\n        while ((1 << log) < N) ++log;\n \
    \       size = 1 << log;\n        node.assign(size << 1, M::e);\n    }\n    void\
    \ update(const int &i) {\n        node[i] = M::op(node[i << 1 | 0], node[i <<\
    \ 1 | 1]);\n    }\n\n  public:\n    SegTree(int n) : N(n) {\n        init();\n\
    \    }\n    SegTree(const vector<T> &a) : N(a.size()) {\n        init();\n   \
    \     for (int i = 0; i < N; ++i) node[i + size] = a[i];\n        for (int i =\
    \ size - 1; i >= 1; --i) update(i);\n    }\n    T operator[](int i) {\n      \
    \  return node[i + size];\n    }\n    vector<T> getall() {\n        return {node.begin()\
    \ + size, node.begin() + size + N};\n    }\n    void set(int i, const T &x) {\n\
    \        node[i += size] = x;\n        while (i >>= 1) update(i);\n    }\n   \
    \ void act(int i, const T &x) {\n        i += size;\n        node[i] = M::op(node[i],\
    \ x);\n        while (i >>= 1) update(i);\n    }\n    T prod(int l, int r) {\n\
    \        T L = M::e, R = M::e;\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) L = M::op(L, node[l++]);\n           \
    \ if (r & 1) R = M::op(node[--r], R);\n        }\n        return M::op(L, R);\n\
    \    }\n    T top() {\n        return node[1];\n    }\n    template <typename\
    \ F> int max_right(const F &test, int L) {\n        if (L == N) return N;\n  \
    \      L += size;\n        T sm = M::e;\n        do {\n            while (L %\
    \ 2 == 0) L >>= 1;\n            if (!test(M::op(sm, node[L]))) {\n           \
    \     while (L < size) {\n                    L = 2 * L;\n                   \
    \ if (test(M::op(sm, node[L]))) sm = M::op(sm, node[L++]);\n                }\n\
    \                return L - size;\n            }\n            sm = M::op(sm, node[L++]);\n\
    \        } while ((L & -L) != L);\n        return N;\n    }\n    template <typename\
    \ F> int min_left(const F &test, int R) {\n        if (R == 0) return 0;\n   \
    \     R += size;\n        T sm = M::e;\n        do {\n            --R;\n     \
    \       while (R > 1 and (R % 2)) R >>= 1;\n            if (!test(M::op(node[R],\
    \ sm))) {\n                while (R < size) {\n                    R = 2 * R +\
    \ 1;\n                    if (test(M::op(node[R], sm))) sm = M::op(node[R--],\
    \ sm);\n                }\n                return R + 1 - size;\n            }\n\
    \            sm = M::op(node[R], sm);\n        } while ((R & -R) != R);\n    \
    \    return 0;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Segment Tree\n * @brief 1\u70B9\u66F4\u65B0 \u533A\
    \u9593\u53D6\u5F97\n */\ntemplate <typename Monoid> struct SegTree {\n    using\
    \ M = Monoid;\n    using T = typename M::value_type;\n\n  private:\n    int N,\
    \ log, size;\n    vector<T> node;\n    void init() {\n        log = 1;\n     \
    \   while ((1 << log) < N) ++log;\n        size = 1 << log;\n        node.assign(size\
    \ << 1, M::e);\n    }\n    void update(const int &i) {\n        node[i] = M::op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n\n  public:\n    SegTree(int n) : N(n)\
    \ {\n        init();\n    }\n    SegTree(const vector<T> &a) : N(a.size()) {\n\
    \        init();\n        for (int i = 0; i < N; ++i) node[i + size] = a[i];\n\
    \        for (int i = size - 1; i >= 1; --i) update(i);\n    }\n    T operator[](int\
    \ i) {\n        return node[i + size];\n    }\n    vector<T> getall() {\n    \
    \    return {node.begin() + size, node.begin() + size + N};\n    }\n    void set(int\
    \ i, const T &x) {\n        node[i += size] = x;\n        while (i >>= 1) update(i);\n\
    \    }\n    void act(int i, const T &x) {\n        i += size;\n        node[i]\
    \ = M::op(node[i], x);\n        while (i >>= 1) update(i);\n    }\n    T prod(int\
    \ l, int r) {\n        T L = M::e, R = M::e;\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = M::op(L, node[l++]);\n\
    \            if (r & 1) R = M::op(node[--r], R);\n        }\n        return M::op(L,\
    \ R);\n    }\n    T top() {\n        return node[1];\n    }\n    template <typename\
    \ F> int max_right(const F &test, int L) {\n        if (L == N) return N;\n  \
    \      L += size;\n        T sm = M::e;\n        do {\n            while (L %\
    \ 2 == 0) L >>= 1;\n            if (!test(M::op(sm, node[L]))) {\n           \
    \     while (L < size) {\n                    L = 2 * L;\n                   \
    \ if (test(M::op(sm, node[L]))) sm = M::op(sm, node[L++]);\n                }\n\
    \                return L - size;\n            }\n            sm = M::op(sm, node[L++]);\n\
    \        } while ((L & -L) != L);\n        return N;\n    }\n    template <typename\
    \ F> int min_left(const F &test, int R) {\n        if (R == 0) return 0;\n   \
    \     R += size;\n        T sm = M::e;\n        do {\n            --R;\n     \
    \       while (R > 1 and (R % 2)) R >>= 1;\n            if (!test(M::op(node[R],\
    \ sm))) {\n                while (R < size) {\n                    R = 2 * R +\
    \ 1;\n                    if (test(M::op(node[R], sm))) sm = M::op(node[R--],\
    \ sm);\n                }\n                return R + 1 - size;\n            }\n\
    \            sm = M::op(node[R], sm);\n        } while ((R & -R) != R);\n    \
    \    return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/datastruct/segment_tree.hpp
  requiredBy: []
  timestamp: '2025-12-14 19:49:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastruct/segment_tree.hpp
layout: document
redirect_from:
- /library/library/datastruct/segment_tree.hpp
- /library/library/datastruct/segment_tree.hpp.html
title: "1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
---
