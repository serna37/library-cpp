---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: library/various/random.hpp
    title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/random.hpp\"\n#include <chrono>\n#include\
    \ <random>\ninline long long random(long long a, long long b) {\n    if (a >=\
    \ b) return a;\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<long long> dist(a, b - 1);\n    return dist(mt);\n\
    }\n#line 3 \"library/string/rolling_hash.hpp\"\nstruct RollingHash {\n    static\
    \ const long long MOD = (1LL << 61) - 1;\n    static inline long long base = 0;\n\
    \    vector<long long> hash_sum;\n\n    // \u57FA\u6570\u3092\u30E1\u30EB\u30BB\
    \u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\u306E\u4E71\u6570\u3067\u521D\u671F\u5316\
    \u3059\u308B\n    static void init_base() {\n        if (base != 0) return;\n\
    \        base = random(2, MOD - 1);\n    }\n\n    // \u6587\u5B57\u5217\u304B\u3089\
    \u30CF\u30C3\u30B7\u30E5\u306E\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\
    \n    RollingHash(const string &s) {\n        init_base();\n        int n = s.size();\n\
    \        hash_sum.assign(n + 1, 0);\n        for (int i = 0; i < n; i++) {\n \
    \           hash_sum[i + 1] = mul(hash_sum[i], base) + s[i];\n            if (hash_sum[i\
    \ + 1] >= MOD) hash_sum[i + 1] -= MOD;\n        }\n    }\n\n    // 2^61-1 \u7528\
    \u306E\u9AD8\u901F\u306A\u639B\u3051\u7B97\n    static long long mul(long long\
    \ a, long long b) {\n        __int128_t res = (__int128_t)a * b;\n        long\
    \ long ans = (long long)(res >> 61) + (long long)(res & MOD);\n        if (ans\
    \ >= MOD) ans -= MOD;\n        return ans;\n    }\n\n    // \u7D2F\u4E57\u30C6\
    \u30FC\u30D6\u30EB\u306E\u7BA1\u7406\n    static const vector<long long>& get_pow(int\
    \ n) {\n        static vector<long long> pow_memo = {1};\n        while ((int)pow_memo.size()\
    \ <= n) {\n            pow_memo.push_back(mul(pow_memo.back(), base));\n     \
    \   }\n        return pow_memo;\n    }\n\n    // s[l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u3092\u53D6\u5F97\n    long long get(int l, int r) const {\n        long\
    \ long res = hash_sum[r] - mul(hash_sum[l], get_pow(r - l)[r - l]);\n        if\
    \ (res < 0) res += MOD;\n        return res;\n    }\n\n    // 2\u3064\u306E\u30CF\
    \u30C3\u30B7\u30E5(a, b)\u3092\u7D50\u5408\u3059\u308B\u3002b\u306E\u9577\u3055\
    \u304C b_len\n    static long long merge(long long a_hash, long long b_hash, int\
    \ b_len) {\n        long long res = mul(a_hash, get_pow(b_len)[b_len]) + b_hash;\n\
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n};\n#line 3\
    \ \"library/string/finds.hpp\"\n// \u30CA\u30A4\u30FC\u30D6\nvector<int> finds(const\
    \ string &T, const string &S) {\n    vector<int> pos;\n    auto p = T.find(S);\n\
    \    while (p != string::npos) {\n        pos.emplace_back(p);\n        p = T.find(S,\
    \ p + 1);\n    }\n    return pos;\n}\n// RollingHash\u3067\u5B9F\u88C5\nvector<int>\
    \ finds_rolling_hash(const string &T, const string &P) {\n    vector<int> res;\n\
    \    int t = T.size();\n    int p = P.size();\n    RollingHash rht(T);\n    RollingHash\
    \ rhp(P);\n    if (t < p) return res;\n    long long hash_p = rhp.get(0, p);\n\
    \    for (int i = 0; i < t - p + 1; ++i) {\n        if (rht.get(i, i + p) == hash_p)\
    \ {\n            res.emplace_back(i);\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"library/string/rolling_hash.hpp\"\n// \u30CA\u30A4\
    \u30FC\u30D6\nvector<int> finds(const string &T, const string &S) {\n    vector<int>\
    \ pos;\n    auto p = T.find(S);\n    while (p != string::npos) {\n        pos.emplace_back(p);\n\
    \        p = T.find(S, p + 1);\n    }\n    return pos;\n}\n// RollingHash\u3067\
    \u5B9F\u88C5\nvector<int> finds_rolling_hash(const string &T, const string &P)\
    \ {\n    vector<int> res;\n    int t = T.size();\n    int p = P.size();\n    RollingHash\
    \ rht(T);\n    RollingHash rhp(P);\n    if (t < p) return res;\n    long long\
    \ hash_p = rhp.get(0, p);\n    for (int i = 0; i < t - p + 1; ++i) {\n       \
    \ if (rht.get(i, i + p) == hash_p) {\n            res.emplace_back(i);\n     \
    \   }\n    }\n    return res;\n}\n"
  dependsOn:
  - library/string/rolling_hash.hpp
  - library/various/random.hpp
  isVerificationFile: false
  path: library/string/finds.hpp
  requiredBy: []
  timestamp: '2026-01-16 11:55:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.finds.test.cpp
documentation_of: library/string/finds.hpp
layout: document
title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570"
---

# 文字列検索 複数

## できること
- 文字列Tの中にあるSの一致場所を全て取得
- マッチした頭のインデックスを返す

## 計算量
- ナイーブ: $O(\vert T \vert \cdot \vert S \vert)$
- ロリハ版: $O(\vert T \vert + \vert S \vert)$ ※ハッシュ衝突の危険性を留意

## 使い方
```cpp
vector<int> pos = finds(T, S);

vector<int> pos = finds_rolling_hash(T, S);
```
