#pragma once
/**
 * @brief 数の性質
 */
class Number {
  private:
    // mod階乗のメモ配列
    vector<long long> _mf;

  public:
    // 割り下げ（負の場合0側へ丸めない）
    template <typename T> T div_ceil(T a, T b) {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    }
    // 割り上げ（負の場合0側へ丸めない）
    template <typename T> T div_floor(T a, T b) {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    }
    // 階乗 ナイーブ
    long long factorial(int N) {
        long long res = 1;
        while (N > 0) res *= N--;
        return res;
    }
    // nCk
    long long combination(int n, int k) {
        if (k < 0 || n < k) return 0ll;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= n--;
            res /= i;
        }
        return res;
    }
    // 桁和
    int digit_sum(int a, int N = 10) {
        int res = 0;
        while (a != 0) {
            res += a % N;
            a /= N;
        }
        return res;
    }
    // 進数変換 fromとtoは10を超えないこと
    string base_convert(string a, int from, int to) {
        long long cvt = 0ll; // 10進数に直す
        for (auto &&v : a) cvt = cvt * from + (int)(v - '0');
        if (cvt == 0) return "0";
        string res = ""; // to進数に直す
        while (cvt) {    // 10進数で表せる範囲の文字しか扱っていない
            res = (char)(cvt % to + '0') + res;
            cvt /= to;
        }
        return res;
    }
    // 約数列挙
    vector<int> divisors(int a) {
        vector<int> res;
        for (int i = 1; i * i <= a; ++i) {
            if (a % i != 0) continue;
            res.push_back(i);
            if (a / i != i) res.push_back(a / i);
        }
        return res;
    }
    // 素数判定
    bool prime_test(int N) {
        if (N == 2) return true;
        if (N == 1 or N % 2 == 0) return false;
        for (int i = 3; i * i <= N; i += 2) {
            if (N % i == 0) return false;
        }
        return true;
    }
    // 素因数分解
    map<int, int> prime_fact(int N) {
        map<int, int> P;
        for (int i = 2; i * i <= N; ++i) {
            while (N % i == 0) {
                ++P[i];
                N /= i;
            }
        }
        if (N > 1) ++P[N];
        return P;
    }
    // 二分累乗(mod)
    long long modpow(long long a, long long n, long long m) {
        long long res = 1ll;
        while (n > 0) {
            if (n & 1) res = res * a % m;
            a = a * a % m;
            n >>= 1ll;
        }
        return res;
    }
    // Fermatの小定理 逆元を求める
    long long modinv(long long a, long long m) {
        return modpow(a, m - 2, m);
    }
    // mod階乗
    long long modfact(int x, long long m) {
        if ((int)_mf.size() > x) return _mf[x];
        if (_mf.empty()) _mf.push_back(1);
        for (int i = _mf.size(); i <= x; ++i) _mf.push_back(_mf.back() * i % m);
        return _mf[x];
    }
    // mod組み合わせnCk
    long long mod_combination(int n, int k, long long m) {
        return modfact(n, m) * modinv(modfact(k, m), m) % m *
               modinv(modfact(n - k, m), m) % m;
    }
};
