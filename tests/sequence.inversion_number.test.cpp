#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include "template/template.hpp"
#include "library/sequence/inversion_number.hpp"
/**
 * @brief 転倒数・座標圧縮・FenwickTreeのテスト
 */
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    long long inv = inversion_number(A);
    print(inv);
}
