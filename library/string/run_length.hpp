#pragma once
vector<pair<char, int>> run_length(const string &S) {
    vector<pair<char, int>> res;
    for (auto &&x : S) {
        if (res.empty() or res.back().first != x) res.emplace_back(x, 0);
        ++res.back().second;
    }
    return res;
}