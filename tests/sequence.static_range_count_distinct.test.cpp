#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include "template/template.hpp"
#include "library/sequence/static_range_count_distinct.hpp"
/**
 * @brief 区間の値の種類数のテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    StaticRangeCountDistinct srcd(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        srcd.add_query(l, r);
    }
    auto ans = srcd.calclate_queries();
    for (auto &&v : ans) print(v);
}
