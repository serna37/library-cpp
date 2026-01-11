---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: library/graph/base/edge.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: library/graph/base/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/shortest_path/bfs.test.cpp
    title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
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
    \           route[to] = v;\n        }\n    }\n    return {dis, route};\n}\n"
  code: "#pragma once\n#include \"library/graph/base/graph.hpp\"\npair<vector<int>,\
    \ vector<int>> bfs(const Graph &G,\n                                   const vector<int>\
    \ &starts = {0}) {\n    int N = G.size();\n    queue<int> q;\n    vector<int>\
    \ dis(N, -1), route(N, -1);\n    for (auto &&v : starts) q.push(v), dis[v] = 0;\n\
    \    while (!q.empty()) {\n        int v = q.front();\n        q.pop();\n    \
    \    for (auto &&[from, to, cost, idx] : G[v]) {\n            if (~dis[to]) continue;\n\
    \            dis[to] = dis[from] + 1;\n            q.push(to);\n            route[to]\
    \ = v;\n        }\n    }\n    return {dis, route};\n}\n"
  dependsOn:
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: false
  path: library/graph/shortest_path/bfs.hpp
  requiredBy: []
  timestamp: '2026-01-11 17:31:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/shortest_path/bfs.test.cpp
documentation_of: library/graph/shortest_path/bfs.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/bfs.hpp
- /library/library/graph/shortest_path/bfs.hpp.html
title: library/graph/shortest_path/bfs.hpp
---
