#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - Dijkstraのテスト
 */
void solve() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V);
    G.read(E, 0, true, true);
    auto [dis, route] = G.dijkstra({r});
    for (auto &&v : dis) {
        if (v == INF) {
            print("INF");
        } else {
            print(v);
        }
    }
}
