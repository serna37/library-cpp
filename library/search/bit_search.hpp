#pragma once
template <typename T> vector<vector<T>> bit_search(const vector<T> &A) {
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