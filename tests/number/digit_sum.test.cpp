#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/number/digit_sum.hpp"
void test_digit_sum() {
    // ケース1: 10進数での基本的な計算
    // 123 -> 1 + 2 + 3 = 6
    assert(digit_sum(123) == 6);
    // ケース2: 10進数で0が含まれる場合
    // 1005 -> 1 + 0 + 0 + 5 = 6
    assert(digit_sum(1005) == 6);
    // ケース3: 1桁の数字
    assert(digit_sum(9) == 9);
    assert(digit_sum(0) == 0);
    // ケース4: 2進数での計算 (base_number = 2)
    // 7 は 2進数で "111" -> 1 + 1 + 1 = 3
    assert(digit_sum(7, 2) == 3);
    // 8 は 2進数で "1000" -> 1 + 0 + 0 + 0 = 1
    assert(digit_sum(8, 2) == 1);
    // ケース5: 16進数での計算 (base_number = 16)
    // 255 (0xFF) -> 15 + 15 = 30
    assert(digit_sum(255, 16) == 30);
    // ケース6: 負の数に対する挙動
    // 現在の実装では N % base_number が負になる可能性があるため確認
    // -123 -> (-3) + (-2) + (-1) = -6 (C++の仕様に依存)
    assert(digit_sum(-123) == -6);
}
/**
 * @brief 桁和のテスト
 */
void solve() {
    print("Hello World");
    test_digit_sum();
}
