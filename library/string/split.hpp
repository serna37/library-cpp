#pragma once
vector<string> split(const string &S, const char &sep) {
    vector<string> res = {""};
    for (auto &&v : S) {
        if (v == sep) {
            res.emplace_back("");
        } else {
            res.back() += v;
        }
    }
    return res;
}