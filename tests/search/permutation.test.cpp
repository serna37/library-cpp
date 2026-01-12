#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/permutation.hpp"
void test_permutation() {
    // ケース1: 特定の並び順が存在するかチェック
    // {1, 2, 3} の並び替えで {3, 2, 1} になる瞬間があるか
    vector<int> v1 = {1, 2, 3};
    auto f1 = [&]() { return v1[0] == 3 && v1[1] == 2 && v1[2] == 1; };
    assert(permutation(v1, f1) == true);
    // ケース2: 条件を満たす並びが存在しない場合
    // {1, 2, 3} の並び替えで 合計が 10 になることはない
    vector<int> v2 = {1, 2, 3};
    auto f2 = [&]() {
        int sum = 0;
        for (int x : v2) sum += x;
        return sum == 10;
    };
    assert(permutation(v2, f2) == false);
    // ケース3: 重複のある要素
    // {1, 1, 2} の全順列は {1,1,2}, {1,2,1}, {2,1,1} の3通り
    vector<int> v3 = {2, 1, 1};
    int count = 0;
    auto f3 = [&]() {
        count++;
        return false; // 最後まで回させる
    };
    permutation(v3, f3);
    assert(count == 3);
    // ケース4: 文字列の並び替え
    // "abc" を並び替えて "cba" にできるか
    vector<char> v4 = {'a', 'b', 'c'};
    auto f4 = [&]() { return v4[0] == 'c' && v4[1] == 'b' && v4[2] == 'a'; };
    assert(permutation(v4, f4) == true);
    // ケース5: 要素が1つの場合
    vector<int> v5 = {1};
    int count5 = 0;
    permutation(v5, [&]() {
        count5++;
        return false;
    });
    assert(count5 == 1);
}
/**
 * @brief 順列全探索のテスト
 */
void solve() {
    print("Hello World");
    test_permutation();
}
