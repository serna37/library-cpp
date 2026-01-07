#pragma once
#include "library/graph/graph.hpp"
tuple<vector<long long>, bool, vector<int>> bellman_ford(const Graph &G, int s = 0) {
    int N = G.size(), loop = 0;
    vector<long long> dis(N, INF);
    vector<int> route(N, -1);
    dis[s] = 0;
    while (1) {
        ++loop;
        bool upd = 0;
        for (int v = 0; v < N; ++v) {
            if (dis[v] == INF) continue;
            for (auto &&[from, to, cost, idx] : G[v]) {
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
    bool negativeCycle = false;
    for (auto &&v : dis) {
        if (v == -INF) {
            negativeCycle = true;
            break;
        }
    }
    return {dis, negativeCycle, route};
}