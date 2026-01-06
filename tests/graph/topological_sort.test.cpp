#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - トポロジカルソートのテスト
 */
void solve() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    G.read(E, 0, false, true);
    vector<int> sorted = G.topological_sort();
    for (auto &&v : sorted) {
        print(v);
    }
}
