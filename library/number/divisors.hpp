#pragma once
vector<int> divisors(int N) {
    vector<int> res;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i != 0) continue;
        res.push_back(i);
        if (N / i != i) res.push_back(N / i);
    }
    return res;
}