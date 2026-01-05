---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"library/graph/edge.hpp\"\n/**\n * @brief \u8FBA\n */\nstruct\
    \ Edge {\n    int from, to;\n    long long cost;\n    Edge(int from, int to, long\
    \ long cost = 1)\n        : from(from), to(to), cost(cost) {\n    }\n};\n#line\
    \ 3 \"library/graph/graph.hpp\"\n/**\n * @brief \u30B0\u30E9\u30D5\n */\nstruct\
    \ Graph {\n  private:\n    int N;\n    vector<vector<Edge>> G;\n    /**\n    \
    \ * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 O(V+E)\n     * @return scc\u306E\
    id\u3001scc\u96C6\u5408\n     */\n    pair<int, vector<int>> strongly_connected_component()\
    \ {\n        int C = 0, now = 0;\n        vector<int> comp(N), low(N), ord(N,\
    \ -1), pth;\n        auto dfs = [&](auto &f, int v) {\n            low[v] = ord[v]\
    \ = now++;\n            pth.emplace_back(v);\n            for (auto &&[from, to,\
    \ cost] : G[v]) {\n                if (ord[to] == -1) {\n                    f(f,\
    \ to);\n                    low[v] = min(low[v], low[to]);\n                }\
    \ else {\n                    low[v] = min(low[v], ord[to]);\n               \
    \ }\n            }\n            if (low[v] == ord[v]) {\n                while\
    \ (1) {\n                    int u = pth.back();\n                    pth.pop_back();\n\
    \                    ord[u] = N, comp[u] = C;\n                    if (u == v)\
    \ break;\n                }\n                ++C;\n            }\n        };\n\
    \        for (int v = 0; v < N; ++v) {\n            if (ord[v] == -1) dfs(dfs,\
    \ v);\n        }\n        for (int v = 0; v < N; ++v) {\n            comp[v] =\
    \ C - 1 - comp[v];\n        }\n        return {C, comp};\n    }\n\n  public:\n\
    \    Graph(int N) : N(N), G(N) {\n    }\n    vector<Edge> operator[](int v) {\n\
    \        return G[v];\n    }\n    int size() {\n        return N;\n    }\n   \
    \ // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n    void add(int from, int to, long\
    \ long cost = 1) {\n        G[from].push_back(Edge(from, to, cost));\n    }\n\
    \    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n    void add_both(int from,\
    \ int to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost));\n\
    \        G[to].push_back(Edge(to, from, cost));\n    }\n    // \u7D4C\u8DEF\u5FA9\
    \u5143\n    vector<int> route_restore(const vector<int> &route, int goal) {\n\
    \        vector<int> path = {goal};\n        while (!~route[path.back()]) path.push_back(route[path.back()]);\n\
    \        reverse(all(path));\n        return path;\n    }\n    /**\n     * BFS\
    \ \u6700\u77ED\u7D4C\u8DEF \u8907\u6570\u59CB\u70B9\n     * @return \u6700\u77ED\
    \u8DDD\u96E2\u3001\u7D4C\u8DEF\n     */\n    pair<vector<int>, vector<int>> bfs(const\
    \ vector<int> &starts = {0}) {\n        queue<int> q;\n        vector<int> dis(N,\
    \ -1), route(N, -1);\n        for (auto &&v : starts) q.push(v), dis[v] = 0;\n\
    \        while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto &&[from, to, cost] : G[v]) {\n                if (~dis[to])\
    \ continue;\n                dis[to] = dis[from] + 1;\n                q.push(to);\n\
    \                route[to] = v;\n            }\n        }\n        return {dis,\
    \ route};\n    }\n    /**\n     * Dijkstra \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\
    \u8DEF \u8907\u6570\u59CB\u70B9\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\
    \u3001\u7D4C\u8DEF\n     */\n    pair<vector<long long>, vector<int>> dijkstra(const\
    \ vector<int> &starts = {\n                                                  \
    \    0}) {\n        reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8\
    (\u5C0F\u3055\u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N,\
    \ INF);\n        vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0,\
    \ v), weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] =\
    \ q.top();\n            q.pop();\n            if (weight[v] < w) continue;\n \
    \           for (auto &&[from, to, cost] : G[v]) {\n                long long\
    \ next_w = w + cost;\n                if (weight[to] <= next_w) continue;\n  \
    \              weight[to] = next_w;\n                q.emplace(weight[to], to);\n\
    \                route[to] = v;\n            }\n        }\n        return {weight,\
    \ route};\n    }\n    /**\n     * BellmanFord \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\
    \u8DEF \u8CA0\u91CD\u307FOK\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\
    \u7D4C\u8DEF\n     */\n    pair<vector<long long>, vector<int>> bellman_ford(int\
    \ s) {\n        int loop = 0;\n        vector<long long> dis(N, INF);\n      \
    \  vector<int> route(N, -1);\n        dis[s] = 0;\n        while (1) {\n     \
    \       ++loop;\n            bool upd = 0;\n            for (int v = 0; v < N;\
    \ ++v) {\n                if (dis[v] == INF) continue;\n                for (auto\
    \ &&[from, to, cost] : G[v]) {\n                    long long asis = dis[to],\
    \ tobe = dis[v] + cost;\n                    if (dis[v] == -INF) tobe = -INF;\n\
    \                    tobe = max(tobe, -INF);\n                    if (asis <=\
    \ tobe) continue;\n                    if (loop >= N) tobe = -INF;\n         \
    \           dis[to] = tobe;\n                    route[to] = v;\n            \
    \        upd = 1;\n                }\n            }\n            if (!upd) break;\n\
    \        }\n        return {dis, route};\n    }\n    /**\n     * WarshallFroyd\
    \ \u5168\u9802\u70B9\u5BFE \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\n     *\
    \ @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u8CA0\u30B5\u30A4\u30AF\u30EB\u6709\
    \u7121\n     */\n    pair<vector<vector<long long>>, bool> warshall_froyd() {\n\
    \        vector<vector<long long>> dis(N, vector<long long>(N, INF));\n      \
    \  for (int v = 0; v < N; ++v) {\n            dis[v][v] = 0;\n            for\
    \ (auto &&[from, to, cost] : G[v]) {\n                dis[v][to] = min(dis[v][to],\
    \ cost);\n            }\n        }\n        for (int k = 0; k < N; ++k) {\n  \
    \          for (int i = 0; i < N; ++i) {\n                if (dis[i][k] == INF)\
    \ continue;\n                for (int j = 0; j < N; ++j) {\n                 \
    \   if (dis[k][j] == INF) continue;\n                    dis[i][j] = min(dis[i][j],\
    \ dis[i][k] + dis[k][j]);\n                }\n            }\n        }\n     \
    \   bool negativeCycle = false;\n        for (int i = 0; i < N; ++i) {\n     \
    \       if (dis[i][i] < 0) {\n                negativeCycle = true;\n        \
    \        break;\n            }\n        }\n        return {dis, negativeCycle};\n\
    \    }\n    /**\n     * \u9589\u8DEF\u691C\u51FA\n     * @return \u30B5\u30A4\u30AF\
    \u30EB\u306A\u8FBA\u306E\u96C6\u5408\n     */\n    vector<Edge> cycle_detect(bool\
    \ directed) {\n        vector<bool> seen(N), finished(N);\n        vector<Edge>\
    \ history;\n        auto dfs = [&](auto &f, int v, const Edge &e) -> int {\n \
    \           seen[v] = true;\n            history.push_back(e);\n            for\
    \ (const auto &ne : G[v]) {\n                auto [from, to, id, cost] = ne;\n\
    \                if (!directed and to == e.from) continue;\n                if\
    \ (finished[to]) continue;\n                if (seen[to] and !finished[to]) {\n\
    \                    history.push_back(ne);\n                    return to;\n\
    \                }\n                int pos = f(f, to, ne);\n                if\
    \ (pos != -1) return pos;\n            }\n            finished[v] = true;\n  \
    \          history.pop_back();\n            return -1;\n        };\n        auto\
    \ restruct = [&](int pos) -> vector<Edge> {\n            vector<Edge> cycle;\n\
    \            while (!history.empty()) {\n                const Edge e = history.back();\n\
    \                cycle.push_back(e);\n                history.pop_back();\n  \
    \              if (e.from == pos) break;\n            }\n            reverse(cycle.begin(),\
    \ cycle.end());\n            return cycle;\n        };\n        int pos = -1;\n\
    \        for (int v = 0; v < N and pos == -1; ++v) {\n            if (seen[v])\
    \ continue;\n            history.clear();\n            pos = dfs(dfs, v, Edge({-1,\
    \ -1, -1, -1}));\n            if (pos != -1) return restruct(pos);\n        }\n\
    \        return vector<Edge>();\n    }\n    /**\n     * DAG\u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n     */\n    vector<int> topological_sort()\
    \ {\n        if (cycle_detect(1).size() != 0) return vector<int>();\n        vector<int>\
    \ seen(N, 0), sorted;\n        auto dfs = [&](auto &f, int v) -> void {\n    \
    \        seen[v] = 1;\n            for (auto &&[from, to, cost] : G[v]) {\n  \
    \              if (!seen[to]) f(f, to);\n            }\n            sorted.push_back(v);\n\
    \        };\n        for (int i = 0; i < N; ++i) {\n            if (!seen[i])\
    \ dfs(dfs, i);\n        }\n        reverse(all(sorted));\n        return sorted;\n\
    \    }\n    /**\n     * \u9023\u7D50\u6210\u5206\u5206\u89E3\n     * @return \u9023\
    \u7D50\u306A\u9802\u70B9\u7FA4\u306E\u96C6\u5408\n     */\n    vector<vector<int>>\
    \ connected_components() {\n        vector<vector<int>> components;\n        vector<int>\
    \ com;\n        vector<bool> seen(N, false);\n        auto dfs = [&](auto &f,\
    \ int v) {\n            seen[v] = true;\n            com.push_back(v);\n     \
    \       for (auto &&[from, to, cost] : G[v]) {\n                if (seen[to])\
    \ continue;\n                f(f, to);\n            }\n        };\n        for\
    \ (int i = 0; i < N; ++i) {\n            if (seen[i]) continue;\n            com.clear();\n\
    \            dfs(dfs, i);\n            components.push_back(com);\n        }\n\
    \        return components;\n    }\n    /**\n     * \u9023\u7D50\u6210\u5206\u5206\
    \u89E3\n     * @return \u9023\u7D50\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u306E\u30EA\
    \u30B9\u30C8\n     */\n    vector<Graph> cc() {\n        vector<vector<int>> components\
    \ = connected_components();\n        vector<Graph> res;\n        for (auto &&comp\
    \ : components) {\n            Graph sub(N);\n            for (auto &&v : comp)\
    \ {\n                for (auto &&[from, to, cost] : G[v]) {\n                \
    \    sub.add_both(from, to, cost); // \u7121\u5411\u30B0\u30E9\u30D5\n       \
    \         }\n            }\n            res.push_back(sub);\n        }\n     \
    \   return res;\n    }\n    /**\n     * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n     * @return scc\u96C6\u5408\u306E\u30EA\u30B9\u30C8\u3002\u30C8\u30DD\u30BD\
    \u9806\n     */\n    vector<vector<int>> scc_vertex_list() {\n        auto [cnt,\
    \ ids] = strongly_connected_component(G);\n        vector<int> c(cnt);\n     \
    \   vector<vector<int>> g(cnt);\n        for (auto &&v : ids) ++c[v];\n      \
    \  for (int i = 0; i < cnt; ++i) g[i].reserve(c[i]);\n        for (int i = 0;\
    \ i < N; ++i) g[ids[i]].push_back(i);\n        return g;\n    }\n    /**\n   \
    \  * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n     * @return \u5F37\u9023\u7D50\
    \u6210\u5206\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u306E\u30EA\u30B9\u30C8\u3002\
    \u6210\u5206\u540C\u58EB\u306E\u60C5\u5831\u30ED\u30B9\u30C8\u306B\u6CE8\u610F\
    \n     */\n    vector<Graph> scc() {\n        vector<vector<int>> components =\
    \ scc_vertex_list(G);\n        vector<Graph> res;\n        for (auto &&comp :\
    \ components) {\n            Graph sub(N);\n            for (auto &&v : comp)\
    \ {\n                for (auto &&[from, to, cost] : G[v]) {\n                \
    \    sub.add(from, to, cost);\n                }\n            }\n            res.push_back(sub);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/edge.hpp\"\n/**\n * @brief \u30B0\u30E9\
    \u30D5\n */\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>>\
    \ G;\n    /**\n     * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 O(V+E)\n    \
    \ * @return scc\u306Eid\u3001scc\u96C6\u5408\n     */\n    pair<int, vector<int>>\
    \ strongly_connected_component() {\n        int C = 0, now = 0;\n        vector<int>\
    \ comp(N), low(N), ord(N, -1), pth;\n        auto dfs = [&](auto &f, int v) {\n\
    \            low[v] = ord[v] = now++;\n            pth.emplace_back(v);\n    \
    \        for (auto &&[from, to, cost] : G[v]) {\n                if (ord[to] ==\
    \ -1) {\n                    f(f, to);\n                    low[v] = min(low[v],\
    \ low[to]);\n                } else {\n                    low[v] = min(low[v],\
    \ ord[to]);\n                }\n            }\n            if (low[v] == ord[v])\
    \ {\n                while (1) {\n                    int u = pth.back();\n  \
    \                  pth.pop_back();\n                    ord[u] = N, comp[u] =\
    \ C;\n                    if (u == v) break;\n                }\n            \
    \    ++C;\n            }\n        };\n        for (int v = 0; v < N; ++v) {\n\
    \            if (ord[v] == -1) dfs(dfs, v);\n        }\n        for (int v = 0;\
    \ v < N; ++v) {\n            comp[v] = C - 1 - comp[v];\n        }\n        return\
    \ {C, comp};\n    }\n\n  public:\n    Graph(int N) : N(N), G(N) {\n    }\n   \
    \ vector<Edge> operator[](int v) {\n        return G[v];\n    }\n    int size()\
    \ {\n        return N;\n    }\n    // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n\
    \    void add(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost));\n    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n  \
    \  void add_both(int from, int to, long long cost = 1) {\n        G[from].push_back(Edge(from,\
    \ to, cost));\n        G[to].push_back(Edge(to, from, cost));\n    }\n    // \u7D4C\
    \u8DEF\u5FA9\u5143\n    vector<int> route_restore(const vector<int> &route, int\
    \ goal) {\n        vector<int> path = {goal};\n        while (!~route[path.back()])\
    \ path.push_back(route[path.back()]);\n        reverse(all(path));\n        return\
    \ path;\n    }\n    /**\n     * BFS \u6700\u77ED\u7D4C\u8DEF \u8907\u6570\u59CB\
    \u70B9\n     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n     */\n \
    \   pair<vector<int>, vector<int>> bfs(const vector<int> &starts = {0}) {\n  \
    \      queue<int> q;\n        vector<int> dis(N, -1), route(N, -1);\n        for\
    \ (auto &&v : starts) q.push(v), dis[v] = 0;\n        while (!q.empty()) {\n \
    \           int v = q.front();\n            q.pop();\n            for (auto &&[from,\
    \ to, cost] : G[v]) {\n                if (~dis[to]) continue;\n             \
    \   dis[to] = dis[from] + 1;\n                q.push(to);\n                route[to]\
    \ = v;\n            }\n        }\n        return {dis, route};\n    }\n    /**\n\
    \     * Dijkstra \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\u6570\u59CB\
    \u70B9\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\n    \
    \ */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int> &starts\
    \ = {\n                                                      0}) {\n        reverse_queue<pair<long\
    \ long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\u3044\u9806), \u9802\u70B9\
    \n        vector<long long> weight(N, INF);\n        vector<int> route(N, -1);\n\
    \        for (auto &&v : starts) q.emplace(0, v), weight[v] = 0;\n        while\
    \ (!q.empty()) {\n            auto [w, v] = q.top();\n            q.pop();\n \
    \           if (weight[v] < w) continue;\n            for (auto &&[from, to, cost]\
    \ : G[v]) {\n                long long next_w = w + cost;\n                if\
    \ (weight[to] <= next_w) continue;\n                weight[to] = next_w;\n   \
    \             q.emplace(weight[to], to);\n                route[to] = v;\n   \
    \         }\n        }\n        return {weight, route};\n    }\n    /**\n    \
    \ * BellmanFord \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8CA0\u91CD\u307F\
    OK\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\n     */\n\
    \    pair<vector<long long>, vector<int>> bellman_ford(int s) {\n        int loop\
    \ = 0;\n        vector<long long> dis(N, INF);\n        vector<int> route(N, -1);\n\
    \        dis[s] = 0;\n        while (1) {\n            ++loop;\n            bool\
    \ upd = 0;\n            for (int v = 0; v < N; ++v) {\n                if (dis[v]\
    \ == INF) continue;\n                for (auto &&[from, to, cost] : G[v]) {\n\
    \                    long long asis = dis[to], tobe = dis[v] + cost;\n       \
    \             if (dis[v] == -INF) tobe = -INF;\n                    tobe = max(tobe,\
    \ -INF);\n                    if (asis <= tobe) continue;\n                  \
    \  if (loop >= N) tobe = -INF;\n                    dis[to] = tobe;\n        \
    \            route[to] = v;\n                    upd = 1;\n                }\n\
    \            }\n            if (!upd) break;\n        }\n        return {dis,\
    \ route};\n    }\n    /**\n     * WarshallFroyd \u5168\u9802\u70B9\u5BFE \u6700\
    \u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\
    \u3001\u8CA0\u30B5\u30A4\u30AF\u30EB\u6709\u7121\n     */\n    pair<vector<vector<long\
    \ long>>, bool> warshall_froyd() {\n        vector<vector<long long>> dis(N, vector<long\
    \ long>(N, INF));\n        for (int v = 0; v < N; ++v) {\n            dis[v][v]\
    \ = 0;\n            for (auto &&[from, to, cost] : G[v]) {\n                dis[v][to]\
    \ = min(dis[v][to], cost);\n            }\n        }\n        for (int k = 0;\
    \ k < N; ++k) {\n            for (int i = 0; i < N; ++i) {\n                if\
    \ (dis[i][k] == INF) continue;\n                for (int j = 0; j < N; ++j) {\n\
    \                    if (dis[k][j] == INF) continue;\n                    dis[i][j]\
    \ = min(dis[i][j], dis[i][k] + dis[k][j]);\n                }\n            }\n\
    \        }\n        bool negativeCycle = false;\n        for (int i = 0; i < N;\
    \ ++i) {\n            if (dis[i][i] < 0) {\n                negativeCycle = true;\n\
    \                break;\n            }\n        }\n        return {dis, negativeCycle};\n\
    \    }\n    /**\n     * \u9589\u8DEF\u691C\u51FA\n     * @return \u30B5\u30A4\u30AF\
    \u30EB\u306A\u8FBA\u306E\u96C6\u5408\n     */\n    vector<Edge> cycle_detect(bool\
    \ directed) {\n        vector<bool> seen(N), finished(N);\n        vector<Edge>\
    \ history;\n        auto dfs = [&](auto &f, int v, const Edge &e) -> int {\n \
    \           seen[v] = true;\n            history.push_back(e);\n            for\
    \ (const auto &ne : G[v]) {\n                auto [from, to, id, cost] = ne;\n\
    \                if (!directed and to == e.from) continue;\n                if\
    \ (finished[to]) continue;\n                if (seen[to] and !finished[to]) {\n\
    \                    history.push_back(ne);\n                    return to;\n\
    \                }\n                int pos = f(f, to, ne);\n                if\
    \ (pos != -1) return pos;\n            }\n            finished[v] = true;\n  \
    \          history.pop_back();\n            return -1;\n        };\n        auto\
    \ restruct = [&](int pos) -> vector<Edge> {\n            vector<Edge> cycle;\n\
    \            while (!history.empty()) {\n                const Edge e = history.back();\n\
    \                cycle.push_back(e);\n                history.pop_back();\n  \
    \              if (e.from == pos) break;\n            }\n            reverse(cycle.begin(),\
    \ cycle.end());\n            return cycle;\n        };\n        int pos = -1;\n\
    \        for (int v = 0; v < N and pos == -1; ++v) {\n            if (seen[v])\
    \ continue;\n            history.clear();\n            pos = dfs(dfs, v, Edge({-1,\
    \ -1, -1, -1}));\n            if (pos != -1) return restruct(pos);\n        }\n\
    \        return vector<Edge>();\n    }\n    /**\n     * DAG\u306E\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n     */\n    vector<int> topological_sort()\
    \ {\n        if (cycle_detect(1).size() != 0) return vector<int>();\n        vector<int>\
    \ seen(N, 0), sorted;\n        auto dfs = [&](auto &f, int v) -> void {\n    \
    \        seen[v] = 1;\n            for (auto &&[from, to, cost] : G[v]) {\n  \
    \              if (!seen[to]) f(f, to);\n            }\n            sorted.push_back(v);\n\
    \        };\n        for (int i = 0; i < N; ++i) {\n            if (!seen[i])\
    \ dfs(dfs, i);\n        }\n        reverse(all(sorted));\n        return sorted;\n\
    \    }\n    /**\n     * \u9023\u7D50\u6210\u5206\u5206\u89E3\n     * @return \u9023\
    \u7D50\u306A\u9802\u70B9\u7FA4\u306E\u96C6\u5408\n     */\n    vector<vector<int>>\
    \ connected_components() {\n        vector<vector<int>> components;\n        vector<int>\
    \ com;\n        vector<bool> seen(N, false);\n        auto dfs = [&](auto &f,\
    \ int v) {\n            seen[v] = true;\n            com.push_back(v);\n     \
    \       for (auto &&[from, to, cost] : G[v]) {\n                if (seen[to])\
    \ continue;\n                f(f, to);\n            }\n        };\n        for\
    \ (int i = 0; i < N; ++i) {\n            if (seen[i]) continue;\n            com.clear();\n\
    \            dfs(dfs, i);\n            components.push_back(com);\n        }\n\
    \        return components;\n    }\n    /**\n     * \u9023\u7D50\u6210\u5206\u5206\
    \u89E3\n     * @return \u9023\u7D50\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u306E\u30EA\
    \u30B9\u30C8\n     */\n    vector<Graph> cc() {\n        vector<vector<int>> components\
    \ = connected_components();\n        vector<Graph> res;\n        for (auto &&comp\
    \ : components) {\n            Graph sub(N);\n            for (auto &&v : comp)\
    \ {\n                for (auto &&[from, to, cost] : G[v]) {\n                \
    \    sub.add_both(from, to, cost); // \u7121\u5411\u30B0\u30E9\u30D5\n       \
    \         }\n            }\n            res.push_back(sub);\n        }\n     \
    \   return res;\n    }\n    /**\n     * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n     * @return scc\u96C6\u5408\u306E\u30EA\u30B9\u30C8\u3002\u30C8\u30DD\u30BD\
    \u9806\n     */\n    vector<vector<int>> scc_vertex_list() {\n        auto [cnt,\
    \ ids] = strongly_connected_component(G);\n        vector<int> c(cnt);\n     \
    \   vector<vector<int>> g(cnt);\n        for (auto &&v : ids) ++c[v];\n      \
    \  for (int i = 0; i < cnt; ++i) g[i].reserve(c[i]);\n        for (int i = 0;\
    \ i < N; ++i) g[ids[i]].push_back(i);\n        return g;\n    }\n    /**\n   \
    \  * \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n     * @return \u5F37\u9023\u7D50\
    \u6210\u5206\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u306E\u30EA\u30B9\u30C8\u3002\
    \u6210\u5206\u540C\u58EB\u306E\u60C5\u5831\u30ED\u30B9\u30C8\u306B\u6CE8\u610F\
    \n     */\n    vector<Graph> scc() {\n        vector<vector<int>> components =\
    \ scc_vertex_list(G);\n        vector<Graph> res;\n        for (auto &&comp :\
    \ components) {\n            Graph sub(N);\n            for (auto &&v : comp)\
    \ {\n                for (auto &&[from, to, cost] : G[v]) {\n                \
    \    sub.add(from, to, cost);\n                }\n            }\n            res.push_back(sub);\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn:
  - library/graph/edge.hpp
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy: []
  timestamp: '2026-01-05 21:42:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5"
---


いろいろ含んだグラフの構造体

- 経路復元
- BFS
- Dijkstra
- DAGのトポロジカルソート
- BellmanFord
- WarshallFroyd
- 閉路検出
- DAGのトポロジカルソート
- 連結成分分解
- 強連結成分分解

