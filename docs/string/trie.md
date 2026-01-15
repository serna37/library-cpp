---
title: Trie木
documentation_of: //library/string/trie.hpp
---

# Trie木

## できること
- 接頭辞の木。複数文字列の共通部分をまとめて管理している
- 単語の登録・検索
- 接頭辞（Prefix）検索（指定文字列で始まる単語がいくつ登録されているか）

<img width="350" height="327" alt="Image" src="https://github.com/user-attachments/assets/331fe951-3b96-4088-849f-50feb83f6f2f" />

画像の引用: https://www.geeksforgeeks.org/dsa/trie-insert-and-search/  
実装の参考: https://ei1333.github.io/library/structure/trie/trie.hpp  
- `accept`: そのノードで「ちょうど終わる単語のID」を保存
  - "apple"を追加したとき、最後の"e"のノードのacceptにそのIDが入る
- `exist`: そのノードを「通過した単語の総数」をカウント

（イメージ）"app" (ID:0) と "apple" (ID:1) を入れた状態  
```
Root (nodes[0])
 └── 'a' (nodes[1])
      └── 'p' (nodes[2])
           └── 'p' (nodes[3])  <-- accept: [0], exist: 2
                └── 'l' (nodes[4])
                     └── 'e' (nodes[5]) <-- accept: [1], exist: 1
```

## 計算量
- `add`: $O(|S| * \sum)$ Sは追加する文字列、 $\sum$ はchar_size
- `search`: $O(|S|)$
- `count_prefix`: $O(|S|)$

## 使い方
```cpp
// 小文字アルファベット 26文字、開始文字 'a' で初期化
Trie<26, 'a'> trie;

// 単語の追加 (IDは任意)
trie.add("apple", 0);
trie.add("app", 1);

// 検索
bool has_apple = trie.search("apple");      // true
bool has_appli = trie.search("appli");      // false (接頭辞としてはあるが単語はない)

// 接頭辞カウント
int cnt = trie.count_prefix("app");         // 2 ("apple", "app")
```
