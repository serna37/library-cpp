#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - BellmanFordのテスト
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
    auto [dis, negativeCycle, route] = G.bellman_ford(r);
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
