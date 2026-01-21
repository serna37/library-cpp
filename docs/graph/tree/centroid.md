---
title: 木の重心
documentation_of: //library/graph/tree/centroid.hpp
---

# 木の重心

## できること
- 木の重心を求める
- 重心 $\cdots$ その頂点を取り除いたときにできる部分木たちの頂点数が、全て半分以下になる
- 重心はは1個か2個存在する

## 計算量
$O(V)$

## 使い方
```cpp
int N;
Graph G(N);
vector<int> C = centroid(G);
```

