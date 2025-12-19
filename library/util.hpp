#pragma once
/**
 * @file util.hpp
 * @brief ユーティリティ
 */
using ll = long long;
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template <typename Tp>
using reverse_queue = priority_queue<Tp, vector<Tp>, greater<Tp>>;
template <typename T>
using vec2 = vector<vector<T>>;
// 2次元配列
template <typename T>
inline vector<vector<T>> make_vec2(const int H, const int W, const T& init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
// 2次元配列
template <typename T>
inline vector<vector<T>> make_vec2(const int H, const int W) {
    return vector<vector<T>>(H, vector<T>(W));
}
// int → char
char int_to_char(int x) {
    return (char)(x + '0');
}
// int → alph
char int_to_alph(int x) {
    return (char)(x + 'a');
}
// char → int
int char_to_int(char c) {
    return (int)(c - '0');
}
// 数字 → string
string toString(long long x) {
    return to_string(x);
}
// string → 数字
long long toInteger(string s) {
    return stoll(s);
}
// 割り下げ（負の場合0側へ丸めない）
auto divCeil = []<class T>(T a, T b) -> T {
	return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
// 割り上げ（負の場合0側へ丸めない）
auto divFloor = []<class T>(T a, T b) -> T {
	return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
};
// iをjで緩和 min
template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmin(T1& i, const T2 j) noexcept {
    if (i > j) {
        i = j;
        return true;
    }
    return false;
}
// iをjで緩和 max
template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmax(T1& i, const T2 j) noexcept {
    if (i < j) {
        i = j;
        return true;
    }
    return false;
}
// all match
template <typename T, typename F> bool allMatch(vector<T> &v, F f) {
    return all_of(all(v), f);
}
// none match
template <typename T, typename F> bool noneMatch(vector<T> &v, F f) {
    return none_of(all(v), f);
}
// any match
template <typename T, typename F> bool anyMatch(vector<T> &v, F f) {
    return any_of(all(v), f);
}
// 最大値
template <typename T> T max(vector<T> &v) {
    return *max_element(all(v));
}
// 最小値
template <typename T> T min(vector<T> &v) {
    return *min_element(all(v));
}
// 総和
long long sum(vector<long long> &v) {
    return accumulate(all(v), 0ll);
}
// 要素数カウント
template <typename T> int cnt(vector<T> &v) {
    return (int)v.size();
}
// フィルタ
template <typename T, typename F> vector<T> filter(vector<T> &v, F f) {
    vector<T> res;
    for (auto &&e : v) {
        if (f(e)) res.push_back(e);
    }
    return res;
}
// ソート
template <typename T> void sort(vector<T> &v) {
    sort(all(v));
}
// ソート(大きい順)
template <typename T> void sortRev(vector<T> &v) {
    sort(rall(v));
}
// リバース
template <typename T> void reverse(vector<T> &v) {
    reverse(all(v));
}
// 重複削除
template <typename T> void distinct(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
// set multisetでのerase
template <typename T> void erase(set<T> &st, T &v) {
    st.erase(st.find(v));
}
// set multisetでのerase
template <typename T> void erase(multiset<T> &st, T &v) {
    st.erase(st.find(v));
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
// vector分割代入用。Gは破壊。auto [a,b]=unpack<2>(G);できる
template <int N, typename T>
auto unpack(vector<T> &&G) {
    array<T, N> res;
    for (int i = 0; i < N; ++i) {
        res[i] = move(G[i]);
    }
    return res;
}
// 数直線上での個数になおす
vector<int> coordinate(vector<int> &A) {
    vector<int> coordinate(MAX);
    for (auto &&v : A) ++coordinate[v];
    return coordinate;
}
