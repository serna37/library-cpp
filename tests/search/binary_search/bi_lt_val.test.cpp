#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/binary_search/bi_lt_val.hpp"
void test_bi_lt_val() {
    // --- Vector版のテスト ---
    vector<int> v = {10, 20, 30, 40, 50};
    // x=25 のとき、25より小さい最大値は 20
    assert(bi_lt_val(v, 25ll) == 20);
    // x=20 のとき、20より小さい最大値は 10 (ちょうどを含まない)
    assert(bi_lt_val(v, 20ll) == 10);
    // 最小要素と同じ、またはそれより小さい場合は -INF
    assert(bi_lt_val(v, 10ll) == -INF);
    assert(bi_lt_val(v, 5ll) == -INF);
    // 最大要素より大きい場合、最大要素が返る
    assert(bi_lt_val(v, 100ll) == 50);
    // --- Set版のテスト ---
    set<int> st = {10, 20, 30, 40, 50};
    assert(bi_lt_val(st, 30ll) == 20);
    assert(bi_lt_val(st, 31ll) == 30);
    assert(bi_lt_val(st, 10ll) == -INF);
    // --- 重複要素がある場合の挙動確認 ---
    vector<int> v_dup = {10, 20, 20, 20, 30};
    // lower_boundは最初の20を指し、その一つ前は10
    assert(bi_lt_val(v_dup, 20ll) == 10);
}
/**
 * @brief 二分探索 配列中 未満の最大値のテスト
 */
void solve() {
    print("Hello World");
    test_bi_lt_val();
}
