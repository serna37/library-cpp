---
title: 文字列複数 統合検索エンジン
documentation_of: //library/string/finds.hpp
---

# 文字列複数 統合検索エンジン

## できること
- 文字列Tの中にあるSの一致場所を全て取得、マッチした頭のインデックスを返す
- 

## 計算量
以下3種類を自動で使い分けます
- ナイーブ: $O(\vert T \vert \cdot \vert S \vert)$
- ロリハ版: $O(\vert T \vert + \vert S \vert)$ ※ハッシュ衝突の危険性を留意
- AhoCorasick版: $O(\vert T \vert + マッチ数)$

## 使い方
```cpp
auto pos = finds(T, {S});
vector<int> idxs = pos[S];

auto pos = finds("abracadabra", {"abr", "ra", "a"});
// pos["abr"] == {0, 7}
// pos["ra"] == {2, 9}
// pos["a"] == {0, 3, 5, 7, 10}
```
