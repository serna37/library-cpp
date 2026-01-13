#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/grid/bfs.hpp"
void run_generic_bfs_tests() {
    // テスト用の共通マップ
    // S . .
    // . # .
    // . . G
    vector<vector<char>> G = {
        {'S', '.', '.'},
        {'.', '#', '.'},
        {'.', '.', '.'}
    };

    // ケース1: d=4 (4近傍) の検証
    {
        auto res4 = bfs(G, 'S', 4ll);
        // (0,0)から(2,2)へは、壁を避けて4ステップかかる
        // (0,0)->(1,0)->(2,0)->(2,1)->(2,2) など
        assert(res4[0][0] == 0);
        assert(res4[2][2] == 4);
        assert(res4[1][1] == -1); // 壁は通れない
    }

    // ケース2: d=8 (8近傍) の検証
    {
        auto res8 = bfs(G, 'S', 8ll);
        // 8近傍なら、斜め移動を使って2ステップで到達可能
        // (0,0)->(1,1)は壁だが、(0,0)->(0,1)->(1,2)などは可能
        // 今回のマップなら (0,0)->(1,0)->(2,1) または (0,0)から周囲を経由して2ステップ
        assert(res8[0][0] == 0);
        assert(res8[2][2] == 3); 
    }

    // ケース3: 壁のブロッキング挙動の差
    {
        // S #
        // # .
        vector<vector<char>> G2 = {
            {'S', '#'},
            {'#', '.'}
        };
        
        // 4近傍では右下に行けない
        auto res4 = bfs(G2, 'S', 4ll);
        assert(res4[1][1] == -1);

        // 8近傍でも、斜め先が壁でなければ行けるが、
        // このコードの実装では「移動先が壁かどうか」を見るため、
        // (1,1)が '.' なら、(0,0)からダイレクトに斜め移動で到達できる
        auto res8 = bfs(G2, 'S', 8ll);
        assert(res8[1][1] == 1);
    }

    // ケース4: 範囲外の d が渡された場合の安全確認
    {
        // d=1 などの場合、ループが i=0 のみ回り、dx[0], dy[0] (右または下) のみが探索される
        auto res1 = bfs(G, 'S', 1ll);
        assert(res1[0][1] == 1 || res1[1][0] == 1); 
    }

    // ケース5: 文字列指定の壁
    {
        vector<vector<char>> G3 = {
            {'S', 'X', '.'},
            {'Y', '.', '.'}
        };
        // X と Y を壁にする
        auto res = bfs(G3, 'S', 4ll, "XY");
        assert(res[0][1] == -1);
        assert(res[1][0] == -1);
        assert(res[1][1] == -1); // どこにも行けない
    }
}
/**
 * @brief グリッドBFSのテスト
 */
void solve() {
    print("Hello World");
    run_generic_bfs_tests();
}
