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
    assert(lib::str.is_low('A') == false);
    assert(lib::str.is_low('a') == true);
    assert(lib::str.is_upp('A') == true);
    assert(lib::str.is_upp('a') == false);
    assert(lib::str.transform_lower("AbC") == "abc");
    assert(lib::str.transform_upper("AbC") == "ABC");
    assert(lib::str.lpad("ABC", 6) == "000ABC");
    assert(lib::str.rpad("ABC", 6) == "ABC000");
    vector<int> exp_finds = {0, 3, 6, 9};
    assert(lib::str.finds("abcaefahia", "a") == exp_finds);
    vector<string> exp_split = {"aa", "bb", "cc"};
    assert(lib::str.split("aa,bb,cc", ',') == exp_split);
    assert(lib::str.split_multi("aa,bb/cc", ",/") == exp_split);
    assert(lib::str.str_range("abc123abc", 3, 6) == "123a");
    vector<pair<char, int>> exp_runlen = {{'a', 3}, {'b', 2}, {'c', 1}};
    assert(lib::str.run_length("aaabbc") == exp_runlen);
    vector<int> exp_z_algo = {13, 0, 0, 0, 3, 0, 0, 1, 0, 2, 0, 0, 1};
    vector<int> val_z_algo = lib::str.z_algo("abc1abca3abZa");
    assert(val_z_algo == exp_z_algo);
}
// ===== library/util/sequence.hpp =====
void test_sequence() {
    // TODO test
}
// ===== library/util/search.hpp =====
void test_search() {
    vector<int> A = {1, 2, 3};
    vector<vector<int>> val_perm;
    vector<vector<int>> exp_perm = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    lib::search.perm(A, [&]() { val_perm.push_back(A); });
    assert(val_perm == exp_perm);
    A = {1, 2, 3};
    vector<vector<int>> val_bit = lib::search.bit(A);
    vector<vector<int>> exp_bit = {{},  {1},    {2},    {1, 2},
                                   {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    assert(val_bit == exp_bit);
    auto [L, R] = lib::search.bi([](int x) { return x >= 5; });
    assert(L == 4 and R == 5);
    auto [l, r] = lib::search.bi_real([](int x) { return x >= 3.5; });
    assert(l < 4.1 and r < 4.1);
    A = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    set<int> st = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    assert(lib::search.bi_le_cnt(A, 7ll) == 6);
    assert(lib::search.bi_le_val(A, 7ll) == 6);
    assert(lib::search.bi_le_val(A, 0ll) == -INF);
    assert(lib::search.bi_le_val(st, 7ll) == 6);
    assert(lib::search.bi_le_val(st, 0ll) == -INF);
    assert(lib::search.bi_ge_cnt(A, 7ll) == 3);
    assert(lib::search.bi_ge_val(A, 7ll) == 8);
    assert(lib::search.bi_ge_val(A, 11ll) == INF);
    assert(lib::search.bi_ge_val(st, 7ll) == 8);
    assert(lib::search.bi_ge_val(st, 11ll) == INF);
    assert(lib::search.bi_lt_cnt(A, 7ll) == 6);
    assert(lib::search.bi_lt_val(A, 7ll) == 6);
    assert(lib::search.bi_lt_val(A, 0ll) == -INF);
    assert(lib::search.bi_lt_val(st, 7ll) == 6);
    assert(lib::search.bi_lt_val(st, 0ll) == -INF);
    assert(lib::search.bi_gt_cnt(A, 7ll) == 3);
    assert(lib::search.bi_gt_val(A, 7ll) == 8);
    assert(lib::search.bi_gt_val(A, 11ll) == INF);
    assert(lib::search.bi_gt_val(st, 7ll) == 8);
    assert(lib::search.bi_gt_val(st, 11ll) == INF);
}
// ===== library/util/grid.hpp =====
void test_grid() {
    vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto T = lib::grid.transpose(G);
    vector<vector<int>> exp_tx = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    assert(T == exp_tx);
    int cnt = 0;
    auto f = [&](int y, int x) {
        if (G[y][x] == 5) ++cnt;
    };
    lib::grid.bfs(G, f);
    assert(cnt == 4);
    cnt = 0;
    lib::grid.bfs8(G, f);
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
