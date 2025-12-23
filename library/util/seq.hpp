
/** ======================================= */
/**              配列・数列                 */
/** ======================================= */
#pragma once
auto len = []<class T>(vector<T> &v) { return (int)v.size(); };
template <typename T> T min(vector<T> &v) {
    return *min_element(all(v));
}
template <typename T> T max(vector<T> &v) {
    return *max_element(all(v));
}
auto sum = [](vector<long long> &v) { return accumulate(all(v), 0ll); };
auto allMatch = []<class T, class F>(vector<T> &v, F f) {
    return all_of(all(v), f);
};
auto noneMatch = []<class T, class F>(vector<T> &v, F f) {
    return none_of(all(v), f);
};
auto anyMatch = []<class T, class F>(vector<T> &v, F f) {
    return any_of(all(v), f);
};
auto sort_asc = []<class T>(vector<T> &v) { sort(all(v)); };
auto sort_desc = []<class T>(vector<T> &v) { sort(rall(v)); };
template <typename T> void reverse(vector<T> &v) {
    reverse(all(v));
}
auto distinct = []<class T>(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
};
// setから要素削除
template <typename T> void erase(set<T> &st, T &v) {
    st.erase(st.find(v));
}
// multisetから要素削除
template <typename T> void erase(multiset<T> &st, T &v) {
    st.erase(st.find(v));
}
// 行列の転置
auto transpose = []<class T>(vector<vector<T>> &G) {
    int H = G.size(), W = G[0].size();
    vector<vector<T>> _G(W, vector<T>(H));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            _G[j][i] = G[i][j];
        }
    }
    return _G;
};
/**
 * 分割代入できるようにする
 * Gは破壊。
 * auto [a,b] = unpack<2>(move(G));
 */
template <int N, typename T> auto unpack(vector<T> &&G) {
    array<T, N> res; // vector -> array変換するだけ
    for (int i = 0; i < N; ++i) res[i] = move(G[i]);
    return res;
}
// AをBにマージテク vector
template <typename T> void merge(vector<T> &A, vector<T> &B) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) B.push_back(v);
    A.clear();
}
// AをBにマージテク set
template <typename T> void merge(set<T> &A, set<T> &B) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) B.insert(v);
    A.clear();
}
// AをBにマージテク マージ操作をラムダ化
template <typename T, typename F> void merge(T &A, T &B, F f) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) {
        f(B, v);
    }
    A.clear();
}
// 数直線上での個数になおす
vector<int> coordinate(vector<int> &A) {
    vector<int> res(MAX);
    for (auto &&v : A) ++res[v];
    return res;
}
// TODO 座標圧縮
// TODO 転倒数
// TODO 累積和系
