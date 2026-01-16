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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
template <typename T> using vec2 = vector<vector<T>>;
template <typename T> using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
const long long INF = 1e18;
const long long MOD = 998244353;
const long long MOD7 = 1e9 + 7;
const long double PI = acosl(-1);
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
    for (int i = 0; i < (int)v.size(); ++i) s << (i ? " " : "") << v[i];
    return s;
}
template <typename T> void print(const T &v) { cout << v << endl; }
template <typename T> void print(const vector<vector<T>> &G) { for (auto &&v : G) cout << v << endl; }
template <typename T> vec2<T> make_vec2(int H, int W, T init = 0) { return vector<vector<T>>(H, vector<T>(W, init)); }
template <typename T> bool chmin(T &i, const T &j) { return i > j && (i = j, true); }
template <typename T> bool chmax(T &i, const T &j) { return i < j && (i = j, true); }
void solve();
signed main() { solve(); }
// ----------------------------------------
// #include "template/template.hpp" is done.
// ----------------------------------------
