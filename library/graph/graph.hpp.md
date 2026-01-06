---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/bellman_ford.test.cpp
    title: "\u30B0\u30E9\u30D5 - BellmanFord\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\u30B9\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/cycle_detect.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9589\u8DEF\u691C\u51FA\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5 - Dijkstra\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      \u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/warshall_froyd.test.cpp
    title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\n/**\n * @brief \u8FBA\n */\nstruct\
    \ Edge {\n    int from, to;\n    long long cost;\n    int idx;\n    Edge(int from,\
    \ int to, long long cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {\n    }\n};\n#line 3 \"library/graph/graph.hpp\"\n/**\n * @brief \u30B0\
    \u30E9\u30D5\n */\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>>\
    \ G;\n    int es;\n\n  public:\n    Graph(int N) : N(N), G(N), es(0) {\n    }\n\
    \    const vector<Edge> &operator[](int v) const {\n        return G[v];\n   \
    \ }\n    int size() {\n        return N;\n    }\n    // (\u6709\u5411)\u8FBA\u3092\
    \u5F35\u308B\n    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es++));\n    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\
    \n    void add_both(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es));\n        G[to].push_back(Edge(to, from, cost, es++));\n    }\n\
    \    // \u30B0\u30E9\u30D5\u3092\u8AAD\u307F\u53D6\u308B\n    void read(int M,\
    \ int padding = -1, bool weighted = false,\n              bool directed = false)\
    \ {\n        for (int i = 0; i < M; i++) {\n            int u, v;\n          \
    \  cin >> u >> v;\n            u += padding, v += padding;\n            long long\
    \ cost = 1ll;\n            if (weighted) cin >> cost;\n            if (directed)\
    \ {\n                add(u, v, cost);\n            } else {\n                add_both(u,\
    \ v, cost);\n            }\n        }\n    }\n    // \u7D4C\u8DEF\u5FA9\u5143\n\
    \    vector<int> route_restore(const vector<int> &route, int goal) {\n       \
    \ vector<int> path = {goal};\n        while (!!~route[path.back()]) path.push_back(route[path.back()]);\n\
    \        reverse(all(path));\n        return path;\n    }\n    /**\n     * BFS\
    \ \u6700\u77ED\u7D4C\u8DEF \u8907\u6570\u59CB\u70B9 O(V+E)\n     * @param starts\
    \ \u59CB\u70B9\u306E\u914D\u5217 \u30C7\u30D5\u30A9\u30EB\u30C80\u306E\u307F\n\
    \     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n     */\n    pair<vector<int>,\
    \ vector<int>> bfs(const vector<int> &starts = {0}) {\n        queue<int> q;\n\
    \        vector<int> dis(N, -1), route(N, -1);\n        for (auto &&v : starts)\
    \ q.push(v), dis[v] = 0;\n        while (!q.empty()) {\n            int v = q.front();\n\
    \            q.pop();\n            for (auto &&[from, to, cost, idx] : G[v]) {\n\
    \                if (~dis[to]) continue;\n                dis[to] = dis[from]\
    \ + 1;\n                q.push(to);\n                route[to] = v;\n        \
    \    }\n        }\n        return {dis, route};\n    }\n    /**\n     * Dijkstra\
    \ \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\u6570\u59CB\u70B9 O(ElogV)\n\
    \     * @param starts \u59CB\u70B9\u306E\u914D\u5217 \u30C7\u30D5\u30A9\u30EB\u30C8\
    0\u306E\u307F\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\
    \n     */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int>\
    \ &starts = {\n                                                      0}) {\n \
    \       reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\
    \u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N, INF);\n     \
    \   vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0, v),\
    \ weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] = q.top();\n\
    \            q.pop();\n            if (weight[v] < w) continue;\n            for\
    \ (auto &&[from, to, cost, idx] : G[v]) {\n                long long next_w =\
    \ w + cost;\n                if (weight[to] <= next_w) continue;\n           \
    \     weight[to] = next_w;\n                q.emplace(weight[to], to);\n     \
    \           route[to] = v;\n            }\n        }\n        return {weight,\
    \ route};\n    }\n    /**\n     * BellmanFord \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\
    \u8DEF \u8CA0\u91CD\u307FOK O(VE)\n     * @param s \u59CB\u70B9 \u30C7\u30D5\u30A9\
    \u30EB\u30C80\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u8CA0\u30B5\
    \u30A4\u30AF\u30EB\u6709\u7121\u3001\u7D4C\u8DEF\n     */\n    tuple<vector<long\
    \ long>, bool, vector<int>> bellman_ford(int s = 0) {\n        int loop = 0;\n\
    \        vector<long long> dis(N, INF);\n        vector<int> route(N, -1);\n \
    \       dis[s] = 0;\n        while (1) {\n            ++loop;\n            bool\
    \ upd = 0;\n            for (int v = 0; v < N; ++v) {\n                if (dis[v]\
    \ == INF) continue;\n                for (auto &&[from, to, cost, idx] : G[v])\
    \ {\n                    long long asis = dis[to], tobe = dis[v] + cost;\n   \
    \                 if (dis[v] == -INF) tobe = -INF;\n                    tobe =\
    \ max(tobe, -INF);\n                    if (asis <= tobe) continue;\n        \
    \            if (loop >= N) tobe = -INF;\n                    dis[to] = tobe;\n\
    \                    route[to] = v;\n                    upd = 1;\n          \
    \      }\n            }\n            if (!upd) break;\n        }\n        bool\
    \ negativeCycle = false;\n        for (auto &&v : dis) {\n            if (v ==\
    \ -INF) {\n                negativeCycle = true;\n                break;\n   \
    \         }\n        }\n        return {dis, negativeCycle, route};\n    }\n \
    \   /**\n     * WarshallFroyd \u5168\u9802\u70B9\u5BFE \u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF O(N^3)\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\
    \u8CA0\u30B5\u30A4\u30AF\u30EB\u6709\u7121\n     */\n    pair<vector<vector<long\
    \ long>>, bool> warshall_froyd() {\n        vector<vector<long long>> dis(N, vector<long\
    \ long>(N, INF));\n        for (int v = 0; v < N; ++v) {\n            dis[v][v]\
    \ = 0;\n            for (auto &&[from, to, cost, idx] : G[v]) {\n            \
    \    dis[v][to] = min(dis[v][to], cost);\n            }\n        }\n        for\
    \ (int k = 0; k < N; ++k) {\n            for (int i = 0; i < N; ++i) {\n     \
    \           if (dis[i][k] == INF) continue;\n                for (int j = 0; j\
    \ < N; ++j) {\n                    if (dis[k][j] == INF) continue;\n         \
    \           dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);\n             \
    \   }\n            }\n        }\n        bool negativeCycle = false;\n       \
    \ for (int i = 0; i < N; ++i) {\n            if (dis[i][i] < 0) {\n          \
    \      negativeCycle = true;\n                break;\n            }\n        }\n\
    \        return {dis, negativeCycle};\n    }\n    /**\n     * \u9589\u8DEF\u691C\
    \u51FA O(V+E)\n     * @param directed \u6709\u5411\u306A\u3089 `true` \u30C7\u30D5\
    \u30A9\u30EB\u30C8 `true`\n     * @return \u30B5\u30A4\u30AF\u30EB\u306A\u8FBA\
    \u306E\u96C6\u5408\n     */\n    vector<Edge> cycle_detect(bool directed = true)\
    \ {\n        vector<bool> seen(N), finished(N);\n        vector<Edge> history;\n\
    \        auto dfs = [&](auto &f, int v, const Edge &e) -> int {\n            seen[v]\
    \ = true;\n            history.push_back(e);\n            for (const auto &ne\
    \ : G[v]) {\n                auto [from, to, cost, idx] = ne;\n              \
    \  if (!directed and to == e.from) continue;\n                if (finished[to])\
    \ continue;\n                if (seen[to] and !finished[to]) {\n             \
    \       history.push_back(ne);\n                    return to;\n             \
    \   }\n                int pos = f(f, to, ne);\n                if (pos != -1)\
    \ return pos;\n            }\n            finished[v] = true;\n            history.pop_back();\n\
    \            return -1;\n        };\n        auto restruct = [&](int pos) -> vector<Edge>\
    \ {\n            vector<Edge> cycle;\n            while (!history.empty()) {\n\
    \                const Edge e = history.back();\n                cycle.push_back(e);\n\
    \                history.pop_back();\n                if (e.from == pos) break;\n\
    \            }\n            reverse(cycle.begin(), cycle.end());\n           \
    \ return cycle;\n        };\n        int pos = -1;\n        for (int v = 0; v\
    \ < N and pos == -1; ++v) {\n            if (seen[v]) continue;\n            history.clear();\n\
    \            pos = dfs(dfs, v, Edge({-1, -1, -1, -1}));\n            if (pos !=\
    \ -1) return restruct(pos);\n        }\n        return vector<Edge>();\n    }\n\
    \    /**\n     * DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \ O(V+E)\n     * \u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306F\u7A7A\u914D\u5217\
    \u3092\u8FD4\u5374\n     * @return \u30BD\u30FC\u30C8\u6E08\u307F\u306E\u9802\u70B9\
    \u914D\u5217\n     */\n    vector<int> topological_sort() {\n        if (cycle_detect().size()\
    \ != 0) return vector<int>();\n        vector<int> seen(N, 0), sorted;\n     \
    \   auto dfs = [&](auto &f, int v) -> void {\n            seen[v] = 1;\n     \
    \       for (auto &&[from, to, cost, idx] : G[v]) {\n                if (!seen[to])\
    \ f(f, to);\n            }\n            sorted.push_back(v);\n        };\n   \
    \     for (int i = 0; i < N; ++i) {\n            if (!seen[i]) dfs(dfs, i);\n\
    \        }\n        reverse(all(sorted));\n        return sorted;\n    }\n   \
    \ /**\n     * \u9023\u7D50\u6210\u5206\u5206\u89E3 O(V+E)\n     * @return groups:\
    \ \u9023\u7D50\u306A\u9802\u70B9\u7FA4\u306E\u96C6\u5408\n     * @return ids:\
    \ \u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B\u6210\u5206\u306EID\uFF08ids[v] =\
    \ i\uFF09\n     */\n    pair<vector<vector<int>>, vector<int>> connected_components()\
    \ {\n        vector<vector<int>> groups;\n        vector<int> ids(N, -1);\n  \
    \      vector<int> com;\n        int cnt = 0;\n        auto dfs = [&](auto &f,\
    \ int v) -> void {\n            ids[v] = cnt;\n            com.push_back(v);\n\
    \            for (auto &&[from, to, cost, idx] : G[v]) {\n                if (ids[to]\
    \ != -1) continue;\n                f(f, to);\n            }\n        };\n   \
    \     for (int i = 0; i < N; ++i) {\n            if (ids[i] != -1) continue;\n\
    \            com.clear();\n            dfs(dfs, i);\n            groups.push_back(com);\n\
    \            ++cnt;\n        }\n        return {groups, ids};\n    }\n    /**\n\
    \     * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 Tarjan O(V+E)\n     * @return\
    \ groups: \u5404\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\u30B9\
    \u30C8\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\uFF09\n     * @return ids:\
    \ \u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B\u6210\u5206\u306EID\uFF08ids[v] =\
    \ i\uFF09\n     */\n    pair<vector<vector<int>>, vector<int>> scc() {\n     \
    \   int cnt = 0, now = 0;\n        vector<int> ids(N), low(N), ord(N, -1), pth;\n\
    \        auto dfs = [&](auto &f, int v) -> void {\n            low[v] = ord[v]\
    \ = now++;\n            pth.emplace_back(v);\n            // lowlink\n       \
    \     for (auto &&[from, to, cost, idx] : G[v]) {\n                if (ord[to]\
    \ == -1) {\n                    f(f, to);\n                    low[v] = min(low[v],\
    \ low[to]);\n                } else {\n                    low[v] = min(low[v],\
    \ ord[to]);\n                }\n            }\n            if (low[v] == ord[v])\
    \ {\n                while (1) {\n                    int u = pth.back();\n  \
    \                  pth.pop_back();\n                    ord[u] = N, ids[u] = cnt;\n\
    \                    if (u == v) break;\n                }\n                ++cnt;\n\
    \            }\n        };\n        for (int v = 0; v < N; ++v) {\n          \
    \  if (ord[v] == -1) dfs(dfs, v);\n        }\n        for (int v = 0; v < N; ++v)\
    \ {\n            ids[v] = cnt - 1 - ids[v];\n        }\n        vector<int> c(cnt);\n\
    \        vector<vector<int>> groups(cnt);\n        for (auto &&v : ids) ++c[v];\n\
    \        for (int i = 0; i < cnt; ++i) groups[i].reserve(c[i]);\n        for (int\
    \ i = 0; i < N; ++i) groups[ids[i]].push_back(i);\n        return {groups, ids};\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\n/**\n * @brief \u30B0\u30E9\
    \u30D5\n */\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>>\
    \ G;\n    int es;\n\n  public:\n    Graph(int N) : N(N), G(N), es(0) {\n    }\n\
    \    const vector<Edge> &operator[](int v) const {\n        return G[v];\n   \
    \ }\n    int size() {\n        return N;\n    }\n    // (\u6709\u5411)\u8FBA\u3092\
    \u5F35\u308B\n    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es++));\n    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\
    \n    void add_both(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost, es));\n        G[to].push_back(Edge(to, from, cost, es++));\n    }\n\
    \    // \u30B0\u30E9\u30D5\u3092\u8AAD\u307F\u53D6\u308B\n    void read(int M,\
    \ int padding = -1, bool weighted = false,\n              bool directed = false)\
    \ {\n        for (int i = 0; i < M; i++) {\n            int u, v;\n          \
    \  cin >> u >> v;\n            u += padding, v += padding;\n            long long\
    \ cost = 1ll;\n            if (weighted) cin >> cost;\n            if (directed)\
    \ {\n                add(u, v, cost);\n            } else {\n                add_both(u,\
    \ v, cost);\n            }\n        }\n    }\n    // \u7D4C\u8DEF\u5FA9\u5143\n\
    \    vector<int> route_restore(const vector<int> &route, int goal) {\n       \
    \ vector<int> path = {goal};\n        while (!!~route[path.back()]) path.push_back(route[path.back()]);\n\
    \        reverse(all(path));\n        return path;\n    }\n    /**\n     * BFS\
    \ \u6700\u77ED\u7D4C\u8DEF \u8907\u6570\u59CB\u70B9 O(V+E)\n     * @param starts\
    \ \u59CB\u70B9\u306E\u914D\u5217 \u30C7\u30D5\u30A9\u30EB\u30C80\u306E\u307F\n\
    \     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n     */\n    pair<vector<int>,\
    \ vector<int>> bfs(const vector<int> &starts = {0}) {\n        queue<int> q;\n\
    \        vector<int> dis(N, -1), route(N, -1);\n        for (auto &&v : starts)\
    \ q.push(v), dis[v] = 0;\n        while (!q.empty()) {\n            int v = q.front();\n\
    \            q.pop();\n            for (auto &&[from, to, cost, idx] : G[v]) {\n\
    \                if (~dis[to]) continue;\n                dis[to] = dis[from]\
    \ + 1;\n                q.push(to);\n                route[to] = v;\n        \
    \    }\n        }\n        return {dis, route};\n    }\n    /**\n     * Dijkstra\
    \ \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\u6570\u59CB\u70B9 O(ElogV)\n\
    \     * @param starts \u59CB\u70B9\u306E\u914D\u5217 \u30C7\u30D5\u30A9\u30EB\u30C8\
    0\u306E\u307F\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\
    \n     */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int>\
    \ &starts = {\n                                                      0}) {\n \
    \       reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\
    \u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N, INF);\n     \
    \   vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0, v),\
    \ weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] = q.top();\n\
    \            q.pop();\n            if (weight[v] < w) continue;\n            for\
    \ (auto &&[from, to, cost, idx] : G[v]) {\n                long long next_w =\
    \ w + cost;\n                if (weight[to] <= next_w) continue;\n           \
    \     weight[to] = next_w;\n                q.emplace(weight[to], to);\n     \
    \           route[to] = v;\n            }\n        }\n        return {weight,\
    \ route};\n    }\n    /**\n     * BellmanFord \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\
    \u8DEF \u8CA0\u91CD\u307FOK O(VE)\n     * @param s \u59CB\u70B9 \u30C7\u30D5\u30A9\
    \u30EB\u30C80\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u8CA0\u30B5\
    \u30A4\u30AF\u30EB\u6709\u7121\u3001\u7D4C\u8DEF\n     */\n    tuple<vector<long\
    \ long>, bool, vector<int>> bellman_ford(int s = 0) {\n        int loop = 0;\n\
    \        vector<long long> dis(N, INF);\n        vector<int> route(N, -1);\n \
    \       dis[s] = 0;\n        while (1) {\n            ++loop;\n            bool\
    \ upd = 0;\n            for (int v = 0; v < N; ++v) {\n                if (dis[v]\
    \ == INF) continue;\n                for (auto &&[from, to, cost, idx] : G[v])\
    \ {\n                    long long asis = dis[to], tobe = dis[v] + cost;\n   \
    \                 if (dis[v] == -INF) tobe = -INF;\n                    tobe =\
    \ max(tobe, -INF);\n                    if (asis <= tobe) continue;\n        \
    \            if (loop >= N) tobe = -INF;\n                    dis[to] = tobe;\n\
    \                    route[to] = v;\n                    upd = 1;\n          \
    \      }\n            }\n            if (!upd) break;\n        }\n        bool\
    \ negativeCycle = false;\n        for (auto &&v : dis) {\n            if (v ==\
    \ -INF) {\n                negativeCycle = true;\n                break;\n   \
    \         }\n        }\n        return {dis, negativeCycle, route};\n    }\n \
    \   /**\n     * WarshallFroyd \u5168\u9802\u70B9\u5BFE \u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF O(N^3)\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\
    \u8CA0\u30B5\u30A4\u30AF\u30EB\u6709\u7121\n     */\n    pair<vector<vector<long\
    \ long>>, bool> warshall_froyd() {\n        vector<vector<long long>> dis(N, vector<long\
    \ long>(N, INF));\n        for (int v = 0; v < N; ++v) {\n            dis[v][v]\
    \ = 0;\n            for (auto &&[from, to, cost, idx] : G[v]) {\n            \
    \    dis[v][to] = min(dis[v][to], cost);\n            }\n        }\n        for\
    \ (int k = 0; k < N; ++k) {\n            for (int i = 0; i < N; ++i) {\n     \
    \           if (dis[i][k] == INF) continue;\n                for (int j = 0; j\
    \ < N; ++j) {\n                    if (dis[k][j] == INF) continue;\n         \
    \           dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);\n             \
    \   }\n            }\n        }\n        bool negativeCycle = false;\n       \
    \ for (int i = 0; i < N; ++i) {\n            if (dis[i][i] < 0) {\n          \
    \      negativeCycle = true;\n                break;\n            }\n        }\n\
    \        return {dis, negativeCycle};\n    }\n    /**\n     * \u9589\u8DEF\u691C\
    \u51FA O(V+E)\n     * @param directed \u6709\u5411\u306A\u3089 `true` \u30C7\u30D5\
    \u30A9\u30EB\u30C8 `true`\n     * @return \u30B5\u30A4\u30AF\u30EB\u306A\u8FBA\
    \u306E\u96C6\u5408\n     */\n    vector<Edge> cycle_detect(bool directed = true)\
    \ {\n        vector<bool> seen(N), finished(N);\n        vector<Edge> history;\n\
    \        auto dfs = [&](auto &f, int v, const Edge &e) -> int {\n            seen[v]\
    \ = true;\n            history.push_back(e);\n            for (const auto &ne\
    \ : G[v]) {\n                auto [from, to, cost, idx] = ne;\n              \
    \  if (!directed and to == e.from) continue;\n                if (finished[to])\
    \ continue;\n                if (seen[to] and !finished[to]) {\n             \
    \       history.push_back(ne);\n                    return to;\n             \
    \   }\n                int pos = f(f, to, ne);\n                if (pos != -1)\
    \ return pos;\n            }\n            finished[v] = true;\n            history.pop_back();\n\
    \            return -1;\n        };\n        auto restruct = [&](int pos) -> vector<Edge>\
    \ {\n            vector<Edge> cycle;\n            while (!history.empty()) {\n\
    \                const Edge e = history.back();\n                cycle.push_back(e);\n\
    \                history.pop_back();\n                if (e.from == pos) break;\n\
    \            }\n            reverse(cycle.begin(), cycle.end());\n           \
    \ return cycle;\n        };\n        int pos = -1;\n        for (int v = 0; v\
    \ < N and pos == -1; ++v) {\n            if (seen[v]) continue;\n            history.clear();\n\
    \            pos = dfs(dfs, v, Edge({-1, -1, -1, -1}));\n            if (pos !=\
    \ -1) return restruct(pos);\n        }\n        return vector<Edge>();\n    }\n\
    \    /**\n     * DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \ O(V+E)\n     * \u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306F\u7A7A\u914D\u5217\
    \u3092\u8FD4\u5374\n     * @return \u30BD\u30FC\u30C8\u6E08\u307F\u306E\u9802\u70B9\
    \u914D\u5217\n     */\n    vector<int> topological_sort() {\n        if (cycle_detect().size()\
    \ != 0) return vector<int>();\n        vector<int> seen(N, 0), sorted;\n     \
    \   auto dfs = [&](auto &f, int v) -> void {\n            seen[v] = 1;\n     \
    \       for (auto &&[from, to, cost, idx] : G[v]) {\n                if (!seen[to])\
    \ f(f, to);\n            }\n            sorted.push_back(v);\n        };\n   \
    \     for (int i = 0; i < N; ++i) {\n            if (!seen[i]) dfs(dfs, i);\n\
    \        }\n        reverse(all(sorted));\n        return sorted;\n    }\n   \
    \ /**\n     * \u9023\u7D50\u6210\u5206\u5206\u89E3 O(V+E)\n     * @return groups:\
    \ \u9023\u7D50\u306A\u9802\u70B9\u7FA4\u306E\u96C6\u5408\n     * @return ids:\
    \ \u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B\u6210\u5206\u306EID\uFF08ids[v] =\
    \ i\uFF09\n     */\n    pair<vector<vector<int>>, vector<int>> connected_components()\
    \ {\n        vector<vector<int>> groups;\n        vector<int> ids(N, -1);\n  \
    \      vector<int> com;\n        int cnt = 0;\n        auto dfs = [&](auto &f,\
    \ int v) -> void {\n            ids[v] = cnt;\n            com.push_back(v);\n\
    \            for (auto &&[from, to, cost, idx] : G[v]) {\n                if (ids[to]\
    \ != -1) continue;\n                f(f, to);\n            }\n        };\n   \
    \     for (int i = 0; i < N; ++i) {\n            if (ids[i] != -1) continue;\n\
    \            com.clear();\n            dfs(dfs, i);\n            groups.push_back(com);\n\
    \            ++cnt;\n        }\n        return {groups, ids};\n    }\n    /**\n\
    \     * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 Tarjan O(V+E)\n     * @return\
    \ groups: \u5404\u6210\u5206\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\u30B9\
    \u30C8\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\uFF09\n     * @return ids:\
    \ \u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B\u6210\u5206\u306EID\uFF08ids[v] =\
    \ i\uFF09\n     */\n    pair<vector<vector<int>>, vector<int>> scc() {\n     \
    \   int cnt = 0, now = 0;\n        vector<int> ids(N), low(N), ord(N, -1), pth;\n\
    \        auto dfs = [&](auto &f, int v) -> void {\n            low[v] = ord[v]\
    \ = now++;\n            pth.emplace_back(v);\n            // lowlink\n       \
    \     for (auto &&[from, to, cost, idx] : G[v]) {\n                if (ord[to]\
    \ == -1) {\n                    f(f, to);\n                    low[v] = min(low[v],\
    \ low[to]);\n                } else {\n                    low[v] = min(low[v],\
    \ ord[to]);\n                }\n            }\n            if (low[v] == ord[v])\
    \ {\n                while (1) {\n                    int u = pth.back();\n  \
    \                  pth.pop_back();\n                    ord[u] = N, ids[u] = cnt;\n\
    \                    if (u == v) break;\n                }\n                ++cnt;\n\
    \            }\n        };\n        for (int v = 0; v < N; ++v) {\n          \
    \  if (ord[v] == -1) dfs(dfs, v);\n        }\n        for (int v = 0; v < N; ++v)\
    \ {\n            ids[v] = cnt - 1 - ids[v];\n        }\n        vector<int> c(cnt);\n\
    \        vector<vector<int>> groups(cnt);\n        for (auto &&v : ids) ++c[v];\n\
    \        for (int i = 0; i < cnt; ++i) groups[i].reserve(c[i]);\n        for (int\
    \ i = 0; i < N; ++i) groups[ids[i]].push_back(i);\n        return {groups, ids};\n\
    \    }\n};\n"
  dependsOn:
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy: []
  timestamp: '2026-01-06 20:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/bfs.test.cpp
  - tests/graph/topological_sort.test.cpp
  - tests/graph/bellman_ford.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/cycle_detect.test.cpp
  - tests/graph/route_restore.test.cpp
  - tests/graph/strongly_connected_components.test.cpp
  - tests/graph/warshall_froyd.test.cpp
  - tests/graph/connected_components.test.cpp
documentation_of: library/graph/graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5"
---


いろいろ含んだグラフの構造体

- 読み取ってグラフ辺貼る関数
- 経路復元
- BFS
- Dijkstra
- BellmanFord
- WarshallFroyd
- 閉路検出
- トポロジカルソート
- 連結成分分解
- 強連結成分分解
