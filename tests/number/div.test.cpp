#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/number/div.hpp"
void test_math_functions() {
    // div_ceil (a/b で切り上げ)
    assert(div_ceil(10, 3) == 4);
    assert(div_ceil(10, 5) == 2);
    assert(div_ceil(-10, 3) == -3); // 0方向ではなく負の無限大方向への切り上げ
    // div_floor (a/b で切り捨て)
    assert(div_floor(10, 3) == 3);
    assert(div_floor(-10, 3) == -4);
}
/**
 * @brief 割り算のテスト
 */
void solve() {
    print("Hello World");
    test_math_functions();
}
