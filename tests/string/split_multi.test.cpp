#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/split_multi.hpp"
void test_split_multi() {
    // ケース1: 複数の区切り文字（スペース、カンマ、セミコロン）
    string s1 = "apple banana,cherry;orange";
    string seps1 = " ,;";
    vector<string> expected1 = {"apple", "banana", "cherry", "orange"};
    assert(split_multi(s1, seps1) == expected1);
    // ケース2: 区切り文字が連続する場合（空要素が生成される）
    string s2 = "a,, b";
    string seps2 = ", ";
    // 'a' -> ','(分割) -> ','(分割) -> ' '(分割) -> 'b'
    vector<string> expected2 = {"a", "", "", "b"};
    assert(split_multi(s2, seps2) == expected2);
    // ケース3: 数値を区切り文字にする
    string s3 = "123a456b789";
    string seps3 = "ab";
    vector<string> expected3 = {"123", "456", "789"};
    assert(split_multi(s3, seps3) == expected3);
    // ケース4: 区切り文字が文字列に含まれない場合
    string s4 = "hello";
    string seps4 = "xyz";
    vector<string> expected4 = {"hello"};
    assert(split_multi(s4, seps4) == expected4);
    // ケース5: 先頭や末尾が区切り文字の場合
    string s5 = "/usr/bin/";
    string seps5 = "/";
    vector<string> expected5 = {"", "usr", "bin", ""};
    assert(split_multi(s5, seps5) == expected5);
    // ケース6: 空の文字列と空の区切り文字
    assert(split_multi("", ",") == vector<string>({""}));
    assert(split_multi("abc", "") == vector<string>({"abc"}));
}
/**
 * @brief 文字列を区切る 複数のテスト
 */
void solve() {
    print("Hello World");
    test_split_multi();
}
