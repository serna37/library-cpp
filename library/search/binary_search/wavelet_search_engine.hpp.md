---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/bit_dict.hpp
    title: "\u5B8C\u5099\u8F9E\u66F8"
  - icon: ':heavy_check_mark:'
    path: library/sequence/compressor.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: library/sequence/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/compressor.hpp\"\ntemplate <typename T>\
    \ struct Compressor {\n    vector<T> origin, dict;\n    Compressor(const vector<T>\
    \ &v) : origin(v), dict(v) {\n        sort(dict.begin(), dict.end());\n      \
    \  dict.erase(unique(dict.begin(), dict.end()), dict.end());\n    }\n    int size()\
    \ const { return dict.size(); }\n    // \u5024 -> ID (\u5727\u7E2E)\n    int get_id(T\
    \ x) const {\n        return lower_bound(dict.begin(), dict.end(), x) - dict.begin();\n\
    \    }\n    // \u5024 -> ID (upper_bound\u7248)\n    int get_upper_id(T x) const\
    \ {\n        return upper_bound(dict.begin(), dict.end(), x) - dict.begin();\n\
    \    }\n    // ID -> \u5024 (\u5FA9\u5143)\n    T get_val(int id) const {\n  \
    \      return dict[id];\n    }\n    // \u3059\u3079\u3066\u5727\u7E2E\n    vector<int>\
    \ get_all() {\n        vector<int> res;\n        for (auto &&x : origin) res.emplace_back(get_id(x));\n\
    \        return res;\n    }\n};\n#line 2 \"library/sequence/bit_dict.hpp\"\nstruct\
    \ BitDict {\n    using uint = uint64_t;\n    int n;\n    vector<uint> bit;   //\
    \ \u30D3\u30C3\u30C8\u5217\u672C\u4F53\n    vector<int> sum;   // \u7D2F\u7A4D\
    \u548C\uFF08\u5404\u30EF\u30FC\u30C9\u958B\u59CB\u6642\u70B9\u3067\u306E1\u306E\
    \u7DCF\u6570\uFF09\n\n    BitDict() {} // \u7A7A\u306E\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\uFF08\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\
    \u306Evector\u78BA\u4FDD\u7528\uFF09\n\n    // 64\u30D3\u30C3\u30C8\u5358\u4F4D\
    \u3067\u683C\u7D0D\u3059\u308B\u305F\u3081\u3001(n/64)+1 \u500B\u306E\u8981\u7D20\
    \u3092\u78BA\u4FDD\n    BitDict(int n) : n(n) { // n \u306F\u6271\u3046\u30D3\u30C3\
    \u30C8\u5217\u306E\u9577\u3055\uFF08\u6700\u5927\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9 + 1\uFF09\n        bit.assign((n >> 6) + 1, 0);\n    }\n\n    // k\u756A\
    \u76EE\u306E\u30D3\u30C3\u30C8\u30921\u306B\u3059\u308B\n    void set(int k) {\n\
    \        bit[k >> 6] |= (1ULL << (k & 63));\n    }\n\n    // \u7D2F\u7A4D\u548C\
    \u3092\u69CB\u7BC9\u3059\u308B\uFF08set\u306E\u5F8C\u306B\u5FC5\u305A\u547C\u3076\
    \uFF09\n    void build() {\n        sum.assign(bit.size() + 1, 0);\n        for\
    \ (int i = 0; i < (int)bit.size(); i++) {\n            sum[i + 1] = sum[i] + __builtin_popcountll(bit[i]);\n\
    \        }\n    }\n\n    // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u3092\u53D6\u5F97\
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
    \ == (r - l)) ? -1 : kth_smallest(l, r, cnt);\n    }\n};\n#line 4 \"library/search/binary_search/wavelet_search_engine.hpp\"\
    \nstruct WaveletSearchEngine {\n    int n;\n    Compressor<long long> cp;\n  \
    \  WaveletMatrix wm;\n    const long long INF_VAL = 1e18;\n    WaveletSearchEngine(const\
    \ vector<long long> &v) : n(v.size()), cp(v), wm({}, 0) {\n        vector<int>\
    \ compressed_all = cp.get_all();\n        vector<long long> wm_input(compressed_all.begin(),\
    \ compressed_all.end());\n        int max_log = 0;\n        while ((1LL << max_log)\
    \ <= (int)cp.size()) max_log++;\n        if (max_log == 0) max_log = 1; // \u8981\
    \u7D20\u304C\u7A7A\u307E\u305F\u306F1\u7A2E\u985E\u306E\u5834\u5408\n        wm\
    \ = WaveletMatrix(wm_input, max_log);\n    }\n\n    // --- \u57FA\u672C\u64CD\u4F5C\
    \ ---\n\n    // i \u756A\u76EE\u306E\u5143\u306E\u5024\u3092\u8FD4\u3059\n   \
    \ long long access(int i) const {\n        return cp.get_val(wm.access(i));\n\
    \    }\n\n    // [l, r) \u5185\u306B x \u304C\u4F55\u500B\u542B\u307E\u308C\u308B\
    \u304B\n    int count_x(int l, int r, long long x) const {\n        int id = cp.get_id(x);\n\
    \        if (id >= cp.size() || cp.get_val(id) != x) return 0;\n        return\
    \ wm.rank(id, r) - wm.rank(id, l);\n    }\n\n    // --- \u4E8C\u5206\u63A2\u7D22\
    \u7CFB\u7D71\u5408\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9 (bi_..._cnt)\
    \ ---\n\n    // [l, r) \u5185\u3067 x \u672A\u6E80 (Less Than) \u306E\u500B\u6570\
    \n    int count_lt(int l, int r, long long x) const {\n        return wm.count_less(l,\
    \ r, cp.get_id(x));\n    }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0B (Less\
    \ Equal) \u306E\u500B\u6570\n    int count_le(int l, int r, long long x) const\
    \ {\n        return wm.count_less(l, r, cp.get_upper_id(x));\n    }\n\n    //\
    \ [l, r) \u5185\u3067 x \u4EE5\u4E0A (Greater Equal) \u306E\u500B\u6570\n    int\
    \ count_ge(int l, int r, long long x) const {\n        return (r - l) - count_lt(l,\
    \ r, x);\n    }\n\n    // [l, r) \u5185\u3067 x \u3088\u308A\u5927\u304D\u3044\
    \ (Greater Than) \u306E\u500B\u6570\n    int count_gt(int l, int r, long long\
    \ x) const {\n        return (r - l) - count_le(l, r, x);\n    }\n\n    // ---\
    \ \u5024\u691C\u7D22\u7CFB\u7D71\u5408\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\
    \u30B9 (bi_..._val) ---\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u5024 (0-indexed)\n    long long kth_smallest(int l, int r, int k)\
    \ const {\n        if (k < 0 || k >= (r - l)) return INF_VAL;\n        return\
    \ cp.get_val(wm.kth_smallest(l, r, k));\n    }\n\n    // [l, r) \u5185\u3067 k\
    \ \u756A\u76EE\u306B\u5927\u304D\u3044\u5024 (0-indexed)\n    long long kth_largest(int\
    \ l, int r, int k) const {\n        if (k < 0 || k >= (r - l)) return -INF_VAL;\n\
    \        return cp.get_val(wm.kth_largest(l, r, k));\n    }\n\n    // [l, r) \u5185\
    \u3067 x \u672A\u6E80\u306E\u6700\u5927\u5024 (Less Than Value)\n    long long\
    \ find_lt(int l, int r, long long x) const {\n        int cnt = count_lt(l, r,\
    \ x);\n        return (cnt == 0) ? -INF_VAL : kth_smallest(l, r, cnt - 1);\n \
    \   }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0B\u306E\u6700\u5927\u5024 (Less\
    \ Equal Value)\n    long long find_le(int l, int r, long long x) const {\n   \
    \     int cnt = count_le(l, r, x);\n        return (cnt == 0) ? -INF_VAL : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 (Greater Equal Value)\n    long long find_ge(int l, int r, long long\
    \ x) const {\n        int cnt = count_lt(l, r, x);\n        return (cnt == (r\
    \ - l)) ? INF_VAL : kth_smallest(l, r, cnt);\n    }\n\n    // [l, r) \u5185\u3067\
    \ x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u5024 (Greater Than Value)\n  \
    \  long long find_gt(int l, int r, long long x) const {\n        int cnt = count_le(l,\
    \ r, x);\n        return (cnt == (r - l)) ? INF_VAL : kth_smallest(l, r, cnt);\n\
    \    }\n\n    // --- \u5FDC\u7528\u30AF\u30A8\u30EA ---\n\n    // [l, r) \u5185\
    \u3067 [lower, upper) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\n    int\
    \ range_freq(int l, int r, long long lower, long long upper) const {\n       \
    \ if (lower >= upper) return 0;\n        return wm.count_less(l, r, cp.get_id(upper))\
    \ - wm.count_less(l, r, cp.get_id(lower));\n    }\n};\n"
  code: "#pragma once\n#include \"library/sequence/compressor.hpp\"\n#include \"library/sequence/wavelet_matrix.hpp\"\
    \nstruct WaveletSearchEngine {\n    int n;\n    Compressor<long long> cp;\n  \
    \  WaveletMatrix wm;\n    const long long INF_VAL = 1e18;\n    WaveletSearchEngine(const\
    \ vector<long long> &v) : n(v.size()), cp(v), wm({}, 0) {\n        vector<int>\
    \ compressed_all = cp.get_all();\n        vector<long long> wm_input(compressed_all.begin(),\
    \ compressed_all.end());\n        int max_log = 0;\n        while ((1LL << max_log)\
    \ <= (int)cp.size()) max_log++;\n        if (max_log == 0) max_log = 1; // \u8981\
    \u7D20\u304C\u7A7A\u307E\u305F\u306F1\u7A2E\u985E\u306E\u5834\u5408\n        wm\
    \ = WaveletMatrix(wm_input, max_log);\n    }\n\n    // --- \u57FA\u672C\u64CD\u4F5C\
    \ ---\n\n    // i \u756A\u76EE\u306E\u5143\u306E\u5024\u3092\u8FD4\u3059\n   \
    \ long long access(int i) const {\n        return cp.get_val(wm.access(i));\n\
    \    }\n\n    // [l, r) \u5185\u306B x \u304C\u4F55\u500B\u542B\u307E\u308C\u308B\
    \u304B\n    int count_x(int l, int r, long long x) const {\n        int id = cp.get_id(x);\n\
    \        if (id >= cp.size() || cp.get_val(id) != x) return 0;\n        return\
    \ wm.rank(id, r) - wm.rank(id, l);\n    }\n\n    // --- \u4E8C\u5206\u63A2\u7D22\
    \u7CFB\u7D71\u5408\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9 (bi_..._cnt)\
    \ ---\n\n    // [l, r) \u5185\u3067 x \u672A\u6E80 (Less Than) \u306E\u500B\u6570\
    \n    int count_lt(int l, int r, long long x) const {\n        return wm.count_less(l,\
    \ r, cp.get_id(x));\n    }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0B (Less\
    \ Equal) \u306E\u500B\u6570\n    int count_le(int l, int r, long long x) const\
    \ {\n        return wm.count_less(l, r, cp.get_upper_id(x));\n    }\n\n    //\
    \ [l, r) \u5185\u3067 x \u4EE5\u4E0A (Greater Equal) \u306E\u500B\u6570\n    int\
    \ count_ge(int l, int r, long long x) const {\n        return (r - l) - count_lt(l,\
    \ r, x);\n    }\n\n    // [l, r) \u5185\u3067 x \u3088\u308A\u5927\u304D\u3044\
    \ (Greater Than) \u306E\u500B\u6570\n    int count_gt(int l, int r, long long\
    \ x) const {\n        return (r - l) - count_le(l, r, x);\n    }\n\n    // ---\
    \ \u5024\u691C\u7D22\u7CFB\u7D71\u5408\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\
    \u30B9 (bi_..._val) ---\n\n    // [l, r) \u5185\u3067 k \u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u5024 (0-indexed)\n    long long kth_smallest(int l, int r, int k)\
    \ const {\n        if (k < 0 || k >= (r - l)) return INF_VAL;\n        return\
    \ cp.get_val(wm.kth_smallest(l, r, k));\n    }\n\n    // [l, r) \u5185\u3067 k\
    \ \u756A\u76EE\u306B\u5927\u304D\u3044\u5024 (0-indexed)\n    long long kth_largest(int\
    \ l, int r, int k) const {\n        if (k < 0 || k >= (r - l)) return -INF_VAL;\n\
    \        return cp.get_val(wm.kth_largest(l, r, k));\n    }\n\n    // [l, r) \u5185\
    \u3067 x \u672A\u6E80\u306E\u6700\u5927\u5024 (Less Than Value)\n    long long\
    \ find_lt(int l, int r, long long x) const {\n        int cnt = count_lt(l, r,\
    \ x);\n        return (cnt == 0) ? -INF_VAL : kth_smallest(l, r, cnt - 1);\n \
    \   }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0B\u306E\u6700\u5927\u5024 (Less\
    \ Equal Value)\n    long long find_le(int l, int r, long long x) const {\n   \
    \     int cnt = count_le(l, r, x);\n        return (cnt == 0) ? -INF_VAL : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // [l, r) \u5185\u3067 x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 (Greater Equal Value)\n    long long find_ge(int l, int r, long long\
    \ x) const {\n        int cnt = count_lt(l, r, x);\n        return (cnt == (r\
    \ - l)) ? INF_VAL : kth_smallest(l, r, cnt);\n    }\n\n    // [l, r) \u5185\u3067\
    \ x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u5024 (Greater Than Value)\n  \
    \  long long find_gt(int l, int r, long long x) const {\n        int cnt = count_le(l,\
    \ r, x);\n        return (cnt == (r - l)) ? INF_VAL : kth_smallest(l, r, cnt);\n\
    \    }\n\n    // --- \u5FDC\u7528\u30AF\u30A8\u30EA ---\n\n    // [l, r) \u5185\
    \u3067 [lower, upper) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\n    int\
    \ range_freq(int l, int r, long long lower, long long upper) const {\n       \
    \ if (lower >= upper) return 0;\n        return wm.count_less(l, r, cp.get_id(upper))\
    \ - wm.count_less(l, r, cp.get_id(lower));\n    }\n};\n"
  dependsOn:
  - library/sequence/compressor.hpp
  - library/sequence/wavelet_matrix.hpp
  - library/sequence/bit_dict.hpp
  isVerificationFile: false
  path: library/search/binary_search/wavelet_search_engine.hpp
  requiredBy: []
  timestamp: '2026-01-16 14:13:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/binary_search/wavelet_search_engine.hpp
layout: document
redirect_from:
- /library/library/search/binary_search/wavelet_search_engine.hpp
- /library/library/search/binary_search/wavelet_search_engine.hpp.html
title: library/search/binary_search/wavelet_search_engine.hpp
---
