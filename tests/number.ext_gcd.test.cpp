#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include "template/template.hpp"
#include "library/number/ext_gcd.hpp"
/**
 * @brief 拡張Euclidの互除法のテスト
 */
void solve() {
    int a, b, x, y;
    cin >> a >> b;
    ext_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}
