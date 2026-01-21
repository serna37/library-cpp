#pragma once
#include "library/graph/base/graph.hpp"
struct HeavyLightDecomposition : Graph {
  public:
    using Graph::Graph;
    using Graph::G;
    vector<int> sz, in, out, head, rev, par, dep;
    void build(int root = 0) {
        sz.assign(G.size(), 0);
        in.assign(G.size(), 0);
        out.assign(G.size(), 0);
        head.assign(G.size(), 0);
        rev.assign(G.size(), 0);
        par.assign(G.size(), 0);
        dep.assign(G.size(), 0);
        dfs_sz(root, -1, 0);
        int t = 0;
        head[root] = root;
        dfs_hld(root, -1, t);
    }
    /* k: 0-indexed */
    int la(int v, int k) {
        while (1) {
            int u = head[v];
            if (in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }
    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    template <typename E, typename Q, typename F, typename S>
    E query(int u, int v, const E &ti, const Q &q, const F &f, const S &s,
            bool edge = false) {
        E l = ti, r = ti;
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v), swap(l, r);
            if (head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return s(f(q(in[u] + edge, in[v] + 1), l), r);
    }
    template <typename E, typename Q, typename F>
    E query(int u, int v, const E &ti, const Q &q, const F &f,
            bool edge = false) {
        return query(u, v, ti, q, f, f, edge);
    }
    template <typename Q>
    void add(int u, int v, const Q &q, bool edge = false) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }
    /* {parent, child} */
    vector<pair<int, int>> compress(vector<int> &remark) {
        auto cmp = [&](int a, int b) { return in[a] < in[b]; };
        sort(begin(remark), end(remark), cmp);
        remark.erase(unique(begin(remark), end(remark)), end(remark));
        int K = (int)remark.size();
        for (int k = 1; k < K; k++)
            remark.emplace_back(lca(remark[k - 1], remark[k]));
        sort(begin(remark), end(remark), cmp);
        remark.erase(unique(begin(remark), end(remark)), end(remark));
        vector<pair<int, int>> es;
        stack<int> st;
        for (auto &k : remark) {
            while (!st.empty() && out[st.top()] <= in[k]) st.pop();
            if (!st.empty()) es.emplace_back(st.top(), k);
            st.emplace(k);
        }
        return es;
    }
    explicit HeavyLightDecomposition(const Graph &G) : Graph(G) {}

  private:
    void dfs_sz(int idx, int p, int d) {
        dep[idx] = d;
        par[idx] = p;
        sz[idx] = 1;
        if (G[idx].size() && G[idx][0].to == p) swap(G[idx][0], G[idx].back());
        for (auto &&edge : G[idx]) {
            if (edge.to == p) continue;
            dfs_sz(edge.to, idx, d + 1);
            sz[idx] += sz[edge.to];
            if (sz[G[idx][0].to] < sz[edge.to]) swap(G[idx][0].to, edge.to);
        }
    }
    void dfs_hld(int idx, int p, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for (auto &&edge : G[idx]) {
            if (edge.to == p) continue;
            head[edge.to] = (G[idx][0].to == edge.to ? head[idx] : edge.to);
            dfs_hld(edge.to, idx, times);
        }
        out[idx] = times;
    }
};
