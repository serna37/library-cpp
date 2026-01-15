---
title: 完備辞書
documentation_of: //library/sequence/bit_dict.hpp
---

# 完備辞書

## できること
- 01のビット列に対し、rank(1の個数計算)とselect(1の位置特定)を定数時間で行う

## 計算量
- `access(k)`: $O(1)$ k番目のビットが0か1かを返す
- `rank(k)`: $O(1)$ 範囲[0, k)内の1の個数を返す
- `select(j)`: $O(1)$ または $O(logN)$ j番目(1-indexed)の1の位置を返す

> `select`について、 $O(1)$ 実現のためには「1が100個おきにどこにあるか」を記録する別のインデックスが必要になる

## 使い方
```cpp
// 01011 のようなビット列を構築
// 左から1, 3, 4番目を立てる
BitDict dict(100);  // 最大桁数を100で初期化
dict.set(1);
dict.set(3);
dict.set(4);
dict.build(); // set後にビルド

dict.access(3); // 1
dict.rank(4);   // 0~3文字目までの'1'の数 => 2
dict.select(2); // 2番目の'1'がある位置 => 3
```
