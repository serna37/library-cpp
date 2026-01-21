#pragma once
#include "library/graph/base/graph.hpp"
Graph convert_rooted_tree(const Graph &G, int r = 0) {
    int N = (int)G.size();
    Graph rg(N);
    vector<int> v(N);
    v[r] = 1;
    queue<int> que;
    que.emplace(r);
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (auto &&edge : G[p]) {
            if (v[edge.to] == 0ll) {
                v[edge.to] = 1;
                que.emplace(edge.to);
                rg.G[p].emplace_back(edge);
            }
        }
    }
    return rg;
}
