#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/segtree/starry_sky_tree.hpp"
void test_starry_sky_tree() {
    // データ準備
    vector<int> initial_data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // ---------------------------------------------------------
    // Case 1: 区間最大値 (Max Mode)
    // ---------------------------------------------------------
    {
        StarrySkyTree<false> sst_max(initial_data);
        // 初期状態のチェック
        assert(sst_max.prod(0, 10) == 9); // 全体最大値
        assert(sst_max.prod(0, 4) == 4);  // {3, 1, 4, 1} の最大値
        assert(sst_max[5] == 9);          // インデックス5の値
        // 区間加算: [0, 5) に +10 -> {13, 11, 14, 11, 15, 9, 2, 6, 5, 3}
        sst_max.apply(0, 5, 10);
        assert(sst_max.prod(0, 5) == 15);
        assert(sst_max.prod(4, 6) == 15); // 15 と 9 の比較
        assert(sst_max.prod(5, 10) == 9); // 加算範囲外
        // 単点更新（set）: index 5 を 0 に変更
        sst_max.set(5, 0);
        assert(sst_max[5] == 0);
        assert(sst_max.prod(0, 10) == 15);
    }
    // ---------------------------------------------------------
    // Case 2: 区間最小値 (Min Mode)
    // ---------------------------------------------------------
    {
        StarrySkyTree<true> sst_min(initial_data);
        // 初期状態のチェック
        assert(sst_min.prod(0, 10) == 1); // 全体最小値
        assert(sst_min.prod(4, 6) == 5);  // {5, 9} の最小値
        // 区間加算: [2, 8) に -20 -> {3, 1, -16, -19, -15, -11, -18, -14, 5, 3}
        sst_min.apply(2, 8, -20);
        assert(sst_min.prod(0, 10) == -19); // 全体最小値
        assert(sst_min.prod(0, 2) == 1);    // 加算範囲外
        assert(sst_min[3] == -19);
        // 区間加算: [0, 10) 全体に +100
        sst_min.apply(0, 10, 100);
        assert(sst_min.prod(0, 10) == 81); // -19 + 100
        assert(sst_min[3] == 81);
    }
    // ---------------------------------------------------------
    // Case 3: 負の値を含む複雑なケース
    // ---------------------------------------------------------
    {
        vector<int> negative_data = {-10, -20, -30, -40};
        StarrySkyTree<true> sst_neg(negative_data);
        assert(sst_neg.prod(0, 4) == -40);
        sst_neg.apply(0, 2, 50); // {40, 30, -30, -40}
        assert(sst_neg.prod(0, 4) == -40);
        assert(sst_neg.prod(0, 2) == 30);
    }
}
/**
 * @brief 星空木のテスト
 */
void solve() {
    print("Hello World");
    test_starry_sky_tree();
}
