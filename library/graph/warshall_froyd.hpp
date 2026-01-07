#pragma once
#include "library/graph/graph.hpp"
pair<vector<vector<long long>>, bool> warshall_froyd(const Graph &G) {
    int N = G.size();
    vector<vector<long long>> dis(N, vector<long long>(N, INF));
    for (int v = 0; v < N; ++v) {
        dis[v][v] = 0;
        for (auto &&[from, to, cost, idx] : G[v]) {
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
