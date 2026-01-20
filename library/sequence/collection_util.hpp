#pragma once
class CollectionUtil {
  public:
    template <typename T> T min(const vector<T> &v) {
        return *min_element(all(v));
    }
    template <typename T> T max(const vector<T> &v) {
        return *max_element(all(v));
    }
    template <typename T> long long sum(const vector<T> &v) {
        return accumulate(all(v), 0ll);
    }
    template <typename T, typename F> bool all_match(const vector<T> &v, F f) {
        bool b = true;
        for (int i = 0; i < (int)v.size(); ++i) b &= f(v[i], i);
        return b;
    }
    template <typename T, typename F> bool none_match(const vector<T> &v, F f) {
        return !any_match(v, f);
    }
    template <typename T, typename F> bool any_match(const vector<T> &v, F f) {
        bool b = false;
        for (int i = 0; i < (int)v.size(); ++i) b |= f(v[i], i);
        return b;
    }
    template <typename T> void distinct(vector<T> &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }
    template <typename T> void asc(vector<T> &v) { sort(all(v)); }
    template <typename T> void desc(vector<T> &v) { sort(rall(v)); }
    template <typename T> void reverse(vector<T> &v) { std::reverse(all(v)); }
    template <typename T> void sequence(vector<T> &v, T start = 0) {
        iota(all(v), start);
    }
    template <typename T> void erase(set<T> &st, const T &v) {
        st.erase(st.find(v));
    }
    template <typename T> void erase(multiset<T> &st, const T &v) {
        st.erase(st.find(v));
    }
} collection;
