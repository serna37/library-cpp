#pragma once
#include <functional>
pair<long long, long long> binary_search(function<bool(long long)> f) {
    long long L = 0, R = 1, MID = 0;
    while (!f(R)) R <<= 1;
    while (abs(R - L) > 1) {
        MID = L + (R - L) / 2;
        (f(MID) ? R : L) = MID;
    }
    return {L, R};
}
