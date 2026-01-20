#pragma once
#include "library/sequence/compressor.hpp"
template <typename T>
struct StaticRangeFrequency {
  private:
    Compressor<T> comp;
    vector<vector<int>> mp;

  public:
    explicit StaticRangeFrequency(const vector<T> &xs) : comp(xs) {
        mp.resize(comp.size());
        for (int i = 0; i < (int)xs.size(); ++i) {
            int id = comp.get_id(xs[i]);
            mp[id].emplace_back(i);
        }
    }
    int query(int l, int r, T x) const {
        int id = comp.get_id(x);
        if (id >= (int)comp.size() or comp.get_val(id) != x) return 0ll;
        const auto &pos = mp[id];
        return lower_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
    }
};
