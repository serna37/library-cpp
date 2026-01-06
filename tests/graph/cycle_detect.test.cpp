#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/cycle_detection"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - 閉路検出のテスト
 */
void solve() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G.add(u, v);
    }
    vector<Edge> cyc = G.cycle_detect();
    if (cyc.empty()) {
        print(-1);
        return;
    }
    print(cyc.size());
    for (auto &&[from, to, cost] : cyc) {
        print(from);
    }
}
