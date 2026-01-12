#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/bi_ge_val.hpp"
void test_bi_ge_val() {
    // --- Vector版のテスト ---
    // lower_boundを使うため、事前にソートされている必要がある
    vector<int> v = {10, 20, 30, 40, 50};
    assert(bi_ge_val(v, 25ll) == 30);  // 25以上の最小値
    assert(bi_ge_val(v, 20ll) == 20);  // 20ちょうど
    assert(bi_ge_val(v, 5ll) == 10);   // 最小要素より小さい場合
    assert(bi_ge_val(v, 55ll) == INF); // 最大要素より大きい場合
    // --- Set版のテスト ---
    // setは内部で常にソートされている
    set<int> st = {10, 20, 30, 40, 50};
    assert(bi_ge_val(st, 25ll) == 30);
    assert(bi_ge_val(st, 20ll) == 20);
    assert(bi_ge_val(st, 60ll) == INF);
    // --- 型の柔軟性テスト (double) ---
    vector<double> vd = {1.1, 2.2, 3.3};
    // 2.0 以上の最小値は 2.2
    assert(abs(bi_ge_val(vd, 2.0) - 2.2) < 1e-9);
}
/**
 * @brief 二分探索 配列中 以上の最小値のテスト
 */
void solve() {
    print("Hello World");
    test_bi_ge_val();
}
