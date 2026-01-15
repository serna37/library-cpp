#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/various/convert.hpp"
void test_conversions() {
    // int_to_char
    assert(int_to_char(4) == '4');
    assert(int_to_char(0) == '0');
    // int_to_alph
    assert(int_to_alph(0) == 'a');
    assert(int_to_alph(25) == 'z');
    // char_to_int
    assert(char_to_int('7') == 7);
    assert(char_to_int('0') == 0);
    // int_to_string
    assert(int_to_string(123LL) == "123");
    assert(int_to_string(-45LL) == "-45");
    // string_to_int
    assert(string_to_int("9876543210") == 9876543210LL);
}
/**
 * @brief 型変換のテスト
 */
void solve() {
    print("Hello World");
    test_conversions();
}
