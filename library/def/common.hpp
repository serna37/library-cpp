
/** ======================================= */
/**              共通                       */
/** ======================================= */
#pragma once
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))
// lambda($(0) + $(1))とできる
#define lambda(...) ([&](auto &&..._args) { return (__VA_ARGS__); })
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
