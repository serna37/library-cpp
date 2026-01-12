#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/split.hpp"
void test_split() {
    // ケース1: 基本的なカンマ区切り
    string s1 = "apple,banana,cherry";
    vector<string> expected1 = {"apple", "banana", "cherry"};
    assert(split(s1, ',') == expected1);
    // ケース2: セパレータが連続する場合（空の要素が作られる）
    string s2 = "a,,b";
    vector<string> expected2 = {"a", "", "b"};
    assert(split(s2, ',') == expected2);
    // ケース3: 先頭や末尾にセパレータがある場合
    string s3 = ",a,b,";
    vector<string> expected3 = {"", "a", "b", ""};
    assert(split(s3, ',') == expected3);
    // ケース4: セパレータが含まれない場合
    string s4 = "hello";
    vector<string> expected4 = {"hello"};
    assert(split(s4, ',') == expected4);
    // ケース5: 空文字列の場合
    string s5 = "";
    vector<string> expected5 = {
        ""}; // 初期値が {""} なので要素数1の空文字が返る
    assert(split(s5, ',') == expected5);
    // ケース6: セパレータのみの文字列
    string s6 = ",,";
    vector<string> expected6 = {"", "", ""};
    assert(split(s6, ',') == expected6);
}
/**
 * @brief 文字列を区切るのテスト
 */
void solve() {
    print("Hello World");
    test_split();
}
