#pragma once
#include "library/graph/base/graph.hpp"
vector<int> centroid(const Graph &G) {
    const int N = (int)G.size();
    stack<pair<int, int>> st;
    st.emplace(0ll, -1ll);
    vector<int> sz(N), par(N);
    while (!st.empty()) {
        auto p = st.top();
        if (sz[p.first] == 0ll) {
            sz[p.first] = 1;
            for (auto &&[from, to, cost, idx] : G[p.first]) {
                if (to != p.second) st.emplace(to, p.first);
            }
        } else {
            for (auto &&[from, to, cost, idx] : G[p.first]) {
                if (to != p.second) sz[p.first] += sz[to];
            }
            par[p.first] = p.second;
            st.pop();
        }
    }
    vector<int> ret;
    int size = N;
    for (int i = 0; i < N; ++i) {
        int val = N - sz[i];
        for (auto &&[from, to, cost, idx] : G[i]) {
            if (to != par[i]) val = max(val, sz[to]);
        }
        if (val < size) size = val, ret.clear();
        if (val == size) ret.emplace_back(i);
    }
    return ret;
}
