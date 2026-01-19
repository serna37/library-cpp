#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"
#include "template/template.hpp"
#include "library/polynomial/fps/stirling_first_number.hpp"
/**
 * @brief 第一種スターリング数のテスト
 */
void solve() {
    int N;
    cin >> N;
    print(stirling_first_number<FPS, modint998244353>(N));
}
