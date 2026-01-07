#pragma once
template <typename T>
vector<vector<long long>> cumulative_sum_2D(const vector<T> &G) {
    int H = G.size(), W = G[0].size();
    vector<vector<long long>> S(H + 1, vector<long long>(W + 1));
    for (int i = 0; i < H; ++i) { // 横向き
        for (int j = 0; j < W; ++j) {
            S[i + 1][j + 1] = S[i + 1][j] + G[i][j];
        }
    }
    for (int i = 0; i < H; ++i) { // 縦向き
        for (int j = 0; j < W; ++j) {
            S[i + 1][j + 1] += S[i][j + 1];
        }
    }
    return S;
}