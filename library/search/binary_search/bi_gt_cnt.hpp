#pragma once
template <typename T> int bi_gt_cnt(vector<T> &v, const T &x) {
    return v.end() - upper_bound(v.begin(), v.end(), x);
}
