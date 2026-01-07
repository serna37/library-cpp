#pragma once
template <typename T> int zip_coordinate(vector<T> &A) {
    vector<T> cvt = A;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : A) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    return (int)cvt.size();
}
