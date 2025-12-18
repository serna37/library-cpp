#pragma once
/**
 * @file util.hpp
 * @brief ユーティリティ
 */
using ll = long long;
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
// 2次元配列
template <typename T>
inline vector<vector<T>> make_vec2(const size_t H, const size_t W, const T& init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
// 2次元配列
template <typename T>
inline vector<vector<T>> make_vec2(const size_t H, const size_t W) {
    return vector<vector<T>>(H, vector<T>(W));
}
// int → char
char int_to_char(int x) {
    return (char)(x + '0');
}
// char → int
int char_to_int(char c) {
    return (int)(c - '0');
}
// 割り下げ（負の場合0側へ丸めない）
auto divCeil = []<class T>(T a, T b) -> T {
	return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
// 割り上げ（負の場合0側へ丸めない）
auto divFloor = []<class T>(T a, T b) -> T {
	return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
};
// 重複削除
template <typename T> void distinct(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
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
// 数直線上での個数になおす
vector<int> coordinate(vector<int> &A) {
    vector<int> coordinate(MAX);
    for (auto &&v : A) ++coordinate[v];
    return coordinate;
}
