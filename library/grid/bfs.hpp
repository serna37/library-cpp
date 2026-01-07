#pragma once
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
template <typename T, typename F> void bfs(vector<vector<T>> &G, F f) {
    int H = G.size(), W = G[0].size();
    // TODO queueの処理なくね？
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int k = 0; k < 4; ++k) {
                int y = i + dy[k], x = j + dx[k];
                if (y < 0 or x < 0 or H <= y or W <= x) continue;
                f(y, x);
            }
        }
    }
}