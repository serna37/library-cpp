---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/wavelet_search_engine.hpp
    title: Wavelet Search Engine
  - icon: ':heavy_check_mark:'
    path: library/sequence/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: library/sequence/static_range_count_distinct.hpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570"
  - icon: ':heavy_check_mark:'
    path: library/sequence/static_range_frequency.hpp
    title: "\u533A\u9593\u306E\u5024\u306E\u51FA\u73FE\u56DE\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search.binary_search.wavelet_search_engine.test.cpp
    title: "WaveletSearchEngine\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.inversion_number.test.cpp
    title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u30FBFenwickTree\u306E\
      \u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.static_range_count_distinct.test.cpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/sequence.static_range_frequency.test.cpp
    title: "\u533A\u9593\u306E\u5024\u306E\u51FA\u73FE\u56DE\u6570\u306E\u30C6\u30B9\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/various.mo.test.cpp
    title: "Mo's algorithm\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/compressor.hpp\"\ntemplate <typename T>\
    \ struct Compressor {\n    vector<T> origin, dict;\n    Compressor(const vector<T>\
    \ &v) : origin(v), dict(v) {\n        sort(dict.begin(), dict.end());\n      \
    \  dict.erase(unique(dict.begin(), dict.end()), dict.end());\n    }\n    int size()\
    \ const { return dict.size(); }\n    // \u5024 -> ID (\u5727\u7E2E)\n    int get_id(T\
    \ x) const {\n        return lower_bound(dict.begin(), dict.end(), x) - dict.begin();\n\
    \    }\n    // \u5024 -> ID (upper_bound\u7248)\n    int get_upper_id(T x) const\
    \ {\n        return upper_bound(dict.begin(), dict.end(), x) - dict.begin();\n\
    \    }\n    // ID -> \u5024 (\u5FA9\u5143)\n    T get_val(int id) const { return\
    \ dict[id]; }\n    // \u3059\u3079\u3066\u5727\u7E2E\n    vector<int> get_all()\
    \ {\n        vector<int> res;\n        for (auto &&x : origin) res.emplace_back(get_id(x));\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct Compressor {\n    vector<T> origin,\
    \ dict;\n    Compressor(const vector<T> &v) : origin(v), dict(v) {\n        sort(dict.begin(),\
    \ dict.end());\n        dict.erase(unique(dict.begin(), dict.end()), dict.end());\n\
    \    }\n    int size() const { return dict.size(); }\n    // \u5024 -> ID (\u5727\
    \u7E2E)\n    int get_id(T x) const {\n        return lower_bound(dict.begin(),\
    \ dict.end(), x) - dict.begin();\n    }\n    // \u5024 -> ID (upper_bound\u7248\
    )\n    int get_upper_id(T x) const {\n        return upper_bound(dict.begin(),\
    \ dict.end(), x) - dict.begin();\n    }\n    // ID -> \u5024 (\u5FA9\u5143)\n\
    \    T get_val(int id) const { return dict[id]; }\n    // \u3059\u3079\u3066\u5727\
    \u7E2E\n    vector<int> get_all() {\n        vector<int> res;\n        for (auto\
    \ &&x : origin) res.emplace_back(get_id(x));\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/compressor.hpp
  requiredBy:
  - library/sequence/static_range_count_distinct.hpp
  - library/sequence/inversion_number.hpp
  - library/sequence/static_range_frequency.hpp
  - library/search/binary_search/wavelet_search_engine.hpp
  timestamp: '2026-01-20 20:11:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/various.mo.test.cpp
  - tests/sequence.static_range_count_distinct.test.cpp
  - tests/sequence.inversion_number.test.cpp
  - tests/search.binary_search.wavelet_search_engine.test.cpp
  - tests/sequence.static_range_frequency.test.cpp
documentation_of: library/sequence/compressor.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

# 座標圧縮

## できること
- 大きさの序列のみを保持したID配列（0-indexed）に圧縮する
- 巨大な値や負の値を含む配列を、要素の種類数（0 ～ size-1）の範囲に収められる
- 圧縮後のIDから元の値を復元できる
- 任意の値が「どのID相当か」を取得できる（二分探索を利用）

## 計算量
- 構築: $O(NlogN)$
- 圧縮 `get_id`: $O(logN)$
- 復元 `get_val`: $O(1)$

## 使い方
```cpp
vector<long long> A = {10, 40, 90, 90, 150, 420};

// 1. 構築
Compressor<long long> zip(A);

// 2. 種類数の取得
int sz = zip.size(); // 5

// 3. 値から ID への変換 (二分探索)
int id1 = zip.get_id(90);       // 2 (90 以上の最小 ID)
int id2 = zip.get_upper_id(90); // 3 (90 より大きい最小 ID)

// 4. ID から元の値への復元
long long val = zip.get_val(2); // 90

// 5. 元の配列をすべて圧縮変換する場合
vector<int> z = zip.get_all();
```
