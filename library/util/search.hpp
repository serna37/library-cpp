
/** ======================================= */
/**               探索                      */
/** ======================================= */
#pragma once
class Search {
  public:
    /**
     * 順列全探索 O(N!) Nは10〜12程度
     * 順列の全パターン中でやりたい関数を入れる
     * 例) search_permu(A, [&](){cout << A;} );
     */
    template <typename T, typename F> void perm(vector<T> &A, F f) {
        sort(all(A));
        do {
            f();
        } while (next_permutation(all(A)));
    }
    /**
     * bit全探索 O(2^N) Nは20前後
     * 集合Aの全パターンの部分集合を返す
     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }
     */
    template <typename T> vector<vector<T>> bit(vector<T> &A) {
        int N = A.size();
        vector<vector<T>> res;
        for (long long bit = 0; bit < (1ll << N); ++bit) {
            vector<T> tmp;
            for (int k = 0; k < N; ++k) {
                if (bit & (1ll << k)) {
                    tmp.push_back(A[k]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
    /**
     * 整数上の二分探索
     *     L R
     * x x x o o o o
     *       ↑ここを求める
     * 条件：5 <= xなら、L=4, R=5
     */
    template <typename F> pair<long long, long long> bi(F f) {
        long long L = 0, R = 1, MID = 0;
        while (!f(R)) R <<= 1;
        while (abs(R - L) > 1) {
            MID = L + (R - L) / 2;
            (f(MID) ? R : L) = MID;
        }
        return make_pair(L, R);
    }
    /**
     * 実数上の二分探索
     *     L R
     * x x x o o o o
     *       ↑ここを求める
     * 条件：3.5 <= xなら、L=3.5, R=3.5 (LRの誤差がEPS内)
     */
    template <typename F> pair<double, double> bi_real(F f) {
        double L = 0, R = 1, MID = 0;
        while (!f(R)) R *= 2;
        auto ABS = [&]() { return abs(R - L) > EPS; };
        auto REL = [&]() { return abs(R - L) / max(R, L) > EPS; };
        while (ABS() and REL()) {
            MID = L + (R - L) / 2;
            (f(MID) ? R : L) = MID;
        }
        return make_pair(L, R);
    }
    // 以下の要素数
    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return upper_bound(all(v), x) - v.begin();
    }
    // 以下の値 存在しない場合-INF
    template <typename T> T bi_le_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = upper_bound(all(v), x);
        return (it == v.begin() ? -INF : *--it);
    }
    // 以下の値  存在しない場合-INF
    template <typename T> T bi_le_val(const set<T> &st, const T &x) {
        auto it = st.upper_bound(x);
        return (it == st.begin() ? -INF : *--it);
    }
    // 以上の要素数
    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return v.end() - lower_bound(all(v), x);
    }
    // 以上の最小値 存在しない場合 INF
    template <typename T> T bi_ge_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = lower_bound(all(v), x);
        return (it == v.end() ? INF : *it);
    }
    // 以上の最小値 存在しない場合 INF
    template <typename T> T bi_ge_val(const set<T> &st, const T &x) {
        auto it = st.lower_bound(x);
        return (it == st.end() ? INF : *it);
    }
    // 未満の要素数
    template <typename T> int bi_lt_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return lower_bound(all(v), x) - v.begin();
    }
    // 未満の最大値 存在しない場合 -INF
    template <typename T> T bi_lt_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = lower_bound(all(v), x);
        return (it == v.begin() ? -INF : *--it);
    }
    // 未満の最大値 存在しない場合 -INF
    template <typename T> T bi_lt_val(const set<T> &st, const T &x) {
        auto it = st.lower_bound(x);
        return (it == st.begin() ? -INF : *--it);
    }
    // より上の要素数
    template <typename T> int bi_gt_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return v.end() - upper_bound(all(v), x);
    }
    // より上の最小値 存在しない場合 INF
    template <typename T> T bi_gt_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = upper_bound(all(v), x);
        return (it == v.end() ? INF : *it);
    }
    // より上の最小値 存在しない場合 INF
    template <typename T> T bi_gt_val(const set<T> &st, const T &x) {
        auto it = st.upper_bound(x);
        return (it == st.end() ? INF : *it);
    }
    // メモ化再帰 !!コピペ用!! 関数内をペーストして書き換えて使う
    void dfs_memo() {
        map<int, int> memo;
        auto dfs = [&](auto f, int n) {
            if (n <= 1) return n;
            if (memo.count(n)) return memo[n];
            return memo[n] = f(f, n - 1) + f(f, n - 2);
        };
        (void)dfs; // unused
        // int ans = dfs(dfs, N);
    }
};
