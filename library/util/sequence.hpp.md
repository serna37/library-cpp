---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
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
    \    }\n    template <typename T> void reverse(vector<T> &v) {\n        std::reverse(all(v));\n\
    \    }\n    // set\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename\
    \ T> void erase(set<T> &st, const T &v) {\n        st.erase(st.find(v));\n   \
    \ }\n    // multiset\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename\
    \ T> void erase(multiset<T> &st, const T &v) {\n        st.erase(st.find(v));\n\
    \    }\n    /**\n     * \u5206\u5272\u4EE3\u5165\u3067\u304D\u308B\u3088\u3046\
    \u306B\u3059\u308B G\u306F\u7834\u58CA\u3002\n     * auto [a,b] = unpack<2>(move(G));\n\
    \     */\n    template <int N, typename T> auto unpack(vector<T> &&G) {\n    \
    \    array<T, N> res; // vector -> array\u5909\u63DB\u3059\u308B\u3060\u3051\n\
    \        for (int i = 0; i < N; ++i) res[i] = move(G[i]);\n        return res;\n\
    \    }\n    // \u9023\u756A\u751F\u6210\n    template <typename T> void renban(vector<T>\
    \ &v, T start = 0) {\n        iota(all(v), start);\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF vector\n    template <typename T> void merge(vector<T>\
    \ &A, vector<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.push_back(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF set\n    template <typename T> void merge(set<T>\
    \ &A, set<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.insert(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF \u30DE\u30FC\u30B8\u64CD\u4F5C\u3092\u30E9\u30E0\
    \u30C0\u5316\n    template <typename T, typename F> void merge(T &A, T &B, F f)\
    \ {\n        if (A.size() > B.size()) swap(A, B);\n        for (auto &&v : A)\
    \ {\n            f(B, v);\n        }\n        A.clear();\n    }\n    // \u6570\
    \u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u306B\u306A\u304A\u3059\n    vector<int>\
    \ coordinate(const vector<int> &A) {\n        vector<int> res(MAX);\n        for\
    \ (auto &&v : A) ++res[v];\n        return res;\n    }\n    // \u5EA7\u6A19\u5727\
    \u7E2E \u5727\u7E2E\u5F8C\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u5374\n    template\
    \ <typename T> int zip_coordinate(vector<T> &A) {\n        vector<T> cvt = A;\n\
    \        distinct(cvt);\n        for (auto &v : A) v = lower_bound(all(cvt), v)\
    \ - cvt.begin();\n        return (int)cvt.size();\n    }\n    // \u8EE2\u5012\u6570\
    \ \u53F3\u306B\u5012\u308C\u308BA_i > A_j (i < j)\u306E\u56DE\u6570\n    template\
    \ <typename T> long long inversion_number(vector<T> &A) {\n        int sz = zip_coordinate(A);\n\
    \        vector<int> fwk(sz + 1);\n        long long inv = 0, N = A.size();\n\
    \        for (int i = 0; i < N; ++i) {\n            for (int f = sz; f; f -= f\
    \ & -f) inv += fwk[f];\n            for (int f = A[i] + 1; f; f -= f & -f) inv\
    \ -= fwk[f];\n            for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n\
    \        }\n        return inv;\n    }\n    // \u7D2F\u7A4D\u548C S[i]=\u03A3\
    (0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename T> vector<long long> zeta(const\
    \ vector<T> &A) {\n        int N = A.size();\n        vector<long long> S(N +\
    \ 1);\n        for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];\n        return\
    \ S;\n    }\n    // \u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\
    \u90E8  \u03A3(0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long\
    \ long> zeta_rev(const vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] +\
    \ A[i];\n        return R;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\
    \u7A4D\u548C S[i]=\u03A3(0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename\
    \ T> vector<long long> zeta_diff(const vector<T> &A) {\n        int N = A.size();\n\
    \        vector<long long> S(N + 1);\n        for (int i = 0; i < N; ++i) {\n\
    \            S[i + 1] = S[i];\n            if (i & 1) S[i + 1] += abs(A[i] - A[i\
    \ - 1]);\n        }\n        return S;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\
    \u306E\u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\u90E8  \u03A3\
    (0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long long>\
    \ zeta_rev_diff(const vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) {\n            R[i]\
    \ = R[i + 1];\n            if (i & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) -\
    \ A[i]);\n        }\n        return R;\n    }\n    /**\n     * 2\u6B21\u5143\u5E73\
    \u9762\u3067\u306E\u7D2F\u7A4D\u548C\n     * \u5305\u9664: (s,t)~(x,y) = S[y][x]-S[y][s]-S[t][x]+S[t][s]\n\
    \     */\n    template <typename T> vector<vector<long long>> zeta_2D(const vector<T>\
    \ &G) {\n        int H = G.size(), W = G[0].size();\n        vector<vector<long\
    \ long>> S(H + 1, vector<long long>(W + 1));\n        for (int i = 0; i < H; ++i)\
    \ { // \u6A2A\u5411\u304D\n            for (int j = 0; j < W; ++j) {\n       \
    \         S[i + 1][j + 1] = S[i + 1][j] + G[i][j];\n            }\n        }\n\
    \        for (int i = 0; i < H; ++i) { // \u7E26\u5411\u304D\n            for\
    \ (int j = 0; j < W; ++j) {\n                S[i + 1][j + 1] += S[i][j + 1];\n\
    \            }\n        }\n        return S;\n    }\n    /**\n     * 3\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n     * ex) Lx Ly Lz\u306F0-indexed Rx Ry Rz\u306F1-indexed\n\
    \     *   S[Rxyz] - S[Lxyz]\n     *          = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] -\
    \ S[Rx][Ly][Rz] -\n     *            S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz]\
    \ +\n     *            S[Rx][Ly][Lz] - S[Lx][Ly][Lz];\n     */\n    template <typename\
    \ T>\n    vector<vector<vector<long long>>> zeta_3D(const vector<vector<vector<T>>>\
    \ &A) {\n        vector<vector<vector<long long>>> S;\n        int szx = A.size(),\
    \ szy = A[0].size(), szz = A[0][0].size();\n        S.resize(szx + 1, vector<vector<long\
    \ long>>(\n                              szy + 1, vector<long long>(szz + 1, 0)));\n\
    \        for (int x = 1; x <= szx; ++x) {\n            for (int y = 1; y <= szy;\
    \ ++y) {\n                for (int z = 1; z <= szz; ++z) {\n                 \
    \   S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +\n                 \
    \                S[x][y - 1][z] + S[x][y][z - 1] -\n                         \
    \        S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -\n                         \
    \        S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];\n                }\n   \
    \         }\n        }\n        return S;\n    }\n    // \u5404\u9805\u306E\u5DEE\
    \u306E\u6570\u5217 \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n    template <typename\
    \ T> vector<long long> moebius(const vector<T> &A) {\n        int N = A.size();\n\
    \        vector<long long> D(N - 1);\n        for (int i = 0; i < N; ++i) D[i]\
    \ = A[i + 1] - A[i];\n        return D;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/sequence.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-02 11:22:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/sequence.hpp
layout: document
title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
---

よくある配列操作をより直感的に使うため`C++`特有のSTLをラップしたり。

