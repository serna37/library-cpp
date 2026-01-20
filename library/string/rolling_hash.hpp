#pragma once
#include "library/various/random.hpp"
struct RollingHash {
    static const long long MOD = (1LL << 61) - 1;
    static inline long long base = 0;
    vector<long long> hash_sum;
    // 基数をメルセンヌツイスタの乱数で初期化する
    static void init_base() {
        if (base != 0) return;
        base = random(2, MOD - 1);
    }
    // 文字列からハッシュの累積和を構築する
    RollingHash(const string &s) {
        init_base();
        int n = s.size();
        hash_sum.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hash_sum[i + 1] = mul(hash_sum[i], base) + s[i];
            if (hash_sum[i + 1] >= MOD) hash_sum[i + 1] -= MOD;
        }
    }
    // 2^61-1 用の高速な掛け算
    static long long mul(long long a, long long b) {
        __int128_t res = (__int128_t)a * b;
        long long ans = (long long)(res >> 61) + (long long)(res & MOD);
        if (ans >= MOD) ans -= MOD;
        return ans;
    }
    // 累乗テーブルの管理
    static const vector<long long> &get_pow(int n) {
        static vector<long long> pow_memo = {1};
        while ((int)pow_memo.size() <= n) {
            pow_memo.push_back(mul(pow_memo.back(), base));
        }
        return pow_memo;
    }
    // s[l, r) のハッシュを取得
    long long get(int l, int r) const {
        long long res = hash_sum[r] - mul(hash_sum[l], get_pow(r - l)[r - l]);
        if (res < 0) res += MOD;
        return res;
    }
    // 2つのハッシュ(a, b)を結合する。bの長さが b_len
    static long long merge(long long a_hash, long long b_hash, int b_len) {
        long long res = mul(a_hash, get_pow(b_len)[b_len]) + b_hash;
        if (res >= MOD) res -= MOD;
        return res;
    }
};
