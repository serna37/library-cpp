#pragma once
#include "library/graph/graph.hpp"
pair<vector<vector<int>>, vector<int>> scc(const Graph &G) {
    int N = G.size(), cnt = 0, now = 0;
    vector<int> ids(N), low(N), ord(N, -1), pth;
    auto dfs = [&](auto &f, int v) -> void {
        low[v] = ord[v] = now++;
        pth.emplace_back(v);
        // lowlink
        for (auto &&[from, to, cost, idx] : G[v]) {
            if (ord[to] == -1) {
                f(f, to);
                low[v] = min(low[v], low[to]);
            } else {
                low[v] = min(low[v], ord[to]);
            }
        }
        if (low[v] == ord[v]) {
            while (1) {
                int u = pth.back();
                pth.pop_back();
                ord[u] = N, ids[u] = cnt;
                if (u == v) break;
            }
            ++cnt;
        }
    };
    for (int v = 0; v < N; ++v) {
        if (ord[v] == -1) dfs(dfs, v);
    }
    for (int v = 0; v < N; ++v) {
        ids[v] = cnt - 1 - ids[v];
    }
    vector<int> c(cnt);
    vector<vector<int>> groups(cnt);
    for (auto &&v : ids) ++c[v];
    for (int i = 0; i < cnt; ++i) groups[i].reserve(c[i]);
    for (int i = 0; i < N; ++i) groups[ids[i]].push_back(i);
    return {groups, ids};
}