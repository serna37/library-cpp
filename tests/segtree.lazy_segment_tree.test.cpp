#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "template/template.hpp"
#include "library/segtree/lazy_segment_tree.hpp"
/**
 * @brief 遅延セグ木のテスト:RMQ RUQ
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, INT_MAX);
    LazySegmentTree<int, int> seg(Monoid::Min::op, Monoid::Min::e,
                                  Monoid::Set::op, Monoid::Set::e,
                                  MonoidAct::MinSet::op, N);
    while (Q--) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        }
        if (com == 1) {
            int s, t;
            cin >> s >> t;
            print(seg.prod(s, t + 1));
        }
    }
}
