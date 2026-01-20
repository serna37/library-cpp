#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "template/template.hpp"
#include "library/sequence/static_range_frequency.hpp"
/**
 * @brief 区間の値の出現回数のテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    StaticRangeFrequency srf(A);
    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;
        print(srf.query(l, r, x));
    }
}
