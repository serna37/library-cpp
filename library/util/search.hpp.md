---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u63A2\u7D22"
    links: []
  bundledCode: "#line 2 \"library/util/search.hpp\"\n/**\n * @brief \u63A2\u7D22\n\
    \ */\nclass Search {\n  public:\n    /**\n     * \u9806\u5217\u5168\u63A2\u7D22\
    \ O(N!) N\u306F10\u301C12\u7A0B\u5EA6\n     * \u9806\u5217\u306E\u5168\u30D1\u30BF\
    \u30FC\u30F3\u4E2D\u3067\u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\u308C\
    \u308B\n     * \u4F8B) search_permu(A, [&](){cout << A;} );\n     */\n    template\
    \ <typename T, typename F> void perm(vector<T> &A, F f) {\n        sort(all(A));\n\
    \        do {\n            f();\n        } while (next_permutation(all(A)));\n\
    \    }\n    /**\n     * bit\u5168\u63A2\u7D22 O(2^N) N\u306F20\u524D\u5F8C\n \
    \    * \u96C6\u5408A\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u306E\u90E8\u5206\u96C6\
    \u5408\u3092\u8FD4\u3059\n     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}\
    \ }\n     */\n    template <typename T> vector<vector<T>> bit(vector<T> &A) {\n\
    \        int N = A.size();\n        vector<vector<T>> res;\n        for (long\
    \ long bit = 0; bit < (1ll << N); ++bit) {\n            vector<T> tmp;\n     \
    \       for (int k = 0; k < N; ++k) {\n                if (bit & (1ll << k)) {\n\
    \                    tmp.push_back(A[k]);\n                }\n            }\n\
    \            res.push_back(tmp);\n        }\n        return res;\n    }\n    /**\n\
    \     * \u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n   \
    \  * x x x o o o o\n     *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n\
    \     * \u6761\u4EF6\uFF1A5 <= x\u306A\u3089\u3001L=4, R=5\n     */\n    template\
    \ <typename F> pair<long long, long long> bi(F f) {\n        long long L = 0,\
    \ R = 1, MID = 0;\n        while (!f(R)) R <<= 1;\n        while (abs(R - L) >\
    \ 1) {\n            MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n\
    \        }\n        return make_pair(L, R);\n    }\n    /**\n     * \u5B9F\u6570\
    \u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n     * x x x o o o o\n \
    \    *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n     * \u6761\u4EF6\uFF1A\
    3.5 <= x\u306A\u3089\u3001L=3.5, R=3.5 (LR\u306E\u8AA4\u5DEE\u304CEPS\u5185)\n\
    \     */\n    template <typename F> pair<double, double> bi_real(F f) {\n    \
    \    double L = 0, R = 1, MID = 0;\n        while (!f(R)) R *= 2;\n        auto\
    \ ABS = [&]() { return abs(R - L) > EPS; };\n        auto REL = [&]() { return\
    \ abs(R - L) / max(R, L) > EPS; };\n        while (ABS() and REL()) {\n      \
    \      MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n        }\n\
    \        return make_pair(L, R);\n    }\n    // \u4EE5\u4E0B\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return upper_bound(all(v), x) - v.begin();\n \
    \   }\n    // \u4EE5\u4E0B\u306E\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    -INF\n    template <typename T> T bi_le_val(vector<T> &v, const T &x) {\n    \
    \    sort(all(v));\n        auto it = upper_bound(all(v), x);\n        return\
    \ (it == v.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0B\u306E\u5024  \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408-INF\n    template <typename T> T bi_le_val(const\
    \ set<T> &st, const T &x) {\n        auto it = st.upper_bound(x);\n        return\
    \ (it == st.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0A\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return v.end() - lower_bound(all(v), x);\n   \
    \ }\n    // \u4EE5\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 INF\n    template <typename T> T bi_ge_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.end() ? INF : *it);\n    }\n    // \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_ge_val(const set<T> &st, const T &x) {\n        auto it = st.lower_bound(x);\n\
    \        return (it == st.end() ? INF : *it);\n    }\n    // \u672A\u6E80\u306E\
    \u8981\u7D20\u6570\n    template <typename T> int bi_lt_cnt(vector<T> &v, const\
    \ T &x) {\n        sort(all(v));\n        return lower_bound(all(v), x) - v.begin();\n\
    \    }\n    // \u672A\u6E80\u306E\u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 -INF\n    template <typename T> T bi_lt_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.begin() ? -INF : *--it);\n    }\n    // \u672A\u6E80\u306E\
    \u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -INF\n    template\
    \ <typename T> T bi_lt_val(const set<T> &st, const T &x) {\n        auto it =\
    \ st.lower_bound(x);\n        return (it == st.begin() ? -INF : *--it);\n    }\n\
    \    // \u3088\u308A\u4E0A\u306E\u8981\u7D20\u6570\n    template <typename T>\
    \ int bi_gt_cnt(vector<T> &v, const T &x) {\n        sort(all(v));\n        return\
    \ v.end() - upper_bound(all(v), x);\n    }\n    // \u3088\u308A\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_gt_val(vector<T> &v, const T &x) {\n        sort(all(v));\n        auto\
    \ it = upper_bound(all(v), x);\n        return (it == v.end() ? INF : *it);\n\
    \    }\n    // \u3088\u308A\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408 INF\n    template <typename T> T bi_gt_val(const set<T> &st,\
    \ const T &x) {\n        auto it = st.upper_bound(x);\n        return (it == st.end()\
    \ ? INF : *it);\n    }\n    // \u30E1\u30E2\u5316\u518D\u5E30 !!\u30B3\u30D4\u30DA\
    \u7528!! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\
    \u63DB\u3048\u3066\u4F7F\u3046\n    void dfs_memo() {\n        map<int, int> memo;\n\
    \        auto dfs = [&](auto f, int n) {\n            if (n <= 1) return n;\n\
    \            if (memo.count(n)) return memo[n];\n            return memo[n] =\
    \ f(f, n - 1) + f(f, n - 2);\n        };\n        (void)dfs; // unused\n     \
    \   // int ans = dfs(dfs, N);\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief \u63A2\u7D22\n */\nclass Search {\n  public:\n\
    \    /**\n     * \u9806\u5217\u5168\u63A2\u7D22 O(N!) N\u306F10\u301C12\u7A0B\u5EA6\
    \n     * \u9806\u5217\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u4E2D\u3067\u3084\u308A\
    \u305F\u3044\u95A2\u6570\u3092\u5165\u308C\u308B\n     * \u4F8B) search_permu(A,\
    \ [&](){cout << A;} );\n     */\n    template <typename T, typename F> void perm(vector<T>\
    \ &A, F f) {\n        sort(all(A));\n        do {\n            f();\n        }\
    \ while (next_permutation(all(A)));\n    }\n    /**\n     * bit\u5168\u63A2\u7D22\
    \ O(2^N) N\u306F20\u524D\u5F8C\n     * \u96C6\u5408A\u306E\u5168\u30D1\u30BF\u30FC\
    \u30F3\u306E\u90E8\u5206\u96C6\u5408\u3092\u8FD4\u3059\n     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}\
    \ }\n     */\n    template <typename T> vector<vector<T>> bit(vector<T> &A) {\n\
    \        int N = A.size();\n        vector<vector<T>> res;\n        for (long\
    \ long bit = 0; bit < (1ll << N); ++bit) {\n            vector<T> tmp;\n     \
    \       for (int k = 0; k < N; ++k) {\n                if (bit & (1ll << k)) {\n\
    \                    tmp.push_back(A[k]);\n                }\n            }\n\
    \            res.push_back(tmp);\n        }\n        return res;\n    }\n    /**\n\
    \     * \u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n   \
    \  * x x x o o o o\n     *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n\
    \     * \u6761\u4EF6\uFF1A5 <= x\u306A\u3089\u3001L=4, R=5\n     */\n    template\
    \ <typename F> pair<long long, long long> bi(F f) {\n        long long L = 0,\
    \ R = 1, MID = 0;\n        while (!f(R)) R <<= 1;\n        while (abs(R - L) >\
    \ 1) {\n            MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n\
    \        }\n        return make_pair(L, R);\n    }\n    /**\n     * \u5B9F\u6570\
    \u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n     * x x x o o o o\n \
    \    *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n     * \u6761\u4EF6\uFF1A\
    3.5 <= x\u306A\u3089\u3001L=3.5, R=3.5 (LR\u306E\u8AA4\u5DEE\u304CEPS\u5185)\n\
    \     */\n    template <typename F> pair<double, double> bi_real(F f) {\n    \
    \    double L = 0, R = 1, MID = 0;\n        while (!f(R)) R *= 2;\n        auto\
    \ ABS = [&]() { return abs(R - L) > EPS; };\n        auto REL = [&]() { return\
    \ abs(R - L) / max(R, L) > EPS; };\n        while (ABS() and REL()) {\n      \
    \      MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n        }\n\
    \        return make_pair(L, R);\n    }\n    // \u4EE5\u4E0B\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return upper_bound(all(v), x) - v.begin();\n \
    \   }\n    // \u4EE5\u4E0B\u306E\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    -INF\n    template <typename T> T bi_le_val(vector<T> &v, const T &x) {\n    \
    \    sort(all(v));\n        auto it = upper_bound(all(v), x);\n        return\
    \ (it == v.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0B\u306E\u5024  \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408-INF\n    template <typename T> T bi_le_val(const\
    \ set<T> &st, const T &x) {\n        auto it = st.upper_bound(x);\n        return\
    \ (it == st.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0A\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return v.end() - lower_bound(all(v), x);\n   \
    \ }\n    // \u4EE5\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 INF\n    template <typename T> T bi_ge_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.end() ? INF : *it);\n    }\n    // \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_ge_val(const set<T> &st, const T &x) {\n        auto it = st.lower_bound(x);\n\
    \        return (it == st.end() ? INF : *it);\n    }\n    // \u672A\u6E80\u306E\
    \u8981\u7D20\u6570\n    template <typename T> int bi_lt_cnt(vector<T> &v, const\
    \ T &x) {\n        sort(all(v));\n        return lower_bound(all(v), x) - v.begin();\n\
    \    }\n    // \u672A\u6E80\u306E\u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 -INF\n    template <typename T> T bi_lt_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.begin() ? -INF : *--it);\n    }\n    // \u672A\u6E80\u306E\
    \u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -INF\n    template\
    \ <typename T> T bi_lt_val(const set<T> &st, const T &x) {\n        auto it =\
    \ st.lower_bound(x);\n        return (it == st.begin() ? -INF : *--it);\n    }\n\
    \    // \u3088\u308A\u4E0A\u306E\u8981\u7D20\u6570\n    template <typename T>\
    \ int bi_gt_cnt(vector<T> &v, const T &x) {\n        sort(all(v));\n        return\
    \ v.end() - upper_bound(all(v), x);\n    }\n    // \u3088\u308A\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_gt_val(vector<T> &v, const T &x) {\n        sort(all(v));\n        auto\
    \ it = upper_bound(all(v), x);\n        return (it == v.end() ? INF : *it);\n\
    \    }\n    // \u3088\u308A\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408 INF\n    template <typename T> T bi_gt_val(const set<T> &st,\
    \ const T &x) {\n        auto it = st.upper_bound(x);\n        return (it == st.end()\
    \ ? INF : *it);\n    }\n    // \u30E1\u30E2\u5316\u518D\u5E30 !!\u30B3\u30D4\u30DA\
    \u7528!! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\
    \u63DB\u3048\u3066\u4F7F\u3046\n    void dfs_memo() {\n        map<int, int> memo;\n\
    \        auto dfs = [&](auto f, int n) {\n            if (n <= 1) return n;\n\
    \            if (memo.count(n)) return memo[n];\n            return memo[n] =\
    \ f(f, n - 1) + f(f, n - 2);\n        };\n        (void)dfs; // unused\n     \
    \   // int ans = dfs(dfs, N);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/search.hpp
  requiredBy:
  - template/lib.hpp
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 23:06:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.dual_segment_tree.test.cpp
  - tests/segtree.segment_tree.test.cpp
  - tests/template.test.cpp
  - tests/segtree.lazy_segment_tree.test.cpp
  - tests/segtree.fenwick_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/util/search.hpp
layout: document
redirect_from:
- /library/library/util/search.hpp
- /library/library/util/search.hpp.html
title: "\u63A2\u7D22"
---
