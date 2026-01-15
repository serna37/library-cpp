#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/geometry/area_triangle.hpp"
// 浮動小数点の比較用ヘルパー
bool is_near(double a, double b, double epsilon = 1e-9) {
    return abs(a - b) < epsilon;
}
void test_area_triangle() {
    // ケース1: 底辺2、高さ1の直角三角形
    // (0,0), (2,0), (0,1) -> 面積: 2 * 1 / 2 = 1.0
    assert(is_near(area_triangle(0, 0, 2, 0, 0, 1), 1.0));
    // ケース2: 単位正方形の半分 (45度の直角二等辺三角形)
    // (0,0), (1,0), (0,1) -> 面積: 0.5
    assert(is_near(area_triangle(0.0, 0.0, 1.0, 0.0, 0.0, 1.0), 0.5));
    // ケース3: 座標が負のケース
    // (-1,-1), (1,-1), (0,1) -> 底辺2, 高さ2 -> 面積: 2 * 2 / 2 = 2.0
    assert(is_near(area_triangle(-1, -1, 1, -1, 0, 1), 2.0));
    // ケース4: 3点が一直線上にある場合（面積0）
    // (0,0), (1,1), (2,2)
    assert(is_near(area_triangle(0, 0, 1, 1, 2, 2), 0.0));
    // ケース5: 大きな値の計算
    // (0,0), (100,0), (0,100) -> 面積: 100 * 100 / 2 = 5000.0
    assert(is_near(area_triangle(0, 0, 100, 0, 0, 100), 5000.0));
}
/**
 * @brief 三角形の面積のテスト
 */
void solve() {
    print("Hello World");
    test_area_triangle();
}
