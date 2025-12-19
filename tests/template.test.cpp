#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
signed main() {
    cout << "Hello World" << endl;
    /*
    template.hppから呼んでいる
    library/util/xxx.hppのユニットテスト
    */
    // ===== library/util/common.hpp =====
    // chmin
    int i = 6, j = 3;
    chmin(i, j);
    assert(i == 3);
    i = 3, j = 6;
    chmin(i, j);
    assert(i == 3);
    // chmax
    i = 5, j = 3;
    chmax(i, j);
    assert(i == 5);
    i = 3, j = 5;
    chmax(i, j);
    assert(i == 5);
    // ===== library/util/type.hpp =====
    // int_to_char
    assert('3' == int_to_char(3));
    // int_to_alph
    assert('d' == int_to_alph(3));
    // char_to_int
    assert(3 == char_to_int('3'));
    // toString
    assert("3" == toString(3));
    // toInteger
    assert(3 == toInteger("3"));
    // ===== library/util/seq.hpp =====
    vector<int> v{1, 3, 2, 4, 5, 5};
    // len
    assert(6 == len(v));
    // min
    assert(1 == min(v));
    // max
    assert(5 == max(v));
    // sum
    assert(20 == sum(v));
    // allMatch
    assert(allMatch(v, [](int x) { return x < 6; }));
    // nonMatch
    assert(!noneMatch(v, [](int x) { return x < 6; }));
    // anyMatch
    assert(anyMatch(v, [](int x) { return x < 6; }));
    // sort_asc
    sort_asc(v);
    vector<int> asc{1, 2, 3, 4, 5, 5};
    assert(v == asc);
    // sort_desc
    sort_desc(v);
    vector<int> desc{5, 5, 4, 3, 2, 1};
    assert(v == desc);
    // reverse
    reverse(v);
    assert(v == asc);
    // distinct
    distinct(v);
    vector<int> dis{1, 2, 3, 4, 5};
    assert(v == dis);
    // erase (set)
    set<int> st{1, 2, 3, 4, 5};
    int val = 3;
    erase(st, val);
    set<int> exp{1, 2, 4, 5};
    assert(st == exp);
    // erase (multiset)
    multiset<int> mst{1, 2, 3, 4, 5};
    erase(mst, val);
    multiset<int> mexp{1, 2, 4, 5};
    assert(mst == mexp);
    // transpose
    int H = 4, W = 4;
    vec2<int> G = make_vec2<int>(H, W);
    int t = 0;
    for (auto &&r : G) {
        ++t;
        for (auto &&e : r) {
            e = t++;
        }
    }
    auto P = transpose(G);
    vec2<int> expP{
        {1, 6, 11, 16}, {2, 7, 12, 17}, {3, 8, 13, 18}, {4, 9, 14, 19}};
    assert(P == expP);
    // unpack
    vec2<int> tmp{{1, 2}, {3, 4}};
    auto [a, b] = unpack<2>(move(tmp));
    vector<int> expa{1, 2};
    vector<int> expb{3, 4};
    assert(a == expa);
    assert(b == expb);
    // coordinate
    vector<int> arr{2, 3, 5, 7, 11, 13};
    vector<int> co = coordinate(arr);
    for (int k = 1; k < 13; ++k) {
        int cnt =
            k == 2 or k == 3 or k == 5 or k == 7 or k == 11 or k == 13 ? 1 : 0;
        assert(co[k] == cnt);
    }
    // ===== library/util/math.hpp =====
    // divCeil
    assert(2 == divCeil(5, 3));
    assert(2 == divCeil(-5, -3));
    // divFloor
    assert(1 == divFloor(5, 3));
    assert(1 == divFloor(-5, -3));
    // ===== library/util/search.hpp =====
    // search_permu
    vector<int> permA{1, 2, 3};
    vec2<int> permB;
    search_permu(permA, [&]() { permB.push_back(permA); });
    vec2<int> expPermB{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                       {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    assert(permB == expPermB);
    // search_bit
    vector<int> bitA{1, 2, 3};
    vec2<int> bitB = search_bit(bitA);
    vec2<int> expBitB{{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    assert(bitB == expBitB);
}
