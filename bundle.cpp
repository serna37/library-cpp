/**
 * @brief ฅ^>ω<^ฅ
 * @author serna37
 * @note https://serna37.github.io/library-cpp/
 */
#ifdef LOCAL

#else
#define debug(...)
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// -----------------------------------------
// #include "template/includes.hpp" is done.
// -----------------------------------------

#include <bits/stdc++.h>
using namespace std;

/** ======================================= */
/**              共通                       */
/** ======================================= */

#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))
// lambda($(0) + $(1))とできる
#define lambda(...) ([&](auto &&..._args) { return (__VA_ARGS__); })
auto chmin = []<class T>(T &i, const T &j) { return i > j && (i = j, true); };
auto chmax = []<class T>(T &i, const T &j) { return i < j && (i = j, true); };
// [a, b)で乱数生成 メルセンヌツイスタ
auto random_mersenne_twister = [](int a = 1, int b = 1e5 + 1) {
    uniform_int_distribution<int> dist(a, b - 1);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    return dist(mt);
};


/** ======================================= */
/**                IO                       */
/** ======================================= */

struct IoSetup {
    IoSetup() {
        cin.tie(0)->sync_with_stdio(0);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template <typename T> istream &operator>>(istream &s, vector<T> &v) {
    for (auto &&e : v) s >> e;
    return s;
}
template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
    int i = 0;
    for (auto &&e : v) s << (i++ ? " " : "") << e;
    return s;
}
template <typename T> void print(const vector<vector<T>> &G) {
    for (auto &&v : G) cout << v << endl;
}
template <typename T, typename U> void print(const pair<T, U> &p) {
    cout << p.first << " " << p.second << endl;
}
template <typename T> void print(const T &v) {
    cout << v << endl;
}
void yn(bool o) {
    cout << (o ? "Yes" : "No") << endl;
}
void YN(bool o) {
    cout << (o ? "YES" : "NO") << endl;
}


/** ======================================= */
/**                 型                      */
/** ======================================= */

template <typename T>
using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec2 = vector<vector<T>>;
vec2<int> make_vec2(int H, int W, int init = 0) {
    return vector<vector<int>>(H, vector<int>(W, init));
}
char int_to_char(int x) {
    return (char)(x + '0');
}
char int_to_alph(int x) {
    return (char)(x + 'a');
}
int char_to_int(char c) {
    return (int)(c - '0');
}
string int_to_string(long long x) {
    return to_string(x);
}
long long string_to_int(string s) {
    return stoll(s);
}


/** ======================================= */
/**              定数                       */
/** ======================================= */

const long long INF = 1e18;
const long long MAX = 2e6;
const long long MOD = 998244353;
const long long MOD7 = 1e9 + 7;
const long double EPS = 1e-14;
const double PI = acos(-1);
// 下右上左 DRUL
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
// 8方向
const vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};

/** ======================================= */
/**              main                       */
/** ======================================= */
void solve();
signed main() {
    solve();
}
// -----------------------------------------
// #include "template/template.hpp" is done.
// -----------------------------------------

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


/**
 * @brief 文字列
 */
class String {
  public:
    bool is_low(char c) {
        return islower(c) != 0;
    }
    bool is_upp(char c) {
        return isupper(c) != 0;
    }
    // 小文字に変換
    string transform_lower(string s) {
        std::transform(all(s), s.begin(), ::tolower);
        return s;
    }
    // 大文字に変換
    string transform_upper(string s) {
        std::transform(all(s), s.begin(), ::toupper);
        return s;
    }
    // 「0000ABCDE」左側を埋めたsize桁の文字
    string lpad(const string &S, int size, char ch = '0') {
        int N = S.size();
        if (N >= size) return S;
        return string(size - N, ch) + S;
    }
    // 「ABCDE0000」右を埋めたsize桁の文字
    string rpad(const string &S, int size, char ch = '0') {
        int N = S.size();
        if (N >= size) return S;
        return S + string(size - N, ch);
    }
    /**
     * 文字列Tの中にあるSの一致場所を全て取得
     * マッチした頭のインデックスを返す
     */
    vector<int> finds(const string &T, const string &S) {
        vector<int> pos;
        auto p = T.find(S);
        while (p != string::npos) {
            pos.emplace_back(p);
            p = T.find(S, p + 1);
        }
        return pos;
    }
    // 区切り文字(1文字)で区切る
    vector<string> split(const string &S, const char &sep) {
        vector<string> res = {""};
        for (auto &&v : S) {
            if (v == sep) {
                res.emplace_back("");
            } else {
                res.back() += v;
            }
        }
        return res;
    }
    // 複数の区切り文字で区切る 区切り文字がない場合空文字
    vector<string> split_multi(const string &S, const string &seps) {
        vector<string> res = {""};
        for (auto &&v : S) {
            if (count(all(seps), v)) {
                res.emplace_back("");
            } else {
                res.back() += v;
            }
        }
        return res;
    }
    // 文字列の区間[A, B]を取得
    string str_range(const string &S, int A, int B) {
        if (A > B or A >= (int)S.size()) return "";
        return S.substr(A, B - A + 1);
    }
    // ランレングス圧縮
    vector<pair<char, int>> run_length(const string &S) {
        vector<pair<char, int>> res;
        for (auto &&x : S) {
            if (res.empty() or res.back().first != x) res.emplace_back(x, 0);
            ++res.back().second;
        }
        return res;
    }
    // Z-Algorithm: SとS[i:|S|]の最大共通接頭辞の長さ
    vector<int> z_algo(const string &S) {
        int n = S.size();
        if (n == 0) return {};
        vector<int> z(n);
        z[0] = n;
        for (int i = 1, j = 0; i < n; ++i) {
            int &k = z[i];
            k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
            while (i + k < n and S[k] == S[i + k]) ++k;
            if (j + z[j] < i + z[i]) j = i;
        }
        return z;
    }
};


/**
 * @brief 配列・数列
 */
class Sequence {
  public:
    template <typename T> T min(const vector<T> &v) {
        return *min_element(all(v));
    }
    template <typename T> T max(const vector<T> &v) {
        return *max_element(all(v));
    }
    template <typename T> long long sum(const vector<T> &v) {
        return accumulate(all(v), 0ll);
    }
    template <typename T, typename F> bool all_match(const vector<T> &v, F f) {
        return all_of(all(v), f);
    }
    template <typename T, typename F> bool none_match(const vector<T> &v, F f) {
        return none_of(all(v), f);
    }
    template <typename T, typename F> bool any_match(const vector<T> &v, F f) {
        return any_of(all(v), f);
    }
    template <typename T> void distinct(vector<T> &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }
    template <typename T> void sort_asc(vector<T> &v) {
        sort(all(v));
    }
    template <typename T> void sort_desc(vector<T> &v) {
        sort(rall(v));
    }
    template <typename T> void reverse(vector<T> &v) {
        std::reverse(all(v));
    }
    // setから要素削除
    template <typename T> void erase(set<T> &st, const T &v) {
        st.erase(st.find(v));
    }
    // multisetから要素削除
    template <typename T> void erase(multiset<T> &st, const T &v) {
        st.erase(st.find(v));
    }
    /**
     * 分割代入できるようにする Gは破壊。
     * auto [a,b] = unpack<2>(move(G));
     */
    template <int N, typename T> auto unpack(vector<T> &&G) {
        array<T, N> res; // vector -> array変換するだけ
        for (int i = 0; i < N; ++i) res[i] = move(G[i]);
        return res;
    }
    // 連番生成
    template <typename T> void renban(vector<T> &v, T start = 0) {
        iota(all(v), start);
    }
    // AをBにマージテク vector
    template <typename T> void merge(vector<T> &A, vector<T> &B) {
        if (A.size() > B.size()) swap(A, B);
        for (auto &&v : A) B.push_back(v);
        A.clear();
    }
    // AをBにマージテク set
    template <typename T> void merge(set<T> &A, set<T> &B) {
        if (A.size() > B.size()) swap(A, B);
        for (auto &&v : A) B.insert(v);
        A.clear();
    }
    // AをBにマージテク マージ操作をラムダ化
    template <typename T, typename F> void merge(T &A, T &B, F f) {
        if (A.size() > B.size()) swap(A, B);
        for (auto &&v : A) {
            f(B, v);
        }
        A.clear();
    }
    // 数直線上での個数になおす
    vector<int> coordinate(const vector<int> &A) {
        vector<int> res(MAX);
        for (auto &&v : A) ++res[v];
        return res;
    }
    // 座標圧縮 圧縮後の種類数を返却
    template <typename T> int zip_coordinate(vector<T> &A) {
        vector<T> cvt = A;
        distinct(cvt);
        for (auto &v : A) v = lower_bound(all(cvt), v) - cvt.begin();
        return (int)cvt.size();
    }
    // 転倒数 右に倒れるA_i > A_j (i < j)の回数
    template <typename T> long long inversion_number(vector<T> &A) {
        int sz = zip_coordinate(A);
        vector<int> fwk(sz + 1);
        long long inv = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int f = sz; f; f -= f & -f) inv += fwk[f];
            for (int f = A[i] + 1; f; f -= f & -f) inv -= fwk[f];
            for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];
        }
        return inv;
    }
    // 累積和 S[i]=Σ(0,i-1)  Σ[l,r)=S[r]-S[l]
    template <typename T> vector<long long> zeta(const vector<T> &A) {
        int N = A.size();
        vector<long long> S(N + 1);
        for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];
        return S;
    }
    // 反転累積和 S[i]=Aiから右全部  Σ(0,i-1)+Σ(i,last)=S[i]+R[i]
    template <typename T> vector<long long> zeta_rev(const vector<T> &A) {
        int N = A.size();
        vector<long long> R(N + 1);
        for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] + A[i];
        return R;
    }
    // 二項差での累積和 S[i]=Σ(0,i-1)  Σ[l,r)=S[r]-S[l]
    template <typename T> vector<long long> zeta_diff(const vector<T> &A) {
        int N = A.size();
        vector<long long> S(N + 1);
        for (int i = 0; i < N; ++i) {
            S[i + 1] = S[i];
            if (i & 1) S[i + 1] += abs(A[i] - A[i - 1]);
        }
        return S;
    }
    // 二項差での反転累積和 S[i]=Aiから右全部  Σ(0,i-1)+Σ(i,last)=S[i]+R[i]
    template <typename T> vector<long long> zeta_rev_diff(const vector<T> &A) {
        int N = A.size();
        vector<long long> R(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            R[i] = R[i + 1];
            if (i & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) - A[i]);
        }
        return R;
    }
    /**
     * 2次元平面での累積和
     * 包除: (s,t)~(x,y) = S[y][x]-S[y][s]-S[t][x]+S[t][s]
     */
    template <typename T>
    vector<vector<long long>> zeta_2D(const vector<T> &G) {
        int H = G.size(), W = G[0].size();
        vector<vector<long long>> S(H + 1, vector<long long>(W + 1));
        for (int i = 0; i < H; ++i) { // 横向き
            for (int j = 0; j < W; ++j) {
                S[i + 1][j + 1] = S[i + 1][j] + G[i][j];
            }
        }
        for (int i = 0; i < H; ++i) { // 縦向き
            for (int j = 0; j < W; ++j) {
                S[i + 1][j + 1] += S[i][j + 1];
            }
        }
        return S;
    }
    /**
     * 3次元累積和
     * ex) Lx Ly Lzは0-indexed Rx Ry Rzは1-indexed
     *   S[Rxyz] - S[Lxyz]
     *          = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] - S[Rx][Ly][Rz] -
     *            S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz] +
     *            S[Rx][Ly][Lz] - S[Lx][Ly][Lz];
     */
    template <typename T>
    vector<vector<vector<long long>>>
    zeta_3D(const vector<vector<vector<T>>> &A) {
        vector<vector<vector<long long>>> S;
        int szx = A.size(), szy = A[0].size(), szz = A[0][0].size();
        S.resize(szx + 1, vector<vector<long long>>(
                              szy + 1, vector<long long>(szz + 1, 0)));
        for (int x = 1; x <= szx; ++x) {
            for (int y = 1; y <= szy; ++y) {
                for (int z = 1; z <= szz; ++z) {
                    S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +
                                 S[x][y - 1][z] + S[x][y][z - 1] -
                                 S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -
                                 S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];
                }
            }
        }
        return S;
    }
    // 各項の差の数列 メビウス変換
    template <typename T> vector<long long> moebius(const vector<T> &A) {
        int N = A.size();
        vector<long long> D(N - 1);
        for (int i = 0; i < N; ++i) D[i] = A[i + 1] - A[i];
        return D;
    }
};


/**
 * @brief 探索
 */
class Search {
  public:
    /**
     * 順列全探索 O(N!) Nは10〜12程度
     * 順列の全パターン中でやりたい関数を入れる
     * 例) search_permu(A, [&](){cout << A;} );
     */
    template <typename T, typename F> void perm(vector<T> &A, F f) {
        sort(all(A));
        do {
            f();
        } while (next_permutation(all(A)));
    }
    /**
     * bit全探索 O(2^N) Nは20前後
     * 集合Aの全パターンの部分集合を返す
     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }
     */
    template <typename T> vector<vector<T>> bit(vector<T> &A) {
        int N = A.size();
        vector<vector<T>> res;
        for (long long bit = 0; bit < (1ll << N); ++bit) {
            vector<T> tmp;
            for (int k = 0; k < N; ++k) {
                if (bit & (1ll << k)) {
                    tmp.push_back(A[k]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
    /**
     * 整数上の二分探索
     *     L R
     * x x x o o o o
     *       ↑ここを求める
     * 条件：5 <= xなら、L=4, R=5
     */
    template <typename F> pair<long long, long long> bi(F f) {
        long long L = 0, R = 1, MID = 0;
        while (!f(R)) R <<= 1;
        while (abs(R - L) > 1) {
            MID = L + (R - L) / 2;
            (f(MID) ? R : L) = MID;
        }
        return make_pair(L, R);
    }
    /**
     * 実数上の二分探索
     *     L R
     * x x x o o o o
     *       ↑ここを求める
     * 条件：3.5 <= xなら、L=3.5, R=3.5 (LRの誤差がEPS内)
     */
    template <typename F> pair<double, double> bi_real(F f) {
        double L = 0, R = 1, MID = 0;
        while (!f(R)) R *= 2;
        auto ABS = [&]() { return abs(R - L) > EPS; };
        auto REL = [&]() { return abs(R - L) / max(R, L) > EPS; };
        while (ABS() and REL()) {
            MID = L + (R - L) / 2;
            (f(MID) ? R : L) = MID;
        }
        return make_pair(L, R);
    }
    // 以下の要素数
    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return upper_bound(all(v), x) - v.begin();
    }
    // 以下の値 存在しない場合-INF
    template <typename T> T bi_le_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = upper_bound(all(v), x);
        return (it == v.begin() ? -INF : *--it);
    }
    // 以下の値  存在しない場合-INF
    template <typename T> T bi_le_val(const set<T> &st, const T &x) {
        auto it = st.upper_bound(x);
        return (it == st.begin() ? -INF : *--it);
    }
    // 以上の要素数
    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return v.end() - lower_bound(all(v), x);
    }
    // 以上の最小値 存在しない場合 INF
    template <typename T> T bi_ge_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = lower_bound(all(v), x);
        return (it == v.end() ? INF : *it);
    }
    // 以上の最小値 存在しない場合 INF
    template <typename T> T bi_ge_val(const set<T> &st, const T &x) {
        auto it = st.lower_bound(x);
        return (it == st.end() ? INF : *it);
    }
    // 未満の要素数
    template <typename T> int bi_lt_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return lower_bound(all(v), x) - v.begin();
    }
    // 未満の最大値 存在しない場合 -INF
    template <typename T> T bi_lt_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = lower_bound(all(v), x);
        return (it == v.begin() ? -INF : *--it);
    }
    // 未満の最大値 存在しない場合 -INF
    template <typename T> T bi_lt_val(const set<T> &st, const T &x) {
        auto it = st.lower_bound(x);
        return (it == st.begin() ? -INF : *--it);
    }
    // より上の要素数
    template <typename T> int bi_gt_cnt(vector<T> &v, const T &x) {
        sort(all(v));
        return v.end() - upper_bound(all(v), x);
    }
    // より上の最小値 存在しない場合 INF
    template <typename T> T bi_gt_val(vector<T> &v, const T &x) {
        sort(all(v));
        auto it = upper_bound(all(v), x);
        return (it == v.end() ? INF : *it);
    }
    // より上の最小値 存在しない場合 INF
    template <typename T> T bi_gt_val(const set<T> &st, const T &x) {
        auto it = st.upper_bound(x);
        return (it == st.end() ? INF : *it);
    }
    // メモ化再帰 !!コピペ用!! 関数内をペーストして書き換えて使う
    void dfs_memo() {
        map<int, int> memo;
        auto dfs = [&](auto f, int n) {
            if (n <= 1) return n;
            if (memo.count(n)) return memo[n];
            return memo[n] = f(f, n - 1) + f(f, n - 2);
        };
        (void)dfs; // unused
        // int ans = dfs(dfs, N);
    }
};


/**
 * @brief グリッド
 */
class Grid {
  public:
    // 行列の転置
    template <typename T>
    vector<vector<T>> transpose(const vector<vector<T>> &G) {
        int H = G.size(), W = G[0].size();
        vector<vector<T>> _G(W, vector<T>(H));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                _G[j][i] = G[i][j];
            }
        }
        return _G;
    }
    // グリッド4方を見るBFS 引数f(y, x)
    template <typename T, typename F> void bfs(vector<vector<T>> &G, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int y = i + dy[k], x = j + dx[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    f(y, x);
                }
            }
        }
    }
    // グリッド8方を見るBFS 引数f(y, x)
    template <typename T, typename F> void bfs8(vector<vector<T>> &G, F f) {
        int H = G.size(), W = G[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 8; ++k) {
                    int y = i + dy8[k], x = j + dx8[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) continue;
                    f(y, x);
                }
            }
        }
    }
};


/**
 * @brief 幾何
 */
class Geometry {
  public:
    // 度数法 → 弧度法
    double deg_to_rad(double d) {
        return d * PI / 180;
    }
    // 弧度法 → 度数法
    double rad_to_deg(double r) {
        return r * 180 / PI;
    }
    // 偏角をラジアンで返す
    double arc_tan(double x, double y) {
        return atan2(y, x);
    }
    /**
     * 三角形の面積
     * doubleは桁数表現11bitを除き、52bit程度の精度
     * 18桁使うなら2で割らずlong longで返すこと
     */
    template <typename T>
    double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {
        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
    }
    /**
     * 四角形の面積
     * doubleは桁数表現11bitを除き、52bit程度の精度
     * 18桁使うなら2で割らずlong longで返すこと
     */
    template <typename T>
    double area_square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
        return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;
    }
};

/**
 * @brief util系
 */
namespace lib {
Number num;
String str;
Sequence seq;
Search search;
Grid grid;
Geometry geo;
}; // namespace lib
// -----------------------------------------
// #include "template/lib.hpp" is done.
// -----------------------------------------


// #include "library/struct/graph.hpp"
// #include "library/struct/union_find.hpp"
// #include "library/struct/fenwick_tree.hpp"
// #include "library/struct/monoid.hpp"
// #include "library/struct/segment_tree.hpp"
// #include "library/struct/dual_segment_tree.hpp"
// #include "library/struct/lazy_segment_tree.hpp"
/**
 * @brief 🍪🧸🐾
 */
void solve() {
}

