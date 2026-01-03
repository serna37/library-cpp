#pragma once
#include "library/struct/monoid.hpp"
/**
 * @brief Segment Tree 1点更新 区間取得
 */
template <typename T> struct SegmentTree {
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

  public:
    SegmentTree(F op, T e, int N) : op(op), e(e), N(N) {
        init();
    }
    SegmentTree(F op, T e, const vector<T> &A) : op(op), e(e), N(A.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = A[i];
        for (int i = size - 1; i >= 1; --i)
            node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    // 要素iの値をxにする
    void set(int i, const T &x) {
        node[i += size] = x;
        while (i >>= 1) node[i] = op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    // 演算[l,r)
    T prod(int l, int r) {
        T L = e, R = e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = op(L, node[l++]);
            if (r & 1) R = op(node[--r], R);
        }
        return op(L, R);
    }
};
