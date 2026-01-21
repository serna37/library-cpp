---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph.tree.tree_isomorphism.test.cpp
    title: "\u6728 - \u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/base/edge.hpp\"\nstruct Edge {\n    int from,\
    \ to;\n    long long cost;\n    int idx;\n    Edge(int from, int to, long long\
    \ cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n};\n#line 3 \"library/graph/base/graph.hpp\"\nstruct Graph {\n  private:\n\
    \    int N;\n    vector<vector<Edge>> G;\n    int es;\n\n  public:\n    Graph(int\
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
    };\n#line 3 \"library/graph/tree/centroid.hpp\"\nvector<int> centroid(const Graph\
    \ &G) {\n    const int N = (int)G.size();\n    stack<pair<int, int>> st;\n   \
    \ st.emplace(0ll, -1ll);\n    vector<int> sz(N), par(N);\n    while (!st.empty())\
    \ {\n        auto p = st.top();\n        if (sz[p.first] == 0ll) {\n         \
    \   sz[p.first] = 1;\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) st.emplace(to, p.first);\n          \
    \  }\n        } else {\n            for (auto &&[from, to, cost, idx] : G[p.first])\
    \ {\n                if (to != p.second) sz[p.first] += sz[to];\n            }\n\
    \            par[p.first] = p.second;\n            st.pop();\n        }\n    }\n\
    \    vector<int> ret;\n    int size = N;\n    for (int i = 0; i < N; ++i) {\n\
    \        int val = N - sz[i];\n        for (auto &&[from, to, cost, idx] : G[i])\
    \ {\n            if (to != par[i]) val = max(val, sz[to]);\n        }\n      \
    \  if (val < size) size = val, ret.clear();\n        if (val == size) ret.emplace_back(i);\n\
    \    }\n    return ret;\n}\n#line 4 \"library/graph/tree/tree_isomorphism.hpp\"\
    \nbool tree_isomorphism(const Graph &a, const Graph &b) {\n    if (a.size() !=\
    \ b.size()) return false;\n    const int N = (int)a.size();\n    using pvi = pair<vector<int>,\
    \ vector<int>>;\n    auto get_uku = [&](const Graph &t, int e) {\n        stack<pair<int,\
    \ int>> st;\n        st.emplace(e, -1);\n        vector<int> dep(N, -1), par(N);\n\
    \        while (!st.empty()) {\n            auto p = st.top();\n            if\
    \ (dep[p.first] == -1ll) {\n                dep[p.first] = p.second == -1ll ?\
    \ 0 : dep[p.second] + 1;\n                for (auto &&[from, to, cost, idx] :\
    \ t[p.first]) {\n                    if (to != p.second) st.emplace(to, p.first);\n\
    \                }\n            } else {\n                par[p.first] = p.second;\n\
    \                st.pop();\n            }\n        }\n        return make_pair(dep,\
    \ par);\n    };\n    auto judge = [&](const pvi &latte, const pvi &malta) {\n\
    \        int d = *max_element(begin(latte.first), end(latte.first));\n       \
    \ if (d != *max_element(begin(malta.first), end(malta.first))) {\n           \
    \ return false;\n        }\n        vector<vector<int>> latte_d(d + 1), malta_d(d\
    \ + 1), latte_key(N),\n            malta_key(N);\n        for (int i = 0; i <\
    \ N; i++) latte_d[latte.first[i]].emplace_back(i);\n        for (int i = 0; i\
    \ < N; i++) malta_d[malta.first[i]].emplace_back(i);\n        for (int i = d;\
    \ i >= 0ll; i--) {\n            map<vector<int>, int> ord;\n            for (auto\
    \ &idx : latte_d[i]) {\n                sort(begin(latte_key[idx]), end(latte_key[idx]));\n\
    \                ord[latte_key[idx]]++;\n            }\n            for (auto\
    \ &idx : malta_d[i]) {\n                sort(begin(malta_key[idx]), end(malta_key[idx]));\n\
    \                if (--ord[malta_key[idx]] < 0ll) return false;\n            }\n\
    \            if (i == 0ll) return ord.size() == 1ll;\n            int ptr = 0;\n\
    \            for (auto &p : ord) {\n                if (p.second != 0ll) return\
    \ false;\n                p.second = ptr++;\n            }\n            for (auto\
    \ &idx : latte_d[i]) {\n                latte_key[latte.second[idx]].emplace_back(ord[latte_key[idx]]);\n\
    \            }\n            for (auto &idx : malta_d[i]) {\n                malta_key[malta.second[idx]].emplace_back(ord[malta_key[idx]]);\n\
    \            }\n        }\n        assert(0);\n    };\n    auto p = centroid(a),\
    \ q = centroid(b);\n    if (p.size() != q.size()) return false;\n    auto a1 =\
    \ get_uku(a, p[0]);\n    auto b1 = get_uku(b, q[0]);\n    if (judge(a1, b1)) return\
    \ true;\n    if (p.size() == 1ll) return false;\n    auto a2 = get_uku(a, p[1]);\n\
    \    return judge(a2, b1);\n}\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\n#include \"library/graph/tree/centroid.hpp\"\
    \nbool tree_isomorphism(const Graph &a, const Graph &b) {\n    if (a.size() !=\
    \ b.size()) return false;\n    const int N = (int)a.size();\n    using pvi = pair<vector<int>,\
    \ vector<int>>;\n    auto get_uku = [&](const Graph &t, int e) {\n        stack<pair<int,\
    \ int>> st;\n        st.emplace(e, -1);\n        vector<int> dep(N, -1), par(N);\n\
    \        while (!st.empty()) {\n            auto p = st.top();\n            if\
    \ (dep[p.first] == -1ll) {\n                dep[p.first] = p.second == -1ll ?\
    \ 0 : dep[p.second] + 1;\n                for (auto &&[from, to, cost, idx] :\
    \ t[p.first]) {\n                    if (to != p.second) st.emplace(to, p.first);\n\
    \                }\n            } else {\n                par[p.first] = p.second;\n\
    \                st.pop();\n            }\n        }\n        return make_pair(dep,\
    \ par);\n    };\n    auto judge = [&](const pvi &latte, const pvi &malta) {\n\
    \        int d = *max_element(begin(latte.first), end(latte.first));\n       \
    \ if (d != *max_element(begin(malta.first), end(malta.first))) {\n           \
    \ return false;\n        }\n        vector<vector<int>> latte_d(d + 1), malta_d(d\
    \ + 1), latte_key(N),\n            malta_key(N);\n        for (int i = 0; i <\
    \ N; i++) latte_d[latte.first[i]].emplace_back(i);\n        for (int i = 0; i\
    \ < N; i++) malta_d[malta.first[i]].emplace_back(i);\n        for (int i = d;\
    \ i >= 0ll; i--) {\n            map<vector<int>, int> ord;\n            for (auto\
    \ &idx : latte_d[i]) {\n                sort(begin(latte_key[idx]), end(latte_key[idx]));\n\
    \                ord[latte_key[idx]]++;\n            }\n            for (auto\
    \ &idx : malta_d[i]) {\n                sort(begin(malta_key[idx]), end(malta_key[idx]));\n\
    \                if (--ord[malta_key[idx]] < 0ll) return false;\n            }\n\
    \            if (i == 0ll) return ord.size() == 1ll;\n            int ptr = 0;\n\
    \            for (auto &p : ord) {\n                if (p.second != 0ll) return\
    \ false;\n                p.second = ptr++;\n            }\n            for (auto\
    \ &idx : latte_d[i]) {\n                latte_key[latte.second[idx]].emplace_back(ord[latte_key[idx]]);\n\
    \            }\n            for (auto &idx : malta_d[i]) {\n                malta_key[malta.second[idx]].emplace_back(ord[malta_key[idx]]);\n\
    \            }\n        }\n        assert(0);\n    };\n    auto p = centroid(a),\
    \ q = centroid(b);\n    if (p.size() != q.size()) return false;\n    auto a1 =\
    \ get_uku(a, p[0]);\n    auto b1 = get_uku(b, q[0]);\n    if (judge(a1, b1)) return\
    \ true;\n    if (p.size() == 1ll) return false;\n    auto a2 = get_uku(a, p[1]);\n\
    \    return judge(a2, b1);\n}\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/graph/tree/centroid.hpp
  isVerificationFile: false
  path: library/graph/tree/tree_isomorphism.hpp
  requiredBy: []
  timestamp: '2026-01-21 10:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph.tree.tree_isomorphism.test.cpp
documentation_of: library/graph/tree/tree_isomorphism.hpp
layout: document
title: "\u6728\u306E\u540C\u578B\u6027\u5224\u5B9A"
---

# 木の同型性判定

## できること
- 見た目の描き方は違っても、グラフとしての構造（つながり方）が本質的に同じかどうかを判定
- 定義: 2つの木 $T_1$ と $T_2$ の頂点の番号をうまく付け替えることで $T_1$ と $T_2$ を全く同じ形にできるとき、同型である
- 部分木の検索や木の圧縮、重複排除などに活用できる

## 計算量
$O(N \log N)$

## 使い方
```cpp
bool is_same = tree_isomorphism(t, g);
```

