#pragma once
#include "library/segtree/fenwick_tree.hpp"
#include "library/sequence/compressor.hpp"
template <typename T> long long inversion_number(const vector<T> &A) {
    if (A.empty()) return 0ll;
    Compressor<T> zip(A);
    vector<int> compressed_a = zip.get_all();
    int N = A.size(), sz = zip.size();
    FenwickTree fwk(sz);
    long long inv = 0;
    for (int i = 0; i < N; ++i) {
        inv += i - fwk.sum(compressed_a[i]);
        fwk.add(compressed_a[i], 1);
    }
    return inv;
}
