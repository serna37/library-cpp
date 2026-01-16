---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/sequence/compressor.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence.inversion_number.test.cpp
    title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u30FBFenwickTree\u306E\
      \u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/fenwick_tree.hpp\"\nstruct FenwickTree {\n\
    \  private:\n    int N;\n    vector<int> fwk;\n\n  public:\n    FenwickTree(int\
    \ N) : N(N) {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const vector<int>\
    \ &A) : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for (int i = 1;\
    \ i <= N; ++i) {\n            fwk[i] += A[i - 1];\n            if (i + (i & -i)\
    \ <= N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    void add(int i, const\
    \ int &x) {\n        for (++i; i <= N; i += i & -i) fwk[i] += x;\n    }\n    int\
    \ sum(int i) {\n        int ans = 0;\n        for (++i; i; i -= i & -i) ans +=\
    \ fwk[i];\n        return ans;\n    }\n};\n#line 2 \"library/sequence/compressor.hpp\"\
    \ntemplate <typename T> struct Compressor {\n    vector<T> origin, dict;\n   \
    \ Compressor(const vector<T> &v) : origin(v), dict(v) {\n        sort(dict.begin(),\
    \ dict.end());\n        dict.erase(unique(dict.begin(), dict.end()), dict.end());\n\
    \    }\n    int size() const { return dict.size(); }\n    // \u5024 -> ID (\u5727\
    \u7E2E)\n    int get_id(T x) const {\n        return lower_bound(dict.begin(),\
    \ dict.end(), x) - dict.begin();\n    }\n    // \u5024 -> ID (upper_bound\u7248\
    )\n    int get_upper_id(T x) const {\n        return upper_bound(dict.begin(),\
    \ dict.end(), x) - dict.begin();\n    }\n    // ID -> \u5024 (\u5FA9\u5143)\n\
    \    T get_val(int id) const {\n        return dict[id];\n    }\n    // \u3059\
    \u3079\u3066\u5727\u7E2E\n    vector<int> get_all() {\n        vector<int> res;\n\
    \        for (auto &&x : origin) res.emplace_back(get_id(x));\n        return\
    \ res;\n    }\n};\n#line 4 \"library/sequence/inversion_number.hpp\"\ntemplate\
    \ <typename T> long long inversion_number(const vector<T> &A) {\n    if (A.empty())\
    \ return 0ll;\n    Compressor<T> zip(A);\n    vector<int> compressed_a = zip.get_all();\n\
    \    int N = A.size(), sz = zip.size();\n    FenwickTree fwk(sz);\n    long long\
    \ inv = 0;\n    for (int i = 0; i < N; ++i) {\n        inv += i - fwk.sum(compressed_a[i]);\n\
    \        fwk.add(compressed_a[i], 1);\n    }\n    return inv;\n}\n"
  code: "#pragma once\n#include \"library/segtree/fenwick_tree.hpp\"\n#include \"\
    library/sequence/compressor.hpp\"\ntemplate <typename T> long long inversion_number(const\
    \ vector<T> &A) {\n    if (A.empty()) return 0ll;\n    Compressor<T> zip(A);\n\
    \    vector<int> compressed_a = zip.get_all();\n    int N = A.size(), sz = zip.size();\n\
    \    FenwickTree fwk(sz);\n    long long inv = 0;\n    for (int i = 0; i < N;\
    \ ++i) {\n        inv += i - fwk.sum(compressed_a[i]);\n        fwk.add(compressed_a[i],\
    \ 1);\n    }\n    return inv;\n}\n"
  dependsOn:
  - library/segtree/fenwick_tree.hpp
  - library/sequence/compressor.hpp
  isVerificationFile: false
  path: library/sequence/inversion_number.hpp
  requiredBy: []
  timestamp: '2026-01-16 15:08:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.inversion_number.test.cpp
documentation_of: library/sequence/inversion_number.hpp
layout: document
title: "\u8EE2\u5012\u6570"
---

# 転倒数

## できること
- 右に倒れる$A_i > A_j (i < j)$の回数を求める
- 座標圧縮したFenwick Treeで求めている

## 計算量
$O(NlogN)$

## 使い方
```cpp
long long inv = inversion_number(A);
```
