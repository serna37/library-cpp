#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
/**
 * @brief library/util/xxx.hppのユニットテスト
 * 出力すると問題に正解できないのでassertのみ
 */
// ===== library/util/number.hpp =====
#include "library/util/number.hpp"
void test_number() {
    Number num;
    assert(num.div_ceil(10, 2) == 5);
    assert(num.div_ceil(11, 2) == 6);
    assert(num.div_floor(10, 2) == 5);
    assert(num.div_floor(11, 2) == 5);
    assert(num.factorial(0) == 1);
    assert(num.factorial(1) == 1);
    assert(num.factorial(2) == 2);
    assert(num.factorial(3) == 6);
    assert(num.combination(0, 0) == 1);
    assert(num.combination(1, 0) == 1);
    assert(num.combination(1, 1) == 1);
    assert(num.combination(2, 0) == 1);
    assert(num.combination(3, 2) == 3);
    assert(num.digit_sum(1234) == 10);
    assert(num.base_convert("1001", 2, 10) == "9");
    vector<int> val_divisors = num.divisors(12);
    sort(all(val_divisors));
    vector<int> exp_divisors = {1, 2, 3, 4, 6, 12};
    assert(val_divisors == exp_divisors);
    assert(num.prime_test(57) == false); // Grothendieck
    assert(num.prime_test(97) == true);
    map<int, int> val_prime_fact = num.prime_fact(100);
    map<int, int> exp_prime_fact = {{2, 2}, {5, 2}};
    assert(val_prime_fact == exp_prime_fact);
    assert(num.modpow(2, 10, MOD) == 1024);
    assert(num.modinv(2, MOD) == 499122177);
    assert(num.modfact(10, MOD) == 3628800);
    assert(num.mod_combination(10, 5, MOD) == 252);
}
// ===== library/util/string.hpp =====
#include "library/util/string.hpp"
void test_string() {
    String str;
    assert(str.is_low('A') == false);
    assert(str.is_low('a') == true);
    assert(str.is_upp('A') == true);
    assert(str.is_upp('a') == false);
    assert(str.transform_lower("AbC") == "abc");
    assert(str.transform_upper("AbC") == "ABC");
    vector<string> val_join = {"aa", "bb", "cc"};
    assert(str.join(val_join, ",") == "aa,bb,cc");
    vector<int> exp_finds = {0, 3, 6, 9};
    assert(str.finds("abcaefahia", "a") == exp_finds);
    vector<string> exp_split = {"aa", "bb", "cc"};
    assert(str.split("aa,bb,cc", ',') == exp_split);
    assert(str.split_multi("aa,bb/cc", ",/") == exp_split);
    assert(str.str_range("abc123abc", 3, 6) == "123a");
    vector<pair<char, int>> exp_runlen = {{'a', 3}, {'b', 2}, {'c', 1}};
    assert(str.run_length("aaabbc") == exp_runlen);
}
// ===== library/util/sequence.hpp =====
#include "library/util/sequence.hpp"
void test_sequence() {
    Sequence seq;
    vector<int> A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};
    assert(seq.min(A) == 1);
    assert(seq.max(A) == 13);
    assert(seq.sum(A) == 51);
    vector<int> evens = {0, 2, 4, 6};
    vector<int> odds = {1, 3, 5, 7};
    auto is_even = [](int x) { return x % 2 == 0; };
    assert(seq.all_match(evens, is_even));
    assert(seq.none_match(odds, is_even));
    assert(seq.any_match(A, is_even));
    vector<int> exp_distinct = {1, 2, 3, 5, 8, 9, 13};
    seq.distinct(A);
    assert(A == exp_distinct);
    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};
    vector<int> exp_asc = {1, 2, 2, 3, 3, 5, 5, 8, 9, 13};
    seq.sort_asc(A);
    assert(A == exp_asc);
    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};
    vector<int> exp_desc = {13, 9, 8, 5, 5, 3, 3, 2, 2, 1};
    seq.sort_desc(A);
    assert(A == exp_desc);
    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};
    vector<int> exp_rev = {5, 3, 9, 2, 13, 8, 5, 2, 3, 1};
    seq.reverse(A);
    assert(A == exp_rev);
    set<int> st = {1, 2, 3, 4, 6, 7, 9, 11};
    set<int> exp_erase = {1, 2, 3, 6, 7, 9, 11};
    seq.erase(st, 4ll);
    assert(st == exp_erase);
    multiset<int> mst = {1, 2, 3, 4, 4, 4, 6, 7, 9, 11};
    multiset<int> exp_merase = {1, 2, 3, 4, 4, 6, 7, 9, 11};
    seq.erase(mst, 4ll);
    assert(mst == exp_merase);
    A = {1, 2};
    auto [a, b] = seq.unpack<2>(move(A));
    assert(a == 1 and b == 2);
    vector<int> val_renban(10);
    vector<int> exp_renban = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    seq.renban(val_renban);
    assert(val_renban == exp_renban);
    A = {1, 2, 3};
    vector<int> B = {1, 2, 3, 4, 5};
    seq.merge(A, B);
    vector<int> exp_merge_vec = {1, 2, 3, 4, 5, 1, 2, 3};
    assert(B == exp_merge_vec);
    set<int> stA = {1, 2, 3};
    set<int> stB = {1, 2, 3, 4, 5};
    set<int> exp_merge_set = {1, 1, 2, 2, 3, 3, 4, 5};
    seq.merge(stA, stB);
    assert(stB == exp_merge_set);
    map<int, int> mpA = {{1, 1}, {2, 2}};
    map<int, int> mpB = {{1, 1}, {2, 2}, {3, 3}};
    auto mergeF = [&](map<int, int> &B, pair<int, int> v) {
        return B[v.first] += v.second;
    };
    seq.merge(mpA, mpB, mergeF);
    map<int, int> exp_merge_map = {{1, 2}, {2, 4}, {3, 3}};
    assert(mpB == exp_merge_map);
    A = {1, 2, 2, 5, 6};
    vector<int> val_coordinate = seq.coordinate(A);
    vector<int> exp_coordinate = {0, 1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; ++i) {
        assert(val_coordinate[i] == exp_coordinate[i]);
    }
    A = {1, 2, 2, 8, 10, 88};
    int zip_cnt = seq.zip_coordinate(A);
    assert(zip_cnt == 5);
    vector<int> exp_zip = {0, 1, 1, 2, 3, 4};
    assert(A == exp_zip);
    A = {1, 3, 9, 3, 8, 2, 99, 4};
    int inv = seq.inversion_number(A);
    assert(inv == 9);
    A = {1, 2, 5, 8, 3, 2, 9};
    vector<int> S = seq.zeta(A);
    vector<int> exp_zeta = {0, 1, 3, 8, 16, 19, 21, 30};
    assert(S == exp_zeta);
    S = seq.zeta_rev(A);
    vector<int> exp_zeta_rev = {30, 29, 27, 22, 14, 11, 9, 0};
    assert(S == exp_zeta_rev);
    S = seq.zeta_diff(A);
    vector<int> exp_zeta_diff = {0, 0, 1, 1, 4, 4, 5, 5};
    assert(S == exp_zeta_diff);
    S = seq.zeta_rev_diff(A);
    vector<int> exp_zeta_rev_diff = {15, 15, 12, 12, 7, 7, 0, 0};
    assert(S == exp_zeta_rev_diff);
    vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> S2 = seq.zeta_2D(G);
    vector<vector<int>> exp_zeta_2D = {
        {0, 0, 0, 0}, {0, 1, 3, 6}, {0, 5, 12, 21}, {0, 12, 27, 45}};
    assert(S2 == exp_zeta_2D);
    vector<vector<vector<int>>> G3 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                                      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                                      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    auto S3 = seq.zeta_3D(G3);
    vector<vector<vector<int>>> exp_zeta_3D = {
        {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 1, 3, 6}, {0, 5, 12, 21}, {0, 12, 27, 45}},
        {{0, 0, 0, 0}, {0, 2, 6, 12}, {0, 10, 24, 42}, {0, 24, 54, 90}},
        {{0, 0, 0, 0}, {0, 3, 9, 18}, {0, 15, 36, 63}, {0, 36, 81, 135}}};
    assert(S3 == exp_zeta_3D);
    vector<int> R = seq.moebius(A);
    vector<int> exp_moebius = {1, 3, 3, -5, -1, 7};
    assert(R == exp_moebius);
}
// ===== library/util/search.hpp =====
#include "library/util/search.hpp"
void test_search() {
    Search search;
    vector<int> A = {1, 2, 3};
    vector<vector<int>> val_perm;
    vector<vector<int>> exp_perm = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    search.perm(A, [&]() { val_perm.push_back(A); });
    assert(val_perm == exp_perm);
    A = {1, 2, 3};
    vector<vector<int>> val_bit = search.bit(A);
    vector<vector<int>> exp_bit = {{},  {1},    {2},    {1, 2},
                                   {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    assert(val_bit == exp_bit);
    auto [L, R] = search.bi([](int x) { return x >= 5; });
    assert(L == 4 and R == 5);
    auto [l, r] = search.bi_real([](int x) { return x >= 3.5; });
    assert(l < 4.1 and r < 4.1);
    A = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    set<int> st = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    assert(search.bi_le_cnt(A, 7ll) == 6);
    assert(search.bi_le_val(A, 7ll) == 6);
    assert(search.bi_le_val(A, 0ll) == -INF);
    assert(search.bi_le_val(st, 7ll) == 6);
    assert(search.bi_le_val(st, 0ll) == -INF);
    assert(search.bi_ge_cnt(A, 7ll) == 3);
    assert(search.bi_ge_val(A, 7ll) == 8);
    assert(search.bi_ge_val(A, 11ll) == INF);
    assert(search.bi_ge_val(st, 7ll) == 8);
    assert(search.bi_ge_val(st, 11ll) == INF);
    assert(search.bi_lt_cnt(A, 7ll) == 6);
    assert(search.bi_lt_val(A, 7ll) == 6);
    assert(search.bi_lt_val(A, 0ll) == -INF);
    assert(search.bi_lt_val(st, 7ll) == 6);
    assert(search.bi_lt_val(st, 0ll) == -INF);
    assert(search.bi_gt_cnt(A, 7ll) == 3);
    assert(search.bi_gt_val(A, 7ll) == 8);
    assert(search.bi_gt_val(A, 11ll) == INF);
    assert(search.bi_gt_val(st, 7ll) == 8);
    assert(search.bi_gt_val(st, 11ll) == INF);
}
// ===== library/util/grid.hpp =====
#include "library/util/grid.hpp"
void test_grid() {
    Grid grid;
    vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto T = grid.transpose(G);
    vector<vector<int>> exp_tx = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    assert(T == exp_tx);
    int cnt = 0;
    auto f = [&](int y, int x) {
        if (G[y][x] == 5) ++cnt;
    };
    grid.bfs(G, f);
    assert(cnt == 4);
    cnt = 0;
    grid.bfs8(G, f);
    assert(cnt == 8);
}
// ===== library/util/geometry.hpp =====
#include "library/util/geometry.hpp"
void test_geometry() {
    Geometry geo;
    assert(geo.rad_to_deg(geo.deg_to_rad(45)) == 45);
    assert(geo.rad_to_deg(geo.deg_to_rad(361)) < 361); // 誤差があるので不等式
    assert(geo.arc_tan(24, 35) < 0.97);
    assert(geo.area_triangle(1, 1, 2, 3, 5, 6) == 1.5);
    assert(geo.area_square(1, 1, 2, 2, 4, 4, 7, 7) == 15);
}
void solve() {
    // URLの問題の答えはこれだけ
    print("Hello World");
    test_number();
    test_string();
    test_sequence();
    test_search();
    test_grid();
    test_geometry();
}
