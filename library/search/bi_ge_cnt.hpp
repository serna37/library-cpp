#pragma once
template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {
    sort(v.begin(), v.end());
    return v.end() - lower_bound(v.begin(), v.end(), x);
}
