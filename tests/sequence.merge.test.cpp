#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/merge.hpp"
void run_merge_tests() {
    // ケース1: vector のマージ
    {
        vector<int> A = {1, 2};
        vector<int> B = {3, 4, 5};
        // Aの方が小さいので B に追加されるはず
        merge(A, B);
        assert(A.empty());
        assert(B.size() == 5);
        // 内容の確認（順序は 3, 4, 5, 1, 2 になる）
        vector<int> expected = {3, 4, 5, 1, 2};
        for (int i = 0; i < 5; i++) assert(B[i] == expected[i]);
    }
    // ケース2: vector のマージ (swapが発生する場合)
    {
        vector<int> A = {1, 2, 3};
        vector<int> B = {4, 5};
        // Aの方が大きいので swap してから A(元B) を B(元A) にマージする
        merge(A, B);
        assert(A.empty());
        assert(B.size() == 5);
        // swapにより元Aがベースになるため、結果は 1, 2, 3, 4, 5 となる
        vector<int> expected = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) assert(B[i] == expected[i]);
    }
    // ケース3: set のマージ (重複あり)
    {
        set<int> A = {10, 20};
        set<int> B = {20, 30, 40};
        merge(A, B);
        assert(A.empty());
        assert(B.size() == 4); // 20が重複しているので {10, 20, 30, 40}
        assert(B.count(10) && B.count(20) && B.count(30) && B.count(40));
    }
    // ケース4: 汎用マージ (map へのマージをカスタム関数で行う)
    {
        map<string, int> A = {{"apple", 1}};
        map<string, int> B = {{"banana", 2}, {"cherry", 3}};
        // ラムダ式で map への挿入ルールを定義
        auto f = [](map<string, int> &target, pair<const string, int> &entry) {
            target[entry.first] += entry.second;
        };
        merge(A, B, f);
        assert(A.empty());
        assert(B.size() == 3);
        assert(B["apple"] == 1);
        assert(B["banana"] == 2);
    }
}
/**
 * @brief マージテクのテスト
 */
void solve() {
    print("Hello World");
    run_merge_tests();
}
