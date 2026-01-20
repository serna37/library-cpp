---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sequence.static_range_count_distinct.test.cpp
    title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570\u306E\u30C6\u30B9\u30C8"
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
    \ fwk[i];\n        return ans;\n    }\n};\n#line 3 \"library/sequence/static_range_count_distinct.hpp\"\
    \ntemplate <typename T>\nstruct StaticRangeCountDistinct {\n  private:\n    size_t\
    \ m;\n    vector<int> xs;\n    vector<vector<int>> mp;\n    vector<pair<int, int>>\
    \ qs;\n\n  public:\n    explicit StaticRangeCountDistinct(const vector<T> &vs)\
    \ : xs(vs.size()) {\n        vector<T> ys = vs;\n        sort(ys.begin(), ys.end());\n\
    \        ys.erase(unique(ys.begin(), ys.end()), ys.end());\n        m = ys.size();\n\
    \        for (int i = 0; i < (int)vs.size(); ++i) {\n            int p = lower_bound(ys.begin(),\
    \ ys.end(), vs[i]) - ys.begin();\n            xs[i] = p;\n        }\n    }\n \
    \   void add_query(int l, int r) {\n        assert(0ll <= l and l <= r and r <=\
    \ (int)xs.size());\n        qs.emplace_back(l, r - 1);\n    }\n    vector<size_t>\
    \ calclate_queries() const {\n        int n = (int)xs.size();\n        int q =\
    \ (int)qs.size();\n        vector<vector<int> > ev(n);\n        for (int i = 0;\
    \ i < q; ++i) {\n            if (qs[i].first <= qs[i].second) {\n            \
    \    ev[qs[i].second].emplace_back(i);\n            }\n        }\n        vector<int>\
    \ pre(m, -1);\n        FenwickTree fwk(n);\n        vector<size_t> ans(q);\n \
    \       for (int i = 0; i < n; ++i) {\n            int v = xs[i];\n          \
    \  if (~pre[v]) fwk.add(n - pre[v] - 1, -1);\n            pre[v] = i;\n      \
    \      fwk.add(n - i - 1, 1);\n            for (auto &&j : ev[i]) {\n        \
    \        ans[j] = fwk.sum(n - qs[j].first - 1);\n            }\n        }\n  \
    \      return ans;\n    }\n};\n"
  code: "#pragma once\n#include \"library/segtree/fenwick_tree.hpp\"\ntemplate <typename\
    \ T>\nstruct StaticRangeCountDistinct {\n  private:\n    size_t m;\n    vector<int>\
    \ xs;\n    vector<vector<int>> mp;\n    vector<pair<int, int>> qs;\n\n  public:\n\
    \    explicit StaticRangeCountDistinct(const vector<T> &vs) : xs(vs.size()) {\n\
    \        vector<T> ys = vs;\n        sort(ys.begin(), ys.end());\n        ys.erase(unique(ys.begin(),\
    \ ys.end()), ys.end());\n        m = ys.size();\n        for (int i = 0; i < (int)vs.size();\
    \ ++i) {\n            int p = lower_bound(ys.begin(), ys.end(), vs[i]) - ys.begin();\n\
    \            xs[i] = p;\n        }\n    }\n    void add_query(int l, int r) {\n\
    \        assert(0ll <= l and l <= r and r <= (int)xs.size());\n        qs.emplace_back(l,\
    \ r - 1);\n    }\n    vector<size_t> calclate_queries() const {\n        int n\
    \ = (int)xs.size();\n        int q = (int)qs.size();\n        vector<vector<int>\
    \ > ev(n);\n        for (int i = 0; i < q; ++i) {\n            if (qs[i].first\
    \ <= qs[i].second) {\n                ev[qs[i].second].emplace_back(i);\n    \
    \        }\n        }\n        vector<int> pre(m, -1);\n        FenwickTree fwk(n);\n\
    \        vector<size_t> ans(q);\n        for (int i = 0; i < n; ++i) {\n     \
    \       int v = xs[i];\n            if (~pre[v]) fwk.add(n - pre[v] - 1, -1);\n\
    \            pre[v] = i;\n            fwk.add(n - i - 1, 1);\n            for\
    \ (auto &&j : ev[i]) {\n                ans[j] = fwk.sum(n - qs[j].first - 1);\n\
    \            }\n        }\n        return ans;\n    }\n};\n"
  dependsOn:
  - library/segtree/fenwick_tree.hpp
  isVerificationFile: false
  path: library/sequence/static_range_count_distinct.hpp
  requiredBy: []
  timestamp: '2026-01-20 09:55:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sequence.static_range_count_distinct.test.cpp
documentation_of: library/sequence/static_range_count_distinct.hpp
layout: document
title: "\u533A\u9593\u306E\u5024\u306E\u7A2E\u985E\u6570"
---

# 区間の値の種類数

## できること
- 静的な配列に対して、指定された範囲 $[l, r)$ 内の値が何種類かを求める
- 先にクエリをすべて読むオフラインクエリ
- 座標圧縮+FenwickTreeで「その位置の値が今の右端 $i$ から見て『最後に現れた位置』かどうか」を求める

## 計算量
$O((N + Q) \log N)$

## 使い方
```cpp
vector<int> A = {1, 2, 1, 3, 2, 4, 4, 1}; 
// インデックス:  0  1  2  3  4  5  6  7

StaticRangeCountDistinct srcd(A);

// クエリの登録: [l, r) の半開区間で指定
// 例1: A[0...3] -> {1, 2, 1} は 2種類 {1, 2}
srcd.add_query(0, 3); 
// 例2: A[2...5] -> {1, 3, 2} は 3種類 {1, 2, 3}
srcd.add_query(2, 5); 
// 例3: A[5...7] -> {4, 4} は 1種類 {4}
srcd.add_query(5, 7);
// 例4: A[0...8] -> 全体 {1, 2, 1, 3, 2, 4, 4, 1} は 4種類 {1, 2, 3, 4}
srcd.add_query(0, 8);

// 計算実行
vector<size_t> results = srcd.calculate_queries();

// 結果の表示サンプル
vector<string> labels = {"[0, 3)", "[2, 5)", "[5, 7)", "[0, 8)"};
for (int i = 0; i < (int)results.size(); ++i) {
    cout << "Range " << labels[i] << " Distinct Count: " << results[i] << endl;
}
```

