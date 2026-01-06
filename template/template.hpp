/**
 * @brief ฅ^>ω<^ฅ
 * @author serna37
 * @note https://serna37.github.io/library-cpp/
 */
#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...)
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

#include "library/def/common.hpp"
#include "library/def/io.hpp"
#include "library/def/type.hpp"
#include "library/def/const.hpp"

/** ======================================= */
/**              main                       */
/** ======================================= */
void solve();
signed main() {
    solve();
}

#include "library/util/number.hpp"
#include "library/util/string.hpp"
#include "library/util/sequence.hpp"
#include "library/util/search.hpp"
#include "library/util/grid.hpp"
#include "library/util/geometry.hpp"
/**
 * @brief util系
 */
namespace lib {
Number num;
String str;
Sequence seq;
Search search;
Grid grid;
Geometry geo;
}; // namespace lib

// -----------------------------------------
// #include "template/template.hpp" is done.
// -----------------------------------------