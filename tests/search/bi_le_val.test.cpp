#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/bi_le_val.hpp"
void test_bi_le_val() {
    // --- Vector版のテスト ---
    vector<int> v = {10, 20, 30, 40, 50};
    // x=25 のとき、25以下の最大値は 20
    assert(bi_le_val(v, 25ll) == 20);
    // x=20 のとき、20以下の最大値は 20 (ちょうどを含む)
    assert(bi_le_val(v, 20ll) == 20);
    // 最大要素より大きい場合、最大要素が返る
    assert(bi_le_val(v, 100ll) == 50);
    // 最小要素より小さい場合、-INF が返る
    assert(bi_le_val(v, 5ll) == -INF);
    // --- Set版のテスト ---
    set<int> st = {10, 20, 30, 40, 50};
    assert(bi_le_val(st, 30ll) == 30);
    assert(bi_le_val(st, 39ll) == 30);
    assert(bi_le_val(st, 9ll) == -INF);
    // --- 重複要素がある場合の挙動確認 ---
    vector<int> v_dup = {10, 20, 20, 20, 30};
    // upper_boundは20を超える最初の位置(30の位置)を指し、その一つ前は20
    assert(bi_le_val(v_dup, 20ll) == 20);
}
/**
 * @brief 二分探索 配列中 以下の最大値のテスト
 */
void solve() {
    print("Hello World");
    test_bi_le_val();
}
