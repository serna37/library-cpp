#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "template/template.hpp"
#include "library/sequence/compressor.hpp"
#include "library/segtree/fenwick_tree.hpp"
#include "library/various/mo.hpp"
/**
 * @brief Mo's algorithmのテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    Mo mo(N, Q);
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        mo.add_query(l, r);
    }
    Compressor zip(A);
    A = zip.get_all();
    FenwickTree fwk(zip.size());
    int64_t inv = 0, all = 0;
    vector<int64_t> ans(Q);
    auto add_left = [&](int idx) {
        inv += fwk.sum(A[idx] - 1);
        fwk.add(A[idx], 1);
        all++;
    };
    auto add_right = [&](int idx) {
        inv += all - fwk.sum(A[idx]);
        fwk.add(A[idx], 1);
        ++all;
    };
    auto erase_left = [&](int idx) {
        fwk.add(A[idx], -1);
        --all;
        inv -= fwk.sum(A[idx] - 1);
    };
    auto erase_right = [&](int idx) {
        fwk.add(A[idx], -1);
        --all;
        inv -= all - fwk.sum(A[idx]);
    };
    auto query = [&](int idx) { ans[idx] = inv; };
    mo.calclate_queries(add_left, add_right, erase_left, erase_right, query);
    for (auto &p : ans) print(p);
}
