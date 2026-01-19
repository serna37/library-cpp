#pragma once
#include "library/polynomial/fft/fast_walsh_hadamard_transform.hpp"
template <typename T>
vector<T> convolution_bitwise_xor(vector<T> f, vector<T> g) {
    const int n = (int)f.size();
    assert(f.size() == g.size());
    assert((n & (n - 1)) == 0);
    fast_walsh_hadamard_transform(f);
    fast_walsh_hadamard_transform(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    fast_walsh_hadamard_transform(f, true);
    return f;
}
