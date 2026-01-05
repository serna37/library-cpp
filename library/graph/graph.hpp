#pragma once
#include "library/graph/edge.hpp"
/**
 * @brief グラフ
 */
struct Graph {
  private:
    int N;
    vector<vector<Edge>> G;

  public:
    Graph(int N) : N(N), G(N) {
    }
    vector<Edge> operator[](int v) {
        return G[v];
    }
    int size() {
        return N;
    }
    // (有向)辺を張る
    void add(int from, int to, long long cost = 1) {
        G[from].push_back(Edge(from, to, cost));
    }
    // (双方向)辺を張る
    void add_both(int from, int to, long long cost = 1) {
        G[from].push_back(Edge(from, to, cost));
        G[to].push_back(Edge(to, from, cost));
    }
    // 経路復元
    vector<int> route_restore(const vector<int> &route, int goal) {
        vector<int> path = {goal};
        while (!~route[path.back()]) path.push_back(route[path.back()]);
        reverse(all(path));
        return path;
    }
    /**
     * BFS 最短経路 複数始点
     * @return 最短距離、経路
     */
    pair<vector<int>, vector<int>> bfs(const vector<int> &starts = {0}) {
        queue<int> q;
        vector<int> dis(N, -1), route(N, -1);
        for (auto &&v : starts) q.push(v), dis[v] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &&[from, to, cost] : G[v]) {
                if (~dis[to]) continue;
                dis[to] = dis[from] + 1;
                q.push(to);
                route[to] = v;
            }
        }
        return {dis, route};
    }
    /**
     * Dijkstra 最小コスト経路 複数始点
     * @return 最小コスト、経路
     */
    pair<vector<long long>, vector<int>> dijkstra(const vector<int> &starts = {
                                                      0}) {
        reverse_queue<pair<long long, int>> q; // コスト(小さい順), 頂点
        vector<long long> weight(N, INF);
        vector<int> route(N, -1);
        for (auto &&v : starts) q.emplace(0, v), weight[v] = 0;
        while (!q.empty()) {
            auto [w, v] = q.top();
            q.pop();
            if (weight[v] < w) continue;
            for (auto &&[from, to, cost] : G[v]) {
                long long next_w = w + cost;
                if (weight[to] <= next_w) continue;
                weight[to] = next_w;
                q.emplace(weight[to], to);
                route[to] = v;
            }
        }
        return {weight, route};
    }
    /**
     * BellmanFord 最小コスト経路 負重みOK
     * @return 最小コスト、経路
     */
    pair<vector<long long>, vector<int>> bellman_ford(int s) {
        int loop = 0;
        vector<long long> dis(N, INF);
        vector<int> route(N, -1);
        dis[s] = 0;
        while (1) {
            ++loop;
            bool upd = 0;
            for (int v = 0; v < N; ++v) {
                if (dis[v] == INF) continue;
                for (auto &&[from, to, cost] : G[v]) {
                    long long asis = dis[to], tobe = dis[v] + cost;
                    if (dis[v] == -INF) tobe = -INF;
                    tobe = max(tobe, -INF);
                    if (asis <= tobe) continue;
                    if (loop >= N) tobe = -INF;
                    dis[to] = tobe;
                    route[to] = v;
                    upd = 1;
                }
            }
            if (!upd) break;
        }
        return {dis, route};
    }
    /**
     * WarshallFroyd 全頂点対 最小コスト経路
     * @return 最小コスト、負サイクル有無
     */
    pair<vector<vector<long long>>, bool> warshall_froyd() {
        vector<vector<long long>> dis(N, vector<long long>(N, INF));
        for (int v = 0; v < N; ++v) {
            dis[v][v] = 0;
            for (auto &&[from, to, cost] : G[v]) {
                dis[v][to] = min(dis[v][to], cost);
            }
        }
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                if (dis[i][k] == INF) continue;
                for (int j = 0; j < N; ++j) {
                    if (dis[k][j] == INF) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        bool negativeCycle = false;
        for (int i = 0; i < N; ++i) {
            if (dis[i][i] < 0) {
                negativeCycle = true;
                break;
            }
        }
        return {dis, negativeCycle};
    }
    /**
     * 閉路検出
     * @return サイクルな辺の集合
     */
    vector<Edge> cycle_detect(bool directed) {
        vector<bool> seen(N), finished(N);
        vector<Edge> history;
        auto dfs = [&](auto &f, int v, const Edge &e) -> int {
            seen[v] = true;
            history.push_back(e);
            for (const auto &ne : G[v]) {
                auto [from, to, id, cost] = ne;
                if (!directed and to == e.from) continue;
                if (finished[to]) continue;
                if (seen[to] and !finished[to]) {
                    history.push_back(ne);
                    return to;
                }
                int pos = f(f, to, ne);
                if (pos != -1) return pos;
            }
            finished[v] = true;
            history.pop_back();
            return -1;
        };
        auto restruct = [&](int pos) -> vector<Edge> {
            vector<Edge> cycle;
            while (!history.empty()) {
                const Edge e = history.back();
                cycle.push_back(e);
                history.pop_back();
                if (e.from == pos) break;
            }
            reverse(cycle.begin(), cycle.end());
            return cycle;
        };
        int pos = -1;
        for (int v = 0; v < N and pos == -1; ++v) {
            if (seen[v]) continue;
            history.clear();
            pos = dfs(dfs, v, Edge({-1, -1, -1, -1}));
            if (pos != -1) return restruct(pos);
        }
        return vector<Edge>();
    }
    /**
     * DAGのトポロジカルソート
     */
    vector<int> topological_sort() {
        if (cycle_detect(1).size() != 0) return vector<int>();
        vector<int> seen(N, 0), sorted;
        auto dfs = [&](auto &f, int v) -> void {
            seen[v] = 1;
            for (auto &&[from, to, cost] : G[v]) {
                if (!seen[to]) f(f, to);
            }
            sorted.push_back(v);
        };
        for (int i = 0; i < N; ++i) {
            if (!seen[i]) dfs(dfs, i);
        }
        reverse(all(sorted));
        return sorted;
    }
    /**
     * 連結成分分解
     * @return 連結な頂点群の集合
     */
    vector<vector<int>> connected_components() {
        vector<vector<int>> components;
        vector<int> com;
        vector<bool> seen(N, false);
        auto dfs = [&](auto &f, int v) {
            seen[v] = true;
            com.push_back(v);
            for (auto &&[from, to, cost] : G[v]) {
                if (seen[to]) continue;
                f(f, to);
            }
        };
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            com.clear();
            dfs(dfs, i);
            components.push_back(com);
        }
        return components;
    }
    /**
     * 連結成分分解
     * @return 連結なグラフ構造のリスト
     */
    vector<Graph> cc() {
        vector<vector<int>> components = connected_components();
        vector<Graph> res;
        for (auto &&comp : components) {
            Graph sub(N);
            for (auto &&v : comp) {
                for (auto &&[from, to, cost] : G[v]) {
                    sub.add_both(from, to, cost); // 無向グラフ
                }
            }
            res.push_back(sub);
        }
        return res;
    }
    // TODO scc
    // TODO クラスカル
    // TODO ドキュメント
};
