
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
// [a, b)で乱数生成 メルセンヌツイスタ
auto random_mersenne_twister = [](int a = 1, int b = 1e5 + 1) {
    uniform_int_distribution<int> dist(a, b - 1);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    return dist(mt);
};
