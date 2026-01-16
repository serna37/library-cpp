---
title: Wavelet Search Engine
documentation_of: //library/sequence/wavelet_search_engine.hpp
---

# Wavelet Search Engine
ウェーブレット行列 + 座標圧縮での、各種問い合わせ関数を整備したもの

## できること
- **多機能な区間クエリ**: 任意の区間 $[l, r)$ に対して、以下の操作を高速に行います。
    - **二分探索の拡張**: ソート済み配列に対する `lower_bound` 等の操作を、元の並び順を維持したまま任意の区間に対して実行します。
    - **K番目の値**: 区間内で $k$ 番目に小さい（または大きい）値を取得します。
    - **範囲周波数**: 区間内の値が $[lower, upper)$ に収まる要素の個数を取得します。
- **座標圧縮の自動適用**: 内部で座標圧縮を行うため、巨大な値や負の値、`long long` 全域の値をそのまま扱えます。
- **静的配列への高速アクセス**: 元の配列の $i$ 番目の値を $O(\log (\text{種類数}))$ で復元します。

## 計算量
$N$ を配列サイズ、$V$ を配列に含まれるユニークな値の種類数とします。

- **構築**: $O(N \log N)$
- **各種クエリ**: $O(\log V)$
    - `access`, `count_x`, `count_lt/le/ge/gt`, `kth_smallest/largest`, `find_lt/le/ge/gt`, `range_freq` のすべて。

## 使い方
### 構築
```cpp
vector<long long> A = {10, 40, 20, 10, 30};
WaveletSearchEngine engine(A);

// 区間 [1, 4) すなわち {40, 20, 10} が対象
int l = 1, r = 4;

// 個数を数える (count系)
engine.count_ge(l, r, 20); // 20以上の個数 -> 2 (40, 20)
engine.range_freq(l, r, 15, 35); // 15以上35未満の個数 -> 1 (20)

// 値を探す (find系)
// 見つからない場合は構築時に設定した INF_VAL または -INF_VAL が返ります
// engine.INF_VAL
// と比較すること
engine.find_lt(l, r, 25); // 25未満で最大の要素 -> 20
engine.find_ge(l, r, 20); // 20以上で最小の要素 -> 20

// K番目の値 (0-indexed)
engine.kth_smallest(l, r, 0); // 区間最小値 -> 10
engine.kth_largest(l, r, 0);  // 区間最大値 -> 40
```
