#pragma once
template <bool is_min_mode = true> struct StarrySkyTree {
  private:
    int N, sz, log = 1;
    const int INF = 1e9;
    vector<int> node;
    int compare(int a, int b) {
        if constexpr (is_min_mode) {
            return min(a, b);
        } else {
            return max(a, b);
        }
    }
    int unit_element() {
        return is_min_mode ? INF : -INF;
    }
    void init() {
        while ((1ll << log) < N) ++log;
        node.assign((sz = 1ll << log) << 1, 0);
    }
    int _star(int i) {
        int val = compare(node[i << 1 | 0], node[i << 1 | 1]);
        node[i << 1 | 0] -= val;
        node[i << 1 | 1] -= val;
        return val;
    }
    void star(int i) {
        node[i] += _star(i);
    }
    int sum(int i) {
        int ans = node[i];
        while (i >>= 1) ans += node[i];
        return ans;
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<int> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + sz] = a[i];
        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);
    }
    int operator[](int i) {
        return sum(i + sz);
    }
    void apply(int l, int r, const int &v) {
        if (l >= r) return;
        int l_bak = l + sz, r_bak = r + sz - 1;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) node[l++] += v;
            if (r & 1) node[--r] += v;
        }
        for (int i = l_bak >> 1; i >= 1; i >>= 1) star(i);
        for (int i = r_bak >> 1; i >= 1; i >>= 1) star(i);
    }
    void set(int p, const int &x) {
        apply(p, p + 1, x - sum(p + sz));
    }
    int prod(int l, int r) {
        if (l >= r) return unit_element();
        int ans = unit_element();
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = compare(ans, sum(l++));
            if (r & 1) ans = compare(ans, sum(--r));
        }
        return ans;
    }
};
