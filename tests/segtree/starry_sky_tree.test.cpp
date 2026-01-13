#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "template/template.hpp"
#include "library/segtree/starry_sky_tree.hpp"
/**
 * @brief 星空木のテスト:RMQ RAQ
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N, 0);
    StarrySkyTree sst(a);
    while (Q--) {
        int com, s, t;
        cin >> com >> s >> t;
        ++t;
        if (com == 0) {
            int x;
            cin >> x;
            sst.apply(s, t, x);
        }
        if (com == 1) {
            print(sst.prod(s, t));
        }
    }
}
