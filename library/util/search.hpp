#pragma once
/**
 * 順列全探索 O(N!) Nは10〜12程度
 * 順列の全パターン中でやりたい関数を入れる
 * 例) search_permu(A, [&](){cout << A;} );
 */
auto search_permu = []<class T, class F>(vector<T> &A, F f) {
    sort(A);
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
// TODO にぶたん系
