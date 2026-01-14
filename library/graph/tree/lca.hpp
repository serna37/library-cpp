#pragma once
#include "library/graph/shortest_path/bfs.hpp"
#include "library/sequence/doubling.hpp"
struct Node {
    static const int e = -1;
    int to = e;
    long long dist = 0;
    Node operator+(const Node &A) const {
        if (to == e) return *this;
        return {A.to, dist + A.dist};
    }
};
struct LCA {
    vector<int> depth;
    Doubling<Node> db;
    LCA(const Graph &G, int root = 0) {
        int N = G.size();
        // 1. 既存のBFSを利用して深さと親を取得
        auto [dis, route] = bfs(G, {root});
        depth = dis;
        // 2. Node(親への移動先, そのエッジのコスト) の初期配列を作成
        // bfsの結果(route)にはコストが含まれていないため、グラフから取得
        vector<Node> next(N, Node(Node::e, 0));
        for (int v = 0; v < N; ++v) {
            int p = route[v];
            if (p != -1) {
                // vから親pへのエッジコストを探す
                for (auto &e : G[v]) {
                    if (e.to == p) {
                        next[v] = Node(p, e.cost);
                        break;
                    }
                }
            }
        }
        // 3. ダブリング構築
        db = Doubling<Node>(next, N);
    }
    int get_lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);
        v = db.query(v, depth[v] - depth[u]).to;
        if (u == v) return u;
        for (int k = db.log - 1; k >= 0; --k) {
            if (db.table[k][u].to != db.table[k][v].to) {
                u = db.table[k][u].to;
                v = db.table[k][v].to;
            }
        }
        return db.table[0][u].to;
    }
    long long get_dist(int u, int v) const {
        int lca = get_lca(u, v);
        return db.query(u, depth[u] - depth[lca]).dist + 
               db.query(v, depth[v] - depth[lca]).dist;
    }
};
