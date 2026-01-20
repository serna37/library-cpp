#pragma once
struct BitDict {
    using uint = uint64_t;
    int n;
    vector<uint> bit; // ビット列本体
    vector<int> sum;  // 累積和（各ワード開始時点での1の総数）
    BitDict() {}      // 空のコンストラクタ（ウェーブレット行列のvector確保用）
    // 64ビット単位で格納するため、(n/64)+1 個の要素を確保
    BitDict(int n) : n(n) { // n は扱うビット列の長さ（最大インデックス + 1）
        bit.assign((n >> 6) + 1, 0);
    }
    // k番目のビットを1にする
    void set(int k) { bit[k >> 6] |= (1ULL << (k & 63)); }
    // 累積和を構築する（setの後に必ず呼ぶ）
    void build() {
        sum.assign(bit.size() + 1, 0);
        for (int i = 0; i < (int)bit.size(); i++) {
            sum[i + 1] = sum[i] + __builtin_popcountll(bit[i]);
        }
    }
    // k番目のビットを取得
    bool access(int k) const { return (bit[k >> 6] >> (k & 63)) & 1; }
    // [0, k) 内の 1 の個数
    int rank1(int k) const {
        int idx = k >> 6;
        int offset = k & 63;
        uint mask = (1ULL << offset) - 1;
        return sum[idx] + __builtin_popcountll(bit[idx] & mask);
    }
    // [0, k) 内の 0 の個数（ウェーブレット行列で多用する）
    int rank0(int k) const { return k - rank1(k); }
    // j番目(1-indexed)の1の位置: O(log N)
    int select(int j) const {
        if (j <= 0 || j > sum.back()) return -1;
        int left = 0, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (rank1(mid) >= j)
                right = mid;
            else
                left = mid;
        }
        return left;
    }
};
