#pragma once
/**
 * @brief 辺
 */
struct Edge {
    int from, to;
    long long cost;
    int idx;
    Edge(int from, int to, long long cost = 1, int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {
    }
};
