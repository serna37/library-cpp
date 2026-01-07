#pragma once
vector<int> finds(const string &T, const string &S) {
    vector<int> pos;
    auto p = T.find(S);
    while (p != string::npos) {
        pos.emplace_back(p);
        p = T.find(S, p + 1);
    }
    return pos;
}