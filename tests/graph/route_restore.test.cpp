#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "template/template.hpp"
#include "library/graph/graph.hpp"
/**
 * @brief グラフ - 経路復元のテスト
 */
void solve() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    Graph G(N);
    G.read(M, 0, true, true);
    auto [dis, route] = G.dijkstra({s});
    if (dis[t] == INF) {
        print(-1);
        return;
    }
    vector<int> pth = G.route_restore(route, t);
    cout << dis[t] << " " << pth.size() - 1 << endl;
    for (int i = 0; i < (int)pth.size() - 1; ++i) {
        cout << pth[i] << " " << pth[i + 1] << endl;
    }
}
