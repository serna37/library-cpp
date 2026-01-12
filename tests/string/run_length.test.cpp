#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/run_length.hpp"
void test_run_length() {
    // ケース1: 基本的な連続文字
    // "aaabbc" -> [('a', 3), ('b', 2), ('c', 1)]
    string s1 = "aaabbc";
    vector<pair<char, int>> res1 = run_length(s1);
    assert(res1.size() == 3ll);
    assert(res1[0] == make_pair('a', 3ll));
    assert(res1[1] == make_pair('b', 2ll));
    assert(res1[2] == make_pair('c', 1ll));
    // ケース2: 全て同じ文字
    string s2 = "aaaaa";
    vector<pair<char, int>> res2 = run_length(s2);
    assert(res2.size() == 1ll);
    assert(res2[0] == make_pair('a', 5ll));
    // ケース3: 交互に現れる文字
    // "abab" -> [('a', 1), ('b', 1), ('a', 1), ('b', 1)]
    string s3 = "abab";
    vector<pair<char, int>> res3 = run_length(s3);
    assert(res3.size() == 4ll);
    assert(res3[2].first == 'a' && res3[2].second == 1ll);
    // ケース4: 空文字列
    string s4 = "";
    vector<pair<char, int>> res4 = run_length(s4);
    assert(res4.empty());
    // ケース5: 1文字だけ
    string s5 = "z";
    vector<pair<char, int>> res5 = run_length(s5);
    assert(res5.size() == 1ll);
    assert(res5[0].first == 'z' && res5[0].second == 1ll);
}
/**
 * @brief ランレングス圧縮のテスト
 */
void solve() {
    print("Hello World");
    test_run_length();
}
