#pragma once
#include "library/number/mod/mod_inverse.hpp"
#include "library/number/mod/mod_factorial.hpp"
long long mod_combination(int n, int k, long long m) {
    if (k < 0 or n < k) return 0ll;
    return mod_factorial(n, m) * mod_inverse(mod_factorial(k, m), m) % m *
           mod_inverse(mod_factorial(n - k, m), m) % m;
}
