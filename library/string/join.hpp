#pragma once
string join(const vector<string> &v, const string &sep) {
    string res;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (0 < i) res += sep;
        res += v[i];
    }
    return res;
}
