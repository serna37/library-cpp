---
title: ダブリング
documentation_of: //library/sequence/doubling.hpp
---

# ダブリング

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
