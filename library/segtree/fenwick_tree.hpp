#pragma once
struct FenwickTree {
  private:
    int N;
    vector<int> fwk;

  public:
    FenwickTree(int N) : N(N) {
        fwk.assign(N + 1, 0);
    }
    FenwickTree(const vector<int> &A) : N(A.size()) {
        fwk.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            fwk[i] += A[i - 1];
            if (i + (i & -i) <= N) fwk[i + (i & -i)] += fwk[i];
        }
    }
    void add(int i, const int &x) {
        for (++i; i <= N; i += i & -i) fwk[i] += x;
    }
    int sum(int i) {
        int ans = 0;
        for (++i; i; i -= i & -i) ans += fwk[i];
        return ans;
    }
};
