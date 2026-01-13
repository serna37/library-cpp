---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/starry_sky_tree.hpp\"\n/**\n * `rev = true`\
    \ \u3067\u533A\u9593min\u306B\u5909\u66F4 -> \u3067\u304D\u306A\u3044\u3001\u30D0\
    \u30B0\u3063\u3066\u308B\n */\ntemplate <bool rev = false> struct StarrySkyTree\
    \ {\n  private:\n    int N, sz, rv, log = 1;\n    vector<int> node;\n    void\
    \ init() {\n        while ((1ll << log) < N) ++log;\n        node.assign((sz =\
    \ 1ll << log) << 1, -INF);\n        rv = (rev ? -1 : 1);\n    }\n    int _star(int\
    \ i) {\n        int mx = max(node[i << 1 | 0], node[i << 1 | 1]);\n        node[i\
    \ << 1 | 0] -= mx;\n        node[i << 1 | 1] -= mx;\n        return mx;\n    }\n\
    \    void star(int i) {\n        node[i] += _star(i);\n    }\n    int sum(int\
    \ i) {\n        int ans = node[i];\n        while (i >>= 1) ans += node[i];\n\
    \        return ans;\n    }\n\n  public:\n    StarrySkyTree(int n) : N(n) {\n\
    \        init();\n    }\n    StarrySkyTree(const vector<int> &a) : N(a.size())\
    \ {\n        init();\n        for (int i = 0; i < N; ++i) node[i + sz] = a[i]\
    \ * rv;\n        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);\n    }\n\
    \    int operator[](int i) {\n        return sum(i + sz) * rv;\n    }\n    vector<int>\
    \ getall() {\n        vector<int> res(N);\n        for (int i = 0; i < N; ++i)\
    \ res[i] = sum(i + sz) * rv;\n        return res;\n    }\n    void set(int p,\
    \ const int &x) {\n        apply(p, p + 1, x - sum(p + sz) * rv);\n    }\n   \
    \ void act(int p, const int &x) {\n        apply(p, p + 1, x);\n    }\n    int\
    \ get(int l, int r) {\n        int ans = -INF;\n        for (l += sz, r += sz;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) ans = max(ans, sum(l++));\n\
    \            if (r & 1) ans = max(ans, sum(--r));\n        }\n        return ans\
    \ * rv;\n    }\n    int top() {\n        return node[1] * rv;\n    }\n    void\
    \ apply(int l, int r, const int &x) {\n        int v = x * rv;\n        for (int\
    \ ll = (l += sz), rr = (r += sz); ll < rr; ll >>= 1, rr >>= 1) {\n           \
    \ if (ll & 1) node[ll++] += v;\n            if (rr & 1) node[--rr] += v;\n   \
    \     }\n        l >>= __builtin_ctz(l);\n        r >>= __builtin_ctz(r);\n  \
    \      while (l >>= 1) star(l);\n        while (r >>= 1) star(r);\n    }\n};\n"
  code: "#pragma once\n/**\n * `rev = true` \u3067\u533A\u9593min\u306B\u5909\u66F4\
    \ -> \u3067\u304D\u306A\u3044\u3001\u30D0\u30B0\u3063\u3066\u308B\n */\ntemplate\
    \ <bool rev = false> struct StarrySkyTree {\n  private:\n    int N, sz, rv, log\
    \ = 1;\n    vector<int> node;\n    void init() {\n        while ((1ll << log)\
    \ < N) ++log;\n        node.assign((sz = 1ll << log) << 1, -INF);\n        rv\
    \ = (rev ? -1 : 1);\n    }\n    int _star(int i) {\n        int mx = max(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n        node[i << 1 | 0] -= mx;\n        node[i\
    \ << 1 | 1] -= mx;\n        return mx;\n    }\n    void star(int i) {\n      \
    \  node[i] += _star(i);\n    }\n    int sum(int i) {\n        int ans = node[i];\n\
    \        while (i >>= 1) ans += node[i];\n        return ans;\n    }\n\n  public:\n\
    \    StarrySkyTree(int n) : N(n) {\n        init();\n    }\n    StarrySkyTree(const\
    \ vector<int> &a) : N(a.size()) {\n        init();\n        for (int i = 0; i\
    \ < N; ++i) node[i + sz] = a[i] * rv;\n        for (int i = sz - 1; i >= 1; --i)\
    \ node[i] = _star(i);\n    }\n    int operator[](int i) {\n        return sum(i\
    \ + sz) * rv;\n    }\n    vector<int> getall() {\n        vector<int> res(N);\n\
    \        for (int i = 0; i < N; ++i) res[i] = sum(i + sz) * rv;\n        return\
    \ res;\n    }\n    void set(int p, const int &x) {\n        apply(p, p + 1, x\
    \ - sum(p + sz) * rv);\n    }\n    void act(int p, const int &x) {\n        apply(p,\
    \ p + 1, x);\n    }\n    int get(int l, int r) {\n        int ans = -INF;\n  \
    \      for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if (l &\
    \ 1) ans = max(ans, sum(l++));\n            if (r & 1) ans = max(ans, sum(--r));\n\
    \        }\n        return ans * rv;\n    }\n    int top() {\n        return node[1]\
    \ * rv;\n    }\n    void apply(int l, int r, const int &x) {\n        int v =\
    \ x * rv;\n        for (int ll = (l += sz), rr = (r += sz); ll < rr; ll >>= 1,\
    \ rr >>= 1) {\n            if (ll & 1) node[ll++] += v;\n            if (rr &\
    \ 1) node[--rr] += v;\n        }\n        l >>= __builtin_ctz(l);\n        r >>=\
    \ __builtin_ctz(r);\n        while (l >>= 1) star(l);\n        while (r >>= 1)\
    \ star(r);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/segtree/starry_sky_tree.hpp
  requiredBy: []
  timestamp: '2026-01-13 09:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/segtree/starry_sky_tree.hpp
layout: document
title: Starry Sky Tree
---

# Starry Sky Tree

## できること
- 累積和の要領で実現してる
  - 参考: https://rsk0315.hatenablog.com/entry/2019/06/21/174953
- 区間[l, r)にの値を加算
- 区間[l, r)のmaxを取得

## 計算量
- 構築: $O(N)$
- 1点更新`set`: $O(logN)$
- 区間更新`apply`: $O(logN)$
- 区間取得`get`: $O(logN)$

## 使い方
```cpp
StarrySkyTree sst(N);
```
