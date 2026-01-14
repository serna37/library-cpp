#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/various/random.hpp"
void test_random() {
    long long a = random(0ll, 10ll);
    assert(0ll <= a and a < 10ll);
}
/**
 * @brief 乱数生成のテスト
 */
void solve() {
    print("Hello World");
    test_random();
}
