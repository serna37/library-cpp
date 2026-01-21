---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.heavy_light_decomposition.test.cpp
    title: "\u6728 - HLD\u306E\u30C6\u30B9\u30C8 \u6728\u4E0A\u30AF\u30A8\u30EA:\u6700\
      \u5927\u9023\u7D9A\u90E8\u5206\u5217\u548C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n    int N;\n\
    \    vector<vector<Edge>> G;\n    int es;\n    Graph() = default;\n    Graph(int\
    \ N) : N(N), G(N), es(0) {}\n    const vector<Edge> &operator[](int v) const {\
    \ return G[v]; }\n    int size() const { return N; }\n    void add(int from, int\
    \ to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost, es++));\n\
    \    }\n    void add_both(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es));\n        G[to].push_back(Edge(to, from, cost, es++));\n    }\n\
    \    void read(int M, int padding = -1, bool weighted = false,\n             \
    \ bool directed = false) {\n        for (int i = 0; i < M; i++) {\n          \
    \  int u, v;\n            cin >> u >> v;\n            u += padding, v += padding;\n\
    \            long long cost = 1ll;\n            if (weighted) cin >> cost;\n \
    \           if (directed) {\n                add(u, v, cost);\n            } else\
    \ {\n                add_both(u, v, cost);\n            }\n        }\n    }\n\
    };\n#line 3 \"library/graph/tree/heavy_light_decomposition.hpp\"\nstruct HeavyLightDecomposition\
    \ : Graph {\n  public:\n    using Graph::G;\n    using Graph::Graph;\n    vector<int>\
    \ sz, in, out, head, rev, par, dep;\n    void build(int root = 0) {\n        sz.assign(G.size(),\
    \ 0);\n        in.assign(G.size(), 0);\n        out.assign(G.size(), 0);\n   \
    \     head.assign(G.size(), 0);\n        rev.assign(G.size(), 0);\n        par.assign(G.size(),\
    \ 0);\n        dep.assign(G.size(), 0);\n        dfs_sz(root, -1, 0);\n      \
    \  int t = 0;\n        head[root] = root;\n        dfs_hld(root, -1, t);\n   \
    \ }\n    /* k: 0-indexed */\n    int la(int v, int k) {\n        while (1) {\n\
    \            int u = head[v];\n            if (in[v] - k >= in[u]) return rev[in[v]\
    \ - k];\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n      \
    \  }\n    }\n    int lca(int u, int v) const {\n        for (;; v = par[head[v]])\
    \ {\n            if (in[u] > in[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n        }\n    }\n    int dist(int u, int v) const {\n        return\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    template <typename E, typename\
    \ Q, typename F, typename S>\n    E query(int u, int v, const E &ti, const Q &q,\
    \ const F &f, const S &s,\n            bool edge = false) {\n        E l = ti,\
    \ r = ti;\n        for (;; v = par[head[v]]) {\n            if (in[u] > in[v])\
    \ swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n      \
    \      l = f(q(in[head[v]], in[v] + 1), l);\n        }\n        return s(f(q(in[u]\
    \ + edge, in[v] + 1), l), r);\n    }\n    template <typename E, typename Q, typename\
    \ F>\n    E query(int u, int v, const E &ti, const Q &q, const F &f,\n       \
    \     bool edge = false) {\n        return query(u, v, ti, q, f, f, edge);\n \
    \   }\n    template <typename Q>\n    void add(int u, int v, const Q &q, bool\
    \ edge = false) {\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            if (head[u] == head[v]) break;\n         \
    \   q(in[head[v]], in[v] + 1);\n        }\n        q(in[u] + edge, in[v] + 1);\n\
    \    }\n    /* {parent, child} */\n    vector<pair<int, int>> compress(vector<int>\
    \ &remark) {\n        auto cmp = [&](int a, int b) { return in[a] < in[b]; };\n\
    \        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        int K = (int)remark.size();\n        for\
    \ (int k = 1; k < K; k++)\n            remark.emplace_back(lca(remark[k - 1],\
    \ remark[k]));\n        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        vector<pair<int, int>> es;\n        stack<int>\
    \ st;\n        for (auto &k : remark) {\n            while (!st.empty() && out[st.top()]\
    \ <= in[k]) st.pop();\n            if (!st.empty()) es.emplace_back(st.top(),\
    \ k);\n            st.emplace(k);\n        }\n        return es;\n    }\n    explicit\
    \ HeavyLightDecomposition(const Graph &G) : Graph(G) {}\n\n  private:\n    void\
    \ dfs_sz(int idx, int p, int d) {\n        dep[idx] = d;\n        par[idx] = p;\n\
    \        sz[idx] = 1;\n        if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0],\
    \ G[idx].back());\n        for (auto &&edge : G[idx]) {\n            if (edge.to\
    \ == p) continue;\n            dfs_sz(edge.to, idx, d + 1);\n            sz[idx]\
    \ += sz[edge.to];\n            if (sz[G[idx][0].to] < sz[edge.to]) swap(G[idx][0].to,\
    \ edge.to);\n        }\n    }\n    void dfs_hld(int idx, int p, int &times) {\n\
    \        in[idx] = times++;\n        rev[in[idx]] = idx;\n        for (auto &&edge\
    \ : G[idx]) {\n            if (edge.to == p) continue;\n            head[edge.to]\
    \ = (G[idx][0].to == edge.to ? head[idx] : edge.to);\n            dfs_hld(edge.to,\
    \ idx, times);\n        }\n        out[idx] = times;\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\nstruct HeavyLightDecomposition\
    \ : Graph {\n  public:\n    using Graph::G;\n    using Graph::Graph;\n    vector<int>\
    \ sz, in, out, head, rev, par, dep;\n    void build(int root = 0) {\n        sz.assign(G.size(),\
    \ 0);\n        in.assign(G.size(), 0);\n        out.assign(G.size(), 0);\n   \
    \     head.assign(G.size(), 0);\n        rev.assign(G.size(), 0);\n        par.assign(G.size(),\
    \ 0);\n        dep.assign(G.size(), 0);\n        dfs_sz(root, -1, 0);\n      \
    \  int t = 0;\n        head[root] = root;\n        dfs_hld(root, -1, t);\n   \
    \ }\n    /* k: 0-indexed */\n    int la(int v, int k) {\n        while (1) {\n\
    \            int u = head[v];\n            if (in[v] - k >= in[u]) return rev[in[v]\
    \ - k];\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n      \
    \  }\n    }\n    int lca(int u, int v) const {\n        for (;; v = par[head[v]])\
    \ {\n            if (in[u] > in[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n        }\n    }\n    int dist(int u, int v) const {\n        return\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    template <typename E, typename\
    \ Q, typename F, typename S>\n    E query(int u, int v, const E &ti, const Q &q,\
    \ const F &f, const S &s,\n            bool edge = false) {\n        E l = ti,\
    \ r = ti;\n        for (;; v = par[head[v]]) {\n            if (in[u] > in[v])\
    \ swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n      \
    \      l = f(q(in[head[v]], in[v] + 1), l);\n        }\n        return s(f(q(in[u]\
    \ + edge, in[v] + 1), l), r);\n    }\n    template <typename E, typename Q, typename\
    \ F>\n    E query(int u, int v, const E &ti, const Q &q, const F &f,\n       \
    \     bool edge = false) {\n        return query(u, v, ti, q, f, f, edge);\n \
    \   }\n    template <typename Q>\n    void add(int u, int v, const Q &q, bool\
    \ edge = false) {\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            if (head[u] == head[v]) break;\n         \
    \   q(in[head[v]], in[v] + 1);\n        }\n        q(in[u] + edge, in[v] + 1);\n\
    \    }\n    /* {parent, child} */\n    vector<pair<int, int>> compress(vector<int>\
    \ &remark) {\n        auto cmp = [&](int a, int b) { return in[a] < in[b]; };\n\
    \        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        int K = (int)remark.size();\n        for\
    \ (int k = 1; k < K; k++)\n            remark.emplace_back(lca(remark[k - 1],\
    \ remark[k]));\n        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        vector<pair<int, int>> es;\n        stack<int>\
    \ st;\n        for (auto &k : remark) {\n            while (!st.empty() && out[st.top()]\
    \ <= in[k]) st.pop();\n            if (!st.empty()) es.emplace_back(st.top(),\
    \ k);\n            st.emplace(k);\n        }\n        return es;\n    }\n    explicit\
    \ HeavyLightDecomposition(const Graph &G) : Graph(G) {}\n\n  private:\n    void\
    \ dfs_sz(int idx, int p, int d) {\n        dep[idx] = d;\n        par[idx] = p;\n\
    \        sz[idx] = 1;\n        if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0],\
    \ G[idx].back());\n        for (auto &&edge : G[idx]) {\n            if (edge.to\
    \ == p) continue;\n            dfs_sz(edge.to, idx, d + 1);\n            sz[idx]\
    \ += sz[edge.to];\n            if (sz[G[idx][0].to] < sz[edge.to]) swap(G[idx][0].to,\
    \ edge.to);\n        }\n    }\n    void dfs_hld(int idx, int p, int &times) {\n\
    \        in[idx] = times++;\n        rev[in[idx]] = idx;\n        for (auto &&edge\
    \ : G[idx]) {\n            if (edge.to == p) continue;\n            head[edge.to]\
    \ = (G[idx][0].to == edge.to ? head[idx] : edge.to);\n            dfs_hld(edge.to,\
    \ idx, times);\n        }\n        out[idx] = times;\n    }\n};\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2026-01-21 19:52:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.heavy_light_decomposition.test.cpp
documentation_of: library/graph/tree/heavy_light_decomposition.hpp
layout: document
title: "\u91CD\u8EFD\u5206\u89E3"
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

