#pragma once
vector<long long> _mf_memo;
long long mod_factorial(int x, long long m) {
    if ((int)_mf_memo.size() > x) return _mf_memo[x];
    if (_mf_memo.empty()) _mf_memo.push_back(1);
    for (int i = _mf_memo.size(); i <= x; ++i)
        _mf_memo.push_back(_mf_memo.back() * i % m);
    return _mf_memo[x];
}
