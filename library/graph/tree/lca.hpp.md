---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/doubling.hpp
    title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/bfs.hpp
    title: BFS
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.lca.test.cpp
    title: "\u6728 - LCA\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {\n    }\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n  private:\n\
    \    int N;\n    vector<vector<Edge>> G;\n    int es;\n\n  public:\n    Graph(int\
    \ N) : N(N), G(N), es(0) {\n    }\n    const vector<Edge> &operator[](int v) const\
    \ {\n        return G[v];\n    }\n    int size() const {\n        return N;\n\
    \    }\n    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es++));\n    }\n    void add_both(int from, int to, long long cost\
    \ = 1) {\n        G[from].push_back(Edge(from, to, cost, es));\n        G[to].push_back(Edge(to,\
    \ from, cost, es++));\n    }\n    void read(int M, int padding = -1, bool weighted\
    \ = false,\n              bool directed = false) {\n        for (int i = 0; i\
    \ < M; i++) {\n            int u, v;\n            cin >> u >> v;\n           \
    \ u += padding, v += padding;\n            long long cost = 1ll;\n           \
    \ if (weighted) cin >> cost;\n            if (directed) {\n                add(u,\
    \ v, cost);\n            } else {\n                add_both(u, v, cost);\n   \
    \         }\n        }\n    }\n};\n#line 3 \"library/graph/shortest_path/bfs.hpp\"\
    \npair<vector<int>, vector<int>> bfs(const Graph &G,\n                       \
    \            const vector<int> &starts = {0}) {\n    int N = G.size();\n    queue<int>\
    \ q;\n    vector<int> dis(N, -1), route(N, -1);\n    for (auto &&v : starts) q.push(v),\
    \ dis[v] = 0;\n    while (!q.empty()) {\n        int v = q.front();\n        q.pop();\n\
    \        for (auto &&[from, to, cost, idx] : G[v]) {\n            if (~dis[to])\
    \ continue;\n            dis[to] = dis[from] + 1;\n            q.push(to);\n \
    \           route[to] = v;\n        }\n    }\n    return {dis, route};\n}\n#line\
    \ 2 \"library/dp/doubling.hpp\"\ntemplate <typename T> struct Doubling {\n   \
    \ int N, log = 0;\n    vector<vector<T>> table;\n    Doubling() {}\n    Doubling(const\
    \ vector<T> &next, long long max_steps) {\n        N = next.size();\n        while\
    \ ((1ll << log) <= max_steps) ++log;\n        table.assign(log, vector<T>(N, T()));\n\
    \        table[0] = next;\n        for (int k = 0; k < log - 1; ++k) {\n     \
    \       for (int v = 0; v < N; ++v) {\n                if (table[k][v].to == T::e)\
    \ {\n                    table[k + 1][v] = table[k][v];\n                } else\
    \ {\n                    table[k + 1][v] = table[k][v] + table[k][table[k][v].to];\n\
    \                }\n            }\n        }\n    }\n    T query(int v, long long\
    \ steps) const {\n        T res;\n        res.to = v;\n        for (int k = 0;\
    \ k < log; ++k) {\n            if ((steps >> k) & 1) {\n                if (res.to\
    \ == T::e) break;\n                res = res + table[k][res.to];\n           \
    \ }\n        }\n        return res;\n    }\n};\n#line 4 \"library/graph/tree/lca.hpp\"\
    \nstruct Node {\n    static const int e = -1;\n    int to = e;\n    long long\
    \ dist = 0;\n    Node() = default;\n    Node(int to, long long dist) : to(to),\
    \ dist(dist) {}\n    Node operator+(const Node &A) const {\n        if (to ==\
    \ e) return *this;\n        return {A.to, dist + A.dist};\n    }\n};\nstruct LCA\
    \ {\n    vector<int> depth;\n    Doubling<Node> db;\n    LCA(const Graph &G, int\
    \ root = 0) {\n        int N = G.size();\n        // 1. \u65E2\u5B58\u306EBFS\u3092\
    \u5229\u7528\u3057\u3066\u6DF1\u3055\u3068\u89AA\u3092\u53D6\u5F97\n        auto\
    \ [dis, route] = bfs(G, {root});\n        depth = dis;\n        // 2. Node(\u89AA\
    \u3078\u306E\u79FB\u52D5\u5148, \u305D\u306E\u30A8\u30C3\u30B8\u306E\u30B3\u30B9\
    \u30C8) \u306E\u521D\u671F\u914D\u5217\u3092\u4F5C\u6210\n        // bfs\u306E\
    \u7D50\u679C(route)\u306B\u306F\u30B3\u30B9\u30C8\u304C\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\u305F\u3081\u3001\u30B0\u30E9\u30D5\u304B\u3089\u53D6\u5F97\
    \n        vector<Node> next(N, Node(Node::e, 0));\n        for (int v = 0; v <\
    \ N; ++v) {\n            int p = route[v];\n            if (p != -1) {\n     \
    \           // v\u304B\u3089\u89AAp\u3078\u306E\u30A8\u30C3\u30B8\u30B3\u30B9\u30C8\
    \u3092\u63A2\u3059\n                for (auto &e : G[v]) {\n                 \
    \   if (e.to == p) {\n                        next[v] = Node(p, e.cost);\n   \
    \                     break;\n                    }\n                }\n     \
    \       }\n        }\n        // 3. \u30C0\u30D6\u30EA\u30F3\u30B0\u69CB\u7BC9\
    \n        db = Doubling<Node>(next, N);\n    }\n    int get_lca(int u, int v)\
    \ const {\n        if (depth[u] > depth[v]) swap(u, v);\n        v = db.query(v,\
    \ depth[v] - depth[u]).to;\n        if (u == v) return u;\n        for (int k\
    \ = db.log - 1; k >= 0; --k) {\n            if (db.table[k][u].to != db.table[k][v].to)\
    \ {\n                u = db.table[k][u].to;\n                v = db.table[k][v].to;\n\
    \            }\n        }\n        return db.table[0][u].to;\n    }\n    long\
    \ long get_dist(int u, int v) const {\n        int lca = get_lca(u, v);\n    \
    \    return db.query(u, depth[u] - depth[lca]).dist + \n               db.query(v,\
    \ depth[v] - depth[lca]).dist;\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/shortest_path/bfs.hpp\"\n#include\
    \ \"library/dp/doubling.hpp\"\nstruct Node {\n    static const int e = -1;\n \
    \   int to = e;\n    long long dist = 0;\n    Node() = default;\n    Node(int\
    \ to, long long dist) : to(to), dist(dist) {}\n    Node operator+(const Node &A)\
    \ const {\n        if (to == e) return *this;\n        return {A.to, dist + A.dist};\n\
    \    }\n};\nstruct LCA {\n    vector<int> depth;\n    Doubling<Node> db;\n   \
    \ LCA(const Graph &G, int root = 0) {\n        int N = G.size();\n        // 1.\
    \ \u65E2\u5B58\u306EBFS\u3092\u5229\u7528\u3057\u3066\u6DF1\u3055\u3068\u89AA\u3092\
    \u53D6\u5F97\n        auto [dis, route] = bfs(G, {root});\n        depth = dis;\n\
    \        // 2. Node(\u89AA\u3078\u306E\u79FB\u52D5\u5148, \u305D\u306E\u30A8\u30C3\
    \u30B8\u306E\u30B3\u30B9\u30C8) \u306E\u521D\u671F\u914D\u5217\u3092\u4F5C\u6210\
    \n        // bfs\u306E\u7D50\u679C(route)\u306B\u306F\u30B3\u30B9\u30C8\u304C\u542B\
    \u307E\u308C\u3066\u3044\u306A\u3044\u305F\u3081\u3001\u30B0\u30E9\u30D5\u304B\
    \u3089\u53D6\u5F97\n        vector<Node> next(N, Node(Node::e, 0));\n        for\
    \ (int v = 0; v < N; ++v) {\n            int p = route[v];\n            if (p\
    \ != -1) {\n                // v\u304B\u3089\u89AAp\u3078\u306E\u30A8\u30C3\u30B8\
    \u30B3\u30B9\u30C8\u3092\u63A2\u3059\n                for (auto &e : G[v]) {\n\
    \                    if (e.to == p) {\n                        next[v] = Node(p,\
    \ e.cost);\n                        break;\n                    }\n          \
    \      }\n            }\n        }\n        // 3. \u30C0\u30D6\u30EA\u30F3\u30B0\
    \u69CB\u7BC9\n        db = Doubling<Node>(next, N);\n    }\n    int get_lca(int\
    \ u, int v) const {\n        if (depth[u] > depth[v]) swap(u, v);\n        v =\
    \ db.query(v, depth[v] - depth[u]).to;\n        if (u == v) return u;\n      \
    \  for (int k = db.log - 1; k >= 0; --k) {\n            if (db.table[k][u].to\
    \ != db.table[k][v].to) {\n                u = db.table[k][u].to;\n          \
    \      v = db.table[k][v].to;\n            }\n        }\n        return db.table[0][u].to;\n\
    \    }\n    long long get_dist(int u, int v) const {\n        int lca = get_lca(u,\
    \ v);\n        return db.query(u, depth[u] - depth[lca]).dist + \n           \
    \    db.query(v, depth[v] - depth[lca]).dist;\n    }\n};\n"
  dependsOn:
  - library/graph/shortest_path/bfs.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/dp/doubling.hpp
  isVerificationFile: false
  path: library/graph/tree/lca.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.lca.test.cpp
documentation_of: library/graph/tree/lca.hpp
layout: document
title: LCA
---

# LCA

## できること
- LCA(木の最小共通祖先)を求める
- 木上の2頂点間の距離を求める
- BFSで1つ親を走査後、ダブリングテーブルを構築している

## 計算量
- 構築: $O(NlogN)$
- `get_lca`: $O(logN)$
- `get_dist`: $O(logN)$

## 使い方
```cpp
int N = 5;
Graph G(N);
// 0-1(10), 1-2(20), 1-3(30), 3-4(40)
G.add_both(0, 1, 10);
G.add_both(1, 2, 20);
G.add_both(1, 3, 30);
G.add_both(3, 4, 40);

LCA tree(G, 0); // 根が0

// 頂点2と頂点4の距離
// パス: 2 - (20) - 1 - (30) - 3 - (40) - 4  => 合計 90
long long dis = tree.get_dist(2, 4);
// LCAは1
int lca = tree.get_lca(2, 4);
```
