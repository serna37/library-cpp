#pragma once
#include "library/sequence/compressor.hpp"
template <typename T> long long inversion_number(vector<T> &A) {
    Compressor<long long> zip(A);
    int sz = zip.size();
    vector<int> fwk(sz + 1);
    long long inv = 0, N = A.size();
    for (int i = 0; i < N; ++i) {
        for (int f = sz; f; f -= f & -f) inv += fwk[f];
        for (int f = A[i] + 1; f; f -= f & -f) inv -= fwk[f];
        for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];
    }
    return inv;
}
