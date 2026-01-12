#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/dispersion.hpp"
void test_dispersion() {
    // ケース1: 基本的なカウント
    vector<int> v1 = {1, 2, 2, 3, 3, 3};
    vector<int> res1 = dispersion(v1);
    assert(res1[1] == 1);
    assert(res1[2] == 2);
    assert(res1[3] == 3);
    assert(res1[0] == 0); // 現れていない数は0
    assert(res1[4] == 0);
    // ケース2: 境界値付近のカウント
    // 2e6 - 1 = 1,999,999
    int limit = 1999999;
    vector<int> v2 = {limit, limit, 0};
    vector<int> res2 = dispersion(v2);
    assert(res2[limit] == 2);
    assert(res2[0] == 1);
    // ケース3: 空の配列
    vector<int> v3 = {};
    vector<int> res3 = dispersion(v3);
    // 全ての要素が0であることを確認 (一部サンプリング)
    assert(res3[0] == 0);
    assert(res3[100] == 0);
    // ケース4: 同じ値がたくさんある場合
    vector<int> v4(100, 500); // 500が100個
    vector<int> res4 = dispersion(v4);
    assert(res4[500] == 100);
}
/**
 * @brief 数直線上での個数分布のテスト
 */
void solve() {
    print("Hello World");
    test_dispersion();
}
