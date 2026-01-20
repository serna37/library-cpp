#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/search/binary_search/wavelet_search_engine.hpp"
void test_wavelet_search_engine() {
    // テストデータ: 負数、重複、大きな値を含む
    vector<int> data = {10, -5, 20, 10, 30, -5, 15};
    WaveletSearchEngine engine(data);
    // access のテスト
    assert(engine.access(0) == 10);
    assert(engine.access(1) == -5);
    assert(engine.access(6) == 15);
    // count 系 (区間 [1, 5) : {-5, 20, 10, 30})
    int l = 1, r = 5;
    assert(engine.count_x(l, r, 10) == 1);
    assert(engine.count_x(l, r, -5) == 1);
    assert(engine.count_lt(l, r, 10) == 1); // {-5}
    assert(engine.count_le(l, r, 10) == 2); // {-5, 10}
    assert(engine.count_gt(l, r, 10) == 2); // {20, 30}
    assert(engine.count_ge(l, r, 10) == 3); // {20, 10, 30}
    // kth 系 (区間 [0, 7) 全体 : {-5, -5, 10, 10, 15, 20, 30} ※ソート時)
    assert(engine.kth_smallest(0, 7, 0) == -5);
    assert(engine.kth_smallest(0, 7, 1) == -5);
    assert(engine.kth_smallest(0, 7, 2) == 10);
    assert(engine.kth_largest(0, 7, 0) == 30);
    assert(engine.kth_largest(0, 7, 1) == 20);
    // find 系 (区間 [4, 7) : {30, -5, 15})
    l = 4, r = 7;
    assert(engine.find_ge(l, r, 10) == 15);
    assert(engine.find_gt(l, r, 15) == 30);
    assert(engine.find_le(l, r, 14) == -5);
    assert(engine.find_lt(l, r, -5) == -engine.INF_VAL); // 存在しない
    // range_freq (区間 [0, 7), 値 [-5, 20))
    // 対象: {-5, -5, 10, 10, 15}
    assert(engine.range_freq(0, 7, -5, 20) == 5);
    assert(engine.range_freq(0, 7, 10, 11) == 2); // count_x と同等
}
void test_with_single_element() {
    vector<int> data = {100};
    WaveletSearchEngine engine(data);
    assert(engine.access(0) == 100);
    assert(engine.count_x(0, 1, 100) == 1);
    assert(engine.find_ge(0, 1, 100) == 100);
    assert(engine.find_gt(0, 1, 100) == engine.INF_VAL);
}
/**
 * @brief WaveletSearchEngineのテスト
 */
void solve() {
    print("Hello World");
    test_wavelet_search_engine();
    test_with_single_element();
}
