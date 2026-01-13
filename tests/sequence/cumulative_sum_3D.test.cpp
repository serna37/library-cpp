#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/cumulative_sum_3D.hpp"
void run_cumulative_sum_3D_tests() {
    // ケース1: 2x2x2 の立方体
    // すべての要素が 1 の場合
    {
        int X = 2, Y = 2, Z = 2;
        vector<vector<vector<int>>> A(
            X, vector<vector<int>>(Y, vector<int>(Z, 1)));
        auto S = cumulative_sum_3D(A);
        // サイズ確認 (X+1, Y+1, Z+1)
        assert(S.size() == 3);
        assert(S[0].size() == 3);
        assert(S[0][0].size() == 3);
        // 境界（0面）はすべて 0 であるべき
        assert(S[0][0][0] == 0);
        assert(S[0][2][2] == 0);
        assert(S[2][0][2] == 0);
        // 各座標の累積和を確認
        // S[1][1][1] は A[0][0][0] のみ = 1
        assert(S[1][1][1] == 1);
        // S[2][1][1] は A[0][0][0] + A[1][0][0] = 2
        assert(S[2][1][1] == 2);
        // S[2][2][2] は全要素の和 = 2*2*2 = 8
        assert(S[2][2][2] == 8);
    }
    // ケース2: 特定の1箇所だけに値がある場合
    {
        vector<vector<vector<int>>> A(
            2, vector<vector<int>>(2, vector<int>(2, 0)));
        A[1][1][1] = 5; // 右端の奥に配置
        auto S = cumulative_sum_3D(A);
        // A[1][1][1] が含まれない範囲は 0
        assert(S[1][1][1] == 0);
        assert(S[2][2][1] == 0);
        assert(S[2][1][2] == 0);
        // A[1][1][1] が含まれる唯一の点
        assert(S[2][2][2] == 5);
    }
    // ケース3: 異なる値の組み合わせ
    {
        // 1x1x2 の直方体
        // A[0][0][0]=1, A[0][0][1]=2
        vector<vector<vector<int>>> A = {{{1, 2}}};
        auto S = cumulative_sum_3D(A);
        assert(S[1][1][1] == 1);
        assert(S[1][1][2] == 3);
    }
}
/**
 * @brief 3次元累積和のテスト
 */
void solve() {
    print("Hello World");
    run_cumulative_sum_3D_tests();
}
