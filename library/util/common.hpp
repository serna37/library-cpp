
/** ======================================= */
/**              共通                       */
/** ======================================= */
#pragma once
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
