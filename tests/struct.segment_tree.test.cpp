#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "template/template.hpp"
#include "library/struct/segment_tree.hpp"
#include "library/struct/monoid.hpp"
/**
 * @brief セグ木のテスト:RMQ
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree seg(MonoidMin<int>(), N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        }
        if (com == 1) {
            print(seg.prod(x, y + 1));
        }
    }
}
