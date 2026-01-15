#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "template/template.hpp"
#include "library/graph/mst/kruskal.hpp"
/**
 * @brief 最小全域木 - クラスカルのテスト
 */
void solve() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.push_back({s, t, w});
    }
    MinSpanTree mst = kruskal(edges, V);
    print(mst.cost);
}
