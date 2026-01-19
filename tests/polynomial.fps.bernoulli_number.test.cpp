#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"
#include "template/template.hpp"
#include "library/polynomial/fps/bernoulli_number.hpp"
/**
 * @brief ベルヌーイ数のテスト
 */
void solve() {
    int N;
    cin >> N;
    print(bernoulli_number<FPS, modint998244353>(N));
}
