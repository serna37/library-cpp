#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include "template/template.hpp"
#include "library/graph/tree/lca.hpp"
//
/**
 * @brief 木 - LCAのテスト
 */
void solve() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;
            G.add_both(i, c);
        }
    }
    LCA tree(G);
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        print(tree.get_lca(u, v));
    }
}
