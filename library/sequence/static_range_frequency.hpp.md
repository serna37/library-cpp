---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/compressor.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence.static_range_frequency.test.cpp
    title: "\u533A\u9593\u306E\u5024\u306E\u51FA\u73FE\u56DE\u6570\u306E\u30C6\u30B9\
      \u30C8"
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
    \    }\n    // ID -> \u5024 (\u5FA9\u5143)\n    T get_val(int id) const {\n  \
    \      return dict[id];\n    }\n    // \u3059\u3079\u3066\u5727\u7E2E\n    vector<int>\
    \ get_all() {\n        vector<int> res;\n        for (auto &&x : origin) res.emplace_back(get_id(x));\n\
    \        return res;\n    }\n};\n#line 3 \"library/sequence/static_range_frequency.hpp\"\
    \ntemplate <typename T>\nstruct StaticRangeFrequency {\n  private:\n    Compressor<T>\
    \ comp;\n    vector<vector<int>> mp;\n\n  public:\n    explicit StaticRangeFrequency(const\
    \ vector<T> &xs) : comp(xs) {\n        mp.resize(comp.size());\n        for (int\
    \ i = 0; i < (int)xs.size(); ++i) {\n            int id = comp.get_id(xs[i]);\n\
    \            mp[id].emplace_back(i);\n        }\n    }\n    int query(int l, int\
    \ r, T x) const {\n        int id = comp.get_id(x);\n        if (id >= (int)comp.size()\
    \ or comp.get_val(id) != x) return 0ll;\n        const auto &pos = mp[id];\n \
    \       return lower_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(),\
    \ pos.end(), l);\n    }\n};\n"
  code: "#pragma once\n#include \"library/sequence/compressor.hpp\"\ntemplate <typename\
    \ T>\nstruct StaticRangeFrequency {\n  private:\n    Compressor<T> comp;\n   \
    \ vector<vector<int>> mp;\n\n  public:\n    explicit StaticRangeFrequency(const\
    \ vector<T> &xs) : comp(xs) {\n        mp.resize(comp.size());\n        for (int\
    \ i = 0; i < (int)xs.size(); ++i) {\n            int id = comp.get_id(xs[i]);\n\
    \            mp[id].emplace_back(i);\n        }\n    }\n    int query(int l, int\
    \ r, T x) const {\n        int id = comp.get_id(x);\n        if (id >= (int)comp.size()\
    \ or comp.get_val(id) != x) return 0ll;\n        const auto &pos = mp[id];\n \
    \       return lower_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(),\
    \ pos.end(), l);\n    }\n};\n"
  dependsOn:
  - library/sequence/compressor.hpp
  isVerificationFile: false
  path: library/sequence/static_range_frequency.hpp
  requiredBy: []
  timestamp: '2026-01-20 10:27:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.static_range_frequency.test.cpp
documentation_of: library/sequence/static_range_frequency.hpp
layout: document
title: "\u533A\u9593\u306E\u5024\u306E\u51FA\u73FE\u56DE\u6570"
---

# 区間の値の出現回数

## できること
- 静的な配列に対して、指定された範囲 $[l, r)$ 内の値が出現する回数を求める
- 先にクエリをすべて読むオフラインクエリ
- 座標圧縮と二分探索で実現

## 計算量
$O(N \log N)$

## 使い方
```cpp
// 1. 数値配列の例
vector<int> a = {1, 2, 1, 3, 1, 4, 1};
StaticRangeFrequency srf(a);

// インデックス 0から4 ([0, 4)) の範囲にある '1' の個数
// a[0], a[1], a[2], a[3] -> {1, 2, 1, 3} なので 2個
cout << "Count of 1 in a[0, 4): " << srf.query(0, 4, 1) << endl;

// インデックス 0から7 ([0, 7)) の全範囲にある '1' の個数 -> 4個
cout << "Count of 1 in a[0, 7): " << srf.query(0, 7, 1) << endl;

// 存在しない値を投げても 0 が返る
cout << "Count of 100 in a[0, 7): " << srf.query(0, 7, 100) << endl;

// ---
// 2. 文字列配列の例
vector<string> b = {"apple", "orange", "apple", "banana"};
StaticRangeFrequency srf_str(b);

// [0, 3) の範囲にある "apple" の個数 -> 2個
cout << "Count of 'apple' in b[0, 3): " << srf_str.query(0, 3, "apple") << endl;
```

