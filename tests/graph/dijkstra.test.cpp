#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "template/template.hpp"
#include "library/graph/dijkstra.hpp"
/**
 * @brief グラフ - Dijkstraのテスト
 */
void solve() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V);
    G.read(E, 0, true, true);
    auto [dis, route] = dijkstra(G, {r});
    for (auto &&v : dis) {
        if (v == INF) {
            print("INF");
        } else {
            print(v);
        }
    }
}
