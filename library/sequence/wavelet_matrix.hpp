#pragma once
#include "library/sequence/bit_dict.hpp"
struct WaveletMatrix {
    int n;
    int max_log;
    vector<BitDict> matrix;
    vector<int> mid_points; // 各段での 0 と 1 の境界線 (0の個数)
    // 構築: O(N log V)
    WaveletMatrix(vector<long long> v, int max_log = 32)
        : n(v.size()), max_log(max_log) {
        matrix.assign(max_log, BitDict(n));
        mid_points.resize(max_log);
        vector<long long> left(n), right(n);
        for (int d = max_log - 1; d >= 0; d--) {
            vector<long long> l_vals, r_vals;
            for (int i = 0; i < n; i++) {
                if ((v[i] >> d) & 1) {
                    matrix[d].set(i);
                    r_vals.push_back(v[i]);
                } else {
                    l_vals.push_back(v[i]);
                }
            }
            matrix[d].build();
            mid_points[d] = l_vals.size();
            // v を次の段のために並び替える (0を前、1を後に集める)
            v = l_vals;
            v.insert(v.end(), r_vals.begin(), r_vals.end());
        }
    }
    // k番目の値を返す: O(log V)
    long long access(int k) const {
        long long res = 0;
        for (int d = max_log - 1; d >= 0; d--) {
            bool bit = matrix[d].access(k);
            if (bit) {
                res |= (1LL << d);
                k = mid_points[d] + matrix[d].rank1(k);
            } else {
                k = matrix[d].rank0(k);
            }
        }
        return res;
    }
    // [0, r) に含まれる x の個数: O(log V)
    int rank(long long x, int r) const {
        int l = 0;
        for (int d = max_log - 1; d >= 0; d--) {
            bool bit = (x >> d) & 1;
            if (bit) {
                l = mid_points[d] + matrix[d].rank1(l);
                r = mid_points[d] + matrix[d].rank1(r);
            } else {
                l = matrix[d].rank0(l);
                r = matrix[d].rank0(r);
            }
        }
        return r - l;
    }
    // [l, r) 内で k 番目に小さい値: O(log V)
    long long kth_smallest(int l, int r, int k) const {
        long long res = 0;
        for (int d = max_log - 1; d >= 0; d--) {
            int cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);
            if (k < cnt0) {
                l = matrix[d].rank0(l);
                r = matrix[d].rank0(r);
            } else {
                res |= (1LL << d);
                k -= cnt0;
                l = mid_points[d] + matrix[d].rank1(l);
                r = mid_points[d] + matrix[d].rank1(r);
            }
        }
        return res;
    }
    // [l, r) 内で k 番目に大きい値: O(log V)
    long long kth_largest(int l, int r, int k) const {
        return kth_smallest(l, r, (r - l) - 1 - k);
    }
    // [l, r) 内で [lower, upper) に含まれる要素数: O(log V)
    int range_freq(int l, int r, long long lower, long long upper) const {
        return count_less(l, r, upper) - count_less(l, r, lower);
    }
    // [l, r) 内で val 未満の要素数 (内部用補助関数)
    int count_less(int l, int r, long long val) const {
        int res = 0;
        for (int d = max_log - 1; d >= 0; d--) {
            bool bit = (val >> d) & 1;
            int cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);
            if (bit) {
                res += cnt0; // 0のビットを持つものは確実に val より小さい
                l = mid_points[d] + matrix[d].rank1(l);
                r = mid_points[d] + matrix[d].rank1(r);
            } else {
                l = matrix[d].rank0(l);
                r = matrix[d].rank0(r);
            }
        }
        return res;
    }
    // [l, r) 内で upper より小さい最大値
    long long prev_value(int l, int r, long long upper) const {
        int cnt = count_less(l, r, upper);
        return (cnt == 0) ? -1 : kth_smallest(l, r, cnt - 1);
    }
    // [l, r) 内で lower 以上の最小値
    long long next_value(int l, int r, long long lower) const {
        int cnt = count_less(l, r, lower);
        return (cnt == (r - l)) ? -1 : kth_smallest(l, r, cnt);
    }
};
