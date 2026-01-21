#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/graph/tree/convert_rooted_tree.hpp"
// --- テスト用関数 ---
void test_rooted_tree() {
    /*
        以下の木構造を作成 (0を根とする)
             0
           /   \
          1     2
         / \
        3   4
    */
    int N = 5;
    Graph G(N);
    G.add_both(0, 1);
    G.add_both(0, 2);
    G.add_both(1, 3);
    G.add_both(1, 4);
    // 0を根として変換
    Graph rg = convert_rooted_tree(G, 0);
    // 各頂点の子の数を確認
    assert(rg[0].size() == 2ll); // 1, 2
    assert(rg[1].size() == 2ll); // 3, 4
    assert(rg[2].size() == 0ll); // 葉
    assert(rg[3].size() == 0ll); // 葉
    assert(rg[4].size() == 0ll); // 葉
    // 具体的な親子関係をチェック
    auto has_child = [&](const Graph &g, int parent, int child) {
        for (auto &&e : g[parent]) {
            if (e.to == child) return true;
        }
        return false;
    };
    assert(has_child(rg, 0, 1));
    assert(has_child(rg, 0, 2));
    assert(has_child(rg, 1, 3));
    assert(has_child(rg, 1, 4));
    // 逆方向（子から親）の辺が存在しないことを確認
    assert(!has_child(rg, 1, 0));
    assert(!has_child(rg, 3, 1));
    /*
        根を変えてテスト (3を根とする)
             3
             |
             1
           / | \
          0  4  (戻る辺なし)
          |
          2
    */
    Graph rg3 = convert_rooted_tree(G, 3);
    assert(rg3[3].size() == 1ll); // 3 -> 1
    assert(has_child(rg3, 3, 1));
    assert(rg3[1].size() == 2ll); // 1 -> 0, 1 -> 4
    assert(has_child(rg3, 1, 0));
    assert(has_child(rg3, 1, 4));
    assert(rg3[0].size() == 1ll); // 0 -> 2
    assert(has_child(rg3, 0, 2));
}
/**
 * @brief 木 - 根付き木変換のテスト
 */
void solve() {
    print("Hello World");
    test_rooted_tree();
}
