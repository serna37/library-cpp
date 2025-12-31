
/** ======================================= */
/**               グリッド                  */
/** ======================================= */
#pragma once
class Grid {
  public:
    // 行列の転置
    template <typename T>
    vector<vector<T>> transpose(const vector<vector<T>> &G) {
        int H = G.size(), W = G[0].size();
        vector<vector<T>> _G(W, vector<T>(H));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                _G[j][i] = G[i][j];
            }
        }
        return _G;
    }
    // XXX 以下をいい感じにしたものに、改良する!
    // TODO 4方 or 8方に行くループ処理
    // TODO 領域外、行けないマスのフィルタ処理
    // TODO 行った結果どうする？最短距離を求める or ラムダにする
    template <typename T, typename F> void bfs(vector<vector<T>> &G, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int y = i + dy[k], x = j + dx[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    f();
                }
            }
        }
    }
    template <typename T, typename F>
    void bfs(vector<string> &G, string alw, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int y = i + dy[k], x = j + dx[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    if (alw.find(G[y][x]) == string::npos) continue;
                    f();
                }
            }
        }
    }
};
