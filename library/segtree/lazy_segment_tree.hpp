#pragma once
#include "library/struct/monoid.hpp"
#include "library/struct/monoid_act.hpp"
/**
 * @brief Lazy Segment Tree 区間更新 区間取得
 * @tparam T 演算モノイドの型
 * @tparam U 更新モノイドの型
 * @note 演算op e 更新op e 作用op
 */
template <typename T, typename U> struct LazySegmentTree {
    using ProdOp = function<T(T, T)>;
    using UpdOp = function<U(U, U)>;
    using ActOp = function<T(T, U, int)>;

  private:
    ProdOp prod_op;
    T prod_e;
    UpdOp upd_op;
    U upd_e;
    ActOp act_op;
    int N, size, log = 1;
    vector<T> node;
    vector<U> lazy;
    void init() {
        while ((1ll << log) < N) ++log;
        node.assign((size = 1ll << log) << 1, prod_e);
        lazy.assign(size, upd_e);
    }
    void update(int i) {
        node[i] = prod_op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    void apply_at(int k, U a) {
        int topbit = k == 0 ? -1 : 31 - __builtin_clzll(k);
        long long sz = 1 << (log - topbit);
        node[k] = act_op(node[k], a, sz);
        if (k < size) lazy[k] = upd_op(lazy[k], a);
    }
    void propagate(int k) {
        if (lazy[k] == upd_e) return;
        apply_at((k << 1 | 0), lazy[k]);
        apply_at((k << 1 | 1), lazy[k]);
        lazy[k] = upd_e;
    }

  public:
    LazySegmentTree(ProdOp prod_op, T prod_e, UpdOp upd_op, U upd_e,
                    ActOp act_op, int n)
        : prod_op(prod_op), prod_e(prod_e), upd_op(upd_op), upd_e(upd_e),
          act_op(act_op), N(n) {
        init();
    }
    LazySegmentTree(ProdOp prod_op, T prod_e, UpdOp upd_op, U upd_e,
                    ActOp act_op, const vector<T> &a)
        : prod_op(prod_op), prod_e(prod_e), upd_op(upd_op), upd_e(upd_e),
          act_op(act_op), N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) update(i);
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        return node[p];
    }
    vector<T> getall() {
        for (int i = 1; i < size; ++i) propagate(i);
        return {node.begin() + size, node.begin() + size + N};
    }
    void set(int p, const T &x) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    T prod(int l, int r) {
        if (l == r) return prod_e;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        T L = prod_e, R = prod_e;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = prod_op(L, node[l++]);
            if (r & 1) R = prod_op(node[--r], R);
        }
        return prod_op(L, R);
    }
    T top() {
        return node[1];
    }
    // 区間[l, r)に値aを作用させる
    void apply(int l, int r, U a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
        }
        l = l2, r = r2;
        for (int i = 1; i <= log; ++i) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template <typename F> int max_right(const F &test, int L) {
        if (L == N) return N;
        L += size;
        for (int i = log; i >= 1; --i) propagate(L >> i);
        T sm = prod_e;
        do {
            while (L % 2 == 0) L >>= 1;
            if (!test(prod_op(sm, node[L]))) {
                while (L < size) {
                    propagate(L);
                    L = 2 * L;
                    if (test(prod_op(sm, node[L]))) sm = prod_op(sm, node[L++]);
                }
                return L - size;
            }
            sm = prod_op(sm, node[L++]);
        } while ((L & -L) != L);
        return N;
    }
    template <typename F> int min_left(const F test, int R) {
        if (R == 0) return 0;
        R += size;
        for (int i = log; i >= 1; i--) propagate((R - 1) >> i);
        T sm = prod_e;
        do {
            R--;
            while (R > 1 && (R % 2)) R >>= 1;
            if (!test(prod_op(node[R], sm))) {
                while (R < size) {
                    propagate(R);
                    R = 2 * R + 1;
                    if (test(prod_op(node[R], sm))) sm = prod_op(node[R--], sm);
                }
                return R + 1 - size;
            }
            sm = prod_op(node[R], sm);
        } while ((R & -R) != R);
        return 0;
    }
};
