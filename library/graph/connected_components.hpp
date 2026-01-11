#pragma once
#include "library/graph/base/graph.hpp"
pair<vector<vector<int>>, vector<int>> connected_components(const Graph &G) {
    int N = G.size(), cnt = 0;
    vector<vector<int>> groups;
    vector<int> ids(N, -1);
    vector<int> com;
    auto dfs = [&](auto &f, int v) -> void {
        ids[v] = cnt;
        com.push_back(v);
        for (auto &&[from, to, cost, idx] : G[v]) {
            if (ids[to] != -1) continue;
            f(f, to);
        }
    };
    for (int i = 0; i < N; ++i) {
        if (ids[i] != -1) continue;
        com.clear();
        dfs(dfs, i);
        groups.push_back(com);
        ++cnt;
    }
    return {groups, ids};
}
