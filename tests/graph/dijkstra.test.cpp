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
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G.add(s, t, d);
    }
    auto [dis, route] = G.dijkstra({r});
    for (auto &&v : dis) {
        if (v == INF) {
            print("INF");
        } else {
            print(v);
        }
    }
}
