#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "template/template.hpp"
#include "library/number/prime/prime_fact.hpp"
/**
 * @brief 素因数分解のテスト
 */
void solve() {
    int N;
    cin >> N;
    cout << N << ":";
    map<int, int> pf = prime_fact(N);
    for (auto &&[k, v] : pf) {
        for (int i = 0; i < v; ++i) {
            cout << " " << k;
        }
    }
    cout << endl;
}
