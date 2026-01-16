---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/sequence/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence.wavelet_matrix.test.cpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306E\u30C6\u30B9\
      \u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/bit_dict.hpp\"\nstruct BitDict {\n    using\
    \ uint = uint64_t;\n    int n;\n    vector<uint> bit;   // \u30D3\u30C3\u30C8\u5217\
    \u672C\u4F53\n    vector<int> sum;   // \u7D2F\u7A4D\u548C\uFF08\u5404\u30EF\u30FC\
    \u30C9\u958B\u59CB\u6642\u70B9\u3067\u306E1\u306E\u7DCF\u6570\uFF09\n\n    BitDict()\
    \ {} // \u7A7A\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF08\u30A6\u30A7\
    \u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306Evector\u78BA\u4FDD\u7528\uFF09\
    \n\n    // 64\u30D3\u30C3\u30C8\u5358\u4F4D\u3067\u683C\u7D0D\u3059\u308B\u305F\
    \u3081\u3001(n/64)+1 \u500B\u306E\u8981\u7D20\u3092\u78BA\u4FDD\n    BitDict(int\
    \ n) : n(n) { // n \u306F\u6271\u3046\u30D3\u30C3\u30C8\u5217\u306E\u9577\u3055\
    \uFF08\u6700\u5927\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 + 1\uFF09\n        bit.assign((n\
    \ >> 6) + 1, 0);\n    }\n\n    // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u3092\
    1\u306B\u3059\u308B\n    void set(int k) {\n        bit[k >> 6] |= (1ULL << (k\
    \ & 63));\n    }\n\n    // \u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\uFF08\
    set\u306E\u5F8C\u306B\u5FC5\u305A\u547C\u3076\uFF09\n    void build() {\n    \
    \    sum.assign(bit.size() + 1, 0);\n        for (int i = 0; i < (int)bit.size();\
    \ i++) {\n            sum[i + 1] = sum[i] + __builtin_popcountll(bit[i]);\n  \
    \      }\n    }\n\n    // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u3092\u53D6\u5F97\
    \n    bool access(int k) const {\n        return (bit[k >> 6] >> (k & 63)) & 1;\n\
    \    }\n\n    // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n    int rank1(int k)\
    \ const {\n        int idx = k >> 6;\n        int offset = k & 63;\n        uint\
    \ mask = (1ULL << offset) - 1;\n        return sum[idx] + __builtin_popcountll(bit[idx]\
    \ & mask);\n    }\n\n    // [0, k) \u5185\u306E 0 \u306E\u500B\u6570\uFF08\u30A6\
    \u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u3067\u591A\u7528\u3059\u308B\
    \uFF09\n    int rank0(int k) const {\n        return k - rank1(k);\n    }\n\n\
    \    // j\u756A\u76EE(1-indexed)\u306E1\u306E\u4F4D\u7F6E: O(log N)\n    int select(int\
    \ j) const {\n        if (j <= 0 || j > sum.back()) return -1;\n        int left\
    \ = 0, right = n;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) / 2;\n            if (rank1(mid) >= j) right = mid;\n            else\
    \ left = mid;\n        }\n        return left;\n    }\n};\n"
  code: "#pragma once\nstruct BitDict {\n    using uint = uint64_t;\n    int n;\n\
    \    vector<uint> bit;   // \u30D3\u30C3\u30C8\u5217\u672C\u4F53\n    vector<int>\
    \ sum;   // \u7D2F\u7A4D\u548C\uFF08\u5404\u30EF\u30FC\u30C9\u958B\u59CB\u6642\
    \u70B9\u3067\u306E1\u306E\u7DCF\u6570\uFF09\n\n    BitDict() {} // \u7A7A\u306E\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF08\u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217\u306Evector\u78BA\u4FDD\u7528\uFF09\n\n    // 64\u30D3\
    \u30C3\u30C8\u5358\u4F4D\u3067\u683C\u7D0D\u3059\u308B\u305F\u3081\u3001(n/64)+1\
    \ \u500B\u306E\u8981\u7D20\u3092\u78BA\u4FDD\n    BitDict(int n) : n(n) { // n\
    \ \u306F\u6271\u3046\u30D3\u30C3\u30C8\u5217\u306E\u9577\u3055\uFF08\u6700\u5927\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 + 1\uFF09\n        bit.assign((n >> 6) +\
    \ 1, 0);\n    }\n\n    // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u30921\u306B\u3059\
    \u308B\n    void set(int k) {\n        bit[k >> 6] |= (1ULL << (k & 63));\n  \
    \  }\n\n    // \u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\uFF08set\u306E\
    \u5F8C\u306B\u5FC5\u305A\u547C\u3076\uFF09\n    void build() {\n        sum.assign(bit.size()\
    \ + 1, 0);\n        for (int i = 0; i < (int)bit.size(); i++) {\n            sum[i\
    \ + 1] = sum[i] + __builtin_popcountll(bit[i]);\n        }\n    }\n\n    // k\u756A\
    \u76EE\u306E\u30D3\u30C3\u30C8\u3092\u53D6\u5F97\n    bool access(int k) const\
    \ {\n        return (bit[k >> 6] >> (k & 63)) & 1;\n    }\n\n    // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n    int rank1(int k) const {\n        int idx = k\
    \ >> 6;\n        int offset = k & 63;\n        uint mask = (1ULL << offset) -\
    \ 1;\n        return sum[idx] + __builtin_popcountll(bit[idx] & mask);\n    }\n\
    \n    // [0, k) \u5185\u306E 0 \u306E\u500B\u6570\uFF08\u30A6\u30A7\u30FC\u30D6\
    \u30EC\u30C3\u30C8\u884C\u5217\u3067\u591A\u7528\u3059\u308B\uFF09\n    int rank0(int\
    \ k) const {\n        return k - rank1(k);\n    }\n\n    // j\u756A\u76EE(1-indexed)\u306E\
    1\u306E\u4F4D\u7F6E: O(log N)\n    int select(int j) const {\n        if (j <=\
    \ 0 || j > sum.back()) return -1;\n        int left = 0, right = n;\n        while\
    \ (right - left > 1) {\n            int mid = (left + right) / 2;\n          \
    \  if (rank1(mid) >= j) right = mid;\n            else left = mid;\n        }\n\
    \        return left;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/bit_dict.hpp
  requiredBy:
  - library/sequence/wavelet_matrix.hpp
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.wavelet_matrix.test.cpp
documentation_of: library/sequence/bit_dict.hpp
layout: document
title: "\u5B8C\u5099\u8F9E\u66F8"
---

# 完備辞書

## できること
- 01のビット列に対し、rank(1の個数計算)とselect(1の位置特定)を定数時間で行う

## 計算量
- `access(k)`: $O(1)$ k番目のビットが0か1かを返す
- `rank(k)`: $O(1)$ 範囲[0, k)内の1の個数を返す
- `select(j)`: $O(1)$ または $O(logN)$ j番目(1-indexed)の1の位置を返す

> `select`について、 $O(1)$ 実現のためには「1が100個おきにどこにあるか」を記録する別のインデックスが必要になる

## 使い方
```cpp
// 01011 のようなビット列を構築
// 左から1, 3, 4番目を立てる
BitDict dict(100);  // 最大桁数を100で初期化
dict.set(1);
dict.set(3);
dict.set(4);
dict.build(); // set後にビルド

dict.access(3); // 1
dict.rank(4);   // 0~3文字目までの'1'の数 => 2
dict.select(2); // 2番目の'1'がある位置 => 3
```
