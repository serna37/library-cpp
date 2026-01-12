#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/number/combination.hpp"
void test_combination() {
    // ケース1: 基本的な組み合わせ
    // 5C2 = (5 * 4) / (2 * 1) = 10
    assert(combination(5, 2) == 10ll);
    // ケース2: nC0 と nCn は常に 1
    assert(combination(5, 0) == 1ll);
    assert(combination(5, 5) == 1ll);
    // ケース3: k > n の場合は 0 (定義に基づく)
    assert(combination(3, 5) == 0ll);
    // ケース4: k < 0 の場合は 0
    assert(combination(5, -1) == 0ll);
    // ケース5: nC1 は n
    assert(combination(10, 1) == 10ll);
    // ケース6: 少し大きめの値
    // 15C7 = 6435
    assert(combination(15, 7) == 6435ll);
    // ケース7: パスカルの三角形の対称性 (nCk == nC(n-k))
    // 10C3 == 10C7 == 120
    assert(combination(10, 3) == 120ll);
    assert(combination(10, 7) == 120ll);
}
/**
 * @brief 組み合わせ nCkのテスト
 */
void solve() {
    print("Hello World");
    test_combination();
}
