#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - 連結成分分解のテスト
 */
void solve() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    G.read(M, 0);
    auto [groups, ids] = G.connected_components();
    int Q;
    cin >> Q;
    while (Q--) {
        int s, t;
        cin >> s >> t;
        print(ids[s] == ids[t] ? "yes" : "no");
    }
}
