---
title: 文字列検索 複数
documentation_of: //library/string/finds.hpp
---

# 文字列検索 複数

## できること
- 文字列Tの中にあるSの一致場所を全て取得
- マッチした頭のインデックスを返す

## 計算量
$O(\vert T \vert \cdot \vert S \vert)$

## 使い方
```cpp
vector<int> pos = finds(T, S);
```
