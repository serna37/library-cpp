---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/various.mo.test.cpp
    title: "Mo's algorithm\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/mo.hpp\"\nstruct Mo {\n  private:\n    int\
    \ n, w;\n    vector<int> ord;\n    vector<pair<int, int> > lr;\n\n  public:\n\
    \    Mo(int n, int q) : n(n), ord(q) {\n        w = max<int>(1ll, n / max(1.0,\
    \ sqrt(q * 2.0 / 3.0)));\n        iota(ord.begin(), ord.end(), 0ll);\n       \
    \ lr.reserve(q);\n    }\n    void add_query(int l, int r) {\n        assert(0ll\
    \ <= l and l < r and r <= n);\n        lr.emplace_back(l, r);\n    }\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename Q>\n    void calclate_queries(const\
    \ AL &add_left, const AR &add_right,\n        const EL &erase_left, const ER &erase_right,\n\
    \        const Q &query) {\n        assert(lr.size() == ord.size());\n       \
    \ vector<int> bs(n);\n        for (int i = 0, cnt = 0, b = 0; i < n; i++) {\n\
    \            bs[i] = b;\n            if (++cnt == w) {\n                ++b;\n\
    \                cnt = 0;\n            }\n        }\n        sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            int a_block = bs[lr[a].first];\n\
    \            int b_block = bs[lr[b].first];\n            if (a_block != b_block)\
    \ return a_block < b_block;\n            if (a_block & 1) {\n                return\
    \ lr[a].second < lr[b].second;\n            } else {\n                return lr[a].second\
    \ > lr[b].second;\n            }\n        });\n        int l = 0, r = 0;\n   \
    \     for (auto idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            query(idx);\n        }\n    }\n    template <typename A, typename\
    \ E, typename Q>\n    void calclate_queries(const A &add, const E &erase, const\
    \ Q &query) {\n        calclate_queries(add, add, erase, erase, query);\n    }\n\
    };\n"
  code: "#pragma once\nstruct Mo {\n  private:\n    int n, w;\n    vector<int> ord;\n\
    \    vector<pair<int, int> > lr;\n\n  public:\n    Mo(int n, int q) : n(n), ord(q)\
    \ {\n        w = max<int>(1ll, n / max(1.0, sqrt(q * 2.0 / 3.0)));\n        iota(ord.begin(),\
    \ ord.end(), 0ll);\n        lr.reserve(q);\n    }\n    void add_query(int l, int\
    \ r) {\n        assert(0ll <= l and l < r and r <= n);\n        lr.emplace_back(l,\
    \ r);\n    }\n    template <typename AL, typename AR, typename EL, typename ER,\
    \ typename Q>\n    void calclate_queries(const AL &add_left, const AR &add_right,\n\
    \        const EL &erase_left, const ER &erase_right,\n        const Q &query)\
    \ {\n        assert(lr.size() == ord.size());\n        vector<int> bs(n);\n  \
    \      for (int i = 0, cnt = 0, b = 0; i < n; i++) {\n            bs[i] = b;\n\
    \            if (++cnt == w) {\n                ++b;\n                cnt = 0;\n\
    \            }\n        }\n        sort(ord.begin(), ord.end(), [&](int a, int\
    \ b) {\n            int a_block = bs[lr[a].first];\n            int b_block =\
    \ bs[lr[b].first];\n            if (a_block != b_block) return a_block < b_block;\n\
    \            if (a_block & 1) {\n                return lr[a].second < lr[b].second;\n\
    \            } else {\n                return lr[a].second > lr[b].second;\n \
    \           }\n        });\n        int l = 0, r = 0;\n        for (auto idx :\
    \ ord) {\n            while (l > lr[idx].first) add_left(--l);\n            while\
    \ (r < lr[idx].second) add_right(r++);\n            while (l < lr[idx].first)\
    \ erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            query(idx);\n        }\n    }\n    template <typename A, typename\
    \ E, typename Q>\n    void calclate_queries(const A &add, const E &erase, const\
    \ Q &query) {\n        calclate_queries(add, add, erase, erase, query);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/various/mo.hpp
  requiredBy: []
  timestamp: '2026-01-20 16:51:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/various.mo.test.cpp
documentation_of: library/various/mo.hpp
layout: document
title: Mo's algorithm
---

# Mo's algorithm

## できること
- 区間クエリを平方分割で管理
- 参考: https://ei1333.github.io/library/other/mo.hpp

## 計算量
- 区間長n, クエリ数qで初期化 `Mo(n, q)`: $O(q)$
- クエリ追加 $[l, r) {}_{0 \le l \lt r \le n}$ `add_query`: $O(1)$
- クエリを処理 `calclate_queries`: $O(\alpha N \sqrt Q)$ ※区間を1伸縮させる計算量を $O(\alpha)$

## 使い方
```cpp
int N, Q;
cin >> N >> Q;
vector<int> A(N);
for (int i = 0; i < N; ++i) {
    cin >> A[i];
}

// Moの初期化
Mo mo(N, Q);

// クエリの登録
for (int i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r; // 0-indexed, 半開区間 [l, r) と想定
    mo.add_query(l, r);
}

// 状態を保持する変数
vector<int> count(1000001, 0); // 数値の出現回数（数値の最大値に合わせる）
int current_distinct_types = 0;
vector<int> results(Q); // 各クエリの結果格納用

// 1. 要素を追加する時の処理
auto add = [&](int i) {
    if (count[A[i]] == 0ll) {
        current_distinct_types++;
    }
    count[A[i]]++;
};

// 2. 要素を削除する時の処理
auto erase = [&](int i) {
    count[A[i]]--;
    if (count[A[i]] == 0ll) {
        current_distinct_types--;
    }
};

// 3. クエリに答える時の処理
auto query = [&](int idx) {
    results[idx] = current_distinct_types;
};

// 計算実行 (2) の左右区別しないバージョンを使用
mo.calclate_queries(add, erase, query);

// 結果出力
for (int i = 0; i < Q; ++i) {
    cout << results[i] << endl;
}
```

