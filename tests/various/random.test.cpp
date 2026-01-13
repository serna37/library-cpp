#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/various/random.hpp"
void test_random() {
    int a = random(0ll, 10ll);
    assert(0 <= a and a < 10);
}
/**
 * @brief 乱数生成のテスト
 */
void solve() {
    print("Hello World");
    test_random();
}
