#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
/**
 * @brief templateのテスト
 */
void solve() {
    print("Hello World");
    int A = 5, B = 7;
    chmin(A, B);
    assert(A == 5ll);
    A = 7, B = 5;
    chmin(A, B);
    assert(A == 5ll);
    A = 7, B = 5;
    chmax(A, B);
    assert(A == 7ll);
    A = 5, B = 7;
    chmax(A, B);
    assert(A == 7ll);
}
