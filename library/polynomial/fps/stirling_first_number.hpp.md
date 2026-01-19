---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/montgomery_mod_int.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/convolution_arbitrary_mod.hpp
    title: "\u7573\u307F\u8FBC\u307F \u4EFB\u610FMOD"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fps/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fps.stirling_first_number.test.cpp
    title: "\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u30C6\
      \u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/polynomial/fps/formal_power_series.hpp\"\n#include\
    \ <functional>\n#line 2 \"library/number/mod/montgomery_mod_int.hpp\"\ntemplate\
    \ <uint32_t mod_, bool fast = false>\nstruct MontgomeryModInt {\n  private:\n\
    \    using mint = MontgomeryModInt;\n    using i32 = int32_t;\n    using i64 =\
    \ int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    static constexpr\
    \ u32 get_r() {\n        u32 ret = mod_;\n        for (i32 i = 0; i < 4; i++)\
    \ ret *= 2 - mod_ * ret;\n        return ret;\n    }\n    static constexpr u32\
    \ r = get_r();\n    static constexpr u32 n2 = -u64(mod_) % mod_;\n    static_assert(r\
    \ * mod_ == 1, \"invalid, r * mod != 1\");\n    static_assert(mod_ < (1 << 30),\
    \ \"invalid, mod >= 2 ^ 30\");\n    static_assert((mod_ & 1) == 1, \"invalid,\
    \ mod % 2 == 0\");\n    u32 x;\n  public:\n    MontgomeryModInt() : x{} {}\n \
    \   MontgomeryModInt(const i64 &a) : x(reduce(u64(fast ? a : (a % mod() + mod()))\
    \ * n2)) {}\n    static constexpr u32 reduce(const u64 &b) {\n        return u32(b\
    \ >> 32) + mod() - u32((u64(u32(b) * r) * mod()) >> 32);\n    }\n    mint &operator+=(const\
    \ mint &p) {\n        if (i32(x += p.x - 2 * mod()) < 0) x += 2 * mod();\n   \
    \     return *this;\n    }\n    mint &operator-=(const mint &p) {\n        if\
    \ (i32(x -= p.x) < 0) x += 2 * mod();\n        return *this;\n    }\n    mint\
    \ &operator*=(const mint &p) {\n        x = reduce(u64(x) * p.x);\n        return\
    \ *this;\n    }\n    mint &operator/=(const mint &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n    mint operator-() const { return mint() - *this;\
    \ }\n    mint operator+(const mint &p) const { return mint(*this) += p; }\n  \
    \  mint operator-(const mint &p) const { return mint(*this) -= p; }\n    mint\
    \ operator*(const mint &p) const { return mint(*this) *= p; }\n    mint operator/(const\
    \ mint &p) const { return mint(*this) /= p; }\n    bool operator==(const mint\
    \ &p) const {\n        return (x >= mod() ? x - mod() : x) == (p.x >= mod() ?\
    \ p.x - mod() : p.x);\n    }\n    bool operator!=(const mint &p) const {\n   \
    \     return (x >= mod() ? x - mod() : x) != (p.x >= mod() ? p.x - mod() : p.x);\n\
    \    }\n    u32 val() const {\n        u32 ret = reduce(x);\n        return ret\
    \ >= mod() ? ret - mod() : ret;\n    }\n    mint pow(u64 n) const {\n        mint\
    \ ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1) ret *=\
    \ mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n    mint inv() const { return pow(mod() - 2); }\n    friend ostream\
    \ &operator<<(ostream &os, const mint &p) {\n        return os << p.val();\n \
    \   }\n    friend istream &operator>>(istream &is, mint &a) {\n        i64 t;\n\
    \        is >> t;\n        a = mint(t);\n        return is;\n    }\n    static\
    \ constexpr u32 mod() { return mod_; }\n};\ntemplate <uint32_t mod>\nusing modint\
    \ = MontgomeryModInt<mod>;\nusing modint998244353 = modint<998244353>;\nusing\
    \ modint1000000007 = modint<1000000007>;\n#line 2 \"library/polynomial/fft/fast_fourier_transform.hpp\"\
    \nnamespace FFT {\nusing real = double;\nstruct C {\n    real x, y;\n    C() :\
    \ x(0), y(0) {};\n    C(real x, real y) : x(x), y(y) {};\n    inline C operator+(const\
    \ C &c) const {\n        return C(x + c.x, y + c.y);\n    }\n    inline C operator-(const\
    \ C &c) const {\n        return C(x - c.x, y - c.y);\n    }\n    inline C operator*(const\
    \ C &c) const {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n   \
    \ }\n    inline C conj() const {\n        return C(x, -y);\n    }\n};\nconst real\
    \ PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int>\
    \ rev = {0, 1};\nvoid ensure_base(int nbase) {\n    if (nbase <= base) return;\n\
    \    rev.resize(1 << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0;\
    \ i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n    }\n    while (base < nbase) {\n        real angle = PI *\
    \ 2.0 / (1 << (base + 1));\n        for (int i = 1 << (base - 1); i < (1 << base);\
    \ i++) {\n            rts[i << 1] = rts[i];\n            real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n        }\n        ++base;\n    }\n}\nvoid fft(vector<C> &a,\
    \ int n) {\n    assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);\n\
    \    }\n    for (int k = 1; k < n; k <<= 1) {\n        for (int i = 0; i < n;\
    \ i += 2 * k) {\n            for (int j = 0; j < k; j++) {\n                C\
    \ z = a[i + j + k] * rts[j + k];\n                a[i + j + k] = a[i + j] - z;\n\
    \                a[i + j] = a[i + j] + z;\n            }\n        }\n    }\n}\n\
    } // namespace FFT\n#line 4 \"library/polynomial/fft/convolution_arbitrary_mod.hpp\"\
    \ntemplate <typename T>\nstruct ConvolutionArbitraryMod {\n    using real = FFT::real;\n\
    \    using C = FFT::C;\n    ConvolutionArbitraryMod() = default;\n    static vector<T>\
    \ multiply(const vector<T>& a, const vector<T>& b, int need = -1) {\n        if\
    \ (need == -1) need = a.size() + b.size() - 1;\n        int nbase = 0;\n     \
    \   while ((1 << nbase) < need) nbase++;\n        FFT::ensure_base(nbase);\n \
    \       int sz = 1 << nbase;\n        vector<C> fa(sz);\n        for (int i =\
    \ 0; i < (int)a.size(); i++) {\n            fa[i] = C(a[i].val() & ((1 << 15)\
    \ - 1), a[i].val() >> 15);\n        }\n        fft(fa, sz);\n        vector<C>\
    \ fb(sz);\n        if (a == b) {\n            fb = fa;\n        } else {\n   \
    \         for (int i = 0; i < (int)b.size(); i++) {\n                fb[i] = C(b[i].val()\
    \ & ((1 << 15) - 1), b[i].val() >> 15);\n            }\n            fft(fb, sz);\n\
    \        }\n        real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0),\
    \ r4(0, -ratio), r5(0, 1);\n        for (int i = 0; i <= (sz >> 1); i++) {\n \
    \           int j = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n\
    \            C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] +\
    \ fb[j].conj()) * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n     \
    \       if (i != j) {\n                C c1 = (fa[j] + fa[i].conj());\n      \
    \          C c2 = (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j]\
    \ + fb[i].conj()) * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n\
    \                fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 *\
    \ d2 + c2 * d1;\n            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n\
    \            fb[j] = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n   \
    \     fft(fb, sz);\n        vector<T> ret(need);\n        for (int i = 0; i <\
    \ need; i++) {\n            int64_t aa = llround(fa[i].x);\n            int64_t\
    \ bb = llround(fb[i].x);\n            int64_t cc = llround(fa[i].y);\n       \
    \     aa = T(aa).val(), bb = T(bb).val(), cc = T(cc).val();\n            ret[i]\
    \ = aa + (bb << 15) + (cc << 30);\n        }\n        return ret;\n    }\n};\n\
    #line 4 \"library/polynomial/fps/formal_power_series.hpp\"\ntemplate <typename\
    \ T>\nstruct FormalPowerSeries : vector<T> {\n    using vector<T>::vector;\n \
    \   using P = FormalPowerSeries;\n    using Conv = ConvolutionArbitraryMod<T>;\n\
    \    P pre(int deg) const {\n        return P(begin(*this), begin(*this) + min((int)this->size(),\
    \ deg));\n    }\n    P rev(int deg = -1) const {\n        P ret(*this);\n    \
    \    if (deg != -1) ret.resize(deg, T(0));\n        reverse(begin(ret), end(ret));\n\
    \        return ret;\n    }\n    void shrink() {\n        while (this->size()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n    P operator+(const P &r)\
    \ const { return P(*this) += r; }\n    P operator+(const T &v) const { return\
    \ P(*this) += v; }\n    P operator-(const P &r) const { return P(*this) -= r;\
    \ }\n    P operator-(const T &v) const { return P(*this) -= v; }\n    P operator*(const\
    \ P &r) const { return P(*this) *= r; }\n    P operator*(const T &v) const { return\
    \ P(*this) *= v; }\n    P operator/(const P &r) const { return P(*this) /= r;\
    \ }\n    P operator%(const P &r) const { return P(*this) %= r; }\n    P &operator+=(const\
    \ P &r) {\n        if (r.size() > this->size()) this->resize(r.size());\n    \
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n    P &operator-=(const P &r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (int i = 0; i < (int)r.size(); i++) (*this)[i]\
    \ -= r[i];\n        return *this;\n    }\n    // https://judge.yosupo.jp/problem/convolution_mod\n\
    \    P &operator*=(const P &r) {\n        if (this->empty() || r.empty()) {\n\
    \            this->clear();\n            return *this;\n        }\n        auto\
    \ ret = Conv::multiply(*this, r);\n        return *this = {begin(ret), end(ret)};\n\
    \    }\n    P &operator/=(const P &r) {\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  int n = this->size() - r.size() + 1;\n        return *this = (rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev(n);\n    }\n    P &operator%=(const P &r) { return\
    \ *this -= *this / r * r; }\n    // https://judge.yosupo.jp/problem/division_of_polynomials\n\
    \    pair<P, P> div_mod(const P &r) {\n        P q = *this / r;\n        return\
    \ make_pair(q, *this - q * r);\n    }\n    P operator-() const {\n        P ret(this->size());\n\
    \        for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n \
    \       return ret;\n    }\n    P &operator+=(const T &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n \
    \   P &operator-=(const T &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] -= r;\n        return *this;\n    }\n    P &operator*=(const\
    \ T &v) {\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= v;\n\
    \        return *this;\n    }\n    P dot(P r) const {\n        P ret(min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n    P operator>>(int sz) const {\n    \
    \    if (this->size() <= sz) return {};\n        P ret(*this);\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\n        return ret;\n    }\n    P operator<<(int sz) const\
    \ {\n        P ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n     \
    \   return ret;\n    }\n    T operator()(T x) const {\n        T r = 0, w = 1;\n\
    \        for (auto &v : *this) {\n            r += w * v;\n            w *= x;\n\
    \        }\n        return r;\n    }\n    P diff() const {\n        const int\
    \ n = (int)this->size();\n        P ret(max(0ll, n - 1));\n        for (int i\
    \ = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return ret;\n    }\n\
    \    P integral() const {\n        const int n = (int)this->size();\n        P\
    \ ret(n + 1);\n        ret[0] = T(0);\n        for (int i = 0; i < n; i++) ret[i\
    \ + 1] = (*this)[i] / T(i + 1);\n        return ret;\n    }\n    // https://judge.yosupo.jp/problem/inv_of_formal_power_series\n\
    \    // F(0) must not be 0\n    P inv(int deg = -1) const {\n        assert(((*this)[0])\
    \ != T(0));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        P ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg;\
    \ i <<= 1) {\n            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i <<\
    \ 1);\n        }\n        return ret.pre(deg);\n    }\n    // https://judge.yosupo.jp/problem/log_of_formal_power_series\n\
    \    // F(0) must be 1\n    P log(int deg = -1) const {\n        assert((*this)[0]\
    \ == T(1));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \    }\n    // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\n \
    \   P sqrt(\n        int deg = -1,\n        const function<T(T)> &get_sqrt = [](T)\
    \ { return T(1); }) const {\n        const int n = (int)this->size();\n      \
    \  if (deg == -1) deg = n;\n        if ((*this)[0] == T(0)) {\n            for\
    \ (int i = 1; i < n; i++) {\n            if ((*this)[i] != T(0)) {\n         \
    \       if (i & 1) return {};\n                if (deg - i / 2 <= 0) break;\n\
    \                auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);\n      \
    \          if (ret.empty()) return {};\n                ret = ret << (i / 2);\n\
    \                if (ret.size() < deg) ret.resize(deg, T(0));\n              \
    \  return ret;\n            }\n            }\n            return P(deg, 0);\n\
    \        }\n        auto sqr = T(get_sqrt((*this)[0]));\n        if (sqr * sqr\
    \ != (*this)[0]) return {};\n        P ret{sqr};\n        T inv2 = T(1) / T(2);\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret + pre(i <<\
    \ 1) * ret.inv(i << 1)) * inv2;\n        }\n        return ret.pre(deg);\n   \
    \ }\n    P sqrt(const function<T(T)> &get_sqrt, int deg = -1) const {\n      \
    \  return sqrt(deg, get_sqrt);\n    }\n    // https://judge.yosupo.jp/problem/exp_of_formal_power_series\n\
    \    // F(0) must be 0\n    P exp(int deg = -1) const {\n        if (deg == -1)\
    \ deg = this->size();\n        assert((*this)[0] == T(0));\n        const int\
    \ n = (int)this->size();\n        if (deg == -1) deg = n;\n        P ret({T(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (pre(i\
    \ << 1) + T(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n    // https://judge.yosupo.jp/problem/pow_of_formal_power_series\n  \
    \  P pow(int64_t k, int deg = -1) const {\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        if (k == 0) {\n            P ret(deg,\
    \ T(0));\n            ret[0] = T(1);\n            return ret;\n        }\n   \
    \     for (int i = 0; i < n; i++) {\n            if (i * k > deg) return P(deg,\
    \ T(0));\n            if ((*this)[i] != T(0)) {\n            T rev = T(1) / (*this)[i];\n\
    \            P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \            ret = (ret << (i * k)).pre(deg);\n            if (ret.size() < deg)\
    \ ret.resize(deg, T(0));\n            return ret;\n            }\n        }\n\
    \        return *this;\n    }\n    // https://yukicoder.me/problems/no/215\n \
    \   P mod_pow(int64_t k, P g) const {\n        P modinv = g.rev().inv();\n   \
    \     auto get_div = [&](P base) {\n            if (base.size() < g.size()) {\n\
    \            base.clear();\n            return base;\n            }\n        \
    \    int n = base.size() - g.size() + 1;\n            return (base.rev().pre(n)\
    \ * modinv.pre(n)).pre(n).rev(n);\n        };\n        P x(*this), ret{1};\n \
    \       while (k > 0) {\n            if (k & 1) {\n            ret *= x;\n   \
    \         ret -= get_div(ret) * g;\n            ret.shrink();\n            }\n\
    \            x *= x;\n            x -= get_div(x) * g;\n            x.shrink();\n\
    \            k >>= 1;\n        }\n        return ret;\n    }\n    // https://judge.yosupo.jp/problem/polynomial_taylor_shift\n\
    \    P taylor_shift(T c) const {\n        int n = (int)this->size();\n       \
    \ vector<T> fact(n), rfact(n);\n        fact[0] = rfact[0] = T(1);\n        for\
    \ (int i = 1; i < n; i++) fact[i] = fact[i - 1] * T(i);\n        rfact[n - 1]\
    \ = T(1) / fact[n - 1];\n        for (int i = n - 1; i > 1; i--) rfact[i - 1]\
    \ = rfact[i] * T(i);\n        P p(*this);\n        for (int i = 0; i < n; i++)\
    \ p[i] *= fact[i];\n        p = p.rev();\n        P bs(n, T(1));\n        for\
    \ (int i = 1; i < n; i++) bs[i] = bs[i - 1] * c * rfact[i] * fact[i - 1];\n  \
    \      p = (p * bs).pre(n);\n        p = p.rev();\n        for (int i = 0; i <\
    \ n; i++) p[i] *= rfact[i];\n        return p;\n    }\n};\ntemplate <typename\
    \ Mint>\nusing FPS = FormalPowerSeries<Mint>;\n#line 3 \"library/polynomial/fps/stirling_first_number.hpp\"\
    \ntemplate <template <typename> class FPS, typename Mint>\nFPS<Mint> stirling_first_number(int\
    \ N) {\n    if (N <= 0) return {Mint(1)};\n    auto f = stirling_first_number<FPS,\
    \ Mint>(N >> 1);\n    f *= f.taylor_shift(-(N >> 1));\n    if (N & 1) f = (f <<\
    \ 1) - f * (N - 1);\n    return f;\n}\n"
  code: "#pragma once\n#include \"library/polynomial/fps/formal_power_series.hpp\"\
    \ntemplate <template <typename> class FPS, typename Mint>\nFPS<Mint> stirling_first_number(int\
    \ N) {\n    if (N <= 0) return {Mint(1)};\n    auto f = stirling_first_number<FPS,\
    \ Mint>(N >> 1);\n    f *= f.taylor_shift(-(N >> 1));\n    if (N & 1) f = (f <<\
    \ 1) - f * (N - 1);\n    return f;\n}\n"
  dependsOn:
  - library/polynomial/fps/formal_power_series.hpp
  - library/polynomial/fft/convolution_arbitrary_mod.hpp
  - library/number/mod/montgomery_mod_int.hpp
  - library/polynomial/fft/fast_fourier_transform.hpp
  isVerificationFile: false
  path: library/polynomial/fps/stirling_first_number.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.fps.stirling_first_number.test.cpp
documentation_of: library/polynomial/fps/stirling_first_number.hpp
layout: document
title: "\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
---

# 第一種スターリング数

## できること
- 入力Nに対し、 $k (0 \le k \le N)$についての第一種スターリング数 $\lbrack {}^n_k \rbrack$ を求める
- 戻り値のFPSの各次数がkに対応する
- 組み合わせ的に、`N人`を`K個の円卓`に座らせる方法の数
- 第二種の逆で $\lbrack {}^n_k \rbrack$ は 下降階乗を $x^n$ に展開する際の係数として現れる
  - $x(x-1) \cdots (x-k+1) = \displaystyle\sum_{k=0}^{n} (-1)^{n-k} \lbrack {}^n_k \rbrack x^k $

## 計算量
$O(NlogN)$

## 使い方
```cpp
using mint = modint998244353;
cout << stirling_first_number<FPS, mint>(N);
```

