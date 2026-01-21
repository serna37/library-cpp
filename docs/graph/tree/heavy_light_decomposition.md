---
title: 重軽分解
documentation_of: //library/graph/tree/heavy_light_decomposition.hpp
---

# 重軽分解
[詳しい説明](https://atcoder.jp/contests/abc269/editorial/4838)

## できること
- 木構造を配列として扱えるため、セグ木などと相性がよい
  - 木上のダブリング→HL分解してセグ木、などとできる
  - 動的パス更新/取得: 頂点u,v間の辺の重みを足す、パス上の最大値など
- パス上のクエリ: 頂点uからvへの最短パス上にある値の、合計や最大
- パス上の一括更新: 頂点uからvへの最短パス上の値を一括更新
- LCA取得: ダブリング実装より定数倍が速い
- LA取得: Level Ancestor 頂点vのk個上の親を取得
- 部分木クエリ: 頂点vの部分木全体に対する操作
- 指定された頂点たちのLCA関係を保って木を圧縮してできる補助的な木 「`Auxiliary Tree` （虚樹）」を作る
- 参考: https://smijake3.hatenablog.com/entry/2019/09/15/200200
- ちょっとした解説
  - 子孫数（部分木サイズ）が多い子への辺を`HeavyEdge`、それ以外を`Light Edge`と呼ぶ
  - HeavyEdgeをつなげていくと、木全体がいくつかの「太いパス」に分解される

<img width="529" height="328" alt="Image" src="https://github.com/user-attachments/assets/07746fb8-59a7-4461-900c-b805e6c5e043" />


また、構造体中で管理する配列の役割は以下

| メンバ | 役割 |
| -- | -- |
| sz | そのノードを根とする部分木のサイズ |
| in | HLDの新ノード順、DFS行きがけ順。セグ木のindexに使う |
| out | 部分木終端のin番号 in[v]からout[v]までがvを根とする部分木全体 |
| head | そのノードが属するパスの先頭ノード |
| rev | in番号から元のノード番号を逆引きする配列 rev[in[v]] == vである |
| par | ノードの親ノード |
| dep | ノードの深さ |

## 計算量
頂点数をN
- 構築 `build`: $O(N)$ `in`順で一列の配列になる
- LCA `lca(u, v)`: $O(\log N)$
- LA `la(v, k)`: $O(\log N)$
- 2点間距離 `dist(u, v)`: $O(\log N)$
- パスクエリ `query` `add`: $O(\log^2 N)$ (セグ木分で2乗)
- 部分木クエリ: $O(log N)$ (セグ木分)
- 虚樹構築 `compress`: $O(K \log K)$ Kは指定頂点集合の要素数

## 使い方
verifyしてるプログラムファイルのが分かりやすいかも。
```cpp
int N;
cin >> N;
vector<int> S(N);
cin >> S;

HeavyLightDecomposition hld(N);
hld.read(N - 1);  // グラフ構造体を継承している
hld.build(0); // 根を指定してビルド

int lca_node = hld.lca(2, 4);    // 2と4の共通祖先
int d = hld.dist(2, 4);         // 2と4の距離
int anc = hld.la(4, 2);         // 4から2代上の親 (k=0なら自分自身)


// 遅延セグ木を用意
vector<int> A(N);
for (int i = 0; i < N; ++i) {
  A[i] = S[hld.rev[i]]; // inやrevをうまく使う
  // 場合によって、新規Node構造体を作って、モノイドを定義
}
LazySegmentTree<int, int> seg(
    Monoid::Add::op,            // 区間取得の演算 (足し算)
    Monoid::Add::e,             // 単位元 (0)
    Monoid::Add::op,            // 更新操作のマージ (足し算)
    Monoid::Add::e,             // 更新の単位元 (0)
    MonoidAct::AddAdd::op,      // ノードへの作用 (加算 * 区間サイズ)
    A
);

int u = 0, v = 4;

// 0番から4番のパス上のノードすべてに +10
hld.add(u, v, [&](int l, int r) {
    seg.apply(l, r, 10);
});

// 0番から4番のパス上の合計を取得
long long res = hld.query(u, v, 0LL, // 初期値
    [&](int l, int r) { return seg.prod(l, r); }, // セグ木を利用
    [](long long a, long long b) { return a + b; } // 計上の二項演算
);

```

