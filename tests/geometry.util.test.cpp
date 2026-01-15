#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/geometry/util.hpp"
void test_util() {
    // degree / radian
    assert(abs(deg_to_rad(180.0) - PI) < 1e-9);
    assert(abs(rad_to_deg(PI / 2.0) - 90.0) < 1e-9);
    // arc_tan (y, x) の順
    assert(abs(arc_tan(1.0, 1.0) - (PI / 4.0)) < 1e-9);
}
/**
 * @brief 幾何Utilのテスト
 */
void solve() {
    print("Hello World");
    test_util();
}
