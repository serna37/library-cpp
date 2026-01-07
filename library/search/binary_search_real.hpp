#pragma once
const long double EPS = 1e-14;
pair<double, double> binary_search_real(function<bool(double)> f) {
    double L = 0, R = 1, MID = 0;
    while (!f(R)) R *= 2;
    auto ABS = [&]() { return abs(R - L) > EPS; };
    auto REL = [&]() { return abs(R - L) / max(R, L) > EPS; };
    while (ABS() and REL()) {
        MID = L + (R - L) / 2;
        (f(MID) ? R : L) = MID;
    }
    return {L, R};
}