#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include "template/template.hpp"
#include "library/graph/connected_components/strongly_connected_components.hpp"
/**
 * @brief グラフ - 強連結成分分解のテスト
 */
void solve() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    G.read(E, 0, false, true);
    auto [groups, ids] = scc(G);
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        print(ids[u] == ids[v] ? "1" : "0");
    }
}
