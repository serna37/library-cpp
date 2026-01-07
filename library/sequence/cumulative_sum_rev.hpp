#pragma once
template <typename T> vector<long long> cumulative_sum_rev(const vector<T> &A) {
    int N = A.size();
    vector<long long> R(N + 1);
    for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] + A[i];
    return R;
}
