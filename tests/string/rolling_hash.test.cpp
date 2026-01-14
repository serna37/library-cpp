#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include "template/template.hpp"
#include "library/string/rolling_hash.hpp"
/**
 * @brief ロリハのテスト
 */
void solve() {
    string T, P;
    cin >> T >> P;
    int t = T.size();
    int p = P.size();
    RollingHash rht(T);
    RollingHash rhp(P);
    if (t < p) return;
    long long hash_p = rhp.get(0, p);
    for (int i = 0; i < t - p + 1; ++i) {
        if (rht.get(i, i + p) == hash_p) {
            print(i);
        }
    }
}
