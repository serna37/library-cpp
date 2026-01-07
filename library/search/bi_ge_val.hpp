#pragma once
template <typename T> T bi_ge_val(vector<T> &v, const T &x) {
    sort(v.begin(), v.end());
    auto it = lower_bound(v.begin(), v.end(), x);
    return (it == v.end() ? INF : *it);
}
template <typename T> T bi_ge_val(const set<T> &st, const T &x) {
    auto it = st.lower_bound(x);
    return (it == st.end() ? INF : *it);
}