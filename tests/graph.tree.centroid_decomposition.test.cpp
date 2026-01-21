#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "template/template.hpp"
#include "library/graph/tree/centroid_decomposition.hpp"
#include "library/polynomial/fft/fast_fourier_transform.hpp"
/**
 * @brief 木 - 重心分解のテスト
 */
void solve() {
    int N;
    cin >> N;
    CentroidDecomposition g(N);
    g.read(N - 1, 0);
    int root = g.build();
    vector<int> used(N), dist(N);
    auto rec = [&](auto self, int centroid) -> void {
        used[centroid] = true;
        vector<int> cnt{1};
        for (auto &&edge : g.G[centroid]) {
            if (used[edge.to]) continue;
            vector<int> num;
            queue<tuple<int, int, int>> que;
            que.emplace(edge.to, centroid, 1);
            while (!que.empty()) {
                int idx, par, dep;
                tie(idx, par, dep) = que.front();
                que.pop();
                if ((int)cnt.size() <= dep) cnt.resize(dep + 1, 0);
                if ((int)num.size() <= dep) num.resize(dep + 1, 0);
                cnt[dep]++;
                num[dep]++;
                for (auto &&edge : g.G[idx]) {
                    if (edge.to == par or used[edge.to]) continue;
                    que.emplace(edge.to, idx, dep + 1);
                }
            }
            auto ret = FFT::multiply(num, num);
            for (int i = 0; i < (int)ret.size(); i++) dist[i] -= ret[i];
        }
        auto ret = FFT::multiply(cnt, cnt);
        for (int i = 0; i < (int)ret.size(); ++i) dist[i] += ret[i];
        for (auto &&[from, to, cost, idx] : g.tree.G[centroid]) self(self, to);
    };
    rec(rec, root);
    dist.erase(begin(dist));
    for (auto &&p : dist) p /= 2ll;
    print(dist);
}
