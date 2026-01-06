#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - WarshallFroydのテスト
 */
void solve() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    G.read(E, 0, true, true);
    auto [dis, negativeCycle] = G.warshall_froyd();
    if (negativeCycle) {
        print("NEGATIVE CYCLE");
        return;
    }
    vec2<string> ans = make_vec2<string>(V, V, "");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            ans[i][j] = dis[i][j] == INF ? "INF" : int_to_string(dis[i][j]);
        }
    }
    print(ans);
}
