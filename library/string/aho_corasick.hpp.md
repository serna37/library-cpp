---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/trie.hpp
    title: "Trie\u6728"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.aho_corasick.test.cpp
    title: "Aho Corasick\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \        }\n        return nodes[now].exist;\n    }\n};\n#line 3 \"library/string/aho_corasick.hpp\"\
    \ntemplate <int char_size, int margin>\nstruct AhoCorasick : Trie<char_size, margin>\
    \ {\n    using Trie<char_size, margin>::nodes;\n\n    vector<int> failure; //\
    \ \u5931\u6557\u30EA\u30F3\u30AF\n    vector<int> count;   // \u305D\u306E\u30CE\
    \u30FC\u30C9\u3067\u30DE\u30C3\u30C1\u3059\u308B\u30D1\u30BF\u30FC\u30F3\u306E\
    \u7DCF\u6570\n    AhoCorasick() : Trie<char_size, margin>() {}\n\n    // \u5931\
    \u6557\u30EA\u30F3\u30AF\u306E\u69CB\u7BC9\u3068\u9077\u79FB\u95A2\u6570\u306E\
    \u6700\u9069\u5316\n    void build() {\n        int n = (int)nodes.size();\n \
    \       failure.assign(n, 0);\n        count.assign(n, 0);\n        for (int i\
    \ = 0; i < n; i++) {\n            count[i] = (int)nodes[i].accept.size();\n  \
    \      }\n        queue<int> que;\n        for (int i = 0; i < char_size; i++)\
    \ {\n            if (nodes[0].nxt[i] != -1) {\n                que.push(nodes[0].nxt[i]);\n\
    \            } else {\n                nodes[0].nxt[i] = 0;\n            }\n \
    \       }\n        while (!que.empty()) {\n            int now = que.front();\n\
    \            que.pop();\n            for (int i = 0; i < char_size; i++) {\n \
    \               int& next_node = nodes[now].nxt[i];\n                int fail_link\
    \ = nodes[failure[now]].nxt[i];\n                if (next_node != -1) {\n    \
    \                failure[next_node] = fail_link;\n                    count[next_node]\
    \ += count[fail_link];\n                    que.push(next_node);\n           \
    \     } else {\n                    next_node = fail_link;\n                }\n\
    \            }\n        }\n    }\n\n    // \u6B21\u306E\u72B6\u614B\u3078\u9077\
    \u79FB\n    int next(int now, char c) const {\n        return nodes[now].nxt[c\
    \ - margin];\n    }\n\n    // \u6587\u5B57\u5217\u5168\u4F53\u3092\u8D70\u67FB\
    \u3057\u3066\u7DCF\u30D2\u30C3\u30C8\u6570\u3092\u8FD4\u3059\n    long long count_all(const\
    \ string& s) const {\n        long long res = 0;\n        int now = 0;\n     \
    \   for (char c : s) {\n            now = next(now, c);\n            res += count[now];\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"library/string/trie.hpp\"\ntemplate <int char_size,\
    \ int margin>\nstruct AhoCorasick : Trie<char_size, margin> {\n    using Trie<char_size,\
    \ margin>::nodes;\n\n    vector<int> failure; // \u5931\u6557\u30EA\u30F3\u30AF\
    \n    vector<int> count;   // \u305D\u306E\u30CE\u30FC\u30C9\u3067\u30DE\u30C3\
    \u30C1\u3059\u308B\u30D1\u30BF\u30FC\u30F3\u306E\u7DCF\u6570\n    AhoCorasick()\
    \ : Trie<char_size, margin>() {}\n\n    // \u5931\u6557\u30EA\u30F3\u30AF\u306E\
    \u69CB\u7BC9\u3068\u9077\u79FB\u95A2\u6570\u306E\u6700\u9069\u5316\n    void build()\
    \ {\n        int n = (int)nodes.size();\n        failure.assign(n, 0);\n     \
    \   count.assign(n, 0);\n        for (int i = 0; i < n; i++) {\n            count[i]\
    \ = (int)nodes[i].accept.size();\n        }\n        queue<int> que;\n       \
    \ for (int i = 0; i < char_size; i++) {\n            if (nodes[0].nxt[i] != -1)\
    \ {\n                que.push(nodes[0].nxt[i]);\n            } else {\n      \
    \          nodes[0].nxt[i] = 0;\n            }\n        }\n        while (!que.empty())\
    \ {\n            int now = que.front();\n            que.pop();\n            for\
    \ (int i = 0; i < char_size; i++) {\n                int& next_node = nodes[now].nxt[i];\n\
    \                int fail_link = nodes[failure[now]].nxt[i];\n               \
    \ if (next_node != -1) {\n                    failure[next_node] = fail_link;\n\
    \                    count[next_node] += count[fail_link];\n                 \
    \   que.push(next_node);\n                } else {\n                    next_node\
    \ = fail_link;\n                }\n            }\n        }\n    }\n\n    // \u6B21\
    \u306E\u72B6\u614B\u3078\u9077\u79FB\n    int next(int now, char c) const {\n\
    \        return nodes[now].nxt[c - margin];\n    }\n\n    // \u6587\u5B57\u5217\
    \u5168\u4F53\u3092\u8D70\u67FB\u3057\u3066\u7DCF\u30D2\u30C3\u30C8\u6570\u3092\
    \u8FD4\u3059\n    long long count_all(const string& s) const {\n        long long\
    \ res = 0;\n        int now = 0;\n        for (char c : s) {\n            now\
    \ = next(now, c);\n            res += count[now];\n        }\n        return res;\n\
    \    }\n};\n"
  dependsOn:
  - library/string/trie.hpp
  isVerificationFile: false
  path: library/string/aho_corasick.hpp
  requiredBy:
  - library/string/finds.hpp
  timestamp: '2026-01-16 14:13:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.finds.test.cpp
  - tests/string.aho_corasick.test.cpp
documentation_of: library/string/aho_corasick.hpp
layout: document
title: Aho Corasick
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
