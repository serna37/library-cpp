#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "template/template.hpp"
#include "library/string/z_algorithm.hpp"
/**
 * @brief Z Algorithmのテスト
 */
void solve() {
    string S;
    cin >> S;
    ZAlgorithm z(S);
    print(z.get());
}
