#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/join.hpp"
void test_join() {
    // ケース1: 複数の要素をカンマで連結
    vector<string> v1 = {"apple", "banana", "cherry"};
    assert(join(v1, ",") == "apple,banana,cherry");
    // ケース2: 区切り文字が複数の文字（文字列）の場合
    vector<string> v2 = {"2026", "01", "12"};
    assert(join(v2, " / ") == "2026 / 01 / 12");
    // ケース3: 要素が1つだけの場合（区切り文字は現れない）
    vector<string> v3 = {"single"};
    assert(join(v3, "-") == "single");
    // ケース4: 空のベクターの場合
    vector<string> v4 = {};
    assert(join(v4, "!") == "");
    // ケース5: 要素が空文字列を含む場合
    vector<string> v5 = {"a", "", "b"};
    assert(join(v5, ",") == "a,,b");
    // ケース6: 区切り文字が空の場合
    vector<string> v6 = {"H", "e", "l", "l", "o"};
    assert(join(v6, "") == "Hello");
}
/**
 * @brief 文字列結合のテスト
 */
void solve() {
    print("Hello World");
    test_join();
}
