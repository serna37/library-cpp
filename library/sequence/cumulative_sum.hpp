#pragma once
vector<long long> cumulative_sum(const vector<long long> &A) {
    int N = A.size();
    vector<long long> S(N + 1);
    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];
    return S;
}