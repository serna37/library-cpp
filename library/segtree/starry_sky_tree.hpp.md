---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/starry_sky_tree.test.cpp
    title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/starry_sky_tree_2.test.cpp
    title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/starry_sky_tree.hpp\"\ntemplate <bool is_min_mode\
    \ = true> struct StarrySkyTree {\n  private:\n    int N, sz, log = 1;\n    const\
    \ int INF = 1e9;\n    vector<int> node;\n    int compare(int a, int b) {\n   \
    \     if constexpr (is_min_mode) {\n            return min(a, b);\n        } else\
    \ {\n            return max(a, b);\n        }\n    }\n    int unit_element() {\n\
    \        return is_min_mode ? INF : -INF;\n    }\n    void init() {\n        while\
    \ ((1ll << log) < N) ++log;\n        node.assign((sz = 1ll << log) << 1, 0);\n\
    \    }\n    int _star(int i) {\n        int val = compare(node[i << 1 | 0], node[i\
    \ << 1 | 1]);\n        node[i << 1 | 0] -= val;\n        node[i << 1 | 1] -= val;\n\
    \        return val;\n    }\n    void star(int i) {\n        node[i] += _star(i);\n\
    \    }\n    int sum(int i) {\n        int ans = node[i];\n        while (i >>=\
    \ 1) ans += node[i];\n        return ans;\n    }\n\n  public:\n    StarrySkyTree(int\
    \ n) : N(n) {\n        init();\n    }\n    StarrySkyTree(const vector<int> &a)\
    \ : N(a.size()) {\n        init();\n        for (int i = 0; i < N; ++i) node[i\
    \ + sz] = a[i];\n        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);\n\
    \    }\n    int operator[](int i) {\n        return sum(i + sz);\n    }\n    void\
    \ apply(int l, int r, const int &v) {\n        if (l >= r) return;\n        int\
    \ l_bak = l + sz, r_bak = r + sz - 1;\n        for (l += sz, r += sz; l < r; l\
    \ >>= 1, r >>= 1) {\n            if (l & 1) node[l++] += v;\n            if (r\
    \ & 1) node[--r] += v;\n        }\n        for (int i = l_bak >> 1; i >= 1; i\
    \ >>= 1) star(i);\n        for (int i = r_bak >> 1; i >= 1; i >>= 1) star(i);\n\
    \    }\n    void set(int p, const int &x) {\n        apply(p, p + 1, x - sum(p\
    \ + sz));\n    }\n    int prod(int l, int r) {\n        if (l >= r) return unit_element();\n\
    \        int ans = unit_element();\n        for (l += sz, r += sz; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) ans = compare(ans, sum(l++));\n      \
    \      if (r & 1) ans = compare(ans, sum(--r));\n        }\n        return ans;\n\
    \    }\n};\n"
  code: "#pragma once\ntemplate <bool is_min_mode = true> struct StarrySkyTree {\n\
    \  private:\n    int N, sz, log = 1;\n    const int INF = 1e9;\n    vector<int>\
    \ node;\n    int compare(int a, int b) {\n        if constexpr (is_min_mode) {\n\
    \            return min(a, b);\n        } else {\n            return max(a, b);\n\
    \        }\n    }\n    int unit_element() {\n        return is_min_mode ? INF\
    \ : -INF;\n    }\n    void init() {\n        while ((1ll << log) < N) ++log;\n\
    \        node.assign((sz = 1ll << log) << 1, 0);\n    }\n    int _star(int i)\
    \ {\n        int val = compare(node[i << 1 | 0], node[i << 1 | 1]);\n        node[i\
    \ << 1 | 0] -= val;\n        node[i << 1 | 1] -= val;\n        return val;\n \
    \   }\n    void star(int i) {\n        node[i] += _star(i);\n    }\n    int sum(int\
    \ i) {\n        int ans = node[i];\n        while (i >>= 1) ans += node[i];\n\
    \        return ans;\n    }\n\n  public:\n    StarrySkyTree(int n) : N(n) {\n\
    \        init();\n    }\n    StarrySkyTree(const vector<int> &a) : N(a.size())\
    \ {\n        init();\n        for (int i = 0; i < N; ++i) node[i + sz] = a[i];\n\
    \        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);\n    }\n    int\
    \ operator[](int i) {\n        return sum(i + sz);\n    }\n    void apply(int\
    \ l, int r, const int &v) {\n        if (l >= r) return;\n        int l_bak =\
    \ l + sz, r_bak = r + sz - 1;\n        for (l += sz, r += sz; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (l & 1) node[l++] += v;\n            if (r & 1) node[--r]\
    \ += v;\n        }\n        for (int i = l_bak >> 1; i >= 1; i >>= 1) star(i);\n\
    \        for (int i = r_bak >> 1; i >= 1; i >>= 1) star(i);\n    }\n    void set(int\
    \ p, const int &x) {\n        apply(p, p + 1, x - sum(p + sz));\n    }\n    int\
    \ prod(int l, int r) {\n        if (l >= r) return unit_element();\n        int\
    \ ans = unit_element();\n        for (l += sz, r += sz; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) ans = compare(ans, sum(l++));\n            if (r\
    \ & 1) ans = compare(ans, sum(--r));\n        }\n        return ans;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/segtree/starry_sky_tree.hpp
  requiredBy: []
  timestamp: '2026-01-14 14:43:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/starry_sky_tree_2.test.cpp
  - tests/segtree/starry_sky_tree.test.cpp
documentation_of: library/segtree/starry_sky_tree.hpp
layout: document
title: Starry Sky Tree
---

# Starry Sky Tree

## できること
- 累積和の要領で実現してる
  - 参考: https://rsk0315.hatenablog.com/entry/2019/06/21/174953
- 区間[l, r)の値を加算
- 区間[l, r)のmax/minを取得

## 計算量
- 構築: $O(N)$
- 1点取得`seg[i]`: $O(logN)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`prod`: $O(logN)$

## 使い方
```cpp
StarrySkyTree sst(N); // 区間min
StarrySkyTree<false> sst(N); // 区間max
```
