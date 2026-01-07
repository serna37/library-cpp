#pragma once
template <typename T> void merge(vector<T> &A, vector<T> &B) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) B.push_back(v);
    A.clear();
}
template <typename T> void merge(set<T> &A, set<T> &B) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) B.insert(v);
    A.clear();
}
template <typename T, typename F> void merge(T &A, T &B, F f) {
    if (A.size() > B.size()) swap(A, B);
    for (auto &&v : A) {
        f(B, v);
    }
    A.clear();
}
