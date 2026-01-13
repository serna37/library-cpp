#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum_2D.hpp"
void run_cumulative_sum_tests() {
    // ケース1: 基本的な 2x3 行列
    {
        vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}};
        // 期待される累積和 S (H+1 x W+1)
        // 0 0 0 0
        // 0 1 3 6
        // 0 5 12 21
        vector<vector<long long>> expected = {
            {0, 0, 0, 0}, {0, 1, 3, 6}, {0, 5, 12, 21}};
        auto res = cumulative_sum_2D(G);
        assert(res.size() == 3);
        assert(res[0].size() == 4);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                assert(res[i][j] == expected[i][j]);
            }
        }
    }
    // ケース2: 最小サイズ (1x1)
    {
        vector<vector<int>> G = {{10}};
        vector<vector<long long>> expected = {{0, 0}, {0, 10}};
        auto res = cumulative_sum_2D(G);
        assert(res[1][1] == 10);
        assert(res[0][0] == 0);
    }
    // ケース3: 全ての要素が 0
    {
        vector<vector<int>> G(3, vector<int>(3, 0));
        auto res = cumulative_sum_2D(G);
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 3; j++) {
                assert(res[i][j] == 0);
            }
        }
    }
    // ケース4: 縦に長い行列 (3x1)
    {
        vector<vector<int>> G = {{1}, {2}, {3}};
        auto res = cumulative_sum_2D(G);
        assert(res.size() == 4);
        assert(res[3][1] == 6); // 1 + 2 + 3
    }
}
/**
 * @brief 2次元累積和のテスト
 */
void solve() {
    print("Hello World");
    run_cumulative_sum_tests();
}
