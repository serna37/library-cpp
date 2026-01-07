#pragma once
template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {
    sort(v.begin(), v.end());
    return upper_bound(v.begin(), v.end(), x) - v.begin();
}