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
    G.read(M, 0, false, true);
    vector<Edge> cyc = G.cycle_detect();
    if (cyc.empty()) {
        print(-1);
        return;
    }
    print(cyc.size());
    for (auto &&e : cyc) {
        print(e.idx);
    }
}
