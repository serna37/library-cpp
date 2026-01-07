#pragma once
template <typename T> T bi_lt_val(vector<T> &v, const T &x) {
    sort(v.begin(), v.end());
    auto it = lower_bound(v.begin(), v.end(), x);
    return (it == v.begin() ? -INF : *--it);
}
template <typename T> T bi_lt_val(const set<T> &st, const T &x) {
    auto it = st.lower_bound(x);
    return (it == st.begin() ? -INF : *--it);
}