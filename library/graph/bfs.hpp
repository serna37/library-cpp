#pragma once
#include "library/graph/graph.hpp"
pair<vector<int>, vector<int>> bfs(const Graph &G,
                                   const vector<int> &starts = {0}) {
    int N = G.size();
    queue<int> q;
    vector<int> dis(N, -1), route(N, -1);
    for (auto &&v : starts) q.push(v), dis[v] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &&[from, to, cost, idx] : G[v]) {
            if (~dis[to]) continue;
            dis[to] = dis[from] + 1;
            q.push(to);
            route[to] = v;
        }
    }
    return {dis, route};
}
