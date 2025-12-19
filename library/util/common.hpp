#pragma once
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
/**
 * 緩和 min
 * chmin(i, j); iをより小さいほうにする
 */
auto chmin = []<class T>(T &i, T &j) {
    if (i > j) {
        i = j;
        return true;
    }
    return false;
};
/**
 * 緩和 max
 * chmax(i, j); iをより大きいほうにする
 */
auto chmax = []<class T>(T &i, T &j) {
    if (i < j) {
        i = j;
        return true;
    }
    return false;
};