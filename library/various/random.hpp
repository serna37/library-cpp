#pragma once
inline int random(int a, int b) {
    if (a >= b) return a;
    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
}
