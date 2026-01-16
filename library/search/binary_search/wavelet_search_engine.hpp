#pragma once
#include "library/sequence/compressor.hpp"
#include "library/sequence/wavelet_matrix.hpp"
struct WaveletSearchEngine {
    int n;
    Compressor<long long> cp;
    WaveletMatrix wm;
    const long long INF_VAL = 1e18;
    WaveletSearchEngine(const vector<long long> &v) : n(v.size()), cp(v), wm({}, 0) {
        vector<int> compressed_all = cp.get_all();
        vector<long long> wm_input(compressed_all.begin(), compressed_all.end());
        int max_log = 0;
        while ((1LL << max_log) <= (int)cp.size()) max_log++;
        if (max_log == 0) max_log = 1; // 要素が空または1種類の場合
        wm = WaveletMatrix(wm_input, max_log);
    }

    // --- 基本操作 ---

    // i 番目の元の値を返す
    long long access(int i) const {
        return cp.get_val(wm.access(i));
    }

    // [l, r) 内に x が何個含まれるか
    int count_x(int l, int r, long long x) const {
        int id = cp.get_id(x);
        if (id >= cp.size() || cp.get_val(id) != x) return 0;
        return wm.rank(id, r) - wm.rank(id, l);
    }

    // --- 二分探索系統合インターフェース (bi_..._cnt) ---

    // [l, r) 内で x 未満 (Less Than) の個数
    int count_lt(int l, int r, long long x) const {
        return wm.count_less(l, r, cp.get_id(x));
    }

    // [l, r) 内で x 以下 (Less Equal) の個数
    int count_le(int l, int r, long long x) const {
        return wm.count_less(l, r, cp.get_upper_id(x));
    }

    // [l, r) 内で x 以上 (Greater Equal) の個数
    int count_ge(int l, int r, long long x) const {
        return (r - l) - count_lt(l, r, x);
    }

    // [l, r) 内で x より大きい (Greater Than) の個数
    int count_gt(int l, int r, long long x) const {
        return (r - l) - count_le(l, r, x);
    }

    // --- 値検索系統合インターフェース (bi_..._val) ---

    // [l, r) 内で k 番目に小さい値 (0-indexed)
    long long kth_smallest(int l, int r, int k) const {
        if (k < 0 || k >= (r - l)) return INF_VAL;
        return cp.get_val(wm.kth_smallest(l, r, k));
    }

    // [l, r) 内で k 番目に大きい値 (0-indexed)
    long long kth_largest(int l, int r, int k) const {
        if (k < 0 || k >= (r - l)) return -INF_VAL;
        return cp.get_val(wm.kth_largest(l, r, k));
    }

    // [l, r) 内で x 未満の最大値 (Less Than Value)
    long long find_lt(int l, int r, long long x) const {
        int cnt = count_lt(l, r, x);
        return (cnt == 0) ? -INF_VAL : kth_smallest(l, r, cnt - 1);
    }

    // [l, r) 内で x 以下の最大値 (Less Equal Value)
    long long find_le(int l, int r, long long x) const {
        int cnt = count_le(l, r, x);
        return (cnt == 0) ? -INF_VAL : kth_smallest(l, r, cnt - 1);
    }

    // [l, r) 内で x 以上の最小値 (Greater Equal Value)
    long long find_ge(int l, int r, long long x) const {
        int cnt = count_lt(l, r, x);
        return (cnt == (r - l)) ? INF_VAL : kth_smallest(l, r, cnt);
    }

    // [l, r) 内で x より大きい最小値 (Greater Than Value)
    long long find_gt(int l, int r, long long x) const {
        int cnt = count_le(l, r, x);
        return (cnt == (r - l)) ? INF_VAL : kth_smallest(l, r, cnt);
    }

    // --- 応用クエリ ---

    // [l, r) 内で [lower, upper) に含まれる要素数
    int range_freq(int l, int r, long long lower, long long upper) const {
        if (lower >= upper) return 0;
        return wm.count_less(l, r, cp.get_id(upper)) - wm.count_less(l, r, cp.get_id(lower));
    }
};
