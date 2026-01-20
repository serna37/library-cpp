#pragma once
template <typename T> T ext_gcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0ll) {
        d = ext_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1ll;
        y = 0ll;
    }
    return d;
}
