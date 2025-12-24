---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "\U0001F36A\U0001F9F8\U0001F43E"
  - icon: ':x:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ library/util/sequence.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**              \u914D\
    \u5217\u30FB\u6570\u5217                 */\n/** =======================================\
    \ */\n#pragma once\nclass Sequence {\n  public:\n    template <typename T> T min(const\
    \ vector<T> &v) {\n        return *min_element(all(v));\n    }\n    template <typename\
    \ T> T max(const vector<T> &v) {\n        return *max_element(all(v));\n    }\n\
    \    template <typename T> long long sum(const vector<T> &v) {\n        return\
    \ accumulate(all(v), 0ll);\n    }\n    template <typename T, typename F> bool\
    \ all_match(const vector<T> &v, F f) {\n        return all_of(all(v), f);\n  \
    \  }\n    template <typename T, typename F> bool none_match(const vector<T> &v,\
    \ F f) {\n        return none_of(all(v), f);\n    }\n    template <typename T,\
    \ typename F> bool any_match(const vector<T> &v, F f) {\n        return any_of(all(v),\
    \ f);\n    }\n    template <typename T> void distinct(vector<T> &v) {\n      \
    \  sort(all(v));\n        v.erase(unique(all(v)), v.end());\n    }\n    template\
    \ <typename T> void sort_asc(vector<T> &v) {\n        sort(all(v));\n    }\n \
    \   template <typename T> void sort_desc(vector<T> &v) {\n        sort(rall(v));\n\
    \    }\n    template <typename T> void reverse(vector<T> &v) {\n        reverse(all(v));\n\
    \    }\n    // set\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename\
    \ T> void erase(set<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n  \
    \  // multiset\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename T>\
    \ void erase(multiset<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n\
    \    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template <typename T>\n    vector<vector<T>>\
    \ transpose(const vector<vector<T>> &G) {\n        int H = G.size(), W = G[0].size();\n\
    \        vector<vector<T>> _G(W, vector<T>(H));\n        for (int i = 0; i < H;\
    \ ++i) {\n            for (int j = 0; j < W; ++j) {\n                _G[j][i]\
    \ = G[i][j];\n            }\n        }\n        return _G;\n    }\n    /**\n \
    \    * \u5206\u5272\u4EE3\u5165\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\
    \ G\u306F\u7834\u58CA\u3002\n     * auto [a,b] = unpack<2>(move(G));\n     */\n\
    \    template <int N, typename T> auto unpack(vector<T> &&G) {\n        array<T,\
    \ N> res; // vector -> array\u5909\u63DB\u3059\u308B\u3060\u3051\n        for\
    \ (int i = 0; i < N; ++i) res[i] = move(G[i]);\n        return res;\n    }\n \
    \   // A\u3092B\u306B\u30DE\u30FC\u30B8\u30C6\u30AF vector\n    template <typename\
    \ T> void merge(vector<T> &A, vector<T> &B) {\n        if (A.size() > B.size())\
    \ swap(A, B);\n        for (auto &&v : A) B.push_back(v);\n        A.clear();\n\
    \    }\n    // A\u3092B\u306B\u30DE\u30FC\u30B8\u30C6\u30AF set\n    template\
    \ <typename T> void merge(set<T> &A, set<T> &B) {\n        if (A.size() > B.size())\
    \ swap(A, B);\n        for (auto &&v : A) B.insert(v);\n        A.clear();\n \
    \   }\n    // A\u3092B\u306B\u30DE\u30FC\u30B8\u30C6\u30AF \u30DE\u30FC\u30B8\u64CD\
    \u4F5C\u3092\u30E9\u30E0\u30C0\u5316\n    template <typename T, typename F> void\
    \ merge(T &A, T &B, F f) {\n        if (A.size() > B.size()) swap(A, B);\n   \
    \     for (auto &&v : A) {\n            f(B, v);\n        }\n        A.clear();\n\
    \    }\n    // \u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u306B\u306A\u304A\
    \u3059\n    vector<int> coordinate(const vector<int> &A) {\n        vector<int>\
    \ res(MAX);\n        for (auto &&v : A) ++res[v];\n        return res;\n    }\n\
    \    // \u5EA7\u6A19\u5727\u7E2E \u5727\u7E2E\u5F8C\u306E\u7A2E\u985E\u6570\u3092\
    \u8FD4\u5374\n    template <typename T> int zip_coordinate(vector<T> &A) {\n \
    \       vector<T> cvt = A;\n        distinct(cvt);\n        for (auto &v : A)\
    \ v = lower_bound(all(cvt), v) - cvt.begin();\n        return (int)cvt.size();\n\
    \    }\n    // \u8EE2\u5012\u6570 \u53F3\u306B\u5012\u308C\u308BA_i > A_j (i <\
    \ j)\u306E\u56DE\u6570\n    template <typename T> long long inversion_number(vector<T>\
    \ &A) {\n        int sz = zip_coordinate(A);\n        vector<int> fwk(sz + 1);\n\
    \        long long inv = 0, N = A.size();\n        for (int i = 0; i < N; ++i)\
    \ {\n            for (int f = sz; f; f -= f & -f) inv += fwk[f];\n           \
    \ for (int f = A[i] + 1; f; f -= f & -f) inv -= fwk[f];\n            for (int\
    \ f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n        }\n        return inv;\n\
    \    };\n};\n// TODO \u7D2F\u7A4D\u548C\u7CFB\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/sequence.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-24 17:14:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/sequence.hpp
layout: document
title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
---

よくある配列操作をより直感的に使うため`C++`特有のSTLをラップしたり。

