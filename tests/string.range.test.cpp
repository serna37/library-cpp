#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/range.hpp"
void test_range() {
    string s = "programming"; // 長さ 11
    // ケース1: 文字列の中間を抽出
    // index: 3(g) から 6(a)
    assert(range(s, 3, 6) == "gram");
    // ケース2: 1文字だけ抽出
    assert(range(s, 0, 0) == "p");
    // ケース3: 最後まで抽出
    assert(range(s, 7, 10) == "ming");
    // ケース4: A > B の場合 (空文字を期待)
    assert(range(s, 5, 2) == "");
    // ケース5: A が文字列のサイズ以上の場合 (空文字を期待)
    assert(range(s, 15, 20) == "");
    // ケース6: B が文字列のサイズを超える場合
    // std::string::substr は長さが範囲を超えると末尾までを返します
    assert(range(s, 8, 20) == "ing");
    // ケース7: 空文字列に対する操作
    assert(range("", 0, 0) == "");
}
/**
 * @brief 文字列の区間取得のテスト
 */
void solve() {
    print("Hello World");
    test_range();
}
