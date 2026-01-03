/**
 * @brief ฅ^>ω<^ฅ
 * @author serna37
 * @note https://serna37.github.io/library-cpp/
 */
#ifdef LOCAL

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
// -----------------------------------------
// #include "template/includes.hpp" is done.
// -----------------------------------------

#include <bits/stdc++.h>
using namespace std;

/** ======================================= */
/**              共通                       */
/** ======================================= */

#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))
// lambda($(0) + $(1))とできる
#define lambda(...) ([&](auto &&..._args) { return (__VA_ARGS__); })
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
// [a, b)で乱数生成 メルセンヌツイスタ
auto random_mersenne_twister = [](int a = 1, int b = 1e5 + 1) {
    uniform_int_distribution<int> dist(a, b - 1);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    return dist(mt);
};


/** ======================================= */
/**                IO                       */
/** ======================================= */

struct IoSetup {
    IoSetup() {
        cin.tie(0)->sync_with_stdio(0);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template <typename T> istream &operator>>(istream &s, vector<T> &v) {
    for (auto &&e : v) s >> e;
    return s;
}
template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
    int i = 0;
    for (auto &&e : v) s << (i++ ? " " : "") << e;
    return s;
}
template <typename T> void print(const vector<vector<T>> &G) {
    for (auto &&v : G) cout << v << endl;
}
template <typename T, typename U> void print(const pair<T, U> &p) {
    cout << p.first << " " << p.second << endl;
}
template <typename T> void print(const T &v) {
    cout << v << endl;
}
void yn(bool o) {
    cout << (o ? "Yes" : "No") << endl;
}
void YN(bool o) {
    cout << (o ? "YES" : "NO") << endl;
}


/** ======================================= */
/**                 型                      */
/** ======================================= */

template <typename T>
using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec2 = vector<vector<T>>;
vec2<int> make_vec2(int H, int W, int init = 0) {
    return vector<vector<int>>(H, vector<int>(W, init));
}
char int_to_char(int x) {
    return (char)(x + '0');
}
char int_to_alph(int x) {
    return (char)(x + 'a');
}
int char_to_int(char c) {
    return (int)(c - '0');
}
string int_to_string(long long x) {
    return to_string(x);
}
long long string_to_int(string s) {
    return stoll(s);
}


/** ======================================= */
/**              定数                       */
/** ======================================= */

const long long INF = 1e18;
const long long MAX = 2e6;
const long long MOD = 998244353;
const long long MOD7 = 1e9 + 7;
const long double EPS = 1e-14;
const double PI = acos(-1);
// 下右上左 DRUL
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
// 8方向
const vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};

void solve();
signed main() {
    solve();
}
// -----------------------------------------
// #include "template/template.hpp" is done.
// -----------------------------------------

// #include "template/lib.hpp"
// #include "library/struct/graph.hpp"
// #include "library/struct/union_find.hpp"
// #include "library/struct/fenwick_tree.hpp"
// #include "library/struct/monoid.hpp"
// #include "library/struct/segment_tree.hpp"
// #include "library/struct/dual_segment_tree.hpp"
// #include "library/struct/lazy_segment_tree.hpp"
/**
 * @brief 🍪🧸🐾
 */
void solve() {
}

