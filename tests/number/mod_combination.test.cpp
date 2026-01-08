#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "template/template.hpp"
#include "library/number/mod_combination.hpp"
/**
 * @brief MOD 組み合わせ nCkのテスト
 */
void solve() {
    int T, m;
    cin >> T >> m;
    while (T--) {
        int n, k;
        cin >> n >> k;
        long long comb = mod_combination(n, k, m);
        print(comb);
    }
}
