#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/sequence/collection_util.hpp"
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
 * @brief 配列系Utilのテスト
 */
void solve() {
    print("Hello World");
    test_collection_class();
}
