#pragma once
/**
 * @file list.hpp
 * @brief 配列 行列 数列 関連
 */
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
// all match
template <typename T, typename F> inline bool allMatch(vector<T> &v, F f) {
    return all_of(all(v), f);
}
// none match
template <typename T, typename F> inline bool noneMatch(vector<T> &v, F f) {
    return none_of(all(v), f);
}
// any match
template <typename T, typename F> inline bool anyMatch(vector<T> &v, F f) {
    return any_of(all(v), f);
}
// 最大値
template <typename T> inline T max(vector<T> &v) {
    return *max_element(all(v));
}
// 最小値
template <typename T> inline T min(vector<T> &v) {
    return *min_element(all(v));
}
// 総和
inline long long sum(vector<long long> &v) {
    return accumulate(all(v), 0ll);
}
// 要素数カウント
template <typename T> inline int cnt(vector<T> &v) {
    return (int)v.size();
}
// フィルタ
template <typename T, typename F> inline vector<T> filter(vector<T> &v, F f) {
    vector<T> res;
    for (auto &&e : v) {
        if (f(e)) res.push_back(e);
    }
    return res;
}
// ソート
template <typename T> inline void sort(vector<T> &v) {
    sort(all(v));
}
// ソート(大きい順)
template <typename T> inline void sortRev(vector<T> &v) {
    sort(rall(v));
}
// リバース
template <typename T> inline void reverse(vector<T> &v) {
    reverse(all(v));
}
// 重複削除
template <typename T> inline void distinct(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
// set multisetでのerase
template <typename T> inline void erase(set<T> &st, T &v) {
    st.erase(st.find(v));
}
// set multisetでのerase
template <typename T> inline void erase(multiset<T> &st, T &v) {
    st.erase(st.find(v));
}
// 行列の転置
template <typename T> inline vector<vector<T>> transpose(vector<vector<T>> &G) {
    int H = G.size(), W = G[0].size();
    vector<vector<T>> _G(W, vector<T>(H));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            _G[j][i] = G[i][j];
        }
    }
    return _G;
}
// vector分割代入用。Gは破壊。auto [a,b]=unpack<2>(move(G));
template <int N, typename T> inline auto unpack(vector<T> &&G) {
    array<T, N> res;
    for (int i = 0; i < N; ++i) {
        res[i] = move(G[i]);
    }
    return res;
}
// TODO マージテク
// 数直線上での個数になおす
inline vector<int> coordinate(vector<int> &A) {
    vector<int> coordinate(MAX);
    for (auto &&v : A) ++coordinate[v];
    return coordinate;
}
// TODO 座標圧縮
// TODO 転倒数
// TODO 累積和系