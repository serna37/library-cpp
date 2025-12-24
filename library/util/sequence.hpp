
/** ======================================= */
/**              配列・数列                 */
/** ======================================= */
#pragma once
class Sequence {
  public:
    template <typename T> T min(const vector<T> &v) {
        return *min_element(all(v));
    }
    template <typename T> T max(const vector<T> &v) {
        return *max_element(all(v));
    }
    template <typename T> long long sum(const vector<T> &v) {
        return accumulate(all(v), 0ll);
    }
    template <typename T, typename F> bool all_match(const vector<T> &v, F f) {
        return all_of(all(v), f);
    }
    template <typename T, typename F> bool none_match(const vector<T> &v, F f) {
        return none_of(all(v), f);
    }
    template <typename T, typename F> bool any_match(const vector<T> &v, F f) {
        return any_of(all(v), f);
    }
    template <typename T> void distinct(vector<T> &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }
    template <typename T> void sort_asc(vector<T> &v) {
        sort(all(v));
    }
    template <typename T> void sort_desc(vector<T> &v) {
        sort(rall(v));
    }
    template <typename T> void reverse(vector<T> &v) {
        reverse(all(v));
    }
    // setから要素削除
    template <typename T> void erase(set<T> &st, T &v) {
        st.erase(st.find(v));
    }
    // multisetから要素削除
    template <typename T> void erase(multiset<T> &st, T &v) {
        st.erase(st.find(v));
    }
    // 行列の転置
    template <typename T>
    vector<vector<T>> transpose(const vector<vector<T>> &G) {
        int H = G.size(), W = G[0].size();
        vector<vector<T>> _G(W, vector<T>(H));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                _G[j][i] = G[i][j];
            }
        }
        return _G;
    }
    /**
     * 分割代入できるようにする Gは破壊。
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
    vector<int> coordinate(const vector<int> &A) {
        vector<int> res(MAX);
        for (auto &&v : A) ++res[v];
        return res;
    }
    // 座標圧縮 圧縮後の種類数を返却
    template <typename T> int zip_coordinate(vector<T> &A) {
        vector<T> cvt = A;
        distinct(cvt);
        for (auto &v : A) v = lower_bound(all(cvt), v) - cvt.begin();
        return (int)cvt.size();
    }
    // 転倒数 右に倒れるA_i > A_j (i < j)の回数
    template <typename T> long long inversion_number(vector<T> &A) {
        int sz = zip_coordinate(A);
        vector<int> fwk(sz + 1);
        long long inv = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int f = sz; f; f -= f & -f) inv += fwk[f];
            for (int f = A[i] + 1; f; f -= f & -f) inv -= fwk[f];
            for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];
        }
        return inv;
    };
};
// TODO 累積和系
