#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "template/template.hpp"
#include "library/segtree/unified_segment_tree.hpp"
/**
 * @brief 統合セグ木のテスト:RMQ RAQ
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, 0);
    UnifiedSegmentTree<Monoid::Min, Monoid::Add, MonoidAct::MinAdd> seg(A, RangeType::Range, RangeType::Range);
    while (Q--) {
        int com, s, t;
        cin >> com >> s >> t;
        ++t;
        if (com == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
        if (com == 1) {
            print(seg.query(s, t));
        }
    }
}
