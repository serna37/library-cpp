#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "template/template.hpp"
#include "library/number/mod/montgomery_mod_int.hpp"
#include "library/polynomial/fft/convolution_bitwise_and.hpp"
/**
 * @brief Bitwise畳み込みANDのテスト
 */
void solve() {
    int N;
    cin >> N;
    using mint = modint998244353;
    vector<mint> a(1 << N), b(1 << N);
    cin >> a;
    cin >> b;
    auto c = convolution_bitwise_and(a, b);
    print(c);
}
