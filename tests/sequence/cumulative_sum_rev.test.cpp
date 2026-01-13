#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum_rev.hpp"
void run_cumulative_sum_rev_tests() {
    // ケース1: 基本的な数列
    {
        vector<int> A = {1, 2, 3, 4};
        // 期待される結果:
        // R[4] = 0
        // R[3] = A[3] = 4
        // R[2] = A[3]+A[2] = 7
        // R[1] = A[3]+A[2]+A[1] = 9
        // R[0] = A[3]+A[2]+A[1]+A[0] = 10
        vector<long long> expected = {10, 9, 7, 4, 0};
        auto R = cumulative_sum_rev(A);
        assert(R.size() == 5);
        for (int i = 0; i < 5; i++) {
            assert(R[i] == expected[i]);
        }
    }
    // ケース2: 空の配列
    {
        vector<int> A = {};
        auto R = cumulative_sum_rev(A);
        assert(R.size() == 1);
        assert(R[0] == 0);
    }
    // ケース3: 負の数を含む配列
    {
        vector<int> A = {10, -3, 5};
        // R[3]=0, R[2]=5, R[1]=2, R[0]=12
        auto R = cumulative_sum_rev(A);
        assert(R[0] == 12);
        assert(R[1] == 2);
        assert(R[2] == 5);
        assert(R[3] == 0);
    }
    // ケース4: 1要素のみ
    {
        vector<int> A = {7};
        auto R = cumulative_sum_rev(A);
        assert(R[0] == 7);
        assert(R[1] == 0);
    }
}
/**
 * @brief 累積和 反転のテスト
 */
void solve() {
    print("Hello World");
    run_cumulative_sum_rev_tests();
}
