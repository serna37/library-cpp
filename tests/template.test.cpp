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
    vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto T = lib::grid.transpose(G);
    vector<vector<int>> exp_tx = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    assert(T == exp_tx);
    int cnt = 0;
    lib::grid.bfs(G, [&](int y, int x) {
        if (G[y][x] == 5) ++cnt;
    });
    assert(cnt == 4);
    cnt = 0;
    lib::grid.bfs8(G, [&](int y, int x) {
        if (G[y][x] == 5) ++cnt;
    });
    assert(cnt == 8);
}
// ===== library/util/gepmetry.hpp =====
void test_geometry() {
    assert(lib::geo.rad_to_deg(lib::geo.deg_to_rad(45)) == 45);
    assert(lib::geo.rad_to_deg(lib::geo.deg_to_rad(361)) <
           361); // 誤差があるので不等式
    assert(lib::geo.arc_tan(24, 35) < 0.97);
    assert(lib::geo.area_triangle(1, 1, 2, 3, 5, 6) == 1.5);
    assert(lib::geo.area_square(1, 1, 2, 2, 4, 4, 7, 7) == 15);
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
