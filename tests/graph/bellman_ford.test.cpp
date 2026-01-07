#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "template/template.hpp"
#include "library/graph/bellman_ford.hpp"
/**
 * @brief グラフ - BellmanFordのテスト
 */
void solve() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V);
    G.read(E, 0, true, true);
    auto [dis, negativeCycle, route] = bellman_ford(G, r);
    if (negativeCycle) {
        print("NEGATIVE CYCLE");
        return;
    }
    for (auto &&v : dis) {
        if (v == INF) {
            print("INF");
        } else {
            print(v);
        }
    }
}
