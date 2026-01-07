#pragma once
long long mod_pow(long long a, long long n, long long m) {
    long long res = 1ll;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1ll;
    }
    return res;
}