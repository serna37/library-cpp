#pragma once
template <typename T> struct Compressor {
    vector<T> origin, dict;
    Compressor(const vector<T> &v) : origin(v), dict(v) {
        sort(dict.begin(), dict.end());
        dict.erase(unique(dict.begin(), dict.end()), dict.end());
    }
    int size() const { return dict.size(); }
    // 値 -> ID (圧縮)
    int get_id(T x) const {
        return lower_bound(dict.begin(), dict.end(), x) - dict.begin();
    }
    // 値 -> ID (upper_bound版)
    int get_upper_id(T x) const {
        return upper_bound(dict.begin(), dict.end(), x) - dict.begin();
    }
    // ID -> 値 (復元)
    T get_val(int id) const { return dict[id]; }
    // すべて圧縮
    vector<int> get_all() {
        vector<int> res;
        for (auto &&x : origin) res.emplace_back(get_id(x));
        return res;
    }
};
