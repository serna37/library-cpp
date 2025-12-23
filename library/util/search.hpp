
/** ======================================= */
/**               探索                      */
/** ======================================= */
#pragma once
/**
 * 順列全探索 O(N!) Nは10〜12程度
 * 順列の全パターン中でやりたい関数を入れる
 * 例) search_permu(A, [&](){cout << A;} );
 */
auto search_permu = []<class T, class F>(vector<T> &A, F f) {
    sort(all(A));
    do {
        f();
    } while (next_permutation(all(A)));
};
/**
 * bit全探索 O(2^N) Nは20前後
 * 集合Aの全パターンの部分集合を返す
 * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }
 */
auto search_bit = []<class T>(vector<T> &A) {
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
};
/**
 * 整数上の二分探索
 *     L R
 * x x x o o o o
 *       ↑ここを求める
 * 条件：5 <= xなら、L=4, R=5
 */
auto search_bi = []<class F>(F f) {
    long long L = 0, R = 1, MID = 0;
    while (!f(R)) R <<= 1;
    while (abs(R - L) > 1) {
        MID = L + (R - L) / 2;
        (f(MID) ? R : L) = MID;
    }
    return make_pair(L, R);
};
/**
 * 実数上の二分探索
 *     L R
 * x x x o o o o
 *       ↑ここを求める
 * 条件：3.5 <= xなら、L=3.5, R=3.5 (LRの誤差がEPS内)
 */
auto search_bi_real = []<class F>(F f) {
    double L = 0, R = 1, MID = 0;
    while (!f(R)) R *= 2;
    auto ABS = [&]() { return abs(R - L) > EPS; };
    auto REL = [&]() { return abs(R - L) / max(R, L) > EPS; };
    while (ABS() and REL()) {
        MID = L + (R - L) / 2;
        (f(MID) ? R : L) = MID;
    }
    return make_pair(L, R);
};
// TODO lower_boundとかのやつ
