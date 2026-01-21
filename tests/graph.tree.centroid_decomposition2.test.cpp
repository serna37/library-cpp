#define PROBLEM "https://yukicoder.me/problems/no/1002"
#include "template/template.hpp"
#include "library/graph/tree/centroid_decomposition.hpp"
/**
 * @brief 木 - 重心分解のテスト2
 */
void solve() {
    int N, K;
    cin >> N >> K;
    CentroidDecomposition G(N);
    G.read(N - 1, -1, true);
    int root = G.build();
    int ans = 0;
    vector<int> used(N);
    map<pair<int, int>, int> mp;
    int all;
    map<int, int> mp2, mp3;
    auto get_vec = [&](auto self, int idx, int par, int a, int b) -> void {
        if (!~b) {
            ans += all - mp2[a];
            ans += mp3[a];
        } else {
            ans++;
            ans += mp2[a] + mp2[b];
            ans += mp[minmax(a, b)];
        }
        for (auto &&e : G.G[idx]) {
            if (e.to == par) continue;
            if (used[e.to]) continue;
            if (a == e.cost) {
                self(self, e.to, idx, e.cost, b);
            } else if (!~b or b == e.cost) {
                self(self, e.to, idx, a, e.cost);
            }
        }
    };
    auto add_vec = [&](auto self, int idx, int par, int a, int b) -> void {
        if (!~b) {
            mp2[a]++;
            all++;
        } else {
            mp[minmax(a, b)]++;
            mp3[a]++;
            mp3[b]++;
        }
        for (auto &&e : G.G[idx]) {
            if (e.to == par) continue;
            if (used[e.to]) continue;
            if (a == e.cost) {
                self(self, e.to, idx, e.cost, b);
            } else {
                self(self, e.to, idx, a, e.cost);
            }
        }
    };
    auto rec = [&](auto self, int idx) -> void {
        used[idx] = true;
        mp.clear();
        mp2.clear();
        mp3.clear();
        all = 0;
        for (auto &&e : G.G[idx]) {
            if (used[e.to]) continue;
            get_vec(get_vec, e.to, idx, e.cost, -1);
            add_vec(add_vec, e.to, idx, e.cost, -1);
        }
        for (auto &&e : G.tree.G[idx]) {
            self(self, e.to);
        }
        used[idx] = false;
    };
    rec(rec, root);
    print(ans);
}
