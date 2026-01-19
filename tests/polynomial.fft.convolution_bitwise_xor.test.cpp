#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "template/template.hpp"
#include "library/number/mod/montgomery_mod_int.hpp"
#include "library/polynomial/fft/convolution_bitwise_xor.hpp"
/**
 * @brief Bitwise畳み込みXORのテスト
 */
void solve() {
    int N;
    cin >> N;
    using mint = modint998244353;
    vector<mint> a(1 << N), b(1 << N);
    cin >> a;
    cin >> b;
    auto c = convolution_bitwise_xor(a, b);
    print(c);
}
