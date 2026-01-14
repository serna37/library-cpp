#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/util.hpp"
void test_string_manipulation() {
    // string_to_lower
    assert(string_to_lower("AbC12") == "abc12");
    // string_to_upper
    assert(string_to_upper("abc12") == "ABC12");
    // char_is_lower / upper
    assert(char_is_lower('a') == true);
    assert(char_is_lower('A') == false);
    assert(char_is_upper('Z') == true);
    assert(char_is_upper('z') == false);
}
/**
 * @brief 文字列Utilのテスト
 */
void solve() {
    print("Hello World");
    test_string_manipulation();
}
