---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "\U0001F36A\U0001F9F8\U0001F43E"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/util/search.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**               \u63A2\
    \u7D22                      */\n/** ======================================= */\n\
    #pragma once\nclass Search {\n  public:\n    /**\n     * \u9806\u5217\u5168\u63A2\
    \u7D22 O(N!) N\u306F10\u301C12\u7A0B\u5EA6\n     * \u9806\u5217\u306E\u5168\u30D1\
    \u30BF\u30FC\u30F3\u4E2D\u3067\u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\
    \u308C\u308B\n     * \u4F8B) search_permu(A, [&](){cout << A;} );\n     */\n \
    \   template <typename T, typename F> void perm(vector<T> &A, F f) {\n       \
    \ sort(all(A));\n        do {\n            f();\n        } while (next_permutation(all(A)));\n\
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
    \ ? INF : *it);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/search.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-27 21:03:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/search.hpp
layout: document
title: "\u63A2\u7D22"
---

全探索などをまとめる
- 順列全探索
- bit全探索
- 二分探索
