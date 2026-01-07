---
title: グラフ
documentation_of: //library/graph/graph.hpp
---

# グラフ

## できること
- グラフの構造体
  - `N`: 頂点数
  - `G`: グラフ本体
  - `es`: カウンタ

辺を貼るたび、`Edge#idx`を自動で採番。

## 計算量
なし

## 使い方
```cpp
Graph G(N);
// 有向グラフ 一方向にのみ辺を張る
G.add(from, to, cost);
// 無向グラフ 双方向に辺を張る
G.add_both(from, to, cost);
```

標準入力にも対応
```cpp
Graph G(N);
// 辺の数、1-indexなら-1する
//             重みtrue  有向true
G.read(M, -1, true, true);
```
