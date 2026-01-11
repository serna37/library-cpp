#pragma once
#include "library/graph/base/edge.hpp"
struct Graph {
  private:
    int N;
    vector<vector<Edge>> G;
    int es;

  public:
    Graph(int N) : N(N), G(N), es(0) {
    }
    const vector<Edge> &operator[](int v) const {
        return G[v];
    }
    int size() const {
        return N;
    }
    void add(int from, int to, long long cost = 1) {
        G[from].push_back(Edge(from, to, cost, es++));
    }
    void add_both(int from, int to, long long cost = 1) {
        G[from].push_back(Edge(from, to, cost, es));
        G[to].push_back(Edge(to, from, cost, es++));
    }
    void read(int M, int padding = -1, bool weighted = false,
              bool directed = false) {
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u += padding, v += padding;
            long long cost = 1ll;
            if (weighted) cin >> cost;
            if (directed) {
                add(u, v, cost);
            } else {
                add_both(u, v, cost);
            }
        }
    }
};
