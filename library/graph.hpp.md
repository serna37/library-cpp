---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"library/graph.hpp\"\n/**\n * @file graph.hpp\n * @brief\
    \ \u30B0\u30E9\u30D5\n */\n// \u8FBA\ntemplate <typename T> struct Edge {\n  \
    \  int from, to;\n    T cost;\n    int id;\n    Edge(int from, int to, T cost\
    \ = 1, int id = -1)\n        : from(from), to(to), cost(cost), id(id) {};\n};\n\
    // \u30B0\u30E9\u30D5\ntemplate <typename T> struct Graph {\n    vector<vector<Edge<T>>>\
    \ G;\n    Graph(int N) : G(N) {};\n    vector<Edge<T>> operator[](T v) const {\n\
    \        return G[v];\n    }\n    int size() const {\n        return G.size();\n\
    \    }\n    // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n    void add(int from,\
    \ int to, T cost = 1, int id = -1) {\n        G[from].push_back({from, to, cost,\
    \ id});\n    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n    void\
    \ add_both(int from, int to) {\n        G[from].push_back({from, to, 1, -1});\n\
    \        G[to].push_back({to, from, 1, -1});\n    }\n    // \u30C7\u30D0\u30C3\
    \u30B0\u8868\u793A\n    void dump() {\n        for (int i = 0; i < (int)G.size();\
    \ ++i) {\n            cerr << i << \": \";\n            for (auto &&edge : G[i])\
    \ {\n                cerr << edge.to << \" \";\n            }\n            cerr\
    \ << endl;\n        }\n    }\n};\n// BFS bfs(G); bfs(G, vector<int>{0});\ntemplate\
    \ <typename T>\nvector<int> bfs(const Graph<T> &G, const vector<int> &starts =\
    \ {0}) {\n    queue<int> q;\n    vector<int> dis(2e6, -1);\n    for (auto &&v\
    \ : starts) {\n        q.push(v);\n        dis[v] = 0;\n    }\n    while (!q.empty())\
    \ {\n        int v = q.front();\n        q.pop();\n        for (auto &&[from,\
    \ to, cost, id] : G[v]) {\n            if (dis[to] == -1) {\n                dis[to]\
    \ = dis[from] + 1;\n                q.push(to);\n            }\n        }\n  \
    \  }\n    return dis;\n}\n"
  code: "#pragma once\n/**\n * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\
    // \u8FBA\ntemplate <typename T> struct Edge {\n    int from, to;\n    T cost;\n\
    \    int id;\n    Edge(int from, int to, T cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {};\n};\n// \u30B0\u30E9\u30D5\ntemplate <typename\
    \ T> struct Graph {\n    vector<vector<Edge<T>>> G;\n    Graph(int N) : G(N) {};\n\
    \    vector<Edge<T>> operator[](T v) const {\n        return G[v];\n    }\n  \
    \  int size() const {\n        return G.size();\n    }\n    // (\u6709\u5411)\u8FBA\
    \u3092\u5F35\u308B\n    void add(int from, int to, T cost = 1, int id = -1) {\n\
    \        G[from].push_back({from, to, cost, id});\n    }\n    // (\u53CC\u65B9\
    \u5411)\u8FBA\u3092\u5F35\u308B\n    void add_both(int from, int to) {\n     \
    \   G[from].push_back({from, to, 1, -1});\n        G[to].push_back({to, from,\
    \ 1, -1});\n    }\n    // \u30C7\u30D0\u30C3\u30B0\u8868\u793A\n    void dump()\
    \ {\n        for (int i = 0; i < (int)G.size(); ++i) {\n            cerr << i\
    \ << \": \";\n            for (auto &&edge : G[i]) {\n                cerr <<\
    \ edge.to << \" \";\n            }\n            cerr << endl;\n        }\n   \
    \ }\n};\n// BFS bfs(G); bfs(G, vector<int>{0});\ntemplate <typename T>\nvector<int>\
    \ bfs(const Graph<T> &G, const vector<int> &starts = {0}) {\n    queue<int> q;\n\
    \    vector<int> dis(2e6, -1);\n    for (auto &&v : starts) {\n        q.push(v);\n\
    \        dis[v] = 0;\n    }\n    while (!q.empty()) {\n        int v = q.front();\n\
    \        q.pop();\n        for (auto &&[from, to, cost, id] : G[v]) {\n      \
    \      if (dis[to] == -1) {\n                dis[to] = dis[from] + 1;\n      \
    \          q.push(to);\n            }\n        }\n    }\n    return dis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph.hpp
  requiredBy: []
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph.hpp
layout: document
redirect_from:
- /library/library/graph.hpp
- /library/library/graph.hpp.html
title: "\u30B0\u30E9\u30D5"
---
