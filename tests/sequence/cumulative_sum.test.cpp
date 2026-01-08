#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/static_range_sum"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum.hpp"
/**
 * @brief 累積和のテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    vector<long long> S = cumulative_sum(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        print(S[r] - S[l]);
    }
}
