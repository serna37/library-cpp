#pragma once
template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
}
