#pragma once
template <typename T, typename F> bool permutation(vector<T> &A, F f) {
    sort(begin(A), end(A));
    do {
        if (f()) return true;
    } while (next_permutation(begin(A), end(A)));
    return false;
}
