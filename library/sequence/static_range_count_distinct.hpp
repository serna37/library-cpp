#pragma once
#include "library/segtree/fenwick_tree.hpp"
#include "library/sequence/compressor.hpp"
template <typename T> struct StaticRangeCountDistinct {
  private:
    size_t m;
    vector<int> xs;
    vector<vector<int>> mp;
    vector<pair<int, int>> qs;

  public:
    explicit StaticRangeCountDistinct(const vector<T> &vs) : xs(vs.size()) {
        Compressor<T> comp(vs);
        m = comp.size();
        xs = comp.get_all();
    }
    void add_query(int l, int r) {
        assert(0ll <= l and l <= r and r <= (int)xs.size());
        qs.emplace_back(l, r - 1);
    }
    vector<size_t> calclate_queries() const {
        int n = (int)xs.size();
        int q = (int)qs.size();
        vector<vector<int>> ev(n);
        for (int i = 0; i < q; ++i) {
            if (qs[i].first <= qs[i].second) {
                ev[qs[i].second].emplace_back(i);
            }
        }
        vector<int> pre(m, -1);
        FenwickTree fwk(n);
        vector<size_t> ans(q);
        for (int i = 0; i < n; ++i) {
            int v = xs[i];
            if (~pre[v]) fwk.add(n - pre[v] - 1, -1);
            pre[v] = i;
            fwk.add(n - i - 1, 1);
            for (auto &&j : ev[i]) {
                ans[j] = fwk.sum(n - qs[j].first - 1);
            }
        }
        return ans;
    }
};
