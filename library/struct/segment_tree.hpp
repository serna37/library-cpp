#pragma once
/**
 * @brief SegmentTree 1点更新 区間取得
 */
template <class Monoid> struct SegmentTree {
    using T = typename Monoid::T;

  private:
    Monoid M;
    int N, size, log = 1;
    vector<T> node;
    void init() {
        while ((1 << log) < N) ++log;
        node.assign((size = 1 << log) << 1, M.e());
    }

  public:
    SegmentTree(Monoid M, int N) : M(M), N(N) {
        init();
    }
    SegmentTree(Monoid M, const vector<T> &A) : M(M), N(A.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = A[i];
        for (int i = size - 1; i >= 1; --i)
            node[i] = M.op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    // 要素iの値をxにする
    void set(int i, const T &x) {
        node[i += size] = x;
        while (i >>= 1) node[i] = M.op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    // 演算[l,r)
    T prod(int l, int r) {
        T L = M.e(), R = M.e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M.op(L, node[l++]);
            if (r & 1) R = M.op(node[--r], R);
        }
        return M.op(L, R);
    }
};
