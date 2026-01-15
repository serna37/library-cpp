#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "template/template.hpp"
#include "library/sequence/wavelet_matrix.hpp"
/**
 * @brief ウェーブレット行列のテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    WaveletMatrix wm(A);
    while (Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        print(wm.kth_smallest(l, r, k));
    }
}
