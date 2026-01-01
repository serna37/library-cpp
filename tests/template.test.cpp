#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
/*
template.hppから呼んでいる
library/util/xxx.hppのユニットテスト
出力すると問題に正解できないのでassertのみ
*/
// ===== library/util/number.hpp =====
void test_number() {
    assert(lib::num.div_ceil(10, 2) == 5);
    assert(lib::num.div_ceil(11, 2) == 6);
    assert(lib::num.div_floor(10, 2) == 5);
    assert(lib::num.div_floor(11, 2) == 5);
    assert(lib::num.factorial(0) == 1);
    assert(lib::num.factorial(1) == 1);
    assert(lib::num.factorial(2) == 2);
    assert(lib::num.factorial(3) == 6);
    assert(lib::num.combination(0, 0) == 1);
    assert(lib::num.combination(1, 0) == 1);
    assert(lib::num.combination(1, 1) == 1);
    assert(lib::num.combination(2, 0) == 1);
    assert(lib::num.combination(3, 2) == 3);
    assert(lib::num.digit_sum(1234) == 10);
    assert(lib::num.base_convert("1001", 2, 10) == "9");
    vector<int> val_divisors = lib::num.divisors(12);
    lib::seq.sort_asc(val_divisors);
    vector<int> exp_divisors = {1, 2, 3, 4, 6, 12};
    assert(val_divisors == exp_divisors);
    assert(lib::num.prime_test(57) == false); // Grothendieck
    assert(lib::num.prime_test(97) == true);
    map<int, int> val_prime_fact = lib::num.prime_fact(100);
    map<int, int> exp_prime_fact = {{2, 2}, {5, 2}};
    assert(val_prime_fact == exp_prime_fact);
    assert(lib::num.modpow(2, 10, MOD) == 1024);
    assert(lib::num.modinv(2, MOD) == 499122177);
    assert(lib::num.modfact(10, MOD) == 3628800);
    assert(lib::num.mod_combination(10, 5, MOD) == 252);
}
// ===== library/util/string.hpp =====
void test_string() {
    // TODO test
}
// ===== library/util/sequence.hpp =====
void test_sequence() {
    // TODO test
}
// ===== library/util/search.hpp =====
void test_search() {
    // TODO test
}
// ===== library/util/grid.hpp =====
void test_grid() {
    // TODO test
}
// ===== library/util/gepmetry.hpp =====
void test_geometry() {
    // TODO test
}
void solve() {
    // URLの問題の答えはこれだけ
    cout << "Hello World" << endl;
    test_number();
    test_string();
    test_sequence();
    test_search();
    test_grid();
    test_geometry();
}
