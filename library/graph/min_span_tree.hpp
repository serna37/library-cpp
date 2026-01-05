#pragma once
#include "library/graph/edge.hpp"
#include "library/struct/union_find.hpp"
/**
 * @brief 最小全域木
 */
struct MinSpanTree {
    long long cost;
    vector<Edge> edges;
};
/**
 * クラスカル O(ElogV)
 * @return 最小全域木
 */
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
