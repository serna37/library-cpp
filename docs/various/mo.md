---
title: Mo's algorithm
documentation_of: //library/various/mo.hpp
---

# Mo's algorithm

## できること
- 区間クエリを平方分割で管理
- 参考: https://ei1333.github.io/library/other/mo.hpp

## 計算量
- 区間長n, クエリ数qで初期化 `Mo(n, q)`: $O(q)$
- クエリ追加 $[l, r) {}_{0 \le l \lt r \le n}$ `add_query`: $O(1)$
- クエリを処理 `calclate_queries`: $O(\alpha N \sqrt Q)$ ※区間を1伸縮させる計算量を $O(\alpha)$

## 使い方
```cpp
int N, Q;
cin >> N >> Q;
vector<int> A(N);
for (int i = 0; i < N; ++i) {
    cin >> A[i];
}

// Moの初期化
Mo mo(N, Q);

// クエリの登録
for (int i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r; // 0-indexed, 半開区間 [l, r) と想定
    mo.add_query(l, r);
}

// 状態を保持する変数
vector<int> count(1000001, 0); // 数値の出現回数（数値の最大値に合わせる）
int current_distinct_types = 0;
vector<int> results(Q); // 各クエリの結果格納用

// 1. 要素を追加する時の処理
auto add = [&](int i) {
    if (count[A[i]] == 0ll) {
        current_distinct_types++;
    }
    count[A[i]]++;
};

// 2. 要素を削除する時の処理
auto erase = [&](int i) {
    count[A[i]]--;
    if (count[A[i]] == 0ll) {
        current_distinct_types--;
    }
};

// 3. クエリに答える時の処理
auto query = [&](int idx) {
    results[idx] = current_distinct_types;
};

// 計算実行 (2) の左右区別しないバージョンを使用
mo.calclate_queries(add, erase, query);

// 結果出力
for (int i = 0; i < Q; ++i) {
    cout << results[i] << endl;
}
```

