#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "template/template.hpp"
#include "library/struct/fenwick_tree.hpp"
/**
 * @brief 🍪🧸🐾
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    FenwickTree fwk(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            --x;
            fwk.add(x, y);
        }
        if (com == 1) {
            --x, --y;
            print(fwk.sum(y) - fwk.sum(x - 1));
        }
    }
}
