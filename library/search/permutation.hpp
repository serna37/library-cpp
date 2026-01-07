#pragma once
template <typename T, typename F> void permutation(vector<T> &A, F f) {
    sort(begin(A), end(A));
    do {
        f();
    } while (next_permutation(begin(A), end(A)));
}
