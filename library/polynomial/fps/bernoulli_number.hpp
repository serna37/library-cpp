#pragma once
#include "library/polynomial/fps/formal_power_series.hpp"
template <template <typename> class FPS, typename Mint>
FPS<Mint> bernoulli_number(int N) {
    FPS<Mint> poly(N + 1);
    poly[0] = Mint(1);
    for (int i = 1; i <= N; i++) {
        poly[i] = poly[i - 1] / Mint(i + 1);
    }
    poly = poly.inv();
    Mint tmp(1);
    for (int i = 1; i <= N; i++) {
        tmp *= Mint(i);
        poly[i] *= tmp;
    }
    return poly;
}
