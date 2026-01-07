#pragma once
const vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};
template <typename T, typename F> void bfs8(vector<vector<T>> &G, F f) {
    int H = G.size(), W = G[0].size();
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int k = 0; k < 8; ++k) {
                int y = i + dy8[k], x = j + dx8[k];
                if (y < 0 or x < 0 or H <= y or W <= x) continue;
                f(y, x);
            }
        }
    }
}