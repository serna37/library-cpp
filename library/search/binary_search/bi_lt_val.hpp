#pragma once
template <typename T> T bi_lt_val(vector<T> &v, const T &x) {
    auto it = lower_bound(v.begin(), v.end(), x);
    return (it == v.begin() ? -1e18 : *--it);
}
template <typename T> T bi_lt_val(const set<T> &st, const T &x) {
    auto it = st.lower_bound(x);
    return (it == st.begin() ? -1e18 : *--it);
}
