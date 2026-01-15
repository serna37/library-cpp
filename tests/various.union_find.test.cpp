#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "template/template.hpp"
#include "library/various/union_find.hpp"
/**
 * @brief Union Findのテスト
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        }
        if (com == 1) {
            print(uf.find(x) == uf.find(y) ? 1 : 0);
        }
    }
}
