#pragma once
template <typename T> vector<long long> cumulative_sum_diff(const vector<T> &A) {
    int N = A.size();
    vector<long long> S(N + 1);
    for (int i = 0; i < N; ++i) {
        S[i + 1] = S[i];
        if (i & 1) S[i + 1] += abs(A[i] - A[i - 1]);
    }
    return S;
}