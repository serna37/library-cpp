#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
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
void test_math_functions() {
    // div_ceil (a/b で切り上げ)
    assert(div_ceil(10, 3) == 4);
    assert(div_ceil(10, 5) == 2);
    assert(div_ceil(-10, 3) == -3); // 0方向ではなく負の無限大方向への切り上げ
    // div_floor (a/b で切り捨て)
    assert(div_floor(10, 3) == 3);
    assert(div_floor(-10, 3) == -4);
    // degree / radian
    assert(abs(deg_to_rad(180.0) - PI) < 1e-9);
    assert(abs(rad_to_deg(PI / 2.0) - 90.0) < 1e-9);
    // arc_tan (y, x) の順
    assert(abs(arc_tan(1.0, 1.0) - (PI / 4.0)) < 1e-9);
}
void test_collection_class() {
    vector<int> v = {3, 1, 4, 1, 5};
    // min / max / sum
    assert(collection.min(v) == 1);
    assert(collection.max(v) == 5);
    assert(collection.sum(v) == 14);
    // match系 (引数: 値, インデックス)
    assert(collection.all_match(v, [](int x, int _) { return x > 0; }) == true);
    assert(collection.any_match(v, [](int x, int _) { return x == 5; }) ==
           true);
    assert(collection.none_match(v, [](int x, int _) { return x == 100; }) ==
           true);
    // sorting / distinct
    vector<int> v2 = {3, 1, 2, 1};
    collection.asc(v2);
    assert(v2 == vector<int>({1, 1, 2, 3}));
    collection.distinct(v2);
    assert(v2 == vector<int>({1, 2, 3}));
    collection.desc(v2);
    assert(v2 == vector<int>({3, 2, 1}));
    collection.reverse(v2);
    assert(v2 == vector<int>({1, 2, 3}));
    // sequence
    vector<int> v3(3);
    collection.sequence(v3, 10ll); // 10, 11, 12
    assert(v3[0] == 10 && v3[2] == 12);
    // erase (set / multiset)
    multiset<int> ms = {1, 2, 2, 3};
    collection.erase(ms, 2ll); // 1つだけ消すはず
    assert(ms.count(2) == 1);
}
/**
 * @brief templateのテスト
 */
void solve() {
    print("Hello World");
    test_conversions();
    test_string_manipulation();
    test_math_functions();
    test_collection_class();
}
