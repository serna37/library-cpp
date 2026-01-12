#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/bi_gt_val.hpp"
void test_bi_gt_val() {
    // --- Vector版のテスト ---
    vector<int> v = {10, 20, 30, 40, 50};
    // x=20 のとき、20より大きい最小の要素は 30
    assert(bi_gt_val(v, 20ll) == 30);
    // x=25 のときは、25より大きい最小の要素は 30
    assert(bi_gt_val(v, 25ll) == 30);
    // 最小要素より小さい場合
    assert(bi_gt_val(v, 5ll) == 10);
    // 最大要素と同じ、またはそれより大きい場合は INF
    assert(bi_gt_val(v, 50ll) == INF);
    assert(bi_gt_val(v, 100ll) == INF);
    // --- Set版のテスト ---
    set<int> st = {10, 20, 30, 40, 50};
    assert(bi_gt_val(st, 20ll) == 30);
    assert(bi_gt_val(st, 45ll) == 50);
    assert(bi_gt_val(st, 50ll) == INF);
    // --- 重複要素がある場合の挙動確認 ---
    vector<int> v_dup = {10, 20, 20, 20, 30};
    // upper_bound は重複する 20 をすべて飛び越えて 30 を指す
    assert(bi_gt_val(v_dup, 20ll) == 30);
}
/**
 * @brief 二分探索 配列中 より上の最小値のテスト
 */
void solve() {
    print("Hello World");
    test_bi_gt_val();
}
