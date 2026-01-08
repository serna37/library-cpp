#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "template/template.hpp"
#include "library/number/prime_test.hpp"
/**
 * @brief 素数判定のテスト
 */
void solve() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        bool is_prime = prime_test(n);
        if (is_prime) ++ans;
    }
    print(ans);
}
