#pragma once
struct Eratosthenes {
  private:
    int N;         // 上限
    vector<int> D; // 最小素因数 (least prime factor)
  public:
    Eratosthenes(int N) : N(N) {
        D.resize(N + 1);
        iota(D.begin(), D.end(), 0ll);
        vector<int> known_prime = {2ll, 3ll, 5ll};
        for (int p : known_prime) {
            for (int i = p * p; i <= N; i += p) {
                if (D[i] == i) D[i] = p;
            }
        }
        vector<int> inc = {4, 2, 4, 2, 4, 6, 2, 6};
        int p = 7, idx = 0;
        int root = floor(sqrt(N) + 0.5);
        while (p <= root) {
            if (D[p] == p) {
                for (int i = p * p; i <= N; i += p) {
                    if (D[i] == i) D[i] = p;
                }
            }
            p += inc[idx++];
            if (idx == 8) idx = 0;
        }
    }
    bool is_prime(int x) const {
        assert(1 <= x and x <= N);
        return x == 1ll ? false : D[x] == x;
    }
    vector<pair<int, int>> factorize(int x) const {
        assert(1 <= x and x <= N);
        vector<pair<int, int>> F;
        while (x != 1) {
            int p = D[x], e = 0;
            while (x % p == 0ll) x /= p, e++;
            F.emplace_back(p, e);
        }
        return F;
    }
    vector<int> calc_divisors(int x) const {
        assert(1 <= x and x <= N);
        int n = 1; // 約数の個数
        vector<pair<int, int>> F;
        while (x != 1ll) {
            int p = D[x], e = 0;
            while (x % p == 0ll) x /= p, e++;
            F.emplace_back(p, e);
            n *= (1 + e);
        }
        vector<int> divisors(n, 1);
        int sz = 1; // 現在の約数の個数
        for (const auto &[p, e] : F) {
            for (int i = 0; i < sz * e; i++) {
                divisors[sz + i] = divisors[i] * p;
            }
            sz *= (1 + e);
        }
        return divisors;
    }
    // 最小素因数 (least prime factor)
    int lpf(int x) const {
        assert(1 <= x and x <= N);
        return D[x];
    }
    int euler_phi(int x) const {
        assert(1 <= x and x <= N);
        int res = x;
        while (x != 1ll) {
            int p = D[x];
            res -= res / p;
            while (x % p == 0ll) x /= p;
        }
        return res;
    }
    // メビウス関数のテーブルを計算する
    vector<int> calc_moebius() const {
        vector<int> moebius(N + 1, 0);
        moebius[1] = 1;
        for (int x = 2; x <= N; x++) {
            int y = x / D[x];
            if (D[x] != D[y]) moebius[x] = -moebius[y];
        }
        return moebius;
    }
};
