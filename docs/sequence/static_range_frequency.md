---
title: 区間の値の出現回数
documentation_of: //library/sequence/static_range_frequency.hpp
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

