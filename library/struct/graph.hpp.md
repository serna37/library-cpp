---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/struct/graph.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**               \u30B0\
    \u30E9\u30D5                    */\n/** =======================================\
    \ */\n#pragma once\nstruct Edge {\n    int from, to;\n    long long cost;\n  \
    \  Edge(int from, int to, long long cost = 1)\n        : from(from), to(to), cost(cost)\
    \ {\n    }\n};\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>>\
    \ G;\n\n  public:\n    Graph(int N) : N(N), G(N) {\n    }\n    vector<Edge> operator[](int\
    \ v) {\n        return G[v];\n    }\n    int size() {\n        return N;\n   \
    \ }\n    // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n    void add(int from, int\
    \ to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost));\n\
    \    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n    void add_both(int\
    \ from, int to) {\n        G[from].push_back(Edge(from, to));\n        G[to].push_back(Edge(to,\
    \ from));\n    }\n    // \u7D4C\u8DEF\u5FA9\u5143\n    vector<int> route_restore(const\
    \ vector<int> &route, int goal) {\n        vector<int> path = {goal};\n      \
    \  while (!~route[path.back()]) path.push_back(route[path.back()]);\n        reverse(all(path));\n\
    \        return path;\n    }\n    /**\n     * BFS \u6700\u77ED\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n\
    \     */\n    pair<vector<int>, vector<int>> bfs(const vector<int> &starts = {0})\
    \ {\n        queue<int> q;\n        vector<int> dis(N, -1), route(N, -1);\n  \
    \      for (auto &&v : starts) q.push(v), dis[v] = 0;\n        while (!q.empty())\
    \ {\n            int v = q.front();\n            q.pop();\n            for (auto\
    \ &&[from, to, cost] : G[v]) {\n                if (~dis[to]) continue;\n    \
    \            dis[to] = dis[from] + 1;\n                q.push(to);\n         \
    \       route[to] = v;\n            }\n        }\n        return {dis, route};\n\
    \    }\n    /**\n     * Dijkstra \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\
    \n     */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int>\
    \ &starts = {\n                                                      0}) {\n \
    \       reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\
    \u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N, INF);\n     \
    \   vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0, v),\
    \ weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] = q.top();\n\
    \            q.pop();\n            if (weight[v] < w) continue;\n            for\
    \ (auto &&[from, to, cost] : G[v]) {\n                long long next_w = w + cost;\n\
    \                if (weight[to] <= next_w) continue;\n                weight[to]\
    \ = next_w;\n                q.emplace(weight[to], to);\n                route[to]\
    \ = v;\n            }\n        }\n        return {weight, route};\n    }\n   \
    \ /**\n     * DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\
    \     */\n    vector<int> topological_sort() {\n        // TODO \u9589\u8DEF\u691C\
    \u77E5\u3057\u3066\u7A7A\u914D\u5217\u3092\u8FD4\u5374\u3068\u304B\n        vector<int>\
    \ seen(N, 0), sorted;\n        auto dfs = [&](auto &f, int v) -> void {\n    \
    \        seen[v] = 1;\n            for (auto &&[from, to, cost] : G[v]) {\n  \
    \              if (!seen[to]) f(f, to);\n            }\n            sorted.push_back(v);\n\
    \        };\n        for (int i = 0; i < N; ++i) {\n            if (!seen[i])\
    \ dfs(dfs, i);\n        }\n        reverse(all(sorted));\n        return sorted;\n\
    \    }\n    // TODO cc\n    // TODO scc\n    // TODO \u30D9\u30EB\u30DE\u30F3\u30D5\
    \u30A9\u30FC\u30C9\n    // TODO \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\n    // TODO\
    \ \u30AF\u30E9\u30B9\u30AB\u30EB\n    // TODO \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\n    // TODO \u30C9\u30AD\u30E5\u30E1\u30F3\u30C8\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/graph.hpp
  requiredBy: []
  timestamp: '2026-01-03 22:10:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/struct/graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5"
---


いろいろ含んだグラフの構造体

- 経路復元
- BFS 最短経路 複数始点
- Dijkstra 最小コスト経路 複数始点
- DAGのトポロジカルソート
- TODO いろいろ追加中

