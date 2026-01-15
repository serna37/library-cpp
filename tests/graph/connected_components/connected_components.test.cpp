#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"
#include "template/template.hpp"
#include "library/graph/connected_components/connected_components.hpp"
/**
 * @brief グラフ - 連結成分分解のテスト
 */
void solve() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    G.read(M, 0);
    auto [groups, ids] = connected_components(G);
    int Q;
    cin >> Q;
    while (Q--) {
        int s, t;
        cin >> s >> t;
        print(ids[s] == ids[t] ? "yes" : "no");
    }
}
