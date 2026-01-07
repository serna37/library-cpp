#pragma once
template <typename T> int zip_coordinate(vector<T> &A) {
    vector<T> cvt = A;
    sort(A.begin(), A.end());
    v.erase(unique(A.begin(), A.end()), v.end());
    for (auto &v : A) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    return (int)cvt.size();
}