#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/difference_sequence.hpp"
void run_difference_sequence_tests() {
    // ケース1: 基本的な数列
    {
        vector<int> A = {1, 3, 6, 10};
        // 期待される結果:
        // D[0] = A[1] - A[0] = 2
        // D[1] = A[2] - A[1] = 3
        // D[2] = A[3] - A[2] = 4
        vector<long long> expected = {2, 3, 4};
        auto D = difference_sequence(A);
        assert(D.size() == 3);
        for (int i = 0; i < (int)D.size(); i++) {
            assert(D[i] == expected[i]);
        }
    }
    // ケース2: 値が減少する場合
    {
        vector<int> A = {10, 7, 5, 5};
        vector<long long> expected = {-3, -2, 0};
        auto D = difference_sequence(A);
        for (int i = 0; i < 3; i++) {
            assert(D[i] == expected[i]);
        }
    }
    // ケース3: 要素が2つの場合 (最小サイズ)
    {
        vector<int> A = {1, 100};
        auto D = difference_sequence(A);
        assert(D.size() == 1);
        assert(D[0] == 99);
    }
}
/**
 * @brief 階差数列のテスト
 */
void solve() {
    print("Hello World");
    run_difference_sequence_tests();
}
