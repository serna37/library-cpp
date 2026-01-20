---
title: 区間の値の種類数
documentation_of: //library/sequence/static_range_count_distinct.hpp
---

# 区間の値の種類数

## できること
- 静的な配列に対して、指定された範囲 $[l, r)$ 内の値が何種類かを求める
- 先にクエリをすべて読むオフラインクエリ
- 座標圧縮+FenwickTreeで「その位置の値が今の右端 $i$ から見て『最後に現れた位置』かどうか」を求める

## 計算量
$O((N + Q) \log N)$

## 使い方
```cpp
vector<int> A = {1, 2, 1, 3, 2, 4, 4, 1}; 
// インデックス:  0  1  2  3  4  5  6  7

StaticRangeCountDistinct srcd(A);

// クエリの登録: [l, r) の半開区間で指定
// 例1: A[0...3] -> {1, 2, 1} は 2種類 {1, 2}
srcd.add_query(0, 3); 
// 例2: A[2...5] -> {1, 3, 2} は 3種類 {1, 2, 3}
srcd.add_query(2, 5); 
// 例3: A[5...7] -> {4, 4} は 1種類 {4}
srcd.add_query(5, 7);
// 例4: A[0...8] -> 全体 {1, 2, 1, 3, 2, 4, 4, 1} は 4種類 {1, 2, 3, 4}
srcd.add_query(0, 8);

// 計算実行
vector<size_t> results = srcd.calculate_queries();

// 結果の表示サンプル
vector<string> labels = {"[0, 3)", "[2, 5)", "[5, 7)", "[0, 8)"};
for (int i = 0; i < (int)results.size(); ++i) {
    cout << "Range " << labels[i] << " Distinct Count: " << results[i] << endl;
}
```

