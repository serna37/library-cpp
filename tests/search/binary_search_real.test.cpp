#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/binary_search_real.hpp"
// 判定用のヘルパー：期待値との誤差が十分小さいか確認
bool is_near(double val, double expected) {
    return abs(val - expected) < 1e-10;
}
void test_binary_search_real() {
    // ケース1: 平方根の計算 (x^2 >= 2)
    // √2 ≒ 1.41421356... を探す
    auto f1 = [](double x) { return x * x >= 2.0; };
    auto [L1, R1] = binary_search_real(f1);
    assert(is_near(R1, sqrt(2.0)));
    // ケース2: 境界が非常に大きい場合
    // x >= 1e10
    double target2 = 1e10;
    auto f2 = [target2](double x) { return x >= target2; };
    auto [L2, R2] = binary_search_real(f2);
    assert(is_near(R1, sqrt(2.0)));
    // 相対誤差(REL)のおかげで、大きな値でも精度良く止まる
    double rel_error = abs(R2 - target2) / target2;
    assert(rel_error < 1e-13);
    // ケース3: 方程式の解 (x + exp(x) >= 2.0)
    auto f3 = [](double x) { return x + exp(x) >= 2.0; };
    auto [L3, R3] = binary_search_real(f3);
    // x ≒ 0.4428544...
    assert(f3(R3) == true);
    assert(f3(L3) == false);
    // ケース4: 境界が1より小さい場合
    // x >= 0.001
    auto f4 = [](double x) { return x >= 0.001; };
    auto [L4, R4] = binary_search_real(f4);
    assert(is_near(R4, 0.001));
}
/**
 * @brief 実数上の二分探索のテスト
 */
void solve() {
    print("Hello World");
    test_binary_search_real();
}
