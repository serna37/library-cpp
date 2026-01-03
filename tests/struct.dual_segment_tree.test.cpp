#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "template/template.hpp"
#include "library/struct/monoid.hpp"
#include "library/struct/dual_segment_tree.hpp"
/**
 * @brief 双対セグ木のテスト:RUQ
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    DualSegmentTree<int> seg(Monoid::Set::op, Monoid::Set::e, N);
    while (Q--) {
        int com;
        cin >> com;
        if (com == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        }
        if (com == 1) {
            int k;
            cin >> k;
            print(seg[k]);
        }
    }
}
