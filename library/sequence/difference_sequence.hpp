#pragma once
template <typename T>
vector<long long> difference_sequence(const vector<T> &A) {
    int N = A.size();
    vector<long long> D(N - 1);
    for (int i = 0; i < N; ++i) D[i] = A[i + 1] - A[i];
    return D;
}
