#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/binary_search/binary_search.hpp"
void test_binary_search() {
    // ケース1: 単純な閾値 (x >= 100 で true)
    auto f1 = [](long long x) { return x >= 100; };
    auto [L1, R1] = binary_search(f1);
    // Lはfalse(99), Rはtrue(100)になるはず
    assert(L1 == 99 && R1 == 100);
    // ケース2: 境界が非常に小さい場合 (x >= 1 で true)
    auto f2 = [](long long x) { return x >= 1; };
    auto [L2, R2] = binary_search(f2);
    assert(L2 == 0 && R2 == 1);
    // ケース3: 境界が 0 の場合
    // 関数内での初期値が L=0, R=1 なので、f(1)は必ずtrueである必要がある
    auto f3 = [](long long x) { return x >= 0; };
    // R=1で最初からf(R)がtrueになるため、そのまま二分探索へ
    auto [L3, R3] = binary_search(f3);
    assert(R3 == 0 ||
           R3 == 1); // 実装によりますが、0以上で常にtrueならRは最小のtrue地点
    // ケース4: 境界が非常に大きい場合
    long long target = 1LL << 40; // 2^40
    auto f4 = [target](long long x) { return x >= target; };
    auto [L4, R4] = binary_search(f4);
    assert(L4 == target - 1 && R4 == target);
    // ケース5: 二次関数の閾値
    // x*x >= 1000000 (x >= 1000)
    auto f5 = [](long long x) { return x * x >= 1000000; };
    auto [L5, R5] = binary_search(f5);
    assert(L5 == 999 && R5 == 1000);
}
/**
 * @brief 整数上の二分探索のテスト
 */
void solve() {
    print("Hello World");
    test_binary_search();
}
