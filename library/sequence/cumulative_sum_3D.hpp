#pragma once
template <typename T>
vector<vector<vector<long long>>>
cumulative_sum_3D(const vector<vector<vector<T>>> &A) {
    vector<vector<vector<long long>>> S;
    int szx = A.size(), szy = A[0].size(), szz = A[0][0].size();
    S.resize(szx + 1, vector<vector<long long>>(
                            szy + 1, vector<long long>(szz + 1, 0)));
    for (int x = 1; x <= szx; ++x) {
        for (int y = 1; y <= szy; ++y) {
            for (int z = 1; z <= szz; ++z) {
                S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +
                                S[x][y - 1][z] + S[x][y][z - 1] -
                                S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -
                                S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];
            }
        }
    }
    return S;
}