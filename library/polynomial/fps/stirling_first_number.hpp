#pragma once
#include "library/polynomial/fps/formal_power_series.hpp"
template <template <typename> class FPS, typename Mint>
FPS<Mint> stirling_first_number(int N) {
    if (N <= 0) return {Mint(1)};
    auto f = stirling_first_number<FPS, Mint>(N >> 1);
    f *= f.taylor_shift(-(N >> 1));
    if (N & 1) f = (f << 1) - f * (N - 1);
    return f;
}
