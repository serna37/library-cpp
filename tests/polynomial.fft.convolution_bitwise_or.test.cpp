#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "template/template.hpp"
#include "library/number/mod/montgomery_mod_int.hpp"
#include "library/polynomial/fft/convolution_bitwise_or.hpp"
#include "library/sequence/collection_util.hpp"
/**
 * @brief Bitwise畳み込みORのテスト
 */
void solve() {
    int N;
    cin >> N;
    using mint = modint998244353;
    vector<mint> a(1 << N), b(1 << N);
    cin >> a;
    cin >> b;
    collection.reverse(a);
    collection.reverse(b);
    auto c = convolution_bitwise_or(a, b);
    collection.reverse(c);
    print(c);
}
