#pragma once
template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {
    return v.end() - lower_bound(v.begin(), v.end(), x);
}
