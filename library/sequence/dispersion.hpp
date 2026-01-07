#pragma once
vector<int> dispersion(const vector<int> &A) {
    vector<int> res(2e6);
    for (auto &&v : A) ++res[v];
    return res;
}