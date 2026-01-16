---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/various/random.hpp
    title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/string.rolling_hash.test.cpp
    title: "\u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8"
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
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"library/various/random.hpp\"\nstruct RollingHash\
    \ {\n    static const long long MOD = (1LL << 61) - 1;\n    static inline long\
    \ long base = 0;\n    vector<long long> hash_sum;\n\n    // \u57FA\u6570\u3092\
    \u30E1\u30EB\u30BB\u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\u306E\u4E71\u6570\u3067\
    \u521D\u671F\u5316\u3059\u308B\n    static void init_base() {\n        if (base\
    \ != 0) return;\n        base = random(2, MOD - 1);\n    }\n\n    // \u6587\u5B57\
    \u5217\u304B\u3089\u30CF\u30C3\u30B7\u30E5\u306E\u7D2F\u7A4D\u548C\u3092\u69CB\
    \u7BC9\u3059\u308B\n    RollingHash(const string &s) {\n        init_base();\n\
    \        int n = s.size();\n        hash_sum.assign(n + 1, 0);\n        for (int\
    \ i = 0; i < n; i++) {\n            hash_sum[i + 1] = mul(hash_sum[i], base) +\
    \ s[i];\n            if (hash_sum[i + 1] >= MOD) hash_sum[i + 1] -= MOD;\n   \
    \     }\n    }\n\n    // 2^61-1 \u7528\u306E\u9AD8\u901F\u306A\u639B\u3051\u7B97\
    \n    static long long mul(long long a, long long b) {\n        __int128_t res\
    \ = (__int128_t)a * b;\n        long long ans = (long long)(res >> 61) + (long\
    \ long)(res & MOD);\n        if (ans >= MOD) ans -= MOD;\n        return ans;\n\
    \    }\n\n    // \u7D2F\u4E57\u30C6\u30FC\u30D6\u30EB\u306E\u7BA1\u7406\n    static\
    \ const vector<long long>& get_pow(int n) {\n        static vector<long long>\
    \ pow_memo = {1};\n        while ((int)pow_memo.size() <= n) {\n            pow_memo.push_back(mul(pow_memo.back(),\
    \ base));\n        }\n        return pow_memo;\n    }\n\n    // s[l, r) \u306E\
    \u30CF\u30C3\u30B7\u30E5\u3092\u53D6\u5F97\n    long long get(int l, int r) const\
    \ {\n        long long res = hash_sum[r] - mul(hash_sum[l], get_pow(r - l)[r -\
    \ l]);\n        if (res < 0) res += MOD;\n        return res;\n    }\n\n    //\
    \ 2\u3064\u306E\u30CF\u30C3\u30B7\u30E5(a, b)\u3092\u7D50\u5408\u3059\u308B\u3002\
    b\u306E\u9577\u3055\u304C b_len\n    static long long merge(long long a_hash,\
    \ long long b_hash, int b_len) {\n        long long res = mul(a_hash, get_pow(b_len)[b_len])\
    \ + b_hash;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n\
    };\n"
  dependsOn:
  - library/various/random.hpp
  isVerificationFile: false
  path: library/string/rolling_hash.hpp
  requiredBy:
  - library/string/finds.hpp
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.rolling_hash.test.cpp
  - tests/string.finds.test.cpp
documentation_of: library/string/rolling_hash.hpp
layout: document
title: Rolling Hash
---

# Rolling Hash
[詳しい説明](https://www.slideshare.net/slideshow/rolling-hash-60984153/60984153)

## できること
- 文字列Sをハッシュに変換する
- `get(0, 5)`: 0~5文字目の部分文字列のハッシュを取得
- ハッシュが同じであれば、文字列が同じである
- ハッシュ衝突の危険性について
  - 法にメルセンヌ素数 $2^{61}-1$ を、基数に実行時疑似乱数を使用していますが、比較するハッシュ値の数が増えると衝突確率が急上昇します
    - 原因: 「誕生日パラドックス」
    - 衝突の目安: およそ $\sqrt M$ 個(約 $1.5 \cdot 10^{9}$ )個の異なるハッシュを生成して比較すると50%の確率で衝突する

## 計算量
- 構築: $O(\vert S \vert)$
- `get`: $O(1)$

## 使い方
```cpp
string S = "xxx";
RollingHash rh(S);
// ハッシュで比較
if (rh.get(0, 4) == rh.get(7, 11)) {}
```

```cpp
string S = "xxxaaa";
RollingHash rh(S);
long long h_1 = rh.get(0, 2);
long long h_2 = rh.get(2, 5); // bの長さ3
// ハッシュをマージ
if (RollingHash::merge(h_1, h_2, 3) == rh.get(0, 5)) {}
```
