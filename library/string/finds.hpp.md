---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/string/aho_corasick.hpp
    title: Aho Corasick
  - icon: ':x:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':x:'
    path: library/string/trie.hpp
    title: "Trie\u6728"
  - icon: ':x:'
    path: library/various/random.hpp
    title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/string.finds.test.cpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/various/random.hpp\"\n#include <chrono>\n#include\
    \ <random>\ninline long long random(long long a, long long b) {\n    if (a >=\
    \ b) return a;\n    static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<long long> dist(a, b - 1);\n    return dist(mt);\n\
    }\n#line 3 \"library/string/rolling_hash.hpp\"\nstruct RollingHash {\n    static\
    \ const long long MOD = (1LL << 61) - 1;\n    static inline long long base = 0;\n\
    \    vector<long long> hash_sum;\n\n    // \u57FA\u6570\u3092\u30E1\u30EB\u30BB\
    \u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\u306E\u4E71\u6570\u3067\u521D\u671F\u5316\
    \u3059\u308B\n    static void init_base() {\n        if (base != 0) return;\n\
    \        base = random(2, MOD - 1);\n    }\n\n    // \u6587\u5B57\u5217\u304B\u3089\
    \u30CF\u30C3\u30B7\u30E5\u306E\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\
    \n    RollingHash(const string &s) {\n        init_base();\n        int n = s.size();\n\
    \        hash_sum.assign(n + 1, 0);\n        for (int i = 0; i < n; i++) {\n \
    \           hash_sum[i + 1] = mul(hash_sum[i], base) + s[i];\n            if (hash_sum[i\
    \ + 1] >= MOD) hash_sum[i + 1] -= MOD;\n        }\n    }\n\n    // 2^61-1 \u7528\
    \u306E\u9AD8\u901F\u306A\u639B\u3051\u7B97\n    static long long mul(long long\
    \ a, long long b) {\n        __int128_t res = (__int128_t)a * b;\n        long\
    \ long ans = (long long)(res >> 61) + (long long)(res & MOD);\n        if (ans\
    \ >= MOD) ans -= MOD;\n        return ans;\n    }\n\n    // \u7D2F\u4E57\u30C6\
    \u30FC\u30D6\u30EB\u306E\u7BA1\u7406\n    static const vector<long long>& get_pow(int\
    \ n) {\n        static vector<long long> pow_memo = {1};\n        while ((int)pow_memo.size()\
    \ <= n) {\n            pow_memo.push_back(mul(pow_memo.back(), base));\n     \
    \   }\n        return pow_memo;\n    }\n\n    // s[l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u3092\u53D6\u5F97\n    long long get(int l, int r) const {\n        long\
    \ long res = hash_sum[r] - mul(hash_sum[l], get_pow(r - l)[r - l]);\n        if\
    \ (res < 0) res += MOD;\n        return res;\n    }\n\n    // 2\u3064\u306E\u30CF\
    \u30C3\u30B7\u30E5(a, b)\u3092\u7D50\u5408\u3059\u308B\u3002b\u306E\u9577\u3055\
    \u304C b_len\n    static long long merge(long long a_hash, long long b_hash, int\
    \ b_len) {\n        long long res = mul(a_hash, get_pow(b_len)[b_len]) + b_hash;\n\
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n};\n#line 2\
    \ \"library/string/trie.hpp\"\ntemplate <int char_size, int margin>\nstruct Trie\
    \ {\n    struct Node {\n        vector<int> nxt;\n        vector<int> accept;\
    \ // \u305D\u306E\u5730\u70B9\u3067\u7D42\u308F\u308B\u5358\u8A9E\u306EID\u30EA\
    \u30B9\u30C8\n        int exist;          // \u305D\u306E\u5730\u70B9\u3092\u63A5\
    \u982D\u8F9E\u3068\u3057\u3066\u6301\u3064\u5358\u8A9E\u306E\u6570\n\n       \
    \ Node() : nxt(char_size, -1), exist(0) {}\n    };\n    vector<Node> nodes;\n\
    \    Trie() { nodes.emplace_back(); }\n    int size() const { return (int)nodes.size();\
    \ }\n\n    // \u5358\u8A9E\u306E\u8FFD\u52A0\n    virtual void add(const string&\
    \ s, int id = -1) {\n        int now = 0;\n        for (char c : s) {\n      \
    \      int x = c - margin;\n            if (nodes[now].nxt[x] == -1) {\n     \
    \           nodes[now].nxt[x] = (int)nodes.size();\n                nodes.emplace_back();\n\
    \            }\n            now = nodes[now].nxt[x];\n            nodes[now].exist++;\n\
    \        }\n        if (id != -1) nodes[now].accept.push_back(id);\n    }\n\n\
    \    // \u5358\u4E00\u306E\u5358\u8A9E\u306E\u691C\u7D22 (\u5B8C\u5168\u4E00\u81F4\
    )\n    bool search(const string& s) const {\n        int now = 0;\n        for\
    \ (char c : s) {\n            int x = c - margin;\n            if (nodes[now].nxt[x]\
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
    \        }\n        return res;\n    }\n};\n#line 4 \"library/string/finds.hpp\"\
    \n// \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\u30F3\uFF1A\u623B\u308A\u5024\u3092\
    \ map<\u691C\u7D22\u5358\u8A9E, \u51FA\u73FE\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u306E\u30EA\u30B9\u30C8> \u3067\u8FD4\u5374\nmap<string, vector<int>> finds(const\
    \ string &T, const vector<string> &patterns) {\n    map<string, vector<int>> res_map;\n\
    \    if (patterns.empty() || T.empty()) return res_map;\n    // 1. \u30D1\u30BF\
    \u30FC\u30F3\u304C1\u3064\u3060\u3051\u3067\u3001\u304B\u3064\u77ED\u3044\u5834\
    \u5408\uFF08\u30CA\u30A4\u30FC\u30D6\uFF09\n    if (patterns.size() == 1 && patterns[0].size()\
    \ < 10) {\n        const string &S = patterns[0];\n        size_t p = T.find(S);\n\
    \        while (p != string::npos) {\n            res_map[S].push_back((int)p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return res_map;\n    }\n\
    \    // 2. \u30D1\u30BF\u30FC\u30F3\u304C1\u3064\u3060\u3051\u3060\u304C\u3001\
    \u9577\u3044\u5834\u5408\uFF08Rolling Hash\uFF09\n    if (patterns.size() == 1)\
    \ {\n        vector<int> res;\n        string P = patterns[0];\n        int t\
    \ = (int)T.size(), p = (int)P.size();\n        if (p <= t) {\n            RollingHash\
    \ rht(T);\n            RollingHash rhp(P);\n            long long hash_p = rhp.get(0,\
    \ p);\n            for (int i = 0; i <= t - p; ++i) {\n                if (rht.get(i,\
    \ i + p) == hash_p) res.emplace_back(i);\n            }\n        }\n        res_map[patterns[0]]\
    \ = res;\n        return res_map;\n    }\n    // 3. \u30D1\u30BF\u30FC\u30F3\u304C\
    \u8907\u6570\u3042\u308B\u5834\u5408\uFF08Aho-Corasick\uFF09\n    AhoCorasick<128,\
    \ 0> ac;\n    for (int i = 0; i < (int)patterns.size(); ++i) {\n        if (patterns[i].empty())\
    \ continue;\n        ac.add(patterns[i], i);\n        res_map[patterns[i]]; //\
    \ \u30D2\u30C3\u30C8\u3057\u306A\u304B\u3063\u305F\u5358\u8A9E\u3082\u30AD\u30FC\
    \u3068\u3057\u3066\u5B58\u5728\u3055\u305B\u308B\u5834\u5408\u306F\u3053\u3053\
    \u3067\u521D\u671F\u5316\n    }\n    ac.build();\n    int now = 0;\n    for (int\
    \ i = 0; i < (int)T.size(); ++i) {\n        now = ac.next(now, T[i]);\n      \
    \  int temp = now;\n        while (temp > 0 && ac.count[temp] > 0) {\n       \
    \     for (int id : ac.nodes[temp].accept) {\n                res_map[patterns[id]].push_back(i\
    \ - (int)patterns[id].size() + 1);\n            }\n            temp = ac.failure[temp];\n\
    \        }\n    }\n    return res_map;\n}\n"
  code: "#pragma once\n#include \"library/string/rolling_hash.hpp\"\n#include \"library/string/aho_corasick.hpp\"\
    \n// \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\u30F3\uFF1A\u623B\u308A\u5024\u3092\
    \ map<\u691C\u7D22\u5358\u8A9E, \u51FA\u73FE\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u306E\u30EA\u30B9\u30C8> \u3067\u8FD4\u5374\nmap<string, vector<int>> finds(const\
    \ string &T, const vector<string> &patterns) {\n    map<string, vector<int>> res_map;\n\
    \    if (patterns.empty() || T.empty()) return res_map;\n    // 1. \u30D1\u30BF\
    \u30FC\u30F3\u304C1\u3064\u3060\u3051\u3067\u3001\u304B\u3064\u77ED\u3044\u5834\
    \u5408\uFF08\u30CA\u30A4\u30FC\u30D6\uFF09\n    if (patterns.size() == 1 && patterns[0].size()\
    \ < 10) {\n        const string &S = patterns[0];\n        size_t p = T.find(S);\n\
    \        while (p != string::npos) {\n            res_map[S].push_back((int)p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return res_map;\n    }\n\
    \    // 2. \u30D1\u30BF\u30FC\u30F3\u304C1\u3064\u3060\u3051\u3060\u304C\u3001\
    \u9577\u3044\u5834\u5408\uFF08Rolling Hash\uFF09\n    if (patterns.size() == 1)\
    \ {\n        vector<int> res;\n        string P = patterns[0];\n        int t\
    \ = (int)T.size(), p = (int)P.size();\n        if (p <= t) {\n            RollingHash\
    \ rht(T);\n            RollingHash rhp(P);\n            long long hash_p = rhp.get(0,\
    \ p);\n            for (int i = 0; i <= t - p; ++i) {\n                if (rht.get(i,\
    \ i + p) == hash_p) res.emplace_back(i);\n            }\n        }\n        res_map[patterns[0]]\
    \ = res;\n        return res_map;\n    }\n    // 3. \u30D1\u30BF\u30FC\u30F3\u304C\
    \u8907\u6570\u3042\u308B\u5834\u5408\uFF08Aho-Corasick\uFF09\n    AhoCorasick<128,\
    \ 0> ac;\n    for (int i = 0; i < (int)patterns.size(); ++i) {\n        if (patterns[i].empty())\
    \ continue;\n        ac.add(patterns[i], i);\n        res_map[patterns[i]]; //\
    \ \u30D2\u30C3\u30C8\u3057\u306A\u304B\u3063\u305F\u5358\u8A9E\u3082\u30AD\u30FC\
    \u3068\u3057\u3066\u5B58\u5728\u3055\u305B\u308B\u5834\u5408\u306F\u3053\u3053\
    \u3067\u521D\u671F\u5316\n    }\n    ac.build();\n    int now = 0;\n    for (int\
    \ i = 0; i < (int)T.size(); ++i) {\n        now = ac.next(now, T[i]);\n      \
    \  int temp = now;\n        while (temp > 0 && ac.count[temp] > 0) {\n       \
    \     for (int id : ac.nodes[temp].accept) {\n                res_map[patterns[id]].push_back(i\
    \ - (int)patterns[id].size() + 1);\n            }\n            temp = ac.failure[temp];\n\
    \        }\n    }\n    return res_map;\n}\n"
  dependsOn:
  - library/string/rolling_hash.hpp
  - library/various/random.hpp
  - library/string/aho_corasick.hpp
  - library/string/trie.hpp
  isVerificationFile: false
  path: library/string/finds.hpp
  requiredBy: []
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/string.finds.test.cpp
documentation_of: library/string/finds.hpp
layout: document
title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\u30F3"
---

# 文字列複数 統合検索エンジン

## できること
- 文字列Tの中にあるSの一致場所を全て取得、マッチした頭のインデックスを返す

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
