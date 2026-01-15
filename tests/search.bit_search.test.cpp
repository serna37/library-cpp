#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/bit_search.hpp"
void test_bit_search() {
    // ケース1: 3つの要素 {1, 2, 3} の部分集合
    // 2^3 = 8通りの部分集合が生成されるはず
    vector<int> v1 = {1, 2, 3};
    vector<vector<int>> res1 = bit_search(v1);
    assert(res1.size() == 8);
    // 空集合が含まれているか
    bool has_empty = false;
    // 特定の部分集合 {1, 3} が含まれているか
    bool has_1_3 = false;
    for (const auto &subset : res1) {
        if (subset.empty()) has_empty = true;
        if (subset == vector<int>{1, 3}) has_1_3 = true;
    }
    assert(has_empty);
    assert(has_1_3);
    // ケース2: 1つの要素 {10}
    // {空}, {10} の2通り
    vector<int> v2 = {10};
    vector<vector<int>> res2 = bit_search(v2);
    assert(res2.size() == 2);
    assert(res2[0].empty());
    assert(res2[1] == vector<int>{10});
    // ケース3: 空の配列
    // 2^0 = 1通り (空集合のみ)
    vector<int> v3 = {};
    vector<vector<int>> res3 = bit_search(v3);
    assert(res3.size() == 1);
    assert(res3[0].empty());
    // ケース4: 文字列の集合
    vector<string> v4 = {"A", "B"};
    vector<vector<string>> res4 = bit_search(v4);
    // {""}, {"A"}, {"B"}, {"A", "B"}
    assert(res4.size() == 4);
    assert(res4[3] == vector<string>({"A", "B"}));
}
/**
 * @brief bit全探索のテスト
 */
void solve() {
    print("Hello World");
    test_bit_search();
}
