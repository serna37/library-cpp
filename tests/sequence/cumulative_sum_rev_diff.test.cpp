#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum_rev_diff.hpp"
void run_cumulative_sum_rev_diff_tests() {
    // ケース1: 基本的な動作（要素数4: 偶数）
    {
        vector<int> A = {1, 5, 2, 10};
        // インデックスと計算の推移 (後ろから):
        // i=3 (奇数): R[3] = R[4] + abs(0 - A[3]) = 0 + abs(0-10) = 10
        // i=2 (偶数): R[2] = R[3] = 10
        // i=1 (奇数): R[1] = R[2] + abs(A[2] - A[1]) = 10 + abs(2-5) = 10 + 3 = 13
        // i=0 (偶数): R[0] = R[1] = 13
        // 期待値 R: {13, 13, 10, 10, 0}
        vector<long long> expected = {13, 13, 10, 10, 0};
        
        auto R = cumulative_sum_rev_diff(A);
        
        assert(R.size() == 5);
        for (int i = 0; i < 5; i++) {
            assert(R[i] == expected[i]);
        }
    }

    // ケース2: 要素数3（奇数）
    {
        vector<int> A = {3, 8, 5};
        // i=2 (偶数): R[2] = R[3] = 0
        // i=1 (奇数): R[1] = R[2] + abs(A[2] - A[1]) = 0 + abs(5-8) = 3
        // i=0 (偶数): R[0] = R[1] = 3
        // 期待値 R: {3, 3, 0, 0}
        vector<long long> expected = {3, 3, 0, 0};
        auto R = cumulative_sum_rev_diff(A);
        
        assert(R.size() == 4);
        for (int i = 0; i < 4; i++) {
            assert(R[i] == expected[i]);
        }
    }

    // ケース3: 負の数を含む場合
    {
        vector<int> A = {1, -5}; 
        // i=1 (奇数): R[1] = abs(0 - (-5)) = 5
        // i=0 (偶数): R[0] = 5
        auto R = cumulative_sum_rev_diff(A);
        assert(R[0] == 5);
        assert(R[1] == 5);
    }

    // ケース4: 空の配列
    {
        vector<int> A = {};
        auto R = cumulative_sum_rev_diff(A);
        assert(R.size() == 1);
        assert(R[0] == 0);
    }
}
/**
 * @brief 二項差での累積和 反転のテスト
 */
void solve() {
    print("Hello World");
    run_cumulative_sum_rev_diff_tests();
}
