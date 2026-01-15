#pragma once
template <typename T> struct Doubling {
    int N, log = 0;
    vector<vector<T>> table;
    Doubling() {}
    Doubling(const vector<T> &next, long long max_steps) {
        N = next.size();
        while ((1ll << log) <= max_steps) ++log;
        table.assign(log, vector<T>(N, T()));
        table[0] = next;
        for (int k = 0; k < log - 1; ++k) {
            for (int v = 0; v < N; ++v) {
                if (table[k][v].to == T::e) {
                    table[k + 1][v] = table[k][v];
                } else {
                    table[k + 1][v] = table[k][v] + table[k][table[k][v].to];
                }
            }
        }
    }
    T query(int v, long long steps) const {
        T res;
        res.to = v;
        for (int k = 0; k < log; ++k) {
            if ((steps >> k) & 1) {
                if (res.to == T::e) break;
                res = res + table[k][res.to];
            }
        }
        return res;
    }
};
