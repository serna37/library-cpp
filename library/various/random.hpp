#pragma once
#include <chrono>
#include <random>
inline long long random(long long a, long long b) {
    if (a >= b) return a;
    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> dist(a, b - 1);
    return dist(mt);
}
