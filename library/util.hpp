#pragma once
/**
 * @file util.hpp
 * @brief ユーティリティ
 */
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
// 重複削除
template <typename T> void distinct(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
// int → char
char int_to_char(int x) {
    return (char)(x + '0');
}
// char → int
int char_to_int(char c) {
    return (int)(c - '0');
}
// 行列の転置
template <typename T> vector<vector<T>> transpose(vector<vector<T>> G) {
    int H = G.size(), W = G[0].size();
    vector<vector<T>> _G(W, vector<T>(H));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            _G[j][i] = G[i][j];
        }
    }
    return _G;
}
