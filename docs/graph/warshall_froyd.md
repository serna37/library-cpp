---
title: Warshall Froyd
documentation_of: //library/graph/warshall_froyd.hpp
---

# Warshall Froyd

## できること
- 全頂点対の最小コストを求める
- 複数始点
  - `dis`: dis[i][j] := 頂点までの最小コスト
  - `negativeCycle`: 負の閉路がある場合true

## 計算量
$O(N^3)$

## 使い方
```cpp
auto [dis, negativeCycle] = warshall_froyd(G);
```
