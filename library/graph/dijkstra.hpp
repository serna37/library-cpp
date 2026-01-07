#pragma once
#include "library/graph/graph.hpp"
pair<vector<long long>, vector<int>> dijkstra(const Graph &G, const vector<int> &starts = {
                                                    0}) {
    int N = G.size();
    reverse_queue<pair<long long, int>> q; // コスト(小さい順), 頂点
    vector<long long> weight(N, INF);
    vector<int> route(N, -1);
    for (auto &&v : starts) q.emplace(0, v), weight[v] = 0;
    while (!q.empty()) {
        auto [w, v] = q.top();
        q.pop();
        if (weight[v] < w) continue;
        for (auto &&[from, to, cost, idx] : G[v]) {
            long long next_w = w + cost;
            if (weight[to] <= next_w) continue;
            weight[to] = next_w;
            q.emplace(weight[to], to);
            route[to] = v;
        }
    }
    return {weight, route};
}