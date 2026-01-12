#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/number/factorial.hpp"
void test_factorial() {
    // ケース1: 基本的な階乗
    // 3! = 3 * 2 * 1 = 6
    assert(factorial(3) == 6ll);
    // 5! = 5 * 4 * 3 * 2 * 1 = 120
    assert(factorial(5) == 120ll);
    // ケース2: 0の階乗 (数学的定義により 0! = 1)
    assert(factorial(0) == 1ll);
    // ケース3: 1の階乗
    assert(factorial(1) == 1ll);
    // ケース4: 少し大きめの値
    // 10! = 3,628,800
    assert(factorial(10) == 3628800ll);
    // ケース5: long long の限界に近い値
    // 20! = 2,432,902,008,176,640,000
    // (これ以上（21!）は 64bit整数の範囲を超えてオーバーフローします)
    assert(factorial(20) == 2432902008176640000ll);
    // ケース6: 負の入力に対する挙動
    // 現在の実装では while (N > 0) なので、負の数を入れると res = 1 が返る
    assert(factorial(-5) == 1ll);
}
/**
 * @brief 階乗のテスト
 */
void solve() {
    print("Hello World");
    test_factorial();
}
