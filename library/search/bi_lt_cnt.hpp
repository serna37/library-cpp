#pragma once
template <typename T> int bi_lt_cnt(vector<T> &v, const T &x) {
    sort(v.begin(), v.end());
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
