#pragma once
#include "library/number/euler_phi.hpp"
#include "library/number/mod/mod_pow.hpp"
template <typename T>
T mod_tetration(const T &a, const T &b, const T &m) {
    if (m == 1ll) return 0ll;
    if (a == 0ll) return !(b & 1ll);
    if (b == 0ll) return 1ll;
    if (b == 1ll) return a % m;
    if (b == 2ll) return mod_pow(a, a, m);
    auto phi = euler_phi(m);
    auto tmp = mod_tetration(a, b - 1, phi);
    if (tmp == 0ll) tmp += phi;
    return mod_pow(a, tmp, m);
}
