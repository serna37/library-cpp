#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/geometry/area_square.hpp"
// 浮動小数点の比較用ヘルパー
bool is_near(double a, double b, double epsilon = 1e-9) {
    return abs(a - b) < epsilon;
}
void test_area_square() {
    // ケース1: 単位正方形 (0,1), (1,1), (1,0), (0,0)
    // 対角線1: (0,1) to (1,0) -> 長さ √2
    // 対角線2: (1,1) to (0,0) -> 長さ √2
    // 面積: (√2 * √2) / 2 = 1.0
    assert(is_near(area_square(0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0), 1.0));
    // ケース2: ひし形 (0,2), (1,0), (0,-2), (-1,0)
    // 対角線1: (0,2) to (0,-2) -> 長さ 4
    // 対角線2: (1,0) to (-1,0) -> 長さ 2
    // 面積: (4 * 2) / 2 = 4.0
    assert(is_near(area_square(0, 2, 1, 0, 0, -2, -1, 0), 4.0));
    // ケース3: 1辺が3の正方形 (回転なし)
    // (0,3), (3,3), (3,0), (0,0)
    // 面積: 3 * 3 = 9.0
    assert(is_near(area_square(0, 3, 3, 3, 3, 0, 0, 0), 9.0));
    // ケース4: 面積0 (全ての点が原点)
    assert(is_near(area_square(0, 0, 0, 0, 0, 0, 0, 0), 0.0));
}
/**
 * @brief 四角形の面積のテスト
 */
void solve() {
    print("Hello World");
    test_area_square();
}
