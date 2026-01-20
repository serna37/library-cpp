#pragma once
template <typename T> void superset_zeta_transform(vector<T> &f) {
    const int n = (int)f.size();
    assert((n & (n - 1)) == 0ll);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                f[j + k] += f[j + k + i];
            }
        }
    }
}
template <typename T> void superset_moebius_transform(vector<T> &f) {
    const int n = (int)f.size();
    assert((n & (n - 1)) == 0ll);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                f[j + k] -= f[j + k + i];
            }
        }
    }
}
