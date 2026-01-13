#pragma once
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
const vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};
template <typename T>
vector<vector<int>> bfs(vector<vector<T>> &G, T start, int d = 4,
                        const string &wall = "#") {
    int H = G.size(), W = G[0].size();
    vector<vector<int>> min_cost(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (G[i][j] == start) {
                q.emplace(i, j);
                min_cost[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [Y, X] = q.front();
        q.pop();
        for (int i = 0; i < d; ++i) {
            int y = Y + (d == 4 ? dy[i] : dy8[i]),
                x = X + (d == 4 ? dx[i] : dx8[i]);
            if (y < 0 or x < 0 or H <= y or W <= x) continue;
            if (~min_cost[y][x]) continue;
            if (wall.find(G[y][x]) != string::npos) continue;
            min_cost[y][x] = min_cost[Y][X] + 1;
            q.emplace(y, x);
        }
    }
    return min_cost;
}
