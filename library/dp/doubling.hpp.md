---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/lca.hpp
    title: LCA
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.lca.test.cpp
    title: "\u6728 - LCA\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/dp/doubling.hpp\"\ntemplate <typename T> struct\
    \ Doubling {\n    int N, log = 0;\n    vector<vector<T>> table;\n    Doubling()\
    \ {}\n    Doubling(const vector<T> &next, long long max_steps) {\n        N =\
    \ next.size();\n        while ((1ll << log) <= max_steps) ++log;\n        table.assign(log,\
    \ vector<T>(N, T()));\n        table[0] = next;\n        for (int k = 0; k < log\
    \ - 1; ++k) {\n            for (int v = 0; v < N; ++v) {\n                if (table[k][v].to\
    \ == T::e) {\n                    table[k + 1][v] = table[k][v];\n           \
    \     } else {\n                    table[k + 1][v] = table[k][v] + table[k][table[k][v].to];\n\
    \                }\n            }\n        }\n    }\n    T query(int v, long long\
    \ steps) const {\n        T res;\n        res.to = v;\n        for (int k = 0;\
    \ k < log; ++k) {\n            if ((steps >> k) & 1) {\n                if (res.to\
    \ == T::e) break;\n                res = res + table[k][res.to];\n           \
    \ }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct Doubling {\n    int N, log = 0;\n\
    \    vector<vector<T>> table;\n    Doubling() {}\n    Doubling(const vector<T>\
    \ &next, long long max_steps) {\n        N = next.size();\n        while ((1ll\
    \ << log) <= max_steps) ++log;\n        table.assign(log, vector<T>(N, T()));\n\
    \        table[0] = next;\n        for (int k = 0; k < log - 1; ++k) {\n     \
    \       for (int v = 0; v < N; ++v) {\n                if (table[k][v].to == T::e)\
    \ {\n                    table[k + 1][v] = table[k][v];\n                } else\
    \ {\n                    table[k + 1][v] = table[k][v] + table[k][table[k][v].to];\n\
    \                }\n            }\n        }\n    }\n    T query(int v, long long\
    \ steps) const {\n        T res;\n        res.to = v;\n        for (int k = 0;\
    \ k < log; ++k) {\n            if ((steps >> k) & 1) {\n                if (res.to\
    \ == T::e) break;\n                res = res + table[k][res.to];\n           \
    \ }\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dp/doubling.hpp
  requiredBy:
  - library/graph/tree/lca.hpp
  timestamp: '2026-01-16 11:55:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.lca.test.cpp
documentation_of: library/dp/doubling.hpp
layout: document
title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
---

# ダブリング
[詳しい説明](https://www.slideshare.net/slideshow/ss-72500089/72500089)

## できること
- k個先を求める
- $2^0$ 先、$2^1$ 先、$2^2$ 先 ... をDPで作っておくことで高速で見つかる

## 計算量
- 構築: $O(NlogM)$ (Mは最大の次数)
- `query`: $O(logK)$

## 使い方
状態を管理する構造体を用意する
```cpp
struct State {
    static const int e = -1; // 必須 - DPテーブルの初期値
    int to; // 必須 - テーブルの値そのもの
    // --- 付属的な項目を追加してOK
    long long cost = 0;
    long long memo = 0;
    // ---
    State operator+(const State &A) const { // DPする際の結合方法を定義
        return {A.to, cost + A.cost, memo + A.memo};
    }
};
```

```cpp
// 入力例: 3つの町、最大10^18回移動
int N = 3;
long long K = 1e18;

// 各町の移動先とコスト
vector<State> next(N);
next[0] = {1, 10}; // 町0 -> 町1 (10円)
next[1] = {2, 20}; // 町1 -> 町2 (20円)
next[2] = {0, 30}; // 町2 -> 町0 (30円)

Doubling<State> db(next, K);
State result = db.query(0ll, K); // 町0からK回移動
int last_position = result.to;
long long cost = result.cost;
```

```cpp
// 木の親を辿るための最小構成
struct Node {
    static const int e = -1;
    int to; 
    Node operator+(const Node &A) const {
        return {A.to};
    }
};
// 木の構造例
//     0
//    / |
//    1  2
//   / |  |
//  3  4   5
int N = 6;
vector<Node> parent(N); // 各親（1回ぶんの移動を作る）
parent[0] = {-1};
parent[1] = {0};
parent[2] = {0};
parent[3] = {1};
parent[4] = {1};
parent[5] = {2};

Doubling<Node> db(parent, N);
// 頂点 4 の 2 個上の親は？ -> 頂点 0
Node res = db.query(4ll, 2ll);
// res.to == 0
```
