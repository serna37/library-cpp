---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/convolution_arbitrary_mod.hpp
    title: "\u7573\u307F\u8FBC\u307F \u4EFB\u610FMOD"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fps/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fps/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fps/stirling_first_number.hpp
    title: "\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fps/stirling_second_number.hpp
    title: "\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_and.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FAND\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_or.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FOR\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fft.convolution_bitwise_xor.test.cpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FXOR\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fps.bernoulli_number.test.cpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fps.stirling_first_number.test.cpp
    title: "\u7B2C\u4E00\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/polynomial.fps.stirling_second_number.test.cpp
    title: "\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u30C6\
      \u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ modint1000000007 = modint<1000000007>;\n"
  code: "#pragma once\ntemplate <uint32_t mod_, bool fast = false>\nstruct MontgomeryModInt\
    \ {\n  private:\n    using mint = MontgomeryModInt;\n    using i32 = int32_t;\n\
    \    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    static constexpr u32 get_r() {\n        u32 ret = mod_;\n        for (i32\
    \ i = 0; i < 4; i++) ret *= 2 - mod_ * ret;\n        return ret;\n    }\n    static\
    \ constexpr u32 r = get_r();\n    static constexpr u32 n2 = -u64(mod_) % mod_;\n\
    \    static_assert(r * mod_ == 1, \"invalid, r * mod != 1\");\n    static_assert(mod_\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((mod_ & 1) == 1,\
    \ \"invalid, mod % 2 == 0\");\n    u32 x;\n  public:\n    MontgomeryModInt() :\
    \ x{} {}\n    MontgomeryModInt(const i64 &a) : x(reduce(u64(fast ? a : (a % mod()\
    \ + mod())) * n2)) {}\n    static constexpr u32 reduce(const u64 &b) {\n     \
    \   return u32(b >> 32) + mod() - u32((u64(u32(b) * r) * mod()) >> 32);\n    }\n\
    \    mint &operator+=(const mint &p) {\n        if (i32(x += p.x - 2 * mod())\
    \ < 0) x += 2 * mod();\n        return *this;\n    }\n    mint &operator-=(const\
    \ mint &p) {\n        if (i32(x -= p.x) < 0) x += 2 * mod();\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &p) {\n        x = reduce(u64(x) * p.x);\n\
    \        return *this;\n    }\n    mint &operator/=(const mint &p) {\n       \
    \ *this *= p.inv();\n        return *this;\n    }\n    mint operator-() const\
    \ { return mint() - *this; }\n    mint operator+(const mint &p) const { return\
    \ mint(*this) += p; }\n    mint operator-(const mint &p) const { return mint(*this)\
    \ -= p; }\n    mint operator*(const mint &p) const { return mint(*this) *= p;\
    \ }\n    mint operator/(const mint &p) const { return mint(*this) /= p; }\n  \
    \  bool operator==(const mint &p) const {\n        return (x >= mod() ? x - mod()\
    \ : x) == (p.x >= mod() ? p.x - mod() : p.x);\n    }\n    bool operator!=(const\
    \ mint &p) const {\n        return (x >= mod() ? x - mod() : x) != (p.x >= mod()\
    \ ? p.x - mod() : p.x);\n    }\n    u32 val() const {\n        u32 ret = reduce(x);\n\
    \        return ret >= mod() ? ret - mod() : ret;\n    }\n    mint pow(u64 n)\
    \ const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n       \
    \     if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    mint inv() const { return pow(mod()\
    \ - 2); }\n    friend ostream &operator<<(ostream &os, const mint &p) {\n    \
    \    return os << p.val();\n    }\n    friend istream &operator>>(istream &is,\
    \ mint &a) {\n        i64 t;\n        is >> t;\n        a = mint(t);\n       \
    \ return is;\n    }\n    static constexpr u32 mod() { return mod_; }\n};\ntemplate\
    \ <uint32_t mod>\nusing modint = MontgomeryModInt<mod>;\nusing modint998244353\
    \ = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n"
  dependsOn: []
  isVerificationFile: false
  path: library/number/mod/montgomery_mod_int.hpp
  requiredBy:
  - library/polynomial/fps/stirling_second_number.hpp
  - library/polynomial/fps/stirling_first_number.hpp
  - library/polynomial/fps/bernoulli_number.hpp
  - library/polynomial/fps/formal_power_series.hpp
  - library/polynomial/fft/convolution_arbitrary_mod.hpp
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial.fps.bernoulli_number.test.cpp
  - tests/polynomial.fft.convolution_bitwise_or.test.cpp
  - tests/polynomial.fft.convolution_bitwise_and.test.cpp
  - tests/polynomial.fps.stirling_second_number.test.cpp
  - tests/polynomial.fps.stirling_first_number.test.cpp
  - tests/polynomial.fft.convolution_bitwise_xor.test.cpp
documentation_of: library/number/mod/montgomery_mod_int.hpp
layout: document
title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
---

# モジュロ演算

## できること
- モンゴメリ乗算を用いた高速なモジュロ演算をおこなう


## 計算量
$O(1)$

## 使い方
```cpp
// 1. 宣言と初期化 任意のMODを指定する。2つはよく使うのであらかじめ定義済み
modint998244353 a = 10;
modint1000000007 b = 20;
using mint = modint<MOD>;
using mint = modint<3456>;

// 2. 標準入出力に対応。自動的に mod されるし、自動的にval()が呼ばれる
modint998244353 c;
cin >> c;
cout << c << endl;

// 3. 四則演算
modint998244353 res_add = a + b;
modint998244353 res_mul = a * b;
modint998244353 res_div = a / b; // 内部で逆元(inv)を掛けています

// 4. 累乗 (pow) は内部で、二分累乗を行う
modint998244353 res_pow = a.pow(100); // a の 100 乗
```
