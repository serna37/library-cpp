#pragma once
#include "library/number/mod/mod_pow.hpp"
long long mod_inverse(long long a, long long m) { return mod_pow(a, m - 2, m); }
