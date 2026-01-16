---
title: 文字列検索 複数
documentation_of: //library/string/finds.hpp
---

# 文字列検索 複数

## できること
- 文字列Tの中にあるSの一致場所を全て取得
- マッチした頭のインデックスを返す

## 計算量
- ナイーブ: $O(\vert T \vert \cdot \vert S \vert)$
- ロリハ版: $O(\vert T \vert + \vert S \vert)$ ※ハッシュ衝突の危険性を留意

## 使い方
```cpp
vector<int> pos = finds(T, S);

vector<int> pos = finds_rolling_hash(T, S);
```
