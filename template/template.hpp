#pragma once
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
#define endl "\n"
constexpr long long INF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr long long MOD998 = 998244353;
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
template <typename T, typename U> istream &operator>>(istream &s, vector<pair<T, U>> &vp) {
  for (auto &&p : vp) s >> p.first >> p.second;
  return s;
}
template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); ++i) s << (i ? " " : "") << v[i];
  return s;
}
template <typename T> void print(const T &v) { cout << v << endl; }
template <typename T> void print(const vector<vector<T>> &G) { for (auto &&v : G) cout << v << endl; }
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
void solve();
signed main() { solve(); }
// ----------------------------------------
// #include "template/template.hpp" is done.
// ----------------------------------------