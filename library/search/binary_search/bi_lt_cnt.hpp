#pragma once
template <typename T> int bi_lt_cnt(vector<T> &v, const T &x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
