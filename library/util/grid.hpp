#pragma once
/**
 * @brief グリッド
 */
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
    // グリッド4方を見るBFS 引数f(y, x)
    template <typename T, typename F> void bfs(vector<vector<T>> &G, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int y = i + dy[k], x = j + dx[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    f(y, x);
                }
            }
        }
    }
    // グリッド8方を見るBFS 引数f(y, x)
    template <typename T, typename F> void bfs8(vector<vector<T>> &G, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 8; ++k) {
                    int y = i + dy8[k], x = j + dx8[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    f(y, x);
                }
            }
        }
    }
};
