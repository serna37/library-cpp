#pragma once
/**
 * @file graph.hpp
 * @brief グラフ
 */
// 辺
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id) {};
};
// グラフ
template <typename T> struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int N) : G(N) {};
    vector<Edge<T>> operator[](T v) const {
        return G[v];
    }
    int size() const {
        return G.size();
    }
    // (有向)辺を張る
    void add(int from, int to, T cost = 1, int id = -1) {
        G[from].push_back({from, to, cost, id});
    }
    // (双方向)辺を張る
    void add_both(int from, int to) {
        G[from].push_back({from, to, 1, -1});
        G[to].push_back({to, from, 1, -1});
    }
    // デバッグ表示
    void dump() {
        for (int i = 0; i < (int)G.size(); ++i) {
            cerr << i << ": ";
            for (auto &&edge : G[i]) {
                cerr << edge.to << " ";
            }
            cerr << endl;
        }
    }
};
// BFS bfs(G); bfs(G, vector<int>{0});
template <typename T>
vector<int> bfs(const Graph<T> &G, const vector<int> &starts = {0}) {
    queue<int> q;
    vector<int> dis(2e6, -1);
    for (auto &&v : starts) {
        q.push(v);
        dis[v] = 0;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &&[from, to, cost, id] : G[v]) {
            if (dis[to] == -1) {
                dis[to] = dis[from] + 1;
                q.push(to);
            }
        }
    }
    return dis;
}
