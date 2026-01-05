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
    // TODO ワーシャルフロイド
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
    // TODO サイクル検出
    /**
     * DAGのトポロジカルソート
     */
    vector<int> topological_sort() {
        // TODO 閉路検知して空配列を返却とか
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
    // TODO cc
    // TODO scc
    // TODO クラスカル
    // TODO ドキュメント
};
