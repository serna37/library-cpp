#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include "template/template.hpp"
#include "library/graph/bfs.hpp"
/**
 * @brief グラフ - BFSのテスト
 */
void solve() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int U, K;
        cin >> U >> K;
        --U;
        for (int j = 0; j < K; ++j) {
            int v;
            cin >> v;
            --v;
            G.add(U, v);
        }
    }
    auto [dis, route] = bfs(G);
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ";
        print(dis[i]);
    }
}
