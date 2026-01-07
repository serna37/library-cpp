#pragma once
#include "library/graph/graph.hpp"
vector<Edge> cycle_detect(const Graph &G, bool directed = true) {
    int N = G.size();
    vector<bool> seen(N), finished(N);
    vector<Edge> history;
    auto dfs = [&](auto &f, int v, const Edge &e) -> int {
        seen[v] = true;
        history.push_back(e);
        for (const auto &ne : G[v]) {
            auto [from, to, cost, idx] = ne;
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
