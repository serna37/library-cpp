/**
 * @brief ฅ^>ω<^ฅ
 * @note https://serna37.github.io/library-cpp/
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct IoSetup {
    IoSetup() {
        cin.tie(0)->sync_with_stdio(0);
        cout << fixed << setprecision(20);
    }
} iosetup;
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
void solve();
signed main() { solve(); }
