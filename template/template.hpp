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
// ---------------------------------------- includeしまくる
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
// ---------------------------------------- いつものやつ
#include <bits/stdc++.h>
using namespace std;
// ---------------------------------------- お守り
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
// ---------------------------------------- main関数
void solve();
signed main() {
    solve();
}
// ---------------------------------------- IO
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
template <typename T> void print(const T &v) {
    cout << v << endl;
}
template <typename T> void print(const vector<vector<T>> &G) {
    for (auto &&v : G) cout << v << endl;
}
// ---------------------------------------- 定数
const long long INF = 1e18;
const long long MOD = 998244353;
const long long MOD7 = 1e9 + 7;
const long double PI = acosl(-1);
// ---------------------------------------- 省略する系のやつ
template <typename T> using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec2 = vector<vector<T>>;
template <typename T> vec2<T> make_vec2(int H, int W, T init = 0) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
template <typename T> void chmin(T &i, const T &j) {
    return i > j && (i = j, true);
}
template <typename T> void chmax(T &i, const T &j) {
    return i < j && (i = j, true);
}
// ---------------------------------------- C++特有の挙動を使いやすくするやつら
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
long long string_to_int(const string &s) {
    return stoll(s);
}
string string_to_lower(string s) {
    std::transform(all(s), s.begin(), ::tolower);
    return s;
}
string string_to_upper(string s) {
    std::transform(all(s), s.begin(), ::toupper);
    return s;
}
bool char_is_lower(char c) { // boolで返す
    return islower(c) != 0;
}
bool char_is_upper(char c) { // boolで返す
    return isupper(c) != 0;
}
long long div_ceil(long long a, long long b) { // 負の場合0側へ丸めない
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
}
long long div_floor(long long a, long long b) { // 負の場合0側へ丸めない
    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
}
double deg_to_rad(double d) { // 度数法 → 弧度法
    return d * PI / 180;
}
double rad_to_deg(double r) { // 弧度法 → 度数法
    return r * 180 / PI;
}
double arc_tan(double x, double y) { // 偏角をラジアンで返す
    return atan2(y, x);
}
class Collection {
  public:
    template <typename T> T min(const vector<T> &v) {
        return *min_element(all(v));
    }
    template <typename T> T max(const vector<T> &v) {
        return *max_element(all(v));
    }
    template <typename T> long long sum(const vector<T> &v) {
        return accumulate(all(v), 0ll);
    }
    template <typename T, typename F> bool all_match(const vector<T> &v, F f) {
        return all_of(all(v), f);
    }
    template <typename T, typename F> bool none_match(const vector<T> &v, F f) {
        return none_of(all(v), f);
    }
    template <typename T, typename F> bool any_match(const vector<T> &v, F f) {
        return any_of(all(v), f);
    }
    template <typename T> void distinct(vector<T> &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }
    template <typename T> void asc(vector<T> &v) {
        sort(all(v));
    }
    template <typename T> void desc(vector<T> &v) {
        sort(rall(v));
    }
    template <typename T> void reverse(vector<T> &v) {
        std::reverse(all(v));
    }
    template <typename T> void erase(set<T> &st, const T &v) {
        st.erase(st.find(v));
    }
    template <typename T> void erase(multiset<T> &st, const T &v) {
        st.erase(st.find(v));
    }
    template <typename T> void sequence(vector<T> &v, T start = 0) {
        iota(all(v), start);
    }
} collection;
// ----------------------------------------
// #include "template/template.hpp" is done.
// ----------------------------------------
