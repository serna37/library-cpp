#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/grid/transpose.hpp"
void test_transpose() {
    // ケース1: 正方形の行列 (2x2)
    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    vector<vector<int>> expected1 = {{1, 3}, {2, 4}};
    assert(transpose(mat1) == expected1);
    // ケース2: 長方形の行列 (2x3)
    vector<vector<int>> mat2 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> expected2 = {{1, 4}, {2, 5}, {3, 6}};
    assert(transpose(mat2) == expected2);
    // ケース3: 1行の行列 (1x3)
    vector<vector<int>> mat3 = {{1, 2, 3}};
    vector<vector<int>> expected3 = {{1}, {2}, {3}};
    assert(transpose(mat3) == expected3);
    // ケース4: 文字列型の行列
    vector<vector<string>> mat4 = {{"a", "b"}, {"c", "d"}};
    vector<vector<string>> expected4 = {{"a", "c"}, {"b", "d"}};
    assert(transpose(mat4) == expected4);
}
/**
 * @brief 転置のテスト
 */
void solve() {
    print("Hello World");
    test_transpose();
}
