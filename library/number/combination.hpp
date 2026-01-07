#pragma once
long long combination(int n, int k) {
    if (k < 0 || n < k) return 0ll;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= n--;
        res /= i;
    }
    return res;
}
