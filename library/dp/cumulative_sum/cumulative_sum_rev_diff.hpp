#pragma once
template <typename T>
vector<long long> cumulative_sum_rev_diff(const vector<T> &A) {
    int N = A.size();
    vector<long long> R(N + 1);
    for (int i = N - 1; i >= 0; --i) {
        R[i] = R[i + 1];
        if (i & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) - A[i]);
    }
    return R;
}
