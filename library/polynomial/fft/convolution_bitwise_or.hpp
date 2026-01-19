#pragma once
#include "library/polynomial/fft/subset_zeta_moebius_transform.hpp"
template <typename T>
vector<T> convolution_bitwise_or(vector<T> f, vector<T> g) {
    const int n = (int)f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    subset_zeta_transform(f);
    subset_zeta_transform(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    subset_moebius_transform(f);
    return f;
}
