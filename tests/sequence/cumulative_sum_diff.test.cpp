#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum_diff.hpp"
void run_cumulative_sum_diff_tests() {
    // ケース1: 基本的な動作（要素数が偶数）
    {
        vector<int> A = {1, 5, 2, 10};
        // インデックスと計算の推移:
        // i=0: S[1] = S[0] = 0 (iが偶数なので足さない)
        // i=1: S[2] = S[1] + abs(5-1) = 4
        // i=2: S[3] = S[2] = 4 (iが偶数なので足さない)
        // i=3: S[4] = S[3] + abs(10-2) = 4 + 8 = 12
        vector<long long> expected = {0, 0, 4, 4, 12};
        auto S = cumulative_sum_diff(A);
        assert(S.size() == 5);
        for (int i = 0; i < 5; i++) {
            assert(S[i] == expected[i]);
        }
    }
    // ケース2: 要素数が奇数
    {
        vector<int> A = {3, 8, 5};
        // i=0: S[1]=0
        // i=1: S[2]=0 + abs(8-3)=5
        // i=2: S[3]=S[2]=5
        vector<long long> expected = {0, 0, 5, 5};
        auto S = cumulative_sum_diff(A);
        assert(S.size() == 4);
        assert(S[3] == 5);
    }
    // ケース3: 負の数を含む場合
    {
        vector<int> A = {-1, -5, 2};
        // i=1: abs(-5 - (-1)) = abs(-4) = 4
        auto S = cumulative_sum_diff(A);
        assert(S[2] == 4);
    }
    // ケース4: 要素が1つだけ
    {
        vector<int> A = {100};
        auto S = cumulative_sum_diff(A);
        assert(S.size() == 2);
        assert(S[0] == 0);
        assert(S[1] == 0);
    }
    // ケース5: 空の配列
    {
        vector<int> A = {};
        auto S = cumulative_sum_diff(A);
        assert(S.size() == 1);
        assert(S[0] == 0);
    }
}
/**
 * @brief 二項差での累積和のテスト
 */
void solve() {
    print("Hello World");
    run_cumulative_sum_diff_tests();
}
