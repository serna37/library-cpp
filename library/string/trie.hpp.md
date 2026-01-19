---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/string/aho_corasick.hpp
    title: Aho Corasick
  - icon: ':x:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/string.aho_corasick.test.cpp
    title: "Aho Corasick\u306E\u30C6\u30B9\u30C8"
  - icon: ':x:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/trie.hpp\"\ntemplate <int char_size, int\
    \ margin>\nstruct Trie {\n    struct Node {\n        vector<int> nxt;\n      \
    \  vector<int> accept; // \u305D\u306E\u5730\u70B9\u3067\u7D42\u308F\u308B\u5358\
    \u8A9E\u306EID\u30EA\u30B9\u30C8\n        int exist;          // \u305D\u306E\u5730\
    \u70B9\u3092\u63A5\u982D\u8F9E\u3068\u3057\u3066\u6301\u3064\u5358\u8A9E\u306E\
    \u6570\n\n        Node() : nxt(char_size, -1), exist(0) {}\n    };\n    vector<Node>\
    \ nodes;\n    Trie() { nodes.emplace_back(); }\n    int size() const { return\
    \ (int)nodes.size(); }\n\n    // \u5358\u8A9E\u306E\u8FFD\u52A0\n    virtual void\
    \ add(const string& s, int id = -1) {\n        int now = 0;\n        for (char\
    \ c : s) {\n            int x = c - margin;\n            if (nodes[now].nxt[x]\
    \ == -1) {\n                nodes[now].nxt[x] = (int)nodes.size();\n         \
    \       nodes.emplace_back();\n            }\n            now = nodes[now].nxt[x];\n\
    \            nodes[now].exist++;\n        }\n        if (id != -1) nodes[now].accept.push_back(id);\n\
    \    }\n\n    // \u5358\u4E00\u306E\u5358\u8A9E\u306E\u691C\u7D22 (\u5B8C\u5168\
    \u4E00\u81F4)\n    bool search(const string& s) const {\n        int now = 0;\n\
    \        for (char c : s) {\n            int x = c - margin;\n            if (nodes[now].nxt[x]\
    \ == -1) return false;\n            now = nodes[now].nxt[x];\n        }\n    \
    \    return !nodes[now].accept.empty();\n    }\n\n    // \u63A5\u982D\u8F9E\u691C\
    \u7D22\uFF1As \u3092\u63A5\u982D\u8F9E\u3068\u3057\u3066\u6301\u3064\u5358\u8A9E\
    \u306E\u6570\u3092\u8FD4\u3059\n    int count_prefix(const string& s) const {\n\
    \        int now = 0;\n        for (char c : s) {\n            int x = c - margin;\n\
    \            if (nodes[now].nxt[x] == -1) return 0;\n            now = nodes[now].nxt[x];\n\
    \        }\n        return nodes[now].exist;\n    }\n};\n"
  code: "#pragma once\ntemplate <int char_size, int margin>\nstruct Trie {\n    struct\
    \ Node {\n        vector<int> nxt;\n        vector<int> accept; // \u305D\u306E\
    \u5730\u70B9\u3067\u7D42\u308F\u308B\u5358\u8A9E\u306EID\u30EA\u30B9\u30C8\n \
    \       int exist;          // \u305D\u306E\u5730\u70B9\u3092\u63A5\u982D\u8F9E\
    \u3068\u3057\u3066\u6301\u3064\u5358\u8A9E\u306E\u6570\n\n        Node() : nxt(char_size,\
    \ -1), exist(0) {}\n    };\n    vector<Node> nodes;\n    Trie() { nodes.emplace_back();\
    \ }\n    int size() const { return (int)nodes.size(); }\n\n    // \u5358\u8A9E\
    \u306E\u8FFD\u52A0\n    virtual void add(const string& s, int id = -1) {\n   \
    \     int now = 0;\n        for (char c : s) {\n            int x = c - margin;\n\
    \            if (nodes[now].nxt[x] == -1) {\n                nodes[now].nxt[x]\
    \ = (int)nodes.size();\n                nodes.emplace_back();\n            }\n\
    \            now = nodes[now].nxt[x];\n            nodes[now].exist++;\n     \
    \   }\n        if (id != -1) nodes[now].accept.push_back(id);\n    }\n\n    //\
    \ \u5358\u4E00\u306E\u5358\u8A9E\u306E\u691C\u7D22 (\u5B8C\u5168\u4E00\u81F4)\n\
    \    bool search(const string& s) const {\n        int now = 0;\n        for (char\
    \ c : s) {\n            int x = c - margin;\n            if (nodes[now].nxt[x]\
    \ == -1) return false;\n            now = nodes[now].nxt[x];\n        }\n    \
    \    return !nodes[now].accept.empty();\n    }\n\n    // \u63A5\u982D\u8F9E\u691C\
    \u7D22\uFF1As \u3092\u63A5\u982D\u8F9E\u3068\u3057\u3066\u6301\u3064\u5358\u8A9E\
    \u306E\u6570\u3092\u8FD4\u3059\n    int count_prefix(const string& s) const {\n\
    \        int now = 0;\n        for (char c : s) {\n            int x = c - margin;\n\
    \            if (nodes[now].nxt[x] == -1) return 0;\n            now = nodes[now].nxt[x];\n\
    \        }\n        return nodes[now].exist;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/trie.hpp
  requiredBy:
  - library/string/aho_corasick.hpp
  - library/string/finds.hpp
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/string.finds.test.cpp
  - tests/string.aho_corasick.test.cpp
documentation_of: library/string/trie.hpp
layout: document
title: "Trie\u6728"
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
- `add`: $O(\vert S \vert \cdot \sum)$ Sは追加する文字列、 $\sum$ はchar_size
- `search`: $O(\vert S \vert)$
- `count_prefix`: $O(\vert S \vert)$

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
