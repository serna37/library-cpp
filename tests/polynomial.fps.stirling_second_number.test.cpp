#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "template/template.hpp"
#include "library/polynomial/fps/stirling_second_number.hpp"
/**
 * @brief 第二種スターリング数のテスト
 */
void solve() {
    int N;
    cin >> N;
    print(stirling_second_number<FPS, modint998244353>(N));
}
