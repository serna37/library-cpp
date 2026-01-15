#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "template/template.hpp"
#include "library/number/divisors.hpp"
/**
 * @brief 約数列挙のテスト
 */
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    vector<int> divs = divisors(c);
    for (auto &&v : divs) {
        if (a <= v and v <= b) {
            ++ans;
        }
    }
    print(ans);
}
