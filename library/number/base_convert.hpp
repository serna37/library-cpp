#pragma once
vector<int> base_convert(long long x, int to) {
    vector<int> ret;
    long long t = 1, k = abs(to);
    while (x) {
        ret.emplace_back((x * t) % k);
        if (ret.back() < 0) ret.back() += k;
        x -= ret.back() * t;
        x /= k;
        t *= to / k;
    }
    if (ret.empty()) ret.emplace_back(0);
    reverse(ret.begin(), ret.end());
    return ret;
}
