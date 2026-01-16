#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/string/finds.hpp"
void test_finds() {
    // ケース1: 単一パターン・短い
    {
        string T = "banana";
        vector<string> P = {"ana"};
        auto res = finds(T, P);
        assert(res["ana"] == vector<int>({1ll, 3ll}));
    }

    // ケース2: 単一パターン・長い
    {
        string T = "abracadabra_abracadabra";
        string pattern = "abracadabra";
        vector<string> P = {pattern};
        auto res = finds(T, P);
        assert(res[pattern] == vector<int>({0ll, 12ll}));
    }

    // ケース3: 複数パターン
    {
        string T = "abracadabra";
        vector<string> P = {"abr", "ra", "a"};
        auto res = finds(T, P);
        assert(res["abr"] == vector<int>({0ll, 7ll}));
        assert(res["ra"] == vector<int>({2ll, 9ll}));
        assert(res["a"] == vector<int>({0ll, 3ll, 5ll, 7ll, 10ll}));
    }

    // ケース4: ヒットしない場合
    {
        string T = "hello";
        vector<string> P = {"world"};
        auto res = finds(T, P);
        assert(res["world"].empty());
    }
}
/**
 * @brief 文字列複数 統合検索エンジンのテスト
 */
void solve() {
    print("Hello World");
    test_finds();
}
