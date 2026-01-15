---
title: ウェーブレット行列
documentation_of: //library/sequence/wavelet_matrix.hpp
---

# ウェーブレット行列

## できること
- 完備辞書を縦に積み、数値の配列をビットごとに分解して管理する

## 計算量
- 構築: $O(NlogV)$ 配列vをもとにビットの深さ分(32bit整数なら32段)の完備辞書を積む
- `access(k)`: $O(logV)$ 元配列のk番目の値を取得
- `rank(x, r)`: $O(logV)$ 区間[0, r)に含まれる値xの個数
- `kth_smallest(l, r, k)`: $O(logV)$ 区間[l, r)内でk番目(0-indexed)に小さい値
- `kth_largest(l, r, k)`: $O(logV)$ 区間[l, r)内でk番目(0-indexed)に大きい値
- `range_freq(l, r, lower, upper)`: $O(logV)$ 区間[l, r)内で値が $lower \le x \lt upper$ なものの個数
- `prev_value(l, r, upper)`: $O(logV)$ 区間[l, r)内でupperより小さいものの中の最大値
- `next_value(l, r, lower)`: $O(logV)$ 区間[l, r)内でlowerより大きいものの中の最小値

※ $V$ は扱う値のビット数

## 使い方
```cpp
vector<int> a = {5, 2, 8, 5, 1, 3};
WaveletMatrix wm(a);

// 0〜4番目の範囲で、小さい方から0番目（最小値）を取得
int val = wm.kth_smallest(0, 4, 0); // 2

// 0〜6番目の範囲で、3以上6未満の値が何個あるか
int count = wm.range_freq(0, 6, 3, 6); // 5, 5, 3 の3個
```
