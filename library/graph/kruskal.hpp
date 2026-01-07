#pragma once
#include "library/graph/min_span_tree.hpp"
#include "library/struct/union_find.hpp"
MinSpanTree kruskal(vector<Edge> edges, int v_cnt) {
    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.cost < b.cost; });
    UnionFind uf(v_cnt);
    long long total = 0ll;
    vector<Edge> es;
    for (auto &&e : edges) {
        if (uf.unite(e.from, e.to)) {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    // 全域に達しない場合
    if (uf[0] < v_cnt) {
        total = INF;
    }
    return {total, es};
}
