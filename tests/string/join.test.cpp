#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/finds.hpp"
void test_finds() {
    // ケース1: 複数回出現する場合
    // "banana" の中に "ana" は 0文字目(ana)na と 2文字目 ban(ana) にある
    string T1 = "banana";
    string S1 = "ana";
    vector<int> expected1 = {1, 3}; // b(ana)na, ban(ana)
    assert(finds(T1, S1) == expected1);
    // ケース2: 1回だけ出現する場合
    string T2 = "hello world";
    string S2 = "world";
    vector<int> expected2 = {6};
    assert(finds(T2, S2) == expected2);
    // ケース3: 全く出現しない場合
    string T3 = "apple";
    string S3 = "orange";
    vector<int> expected3 = {};
    assert(finds(T3, S3) == expected3);
    // ケース4: 重なる出現の確認
    // "aaaaa" の中に "aa" は 0, 1, 2, 3 文字目にある
    string T4 = "aaaaa";
    string S4 = "aa";
    vector<int> expected4 = {0, 1, 2, 3};
    assert(finds(T4, S4) == expected4);
    // ケース5: 検索文字列が空の場合
    // string::find("") は通常 0 を返すが、ループの仕方に依存する
    // この実装では 0, 1, 2, ... T.size() まで返る挙動になる
    string T5 = "abc";
    string S5 = "";
    vector<int> result5 = finds(T5, S5);
    assert(!result5.empty());
    assert(result5[0] == 0);
}
/**
 * @brief 文字列検索 複数のテスト
 */
void solve() {
    print("Hello World");
    test_finds();
}
