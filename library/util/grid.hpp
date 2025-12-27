
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
    // TODO グリッド中での4方向とか8方向のBFSとかほしいかなぁ
    // TODO ドキュメント
};

