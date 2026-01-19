---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/sequence/bit_dict.hpp
    title: "\u5B8C\u5099\u8F9E\u66F8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/wavelet_search_engine.hpp
    title: Wavelet Search Engine
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/search.binary_search.wavelet_search_engine.test.cpp
    title: "WaveletSearchEngine\u306E\u30C6\u30B9\u30C8"
  - icon: ':x:'
    path: tests/sequence.wavelet_matrix.test.cpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306E\u30C6\u30B9\
      \u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ left = mid;\n        }\n        return left;\n    }\n};\n#line 3 \"library/sequence/wavelet_matrix.hpp\"\
    \nstruct WaveletMatrix {\n    int n;\n    int max_log;\n    vector<BitDict> matrix;\n\
    \    vector<int> mid_points; // \u5404\u6BB5\u3067\u306E 0 \u3068 1 \u306E\u5883\
    \u754C\u7DDA (0\u306E\u500B\u6570)\n\n    // \u69CB\u7BC9: O(N log V)\n    WaveletMatrix(vector<long\
    \ long> v, int max_log = 32) : n(v.size()), max_log(max_log) {\n        matrix.assign(max_log,\
    \ BitDict(n));\n        mid_points.resize(max_log);\n        vector<long long>\
    \ left(n), right(n);\n\n        for (int d = max_log - 1; d >= 0; d--) {\n   \
    \         vector<long long> l_vals, r_vals;\n            for (int i = 0; i < n;\
    \ i++) {\n                if ((v[i] >> d) & 1) {\n                    matrix[d].set(i);\n\
    \                    r_vals.push_back(v[i]);\n                } else {\n     \
    \               l_vals.push_back(v[i]);\n                }\n            }\n  \
    \          matrix[d].build();\n            mid_points[d] = l_vals.size();\n  \
    \          \n            // v \u3092\u6B21\u306E\u6BB5\u306E\u305F\u3081\u306B\
    \u4E26\u3073\u66FF\u3048\u308B (0\u3092\u524D\u30011\u3092\u5F8C\u306B\u96C6\u3081\
    \u308B)\n            v = l_vals;\n            v.insert(v.end(), r_vals.begin(),\
    \ r_vals.end());\n        }\n    }\n\n    // k\u756A\u76EE\u306E\u5024\u3092\u8FD4\
    \u3059: O(log V)\n    long long access(int k) const {\n        long long res =\
    \ 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n            bool bit =\
    \ matrix[d].access(k);\n            if (bit) {\n                res |= (1LL <<\
    \ d);\n                k = mid_points[d] + matrix[d].rank1(k);\n            }\
    \ else {\n                k = matrix[d].rank0(k);\n            }\n        }\n\
    \        return res;\n    }\n\n    // [0, r) \u306B\u542B\u307E\u308C\u308B x\
    \ \u306E\u500B\u6570: O(log V)\n    int rank(long long x, int r) const {\n   \
    \     int l = 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n         \
    \   bool bit = (x >> d) & 1;\n            if (bit) {\n                l = mid_points[d]\
    \ + matrix[d].rank1(l);\n                r = mid_points[d] + matrix[d].rank1(r);\n\
    \            } else {\n                l = matrix[d].rank0(l);\n             \
    \   r = matrix[d].rank0(r);\n            }\n        }\n        return r - l;\n\
    \    }\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\
    : O(log V)\n    long long kth_smallest(int l, int r, int k) const {\n        long\
    \ long res = 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n          \
    \  int cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);\n            if (k < cnt0)\
    \ {\n                l = matrix[d].rank0(l);\n                r = matrix[d].rank0(r);\n\
    \            } else {\n                res |= (1LL << d);\n                k -=\
    \ cnt0;\n                l = mid_points[d] + matrix[d].rank1(l);\n           \
    \     r = mid_points[d] + matrix[d].rank1(r);\n            }\n        }\n    \
    \    return res;\n    }\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5927\
    \u304D\u3044\u5024: O(log V)\n    long long kth_largest(int l, int r, int k) const\
    \ {\n        return kth_smallest(l, r, (r - l) - 1 - k);\n    }\n\n    // [l,\
    \ r) \u5185\u3067 [lower, upper) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\
    : O(log V)\n    int range_freq(int l, int r, long long lower, long long upper)\
    \ const {\n        return count_less(l, r, upper) - count_less(l, r, lower);\n\
    \    }\n\n    // [l, r) \u5185\u3067 val \u672A\u6E80\u306E\u8981\u7D20\u6570\
    \ (\u5185\u90E8\u7528\u88DC\u52A9\u95A2\u6570)\n    int count_less(int l, int\
    \ r, long long val) const {\n        int res = 0;\n        for (int d = max_log\
    \ - 1; d >= 0; d--) {\n            bool bit = (val >> d) & 1;\n            int\
    \ cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);\n            if (bit) {\n  \
    \              res += cnt0; // 0\u306E\u30D3\u30C3\u30C8\u3092\u6301\u3064\u3082\
    \u306E\u306F\u78BA\u5B9F\u306B val \u3088\u308A\u5C0F\u3055\u3044\n          \
    \      l = mid_points[d] + matrix[d].rank1(l);\n                r = mid_points[d]\
    \ + matrix[d].rank1(r);\n            } else {\n                l = matrix[d].rank0(l);\n\
    \                r = matrix[d].rank0(r);\n            }\n        }\n        return\
    \ res;\n    }\n\n    // [l, r) \u5185\u3067 upper \u3088\u308A\u5C0F\u3055\u3044\
    \u6700\u5927\u5024\n    long long prev_value(int l, int r, long long upper) const\
    \ {\n        int cnt = count_less(l, r, upper);\n        return (cnt == 0) ? -1\
    \ : kth_smallest(l, r, cnt - 1);\n    }\n\n    // [l, r) \u5185\u3067 lower \u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u5024\n    long long next_value(int l, int r, long long\
    \ lower) const {\n        int cnt = count_less(l, r, lower);\n        return (cnt\
    \ == (r - l)) ? -1 : kth_smallest(l, r, cnt);\n    }\n};\n"
  code: "#pragma once\n#include \"library/sequence/bit_dict.hpp\"\nstruct WaveletMatrix\
    \ {\n    int n;\n    int max_log;\n    vector<BitDict> matrix;\n    vector<int>\
    \ mid_points; // \u5404\u6BB5\u3067\u306E 0 \u3068 1 \u306E\u5883\u754C\u7DDA\
    \ (0\u306E\u500B\u6570)\n\n    // \u69CB\u7BC9: O(N log V)\n    WaveletMatrix(vector<long\
    \ long> v, int max_log = 32) : n(v.size()), max_log(max_log) {\n        matrix.assign(max_log,\
    \ BitDict(n));\n        mid_points.resize(max_log);\n        vector<long long>\
    \ left(n), right(n);\n\n        for (int d = max_log - 1; d >= 0; d--) {\n   \
    \         vector<long long> l_vals, r_vals;\n            for (int i = 0; i < n;\
    \ i++) {\n                if ((v[i] >> d) & 1) {\n                    matrix[d].set(i);\n\
    \                    r_vals.push_back(v[i]);\n                } else {\n     \
    \               l_vals.push_back(v[i]);\n                }\n            }\n  \
    \          matrix[d].build();\n            mid_points[d] = l_vals.size();\n  \
    \          \n            // v \u3092\u6B21\u306E\u6BB5\u306E\u305F\u3081\u306B\
    \u4E26\u3073\u66FF\u3048\u308B (0\u3092\u524D\u30011\u3092\u5F8C\u306B\u96C6\u3081\
    \u308B)\n            v = l_vals;\n            v.insert(v.end(), r_vals.begin(),\
    \ r_vals.end());\n        }\n    }\n\n    // k\u756A\u76EE\u306E\u5024\u3092\u8FD4\
    \u3059: O(log V)\n    long long access(int k) const {\n        long long res =\
    \ 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n            bool bit =\
    \ matrix[d].access(k);\n            if (bit) {\n                res |= (1LL <<\
    \ d);\n                k = mid_points[d] + matrix[d].rank1(k);\n            }\
    \ else {\n                k = matrix[d].rank0(k);\n            }\n        }\n\
    \        return res;\n    }\n\n    // [0, r) \u306B\u542B\u307E\u308C\u308B x\
    \ \u306E\u500B\u6570: O(log V)\n    int rank(long long x, int r) const {\n   \
    \     int l = 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n         \
    \   bool bit = (x >> d) & 1;\n            if (bit) {\n                l = mid_points[d]\
    \ + matrix[d].rank1(l);\n                r = mid_points[d] + matrix[d].rank1(r);\n\
    \            } else {\n                l = matrix[d].rank0(l);\n             \
    \   r = matrix[d].rank0(r);\n            }\n        }\n        return r - l;\n\
    \    }\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\
    : O(log V)\n    long long kth_smallest(int l, int r, int k) const {\n        long\
    \ long res = 0;\n        for (int d = max_log - 1; d >= 0; d--) {\n          \
    \  int cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);\n            if (k < cnt0)\
    \ {\n                l = matrix[d].rank0(l);\n                r = matrix[d].rank0(r);\n\
    \            } else {\n                res |= (1LL << d);\n                k -=\
    \ cnt0;\n                l = mid_points[d] + matrix[d].rank1(l);\n           \
    \     r = mid_points[d] + matrix[d].rank1(r);\n            }\n        }\n    \
    \    return res;\n    }\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5927\
    \u304D\u3044\u5024: O(log V)\n    long long kth_largest(int l, int r, int k) const\
    \ {\n        return kth_smallest(l, r, (r - l) - 1 - k);\n    }\n\n    // [l,\
    \ r) \u5185\u3067 [lower, upper) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\
    : O(log V)\n    int range_freq(int l, int r, long long lower, long long upper)\
    \ const {\n        return count_less(l, r, upper) - count_less(l, r, lower);\n\
    \    }\n\n    // [l, r) \u5185\u3067 val \u672A\u6E80\u306E\u8981\u7D20\u6570\
    \ (\u5185\u90E8\u7528\u88DC\u52A9\u95A2\u6570)\n    int count_less(int l, int\
    \ r, long long val) const {\n        int res = 0;\n        for (int d = max_log\
    \ - 1; d >= 0; d--) {\n            bool bit = (val >> d) & 1;\n            int\
    \ cnt0 = matrix[d].rank0(r) - matrix[d].rank0(l);\n            if (bit) {\n  \
    \              res += cnt0; // 0\u306E\u30D3\u30C3\u30C8\u3092\u6301\u3064\u3082\
    \u306E\u306F\u78BA\u5B9F\u306B val \u3088\u308A\u5C0F\u3055\u3044\n          \
    \      l = mid_points[d] + matrix[d].rank1(l);\n                r = mid_points[d]\
    \ + matrix[d].rank1(r);\n            } else {\n                l = matrix[d].rank0(l);\n\
    \                r = matrix[d].rank0(r);\n            }\n        }\n        return\
    \ res;\n    }\n\n    // [l, r) \u5185\u3067 upper \u3088\u308A\u5C0F\u3055\u3044\
    \u6700\u5927\u5024\n    long long prev_value(int l, int r, long long upper) const\
    \ {\n        int cnt = count_less(l, r, upper);\n        return (cnt == 0) ? -1\
    \ : kth_smallest(l, r, cnt - 1);\n    }\n\n    // [l, r) \u5185\u3067 lower \u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u5024\n    long long next_value(int l, int r, long long\
    \ lower) const {\n        int cnt = count_less(l, r, lower);\n        return (cnt\
    \ == (r - l)) ? -1 : kth_smallest(l, r, cnt);\n    }\n};\n"
  dependsOn:
  - library/sequence/bit_dict.hpp
  isVerificationFile: false
  path: library/sequence/wavelet_matrix.hpp
  requiredBy:
  - library/search/binary_search/wavelet_search_engine.hpp
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/search.binary_search.wavelet_search_engine.test.cpp
  - tests/sequence.wavelet_matrix.test.cpp
documentation_of: library/sequence/wavelet_matrix.hpp
layout: document
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
---

# ウェーブレット行列

## できること
- 完備辞書を縦に積み、数値の配列をビットごとに分解して管理する

## 計算量
- 構築: $O(NlogV)$ 配列vをもとにビットの深さ分(32bit整数なら32段)の完備辞書を積む
- `access(k)`: $O(logV)$ 元配列のk番目の値を取得
- `rank(x, r)`: $O(logV)$ 区間[0, r)に含まれる値xの個数
- `kth_smallest(l, r, k)`: $O(logV)$ 区間[l, r)内でk番目(0-indexed)に小さい値
- `kth_largest(l, r, k)`: $O(logV)$ 区間[l, r)内でk番目(0-indexed)に大きい値
- `range_freq(l, r, lower, upper)`: $O(logV)$ 区間[l, r)内で値が $lower \le x \lt upper$ なものの個数
- `prev_value(l, r, upper)`: $O(logV)$ 区間[l, r)内でupperより小さいものの中の最大値
- `next_value(l, r, lower)`: $O(logV)$ 区間[l, r)内でlowerより大きいものの中の最小値

※ $V$ は扱う値のビット数

## 使い方
```cpp
vector<int> a = {5, 2, 8, 5, 1, 3};
WaveletMatrix wm(a);

// 0〜4番目の範囲で、小さい方から0番目（最小値）を取得
int val = wm.kth_smallest(0, 4, 0); // 2

// 0〜6番目の範囲で、3以上6未満の値が何個あるか
int count = wm.range_freq(0, 6, 3, 6); // 5, 5, 3 の3個
```
