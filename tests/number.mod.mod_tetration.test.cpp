#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "template/template.hpp"
#include "library/number/mod/mod_tetration.hpp"
/**
 * @brief MOD テトレーションのテスト
 */
void solve() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, m;
        cin >> a >> b >> m;
        long long ans = mod_tetration(a, b, m) % m;
        print(ans);
    }
}
