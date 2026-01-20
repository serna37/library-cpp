#pragma once
#include <functional>
#include "library/various/monoid.hpp"
template <typename T> struct DualSegmentTree {
    using F = function<T(T, T)>;

  private:
    F op;
    T e;
    int N, size, log = 1;
    vector<T> node;
    void init() {
        while ((1ll << log) < N) ++log;
        node.assign((size = 1ll << log) << 1, e);
    }
    void apply_at(int k, T a) { node[k] = op(node[k], a); }
    void propagate(int k) {
        if (node[k] == e) return;
        apply_at((k << 1 | 0), node[k]);
        apply_at((k << 1 | 1), node[k]);
        node[k] = e;
    }

  public:
    DualSegmentTree(F op, T e, int n) : op(op), e(e), N(n) { init(); }
    DualSegmentTree(F op, T e, const vector<T> &a) : op(op), e(e), N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        return node[p];
    }
    void set(int p, const T &x) {
        p += size;
        apply_at(p, x);
        node[p] = x;
    }
    void apply(int l, int r, const T &a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        while (l < r) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
            l >>= 1, r >>= 1;
        }
    }
};
