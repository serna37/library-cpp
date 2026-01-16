#pragma once
#include "library/string/rolling_hash.hpp"
// ナイーブ
vector<int> finds(const string &T, const string &S) {
    vector<int> pos;
    auto p = T.find(S);
    while (p != string::npos) {
        pos.emplace_back(p);
        p = T.find(S, p + 1);
    }
    return pos;
}
// RollingHashで実装
vector<int> finds_rolling_hash(const string &T, const string &P) {
    vector<int> res;
    int t = T.size();
    int p = P.size();
    RollingHash rht(T);
    RollingHash rhp(P);
    if (t < p) return res;
    long long hash_p = rhp.get(0, p);
    for (int i = 0; i < t - p + 1; ++i) {
        if (rht.get(i, i + p) == hash_p) {
            res.emplace_back(i);
        }
    }
    return res;
}
