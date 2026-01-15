---
title: Aho Corasick
documentation_of: //library/string/aho_corasick.hpp
---

# Aho Corasick

## できること
- Trie木を使って、複数文字列に対するパターンマッチングオートマトンを構築する
- 単語が含まれる回数や、一文字ずつ読み進めてヒット数を累積したりできる

### オートマトンとは
5つの組からなる。
$M = (Q, \sum, \delta, q_0, F)$
- $Q$ : 状態の集合
- $\sum$ : 入力定義の集合
- $\delta$ : 状態遷移関数
- $q_0$ : 初期状態
- $F$ : 受理状態の集合（「一連の動作が正しく終わった」とみなせる状態。迷路でいうゴール）

| $M$ | 自動改札なら |
| -- | -- |
| $Q$ | { `閉鎖`, `開放` } |
| $\sum$ | { `ICカードタッチ`, `通り抜ける` } |
| $\delta$ | { `(閉でタッチ) => 開にする`, `(閉で通り抜け) => 閉のまま`, etc... } |
| $q_0$ | `閉鎖` |
| $F$ | { `閉鎖` } |

## 計算量
追加した文字列の長さの総和を $L$ 、文字種数を $\sum$ とする
- `build`: $O(L \cdot \sum)$ Trie木にパターンをaddしたあとで、Failure Linkを構築する
- `next`: $O(1)$ オートマトン上を1文字進み、次の状態を返す
- `count_all`: $O(\vert S \vert)$ テキストに含まれるパターンの総出現回数をカウント

## 使い方
```cpp
// char_size=26, margin='a' と仮定
AhoCorasick<26, 'a'> ac;
vector<string> patterns = {"hers", "she", "he", "his"};
// Trie木に追加してからビルド
for (int i = 0; i < (int)patterns.size(); ++i) ac.add(patterns[i], i);
ac.build();

string text = "ushershehis";

// 文字列中の全ヒット数を数える
long long total = ac.count_all(text); // 6 (she, he, hers, she, he, his)

// 1文字ずつ遷移する
int now = 0;
for (char c : text) {
    now = ac.next(now, c);
    int hits = ac.count[now]; // その地点で終わるパターンの数
}
```
