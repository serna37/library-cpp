#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/number/prime/eratosthenes.hpp"
#include "library/number/prime/prime_test.hpp"
#include "library/number/prime/prime_fact.hpp"
#include "library/number/prime/euler_phi.hpp"
#include "library/number/divisors.hpp"
/**
 * @brief エラトステネスの篩のテスト
 */
void test() {
    int N = 1000000;
    Eratosthenes er(N);
    int x = 999982;
    // 素数判定
    bool is_p = er.is_prime(x);
    assert(is_p == prime_test(x));
    // 素因数分解 <素因数: 個数>
    vector<pair<int, int>> factors = er.factorize(x);
    map<int, int> mp = prime_fact(x);
    for (auto &&[p, cnt] : factors) {
        assert(mp[p] == cnt);
    }
    // 約数列挙 (ソートされてないよ)
    vector<int> divs = er.calc_divisors(x);
    vector<int> exp = divisors(x);
    sort(all(divs));
    sort(all(exp));
    assert(divs == exp);
    // 最小素因数
    int lpf = er.lpf(x);
    assert(lpf == 2ll);
    // φ(x)
    int phi = er.euler_phi(x);
    assert(phi == euler_phi(x));
}
void solve() {
    print("Hello World");
    test();
}
