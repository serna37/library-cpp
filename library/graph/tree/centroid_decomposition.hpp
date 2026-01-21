#pragma once
#include "library/graph/base/graph.hpp"
struct CentroidDecomposition : Graph {
  public:
    using Graph::Graph;
    using Graph::G;
    Graph tree;
    int build() {
        sub.assign(G.size(), 0ll);
        v.assign(G.size(), 0ll);
        tree = Graph(G.size());
        return build_dfs(0ll);
    }
    explicit CentroidDecomposition(const Graph &G) : Graph(G) {}

  private:
    vector<int> sub;
    vector<int> v;
    inline int build_dfs(int idx, int par) {
        sub[idx] = 1;
        for (auto &&edge : G[idx]) {
            if (edge.to == par or v[edge.to]) continue;
            sub[idx] += build_dfs(edge.to, idx);
        }
        return sub[idx];
    }
    inline int search_centroid(int idx, int par, const int mid) {
        for (auto &&edge : G[idx]) {
            if (edge.to == par or v[edge.to]) continue;
            if (sub[edge.to] > mid) return search_centroid(edge.to, idx, mid);
        }
        return idx;
    }
    inline int build_dfs(int idx) {
        int centroid = search_centroid(idx, -1, build_dfs(idx, -1) / 2ll);
        v[centroid] = true;
        for (auto &&edge : G[centroid]) {
            if (!v[edge.to]) tree.add(centroid, build_dfs(edge.to));
        }
        v[centroid] = false;
        return centroid;
    }
};
