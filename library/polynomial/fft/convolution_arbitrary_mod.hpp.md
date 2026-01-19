---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/number/mod/montgomery_mod_int.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/polynomial/fps/bernoulli_number.hpp
    title: library/polynomial/fps/bernoulli_number.hpp
  - icon: ':warning:'
    path: library/polynomial/fps/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':warning:'
    path: library/polynomial/fps/stirling_first_number.hpp
    title: library/polynomial/fps/stirling_first_number.hpp
  - icon: ':warning:'
    path: library/polynomial/fps/stirling_second_number.hpp
    title: library/polynomial/fps/stirling_second_number.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/number/mod/montgomery_mod_int.hpp\"\ntemplate <uint32_t\
    \ mod_, bool fast = false>\nstruct MontgomeryModInt {\n  private:\n    using mint\
    \ = MontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n  \
    \  using u32 = uint32_t;\n    using u64 = uint64_t;\n    static constexpr u32\
    \ get_r() {\n        u32 ret = mod_;\n        for (i32 i = 0; i < 4; i++) ret\
    \ *= 2 - mod_ * ret;\n        return ret;\n    }\n    static constexpr u32 r =\
    \ get_r();\n    static constexpr u32 n2 = -u64(mod_) % mod_;\n    static_assert(r\
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
    \ 0; i < a.size(); i++) {\n            fa[i] = C(a[i].val() & ((1 << 15) - 1),\
    \ a[i].val() >> 15);\n        }\n        fft(fa, sz);\n        vector<C> fb(sz);\n\
    \        if (a == b) {\n            fb = fa;\n        } else {\n            for\
    \ (int i = 0; i < b.size(); i++) {\n                fb[i] = C(b[i].val() & ((1\
    \ << 15) - 1), b[i].val() >> 15);\n            }\n            fft(fb, sz);\n \
    \       }\n        real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0),\
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
    \ = aa + (bb << 15) + (cc << 30);\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"library/number/mod/montgomery_mod_int.hpp\"\n#include\
    \ \"library/polynomial/fft/fast_fourier_transform.hpp\"\ntemplate <typename T>\n\
    struct ConvolutionArbitraryMod {\n    using real = FFT::real;\n    using C = FFT::C;\n\
    \    ConvolutionArbitraryMod() = default;\n    static vector<T> multiply(const\
    \ vector<T>& a, const vector<T>& b, int need = -1) {\n        if (need == -1)\
    \ need = a.size() + b.size() - 1;\n        int nbase = 0;\n        while ((1 <<\
    \ nbase) < need) nbase++;\n        FFT::ensure_base(nbase);\n        int sz =\
    \ 1 << nbase;\n        vector<C> fa(sz);\n        for (int i = 0; i < a.size();\
    \ i++) {\n            fa[i] = C(a[i].val() & ((1 << 15) - 1), a[i].val() >> 15);\n\
    \        }\n        fft(fa, sz);\n        vector<C> fb(sz);\n        if (a ==\
    \ b) {\n            fb = fa;\n        } else {\n            for (int i = 0; i\
    \ < b.size(); i++) {\n                fb[i] = C(b[i].val() & ((1 << 15) - 1),\
    \ b[i].val() >> 15);\n            }\n            fft(fb, sz);\n        }\n   \
    \     real ratio = 0.25 / sz;\n        C r2(0, -1), r3(ratio, 0), r4(0, -ratio),\
    \ r5(0, 1);\n        for (int i = 0; i <= (sz >> 1); i++) {\n            int j\
    \ = (sz - i) & (sz - 1);\n            C a1 = (fa[i] + fa[j].conj());\n       \
    \     C a2 = (fa[i] - fa[j].conj()) * r2;\n            C b1 = (fb[i] + fb[j].conj())\
    \ * r3;\n            C b2 = (fb[i] - fb[j].conj()) * r4;\n            if (i !=\
    \ j) {\n                C c1 = (fa[j] + fa[i].conj());\n                C c2 =\
    \ (fa[j] - fa[i].conj()) * r2;\n                C d1 = (fb[j] + fb[i].conj())\
    \ * r3;\n                C d2 = (fb[j] - fb[i].conj()) * r4;\n               \
    \ fa[i] = c1 * d1 + c2 * d2 * r5;\n                fb[i] = c1 * d2 + c2 * d1;\n\
    \            }\n            fa[j] = a1 * b1 + a2 * b2 * r5;\n            fb[j]\
    \ = a1 * b2 + a2 * b1;\n        }\n        fft(fa, sz);\n        fft(fb, sz);\n\
    \        vector<T> ret(need);\n        for (int i = 0; i < need; i++) {\n    \
    \        int64_t aa = llround(fa[i].x);\n            int64_t bb = llround(fb[i].x);\n\
    \            int64_t cc = llround(fa[i].y);\n            aa = T(aa).val(), bb\
    \ = T(bb).val(), cc = T(cc).val();\n            ret[i] = aa + (bb << 15) + (cc\
    \ << 30);\n        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - library/number/mod/montgomery_mod_int.hpp
  - library/polynomial/fft/fast_fourier_transform.hpp
  isVerificationFile: false
  path: library/polynomial/fft/convolution_arbitrary_mod.hpp
  requiredBy:
  - library/polynomial/fps/stirling_second_number.hpp
  - library/polynomial/fps/stirling_first_number.hpp
  - library/polynomial/fps/bernoulli_number.hpp
  - library/polynomial/fps/formal_power_series.hpp
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/fft/convolution_arbitrary_mod.hpp
layout: document
title: "\u7573\u307F\u8FBC\u307F \u4EFB\u610FMOD"
---

# 畳み込み 任意MOD

## できること
- 任意の法において、2つの多項式の積を計算する

## 計算量
$O(NlogN)$

## 使い方
```cpp
// 法を設定: ライブラリ「montgomery_mod_int.hpp」を使用している
using mint = modint<MOD>;
//using mint = modint998244353; // 用意済みのものでもOK

// 1. 多項式の係数を用意
ConvolutionArbitraryMod<mint> fft;
vector<mint> a = {1, 2, 3}; // 1 + 2x + 3x^2
vector<mint> b = {4, 5};    // 4 + 5x

// 2. 畳み込み実行
// (1+2x+3x^2)(4+5x) = 4 + 13x + 22x^2 + 15x^3
vector<mint> result = fft.multiply(a, b);
// 結果: 4 13 22 15
```

