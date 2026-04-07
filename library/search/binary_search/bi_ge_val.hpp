#pragma once
template <typename T> T bi_ge_val(vector<T> &v, const T &x) {
  auto it = lower_bound(v.begin(), v.end(), x);
  return (it == v.end() ? 1e18 : *it);
}
template <typename T> T bi_ge_val(const set<T> &st, const T &x) {
  auto it = st.lower_bound(x);
  return (it == st.end() ? 1e18 : *it);
}
