#pragma once
#include "library/graph/cycle_detect.hpp"
vector<int> topological_sort(const Graph &G) {
    if (cycle_detect(G).size() != 0) return vector<int>();
    int N = G.size();
    vector<int> seen(N, 0), sorted;
    auto dfs = [&](auto &f, int v) -> void {
        seen[v] = 1;
        for (auto &&[from, to, cost, idx] : G[v]) {
            if (!seen[to]) f(f, to);
        }
        sorted.push_back(v);
    };
    for (int i = 0; i < N; ++i) {
        if (!seen[i]) dfs(dfs, i);
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}